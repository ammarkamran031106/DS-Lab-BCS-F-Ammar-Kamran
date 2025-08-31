#include <iostream>
using namespace std;

int main() {
    int days, times;
    cout << "Enter number of days: ";
    cin >> days;
    cout << "How many time reading per day: ";
    cin >> times;

    int** temp = new int*[days];
    for (int i = 0; i < days; i++) {
        temp[i] = new int[times];
    }

    cout << "Enter temperature readings:" << endl;
    for (int i = 0; i < days; i++) {
        cout << "Day " << i + 1 << ":" << endl;
        for (int j = 0; j < times; j++) {
            cin >> temp[i][j];
        }
    }

    double* avg = new double[days];
    for (int i = 0; i < days; i++) {
        int sum = 0;
        for (int j = 0; j < times; j++) {
            sum += temp[i][j];
        }
        avg[i] = sum / times;
    }

    cout << endl << "Daily average temperatures:" << endl;
    for (int i = 0; i < days; i++) {
        cout << "Day " << i + 1 << ": " << avg[i] << endl;
    }

    int hottest = 0, coldest = 0;
    for (int i = 1; i < days; i++) {
        if (avg[i] > avg[hottest]) hottest = i;
        if (avg[i] < avg[coldest]) coldest = i;
    }

    cout << endl << "Hottest day: Day " << hottest + 1 << " (" << avg[hottest] << ")" << endl;
    cout << "Coldest day: Day " << coldest + 1 << " (" << avg[coldest] << ")" << endl;

    for (int i = 0; i < days; i++) {
        delete[] temp[i];
    }
    delete[] temp;
    delete[] avg;

    return 0;
}

