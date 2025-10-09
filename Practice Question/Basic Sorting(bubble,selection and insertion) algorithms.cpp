#include<iostream>
using namespace std;
void bubblesort(int *arr,int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j],arr[j+1]);
			}
		}
	}
}
void insertionsort(int *arr,int n){
	for(int i=1;i<n;i++){
		int key=arr[i];
		int j=i-1;
		while(j>=0 && arr[j]>key){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}
void selectionsort(int *arr,int n){
	for(int i=0;i<n-1;i++){
	int minidx=i;
		for(int j=i+1;j<n;j++){
			if(arr[minidx]>arr[j]){
				minidx=j;}
		}
	swap(arr[i],arr[minidx]);
	}
}
int main(){
	cout<<"Enter size of element: "; 
	int n;
	cin>>n;
	int *arr;
	arr=new int[n];
	for(int i=0;i<n;i++){
		cout<<"Enter Element For Index "<<i<<": ";
		cin>>arr[i];
	}
	//bubblesort(arr,n);
	//cout<<"The sorted array using bubble sort: "<<endl;
	insertionsort(arr,n);
	cout<<"The sorted array using insertion sort: "<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<"     "; 
	}
}
