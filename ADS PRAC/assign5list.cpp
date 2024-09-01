#include <iostream>
using namespace std;
int i,j;
class AL
{
public:
    int fuel,v ;
    string city;
    AL *next;
    void create();
    void display();
    void grp();
} *start[20];
void AL::create()
{
    cout << "Total no of vertices:";
    cin >> v;
    cout << "Enter the name of cities:" << endl;
    for (i = 0; i < v; i++)
    {
        start[i] = new AL;
        cout << "City name:";
        cin >> start[i]->city;
        start[i]->next = NULL;
    }
}
void AL::grp()
{
   // int i, j;
    string s, d;
    int e;
    AL *nn, *temp;
    cout << "Enter the total no. of edges";
    cin >> e;
    for (i = 0; i < e; i++)
    {
        cout << "Enter the source and dest city:";
        cin >> s >> d;

        for (j = 0; j < v; j++)
        {
            if (s == start[j]->city)
                break;
        }
        nn = new AL;
        nn->city = d;
        cout << "Enter the fuel: ";
        cin >> nn->fuel;
        nn->next = NULL;
        temp = start[j];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = nn;
    }
}
void AL::display()
{
    AL *nn;
    for (i = 0; i < v; i++)
    {
        cout << "source" << start[i]->city;
        nn = start[i]->next;
        while (nn != NULL)
        {
            cout << "\tDest:" << nn->city;
            cout << "\tfuel:" << nn->fuel;
            cout<<"\n";
            nn = nn->next;
        }
    }
}
int main()
{
    AL obj;
    obj.create();
    obj.grp();
    obj.display();
    return 0;
}