#include<iostream>
using namespace std;
int health=100;
bool issafe(int arr[4][4], int x, int y, int n,int &health){
    if (x >= 0 && y >= 0 && x < n && y < n && arr[x][y] == 1 ||x >= 0 && y >= 0 && x < n && y < n && arr[x][y] == 2){
    	if(arr[x][y]==1){
    		return true;
		}
		else if(arr[x][y]==2){
				health=health-10;
				return true;
		}
	}
	return false;
}

bool ratinmaze(int arr[4][4], int x, int y, int n, int solarr[4][4],int &health){
    cout << "Checking cell (" << x << ", " << y << ")" << endl;

    // Base case: reached destination
    if(x == n-1 && y == n-1){
        solarr[x][y] = 3;
        
        cout << "Reached destination!" << endl;
        return true;
    }

    if(issafe(arr, x, y, n,health)){
        solarr[x][y] = 3;  // mark path

        // Move Right
        if(ratinmaze(arr, x, y+1, n, solarr,health)) return true;
        // Move Down
        if(ratinmaze(arr, x+1, y, n, solarr,health)) return true;
        // Move Left
        if(ratinmaze(arr, x, y-1, n, solarr,health)) return true;
        // Move Up
        if(ratinmaze(arr, x-1, y, n, solarr,health)) return true;

        // Backtracking
        cout << "Backtracking from (" << x << ", " << y << ")" << endl;
        solarr[x][y] = 0;
        health=health;
        return false;
    }

    return false;
}

int main(){
    int arr[4][4] = {
        {1,0,0,0},
        {1,2,0,1},
        {1,1,1,0},
        {1,0,2,1}
    };
	for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        cout<<health<<endl;
    int solarr[4][4] = {0};
    bool x = ratinmaze(arr, 0, 0, 4, solarr,health);
    if(x){
        cout << "\nPath found:" << endl;
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                cout << solarr[i][j] << " ";
            }
            cout << endl;
        }
        cout<<health<<endl;
    }
    else{
        cout << "No path found" << endl;
    }
}
