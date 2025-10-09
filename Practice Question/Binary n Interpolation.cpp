#include<iostream>
using namespace std;
int binarysearch(int *arr,int n,int x){
	int left=0;
	int right=n-1;
	while (left<=right){
	int mid=left+(right-left)/2;
	if(arr[mid]==x){
		return mid;
	}
	if(arr[mid]<x){
		left=mid+1;
	}
	else{
		right=mid-1;
	}
	}
	return -1;
}
int interpolationsearch(int* arr,int n,int x){
	int lo=0;
	int high=n-1;
	while(lo<=high && x>=arr[lo] && x<=arr[high]){
		if(lo==high){
			if(arr[lo]==x){
				return lo;
			}
		return -1;
		}
	int pos=lo+((x-arr[lo])*(high-lo))/(arr[high]-arr[lo]);
	if(x==arr[pos]){
		return pos;
	}
	if(x<arr[pos]){
		high=pos-1;
	}
	else{
		lo=pos+1;
	}
	}
	return -1;
}
int main(){
	int n;
	cout<<"Enter size of array: ";
	cin>>n;
	int *arr=new int[n];
	cout<<"Enter the element of array in sorted order: ";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int target;
	cout<<"Enter target u want to enter: ";
	cin>>target;
	int x=interpolationsearch(arr,n,target);
	if(x==-1){
		cout<<"Target not found"<<endl;
	}
	else{
		cout<<"Target Found At Index: "<<x+1;
	}
}

