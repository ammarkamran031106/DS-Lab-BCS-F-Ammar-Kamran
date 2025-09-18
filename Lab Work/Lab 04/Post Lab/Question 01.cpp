#include<iostream>
using namespace std;
int Linear_Search(int *arr,int size,int target){
	for(int i=0;i<size;i++){
		if(arr[i]==target){
			return i;
		}
	}
}
int main(){
	int *arr;
	cout<<"Enter the size of array: ";
	int n;
	cin>>n;
	cout<<"Enter the element of the array: ";
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		arr[i]=x;
	}
	int target;
	cout<<"Enter the target value u want: ";
	cin>>target;
	 int z=Linear_Search(arr,n,target);
	if(z<-1){
		cout<<"Element Not Found In Array "<<endl;
	}
	else{
		cout<<"Element "<<target<<" Found At Index "<<z+1;
	}
}
