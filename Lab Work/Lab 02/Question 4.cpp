#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of months to track expenses: ";
    cin >> n;

    double* expenses = new double[n];

    cout << "\nEnter expenses for " << n << " months:\n";
    for (int i = 0; i < n; i++) {
        cout << "Month " << i + 1 << ": ";
        cin >> expenses[i];
    }

    char choice;
    cout << "\nDo you want to add more months?(yes or no) ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        int extra;
        cout << "How many extra months to add? ";
        cin >> extra;

        double* newExpenses = new double[n + extra];

        for (int i = 0; i < n; i++) {
            newExpenses[i] = expenses[i];
        }

        delete[] expenses;
        expenses = newExpenses;

        cout << "\nEnter expenses for extra " << extra << " months:\n";
        for (int i = n; i < n + extra; i++) {
            cout << "Month " << i + 1 << ": ";
            cin >> expenses[i];
        }

        n += extra;
    }

    double total = 0;
    for (int i = 0; i < n; i++) {
        total += expenses[i];
    }
    double average = total / n;

    cout << "TOTAL EXPENSE REPORT "<<endl;;
    cout << "Total months tracked: " << n << endl;
    cout << "Total expenses: " << total << endl;
    cout << "Average monthly expense: " << average << endl;

    delete[] expenses;
    return 0;
}
