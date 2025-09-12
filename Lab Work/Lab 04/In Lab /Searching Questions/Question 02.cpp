#include<iostream>
using namespace std;
int Binary_Search(int *arr,int left,int right,int id);
int main(){
	int arr[10]={20,22,24,26,28,32,36,38,40,42};
	int my_id=27;
	int left=0;
	int right=9;
	int mid= (left+right)/2;
	int temp=Binary_Search(arr,left,right,my_id);
	if(temp != -1){
		cout<<"Value Found At Index "<< temp<<endl;
	}
	else{
		int pos;
		for(int i=0;i<10;i++){
			if(my_id<arr[i]){
				pos=i;
				break;
			}
		}
		for(int i=11;i>pos;i--){
			arr[i]=arr[i-1];
		}
		arr[pos]=my_id;
	}
	for(int i=0;i<10;i++){
		cout<<arr[i]<<"    ";
	}
}
int Binary_Search(int *arr,int left,int right,int id){
	while(left<=right){
	int mid= (right+left)/2;
	if(arr[mid]==id){
		return mid;
	}
	else if (arr[mid]<id){
		left=mid+1;
	}
	else{
		right=mid-1;
	}
	}
	return -1;
}
