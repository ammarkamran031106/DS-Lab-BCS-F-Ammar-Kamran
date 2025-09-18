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
int Binary_Search(int *a,int size,int target){
	int left=0;
	int right=size-1;
	while(left<=right){
		int mid=left+(right-left)/2;
		if(a[mid]==target){
			return mid;
		}
		else if(a[mid]<target){
			left=mid+1;
		}
		else{
			right=mid-1;
		}
	}
	return -1;
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
	int target;
	cout<<endl;
	cout<<"Enter the target u want to find in this sorted array :";
	cin>>target;
	int x=Binary_Search(a,size,target);
	if(x >-1){
		cout<<"Element Found at index "<<x+1<<" having value "<<a[x]<<endl;
	}
	else{
		cout<<"Element Not Found In Array "<<endl;
	}
}
