#include<iostream>
using namespace std;
void shellsort(int *arr,int n){
	for(int gap=n/2;gap>0;gap=gap/2){
		for(int i=gap;i<n;i++){
			int key=arr[i];
			int j=i-gap;
			while(j>=0 && arr[j]>key){
				arr[j+gap]=arr[j];
				j=j-gap;}
			
		arr[j+gap]=key;
	}
	}
}
void combsort(int *arr,int n){
	float shrink=1.3;
	int gap=n;
	bool swapped=true;
	while(gap>1 || swapped){
		gap=(int) gap/shrink;
		if(gap<1){
			gap=1;}
		swapped=false;
		for(int i=0;i+gap<n;i++){
			if(arr[i]>arr[i+gap]){
				swap(arr[i],arr[i+gap]);
				swapped=true;}
		}
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
	combsort(arr,n);
	cout<<"The sorted array using comb sort: "<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<"     "; 
	}
}
