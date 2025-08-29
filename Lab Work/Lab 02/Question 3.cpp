#include <iostream>
using namespace std;

int main(){
	int studentCount, courseCount, markInput, i, j;
	float average, sum = 0.0;
	int **scores;
	
	cout << "Enter total number of students: ";
	cin >> studentCount;
	scores = new int*[studentCount];
	int courseSizes[studentCount];
	
	for (i = 0; i < studentCount; i++){
		cout << "Enter number of courses for student " << i + 1 << ": ";
		cin >> courseSizes[i];
		scores[i] = new int[courseSizes[i]];
	}
	
	for(i = 0; i < studentCount; i++){
		for (j = 0; j < courseSizes[i]; j++){
			cout << "Enter marks for student " << i + 1 << ", course " << j + 1 << ": ";
			cin >> markInput;
			scores[i][j] = markInput;
		}
	}
	
	for(i = 0; i < studentCount; i++){
		for(j = 0; j < courseSizes[i]; j++){
			sum += scores[i][j];
		}
		cout << "Total marks for student " << i + 1 << ": " << sum << endl;
		average = sum / courseSizes[i];
		cout << "Average marks for student " << i + 1 << ": " << average << endl;
		sum = 0;
	}
	
	for(i = 0; i < studentCount; i++){
		delete[] scores[i];
	}
	delete[] scores;
}
