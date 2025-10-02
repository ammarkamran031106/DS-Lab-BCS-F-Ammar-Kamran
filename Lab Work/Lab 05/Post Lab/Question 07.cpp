#include<iostream>
using namespace std;
bool isSafe(char** board,int row,int col,int n){
	for(int j=0;j<n;j++){				//horizontal
		if(board[row][j]=='Q'){
			return false;
		}
	}
	for(int i=0;i<n;i++){				//verticall
		if(board[i][col]=='Q'){
			return false;
		}
	}
	for(int i=row, j=col; i>=0 && j>=0; i--, j--){	//check left diagnol(upper left)		
        if(board[i][j]=='Q') return false;
    }
    for(int i=row, j=col; i>=0 && j<n; i--, j++){	// check right diagonal (upper-right)
        if(board[i][j]=='Q') return false;
    }

    return true;
}
void nQueen(char **board,int row,int n){
	if(row==n){
	 cout<<"solution found: "<<endl;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cout<<board[i][j]<<"       ";
		}
	cout<<endl;
	}
	cout<<"--------------------------"<<endl;
	return;
	}
	for(int j=0;j<n;j++){
		if(isSafe(board,row,j,n)){
			board[row][j]='Q';
			nQueen(board,row+1,n);
			board[row][j]='.'; 				//?
		}
	}

}
int main(){
	char **board=new char*[4];
	for(int i=0;i<4;i++){
		board[i]=new char[4];
		for(int j=0;j<4;j++){
			board[i][j]='.';
		}
	}
	cout<<"Printing N Queens Solution: "<<endl;
	nQueen(board,0,4);
	
}
