Its say to recursively solve an array by each elemt of aray to be replaced by the count of element greater than that number present.
for example in array index 0 4 is there and so u have to see how many number are there in array fgreater than 4 and repalce 4 with that count.
but not u cant use any extra memory.
#include<iostream>
using namespace std;
int isduplicate(int i,int arr[],int n){
	if(i==n){
		return 0;
	}
	int x=0;
	for(int j=0;j<n;j++){
		if(j!= i){
		if(arr[i]==arr[j]){
			arr[j]=-1;
			x++;	
		}
		}
	}
	for(int j=0;j<n;j++){
		if(arr[j]==-1){
			arr[j]=arr[i];
		}
	}
	isduplicate(i+1,arr,n);
	return x;
}
void recursionarray(int i,int arr[],int n){
	int counter=0;
	if(i==n){
		return;
	}
	int x=isduplicate(i,arr,n);
	for(int j=0;j<n;j++){
		if(arr[j]>arr[i]){
			counter++;
		}
	}
	recursionarray(i+1,arr,n);
	arr[i]=counter+x;
}
int main(){
	int n;
	cout<<"Enter size of array: ";
	cin>>n;
	int arr[n];
	cout<<"Enter elemnt of array: ";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	recursionarray(0,arr,n);
	cout<<"The count of changed"<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<"     ";
	}
}
