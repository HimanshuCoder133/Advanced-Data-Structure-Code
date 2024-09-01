#include<iostream>
using namespace std;

class book {
public:
    int id, prize;
    string title, author, isbn, pub;
    book* next;

    void accept();      // accept the record
    void display();     // display the record
    void search();      // search the record
    void update();      // update the record
    void fdelete();     // delete first record
    void ldelete();     // delete last record
    void pdelete();     // delete specific record
};

book* start = NULL;
book* end1 = NULL;

void book::accept() {
    book* temp = new book;
    cout << "Enter the book id: ";
    cin >> temp->id;
    cout << "Enter the book title: ";
    cin >> temp->title;
    cout << "Enter the book author: ";
    cin >> temp->author;
    cout << "Enter the book publisher: ";
    cin >> temp->pub;
    cout << "Enter the book isbn: ";
    cin >> temp->isbn;
    cout << "Enter the book prize: ";
    cin >> temp->prize;
    temp->next = NULL;
    if (start == NULL) {
        end1 = start = temp;
    }
    else {
        end1->next = temp;
        end1 = temp;
    }
}

void book::display() {
    book* temp = start;
    int c = 0;
    cout << "\nBookid\tTitle\tAuthor\tPublisher\tISBN\tPrize\n";
    while (temp != NULL) {
        c++;
        cout << temp->id << "\t" << temp->title << "\t" << temp->author << "\t" << temp->pub << "\t\t" << temp->isbn << "\t" << temp->prize << endl;
        temp = temp->next;
    }
    cout << "Total number of books: " << c << endl;
}

void book::search() {
    book* temp = start;
    int n, f = 0;
    cout << "Enter the id to search: ";
    cin >> n;
    while (temp != NULL) {
        if (temp->id == n) {
            f = 1;
            cout << "Record found\n";
            cout << "Bookid\tTitle\tAuthor\tPublisher\tISBN\tPrize\n";
            cout << temp->id << "\t" << temp->title << "\t" << temp->author << "\t" << temp->pub << "\t\t" << temp->isbn << "\t" << temp->prize << endl;
            break;
        }
        temp = temp->next;
    }
    if (f == 0) {
        cout << "Record not found\n";
    }
}

void book::update() {
    book* temp = start;
    int n, f = 0;
    cout << "Enter the id to update: ";
    cin >> n;
    while (temp != NULL) {
        if (temp->id == n) {
            f = 1;
            cout << "Record found\n";
            cout << "Enter the new book title: ";
            cin >> temp->title;
            cout << "Enter the new book author: ";
            cin >> temp->author;
            cout << "Enter the new book publisher: ";
            cin >> temp->pub;
            cout << "Enter the new book isbn: ";
            cin >> temp->isbn;
            cout << "Enter the new book prize: ";
            cin >> temp->prize;
            break;
        }
        temp = temp->next;
    }
    if (f == 0) {
        cout << "Record not found\n";
    }
}

void book::fdelete() {
    if (start == NULL) {
        cout << "Records are empty\n";
    }
    else {
        book* temp = start;
        start = start->next;
        delete temp;
        cout << "Record deleted successfully\n";
    }
}

void book::ldelete() {
    if (start == NULL) {
        cout << "Records are empty\n";
    }
    else {
        if (start->next == NULL) {
            delete start;
            start = end1 = NULL;
        }
        else {
            book* temp = start;
            while (temp->next->next != NULL) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
            end1 = temp;
        }
        cout << "Last record deleted successfully\n";
    }
}

void book::pdelete() {
    int x;
    cout << "Enter the book id to delete: ";
    cin >> x;
    book* temp = start;
    book* prev = NULL;
    while (temp != NULL) {
        if (temp->id == x) {
            if (temp == start) {
                start = start->next;
                delete temp;
                cout << "Record deleted successfully\n";
                return;
            }
            prev->next = temp->next;
            if (temp == end1) {
                end1 = prev;
            }
            delete temp;
            cout << "Record deleted successfully\n";
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "Record not found\n";
}

int main() {
    book b;
    int ch;
    do {
        cout << "\nWELCOME TO LIBRARY!\n";
        cout << "1. Accept the book record\n";
        cout << "2. Display the book record\n";
        cout << "3. Search the book record\n";
        cout << "4. Update the book record\n";
        cout << "5. Delete the first book record\n";
        cout << "6. Delete the last record\n";
        cout << "7. Delete any record\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                b.accept();
                break;
            case 2:
                cout << "\nBookid\tTitle\tAuthor\tPublisher\tISBN\tPrize\n";
                b.display();
                break;
            case 3:
                b.search();
                break;
            case 4:
                b.update();
                break;
            case 5:
                b.fdelete();
                break;
            case 6:
                b.ldelete();
                break;
            case 7:
                b.pdelete();
                break;
            case 8:
                cout << "Thanks for visiting!\n";
                break;
            default:
                cout << "Wrong choice\n";
        }
    } while (ch != 8);
    return 0;
}
