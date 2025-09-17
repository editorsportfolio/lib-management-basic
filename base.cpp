#include <iostream>
#include <vector>
#include <string>

using namespace std;

class book {
public:
    string title;
    string author;
    int id;
    bool issued;

    book(string t, string a, int i) {
        title = t;
        author = a;
        id = i;
        issued = false;
    }

    void display() const {
        cout << "ID: " << id << " | Title: " << title << " | Author: " << author << " | Status: " << (issued ? "Issued" : "Available") << endl;
    }
};

void addbook(vector<book>& library) {
    string title, author;
    int id;
    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, title);
    cout << "Enter author: ";
    getline(cin, author);
    cout << "Enter ID: ";
    cin >> id;
    library.push_back(book(title, author, id));
    cout << "Book added successfully!" << endl;
}

void viewbook(const vector<book>& library) {
    if (library.empty()) {
        cout << "No books in library." << endl;
        return;
    }
    for (const auto& b : library) {
        b.display();
    }
}

void issueBook(vector<book>& library) {
    int id;
    cout << "Enter book ID to issue: ";
    cin >> id;
    for (auto& b : library) {
        if (b.id == id) {
            if (!b.issued) {
                b.issued = true;
                cout << "Book issued successfully!" << endl;
            } else {
                cout << "Book is already issued." << endl;
            }
            return;
        }
    }
    cout << "Book not found." << endl;
}

void returnBook(vector<book>& library) {
    int id;
    cout << "Enter book ID to return: ";
    cin >> id;
    for (auto& b : library) {
        if (b.id == id) {
            if (b.issued) {
                b.issued = false;
                cout << "Book returned successfully!" << endl;
            } else {
                cout << "Book was not issued." << endl;
            }
            return;
        }
    }
    cout << "Book not found." << endl;
}

void searchBook(const vector<book>& library) {
    string query;
    cout << "Enter title, author, or ID to search: ";
    cin.ignore();
    getline(cin, query);
    bool found = false;
    for (const auto& b : library) {
        if (b.title.find(query) != string::npos || b.author.find(query) != string::npos || to_string(b.id) == query) {
            b.display();
            found = true;
        }
    }
    if (!found) {
        cout << "No books found matching the query." << endl;
    }
}

int main() {
    vector<book> library;
    int choice;
    do {
        cout << "--- Library Management System ---" << endl;
        cout << "1. Add book" << endl;
        cout << "2. View books" << endl;
        cout << "3. Issue book" << endl;
        cout << "4. Return book" << endl;
        cout << "5. Search book" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: addbook(library); break;
            case 2: viewbook(library); break;
            case 3: issueBook(library); break;
            case 4: returnBook(library); break;
            case 5: searchBook(library); break;
            case 6: cout << "...Exiting..." << endl; break;
            default: cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 6);
    return 0;
}
