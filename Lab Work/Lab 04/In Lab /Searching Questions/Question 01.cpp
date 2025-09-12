#include<iostream>
using namespace std;
int main(){
	int n;
	int arr[n];
	cout<<"Enter size of array: ";
	cin>>n;
	cout<<"Enter element in array"<<endl;
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	int target;
	cout<<"Enter target value: ";
	cin>>target;
	cout<<"Searching For Target By Linear Search"<<endl;
	bool flag=false;
	for(int i=0;i<n; i++){
		if(arr[i]==target){
			flag=true;
			cout<<"target "<<arr[i]<< " found at index "<<i+1<<endl;
			break;
		}
		else{
			flag=false;
		}
	}
	if(flag==false){
		cout<<"Target Not Found"<<endl;
	}
	
}
