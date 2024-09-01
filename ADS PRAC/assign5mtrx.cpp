#include <iostream>
using namespace std;
class graph{
    public:
    int fuel,n,i,j;
    string city[10];
    int a[10][10];
    void create();
    void display();
    }*g;
void graph::create(){
    cout<<"enter the number of cities:";
    cin>>n;
    cout<<"enter the names of the cities:";
    for(i=0;i<n;i++){
        cin>>city[i];
}

cout<<"enter the fuel cost of each:\n";
for(i=0;i<n;i++){
    for(j=i;j<n;j++){
         if(i==j){
            a[i][j]=0;
            }
            else{
                cout<<city[i]<<"-"<<city[j]<<endl;
              cin>>a[i][j]; 
              a[j][i]=a[i][j];
            }
    }
}
}
void graph::display(){
    cout<<"\t";
    for(i=0;i<n;i++)
    {
        cout<<city[i]<<"\t";
    }
    cout<<"\n";
    for(i=0;i<n;i++){
        cout<<city[i]<<"\t";
        for(j=0;j<n;j++){
           cout<<a[i][j]<<"\t";
        }
           cout<<endl;
    }
 
}

int main(){
    graph b;
    b.create();
    b.display();
    return 0;
}