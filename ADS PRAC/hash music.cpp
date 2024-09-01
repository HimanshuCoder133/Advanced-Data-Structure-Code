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
    cout<<"enter the track number:";
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
    cout<<" \nTrack_no\tS_name\tM_name\t R_year\tlikes\tCHAIN";
   
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
           cout <<"\nEnter Song details:\n";
           cout <<"\nSong name:";
           cin>>h[no].sname;
           cout<<"\nMovie Name:";
           cin>>h[no].mname;
           cout<<"\nRelease year:";
           cin>>h[no].ryear;
           cout<<"\nNo of likes:";
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
    cout << "\nEnter track no that you want to search: ";
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
            cout << "Track no: " << h[no].tn << "\n";
            cout << "Song name: " << h[no].sname << "\n";
            cout << "Movie name: " << h[no].mname << "\n";
            cout << "Release year: " << h[no].ryear << "\n";
            cout << "No of likes: " << h[no].no_likes << "\n";

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
    cout << "\nEnter Track no that you want to update: ";
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
            cout<<"\nTrack no:";
            cin>>h[no].tn ;
            cout <<"\nSong name:";
            cin>>h[no].sname;
            cout<<"\nMovie Name:";
            cin>>h[no].mname;
            cout<<"\nRelease year:";
            cin>>h[no].ryear;
            cout<<"\nNo of likes:";
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
    cout << "\nEnter Track no that you want to delete: ";
    cin >> trn;

    int no = trn % 10;
    int pos = no;
    if(h[no].tn==-1)
    {
        cout<<"\nTable is empty.";
    }
    else{

    while (h[no].tn != -1)
    {
        if (h[no].tn == trn)
        {
            f = 1;
            cout << "Record found at location " << no << "\n";
            h[no].tn = -1;
            h[no].sname = -1; 
            h[no].mname = -1;
            h[no].ryear = -1;
            h[no].no_likes = -1;

            break;
        }
        no = (no + 1) % n; 
        if (no == pos)
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