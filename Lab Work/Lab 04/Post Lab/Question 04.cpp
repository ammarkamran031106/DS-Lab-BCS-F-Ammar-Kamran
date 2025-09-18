#include<iostream>
using namespace std;
int *Insertion_Sort(int *arr,int size){
	for(int i=1;i<size;i++){
		int key=arr[i];
		int j=i-1;
		while(j>= 0 && arr[j]>key){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
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
	int *a=Insertion_Sort(arr,size);
	cout<<"Sorted Array"<<endl;
	for(int i=0;i<size;i++){
		cout<<arr[i]<<"    " ;
	}
}
