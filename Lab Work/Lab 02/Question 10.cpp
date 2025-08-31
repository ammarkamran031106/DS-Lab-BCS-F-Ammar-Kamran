#include <iostream>
using namespace std;

int main() {
    int categories;
    cout << "Enter number of categories: ";
    cin >> categories;

    int** books = new int*[categories];
    int* bookCount = new int[categories];

    for (int i = 0; i < categories; i++) {
        cout << "Enter number of books in category " << i + 1 << ": ";
        cin >> bookCount[i];
        books[i] = new int[bookCount[i]];
        cout << "Enter book IDs for category " << i + 1 << ":" << endl;
        for (int j = 0; j < bookCount[i]; j++) {
            cin >> books[i][j];
        }
    }

    int searchID;
    cout << endl << "Enter book ID to search: ";
    cin >> searchID;

    bool found = false;
    int foundCategory = -1;

    for (int i = 0; i < categories; i++) {
        for (int j = 0; j < bookCount[i]; j++) {
            if (books[i][j] == searchID) {
                found = true;
                foundCategory = i;
                break;
            }
        }
        if (found) break;
    }

    if (found) {
        cout << "Book ID " << searchID << " is available in Category " << foundCategory + 1 << endl;
    } else {
        cout << "Book ID " << searchID << " is not available in the library." << endl;
    }

    for (int i = 0; i < categories; i++) {
        delete[] books[i];
    }
    delete[] books;
    delete[] bookCount;

    return 0;
}
