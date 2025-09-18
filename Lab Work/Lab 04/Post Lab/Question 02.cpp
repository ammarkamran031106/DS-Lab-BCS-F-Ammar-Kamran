#include<iostream>
using namespace std;
int*Bubble_Sort(int *arr,int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	return arr;
}
int main(){
	int *arr;
	cout<<"Enter size of array: ";
	int size;
	cin>>size;
	arr=new int[size];
	cout<<"Enter elements of an Array: ";
	for(int i=0;i<size;i++){
		int x;
		cin>>x;
		arr[i]=x;
		}
	int *a=Bubble_Sort(arr,size);
	cout<<"Sorted Array"<<endl;
	for(int i=0;i<size;i++){
		cout<<arr[i]<<"    " ;
	}
}
