#include<iostream>
using namespace std;

class cms {
public:
    int amt, did;
    string name, addd;
    long int cn;
    cms *next, *prev;
    
    void accept(); // accept the record
    void display(); // display the record
    void search(); // search the record
    void update(); // update the record
    void Delete(); // delete the record
};

cms *start = NULL, *end1 = NULL;

void cms::accept() {
    cms *temp = new cms;
    cout << "Enter the id = ";
    cin >> temp->did;
    cout << "Enter the name = ";
    cin >> temp->name;
    cout << "Enter the phone no = ";
    cin >> temp->cn;
    cout << "Enter the address = ";
    cin >> temp->addd;
    cout << "Enter the amount = ";
    cin >> temp->amt;
    temp->prev = temp->next = NULL;
    if (start == NULL) {
        start = end1 = temp;
    }
    else {
        end1->next = temp;
        temp->prev = end1;
        end1 = temp;
    }
}

void cms::display() {
    cms *temp = start;
    int c = 0;
    cout << "\nDid\tName\tAddress\tContact No\tAmount\n";
    while (temp != NULL) {
        c++;
        cout << temp->did << "\t" << temp->name << "\t" << temp->addd << "\t" << temp->cn << "\t" << temp->amt << endl;
        temp = temp->next;
    }
    cout << "Total no of records: " << c << endl;
}

void cms::search() {
    cms *temp = start;
    int n, f = 0;
    cout << "Enter the id for search: ";
    cin >> n;
    while (temp != NULL) {
        if (temp->did == n) {
            f = 1;
            cout << "Record found\n";
            cout << "Did\tName\tAddress\tContact No\tAmount\n";
            cout << temp->did << "\t" << temp->name << "\t" << temp->addd << "\t" << temp->cn << "\t" << temp->amt << endl;
            break;
        }
        temp = temp->next;
    }
    if (f == 0) {
        cout << "Record not found\n";
    }
}

void cms::update() {
    cms *temp = start;
    int n, f = 0;
    cout << "Enter the id for update: ";
    cin >> n;
    while (temp != NULL) {
        if (temp->did == n) {
            f = 1;
            cout << "Record found\n";
            cout << "Enter new record\n";
            cout << "Enter the id = ";
            cin >> temp->did;
            cout << "Enter the name = ";
            cin >> temp->name;
            cout << "Enter the phone no = ";
            cin >> temp->cn;
            cout << "Enter the address = ";
            cin >> temp->addd;
            cout << "Enter the amount = ";
            cin >> temp->amt;
            break;
        }
        temp = temp->next;
    }
    if (f == 0) {
        cout << "Record not found\n";
    }
}

void cms::Delete() {
    cms *temp = start, *p = NULL;
    int n, f = 0;
    cout << "Enter the id for delete: ";
    cin >> n;
    while (temp != NULL) {
        if (temp->did == n) {
            f = 1;
            break;
        }
        p = temp;
        temp = temp->next;
    }
    if (f == 1) {
        if (temp == start) {
            start = temp->next;
        }
        if (temp == end1) {
            end1 = p;
        }
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        }
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        delete temp;
        cout << "Record deleted successfully\n";
    }
    else {
        cout << "Record not found\n";
    }
}

int main() {
    cms b;
    int ch, u;
    do {
        cout << "\nWELCOME TO CMS!\n";
        cout << "1. Accept the donor record\n";
        cout << "2. Display the donor record\n";
        cout << "3. Search the donor record\n";
        cout << "4. Update the donor record\n";
        cout << "5. Delete the donor record\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                b.accept();
                break;
            case 2:
                cout << "\nDid\tName\tAddress\tContact No\tAmount\n";
                b.display();
                break;
            case 3:
                b.search();
                break;
            case 4:
                b.update();
                break;
            case 5:
                b.Delete();
                break;
            case 6:
                cout << "Thanks for visiting...!!!" << endl;
                break;
            default:
                cout << "Wrong choice\n";
        }
        cout << "Do you want to repeat? (1/0): ";
        cin >> u;
    } while (u != 0);
    return 0;
}
