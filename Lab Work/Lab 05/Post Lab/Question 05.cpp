#include<iostream>
using namespace std;
bool issafe(int **board,int row,int col,int dig){
	for(int j=0;j<9;j++){			//horizontal
		if(board[row][j]==dig){
			return false;
		}
	}
	for(int i=0;i<9;i++){		//vertical	
		if(board[i][col]==dig){
			return false;
		}
	}
	int srow=(row/3)*3;
	int scol=(col/3)*3;
	for(int i=srow;i<srow+2;i++){
		for(int j=scol;j<scol+2;j++){
			if(board[i][j]==dig){
				return false;
			}
		}
	}
	return true;
}	
bool Skudo_solver(int **board ,int row,int col){
		if(row==9){
			return true;
		}
		
		int nextrow=row;		int nextcol=col+1;
		if(nextcol==9){
			nextrow=row+1;
			nextcol=0;
			
		}
		
		
		if(board[row][col] != 0){
			return Skudo_solver(board,nextrow,nextcol);
		}
		
		for(int i=0;i<=9;i++){
			if(issafe(board,row,col,i)){
				board[row][col]=i;
				if(Skudo_solver(board,nextrow,nextcol)){
					return true;
				}
				board[row][col]=0;
			}
			
		}
	return false;
}
int main(){
	int **board=new int*[9];
	for(int i=0;i<9;i++){
		board[i]=new int[9];
		for(int j=0;j<9;j++){
			board[i][j]=0;
		}
	}
	if(Skudo_solver(board,0,0)){
		cout<<"Solved Skudo: "<<endl;
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				cout<<board[i][j]<<"   ";
			}
		cout<<endl;
		}
	}
	else{
		cout<<"No solution exists "<<endl;
	}
}
