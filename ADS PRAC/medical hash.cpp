#include<iostream>
#include<string>
using namespace std;
int key[100],c[100],n;
class music
{
    public:
    int tn,no_likes,ryear;
    string sname,mname;
    void declare();
    void htable();
    void accept();
    void search();
    void update();
    void remove();
}h[100];

void music::declare()
{
    cout<<"enter total no. of keys :";
    cin>>n;
    cout<<"enter the medical number:";
    for(int i = 0;i<n;i++)
    {
    cin>>key[i];
    }
    for(int i =0;i<100;i++)
     {
    h[i].tn=-1;
    c[i]=0;
    }
    }
void music::htable()
{
    cout<<" \nMed_no\tM_name\tB_name\t E_year\tQuantity\tCHAIN";
   
    for(int i =0;i<100;i++)
    {
    cout<<"\n"<< h[i].tn<<"\t"<<h[i].sname<<"\t"<< h[i].mname<<"\t"<<h[i].ryear<<"\t"<<h[i].no_likes<<"\t"<<c[i];
}
}
void music::accept()
{
    int no,pos;
    for(int i=0;i<n;i++)
    {
        no = key[i] % 10;
        pos=no;
    
    do{
        if(h[no].tn==-1)
        {
            h[no].tn=key[i];
           cout <<"\nEnter Meicine details:\n";
           cout <<"\nMedicine name:";
           cin>>h[no].sname;
           cout<<"\nBrand Name:";
           cin>>h[no].mname;
           cout<<"\nExpiry year:";
           cin>>h[no].ryear;
           cout<<"\nQuantity:";
           cin>>h[no].no_likes;
            break;
        }
        else{
            no++;
            c[pos]=no;
            if(no>n){
                no=0;
            }
        }
    }while(no<10);
    }
}
void music::search()
{
    int trn, f = 0;
    cout << "\nEnter Medicine no that you want to search: ";
    cin >>trn;
    
    int no = trn % 10;
    int pos= no;
    if(h[no].tn==-1)
    {
        cout<<"\ntable is empty.";
    }
    else{
    
    while (h[no].tn != -1)
    {
        if (h[no].tn == trn)
        {
            f = 1;
            cout << "Record found at location " << no<< "\n";
            cout << "Medicine no: " << h[no].tn << "\n";
            cout << "Medicine name: " << h[no].sname << "\n";
            cout << "Brand name: " << h[no].mname << "\n";
            cout << "Expiry year: " << h[no].ryear << "\n";
            cout << "Quantity: " << h[no].no_likes << "\n";

            break;
        }
        no= (no+ 1) % n; 
        if (no == pos)
            break;
    }

    if (f == 0)
    {
        cout << "Record not found!\n";
    }
    }
}
void music::update()
{
    int trn, f = 0;
    int i;
    cout << "\nEnter Medicine no that you want to update: ";
    cin >> trn;
    
    int no = trn % 10;
    int pos= no;
    for ( i = 0; i < n; i++)
    {
        
    
    
    if(h[no].tn==-1)
    {
        cout<<"\nTable is empty.";
    }
    else
    {
    while (h[no].tn != -1)
    {
        if (h[no].tn == trn)
        {
            f = 1;
            cout << "Record found at location " << no<< "\n";
            cout<<"Enter the new record:\n";
            cout<<"\nMedicine no:";
            cin>>h[no].tn ;
            cout <<"\nMedicine name:";
            cin>>h[no].sname;
            cout<<"\nBrand Name:";
            cin>>h[no].mname;
            cout<<"\nExpiry year:";
            cin>>h[no].ryear;
            cout<<"\nQuantity:";
            cin>>h[no].no_likes;
            cout<<"\nRecord got updated.";
            break;
        }
        no= (no+ 1) % n; 
        if (no == pos)
            break;
    }
    }}
    if (f == 0)
    {
        cout << "Record not found!\n";
    }
}


void music::remove()
{
    int trn, f = 0;
    cout << "\nEnter Medicine no that you want to delete: ";
    cin >> trn;

    int hash_value = trn % 10;
    int initial_hash_value = hash_value;
    if(h[hash_value].tn==-1)
    {
        cout<<"\nTable is empty.";
    }
    else{

    while (h[hash_value].tn != -1)
    {
        if (h[hash_value].tn == trn)
        {
            f = 1;
            cout << "Record found at location " << hash_value << "\n";
            h[hash_value].tn = -1;
            h[hash_value].sname = -1; 
            h[hash_value].mname = -1;
            h[hash_value].ryear = -1;
            h[hash_value].no_likes = -1;

            break;
        }
        hash_value = (hash_value + 1) % n; 
        if (hash_value == initial_hash_value)
            break;
    }

    if (f == 0)
    {
        cout << "Record not found!\n";
    }
}
}

int main()

{
    music m;
    int ch,y;
   
    do{
        cout<<"\n1.Declare\n2.Htable\n3.Accept\n4.Search\n5.Update\n6.Remove\n7.Exit\n";
        cout<<"Enter ur choice:\n";
        cin>>ch;

    switch(ch)
    {

    case 1:
    m.declare();
    break;
    
    case 2:
    m.htable();
    break;
    
    case 3:
    m.accept();
    break;
   
   
    case 4:
    m.search();
    break;
   
    case 5:
    m.update();
    break;
  
    case 6:
    m.remove();
    break;

    case 7:
    exit(0);
   
    break;
    }cout<<"\nIf u want to continue press 1 or for exit press 0\n";
    cin>>y;
    }while(y==1);
    return 0;
}