#include <iostream>
using namespace std;

int main() {
    int dept;
    cout << "Enter number of departments: ";
    cin >> dept;

    int** salaries = new int*[dept];
    int* empCount = new int[dept];

   for(int i=0;i<dept;i++){
       cout<<"Enter the no of employee in department "<<i+1<<": "<<endl;
       cin>>empCount[i];
       salaries[i]=new int[empCount[i]];
   }
   for(int i=0;i<dept;i++){
       for(int j=0; j<empCount[i];j++){
           cout<<"Enter salaries of department "<<i+1<<" of employee "<< j+1<<": "<<endl;
           int n;
           cin>>n;
           salaries[i][j]=n;
       }
   }
   

    cout << endl << "Highest salary in each department:" << endl;
    for (int i = 0; i < dept; i++) {
        int highest = salaries[i][0];
        for (int j = 1; j < empCount[i]; j++) {
            if (salaries[i][j] > highest) highest = salaries[i][j];
        }
        cout << "Department " << i + 1 << ": " << highest << endl;
    }

    int bestDept = 0;
    double maxAvg = 0;
    for (int i = 0; i < dept; i++) {
        int sum = 0;
        for (int j = 0; j < empCount[i]; j++) sum += salaries[i][j];
        double avg = (double)sum / empCount[i];
        if (avg > maxAvg) {
            maxAvg = avg;
            bestDept = i;
        }
    }

    cout << endl << "Department with maximum average salary: Department " << bestDept + 1 << " (" << maxAvg << ")" << endl;

    for (int i = 0; i < dept; i++) delete[] salaries[i];
    delete[] salaries;
    delete[] empCount;
    return 0;
}
