#include <iostream>
using namespace std; 

int main(){
	int benchCount;        
	int **benchSeats;      
	int *seatCounts;       
	int totalSeatsNeeded;  
	int benchNumber;       
	int seatNumber;        
	
	cout << "Enter the number of benches available: ";
	cin >> benchCount;
	
	benchSeats = new int*[benchCount];
	seatCounts = new int[benchCount];
	
	cout << "Enter the number of seats on each bench:" << endl; 
	for(int i = 0; i < benchCount; i++){
		cout << "Seats in bench number " << i+1 << ": ";
		cin >> seatCounts[i];
		benchSeats[i] = new int[seatCounts[i]];
	}
	
	for(int i = 0; i < benchCount; i++){
		for(int j = 0; j < seatCounts[i]; j++){
			benchSeats[i][j] = 0;
		}
	}
	
	cout << "How many seats do you want to book? "; 
	cin >> totalSeatsNeeded;
	
	for(int i = 0; i < totalSeatsNeeded; i++){
		cout << "Enter the bench number and seat number you want: ";
		cin  >> benchNumber;
		cin >> seatNumber;
		
		if(benchNumber > benchCount || seatNumber > seatCounts[benchNumber - 1]){
			cout << "Out Of Bound" << endl;
		}
		else {
			benchSeats[benchNumber - 1][seatNumber - 1] = 1;
		}
	}
	
	for(int i = 0; i < benchCount; i++){
		for(int j = 0; j < seatCounts[i]; j++){
			cout << benchSeats[i][j] << " ";
		}
		cout << endl;
	}
	
	for(int i = 0; i < benchCount; i++){
		delete[] benchSeats[i];
	}
	delete[] benchSeats;
	delete[] seatCounts;
	
	return 0;
}
