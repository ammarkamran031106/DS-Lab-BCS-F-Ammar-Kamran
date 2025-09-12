#include<iostream>
using namespace std;

int main(){
	int arr[10]={5,1,3,6,2,9,7,4,8,10};
	bool swap=false;
	int boundary=10-1;
	int temp;
	while(swap==false){
		swap=true;
		for (int j=0;j<boundary;j++){
			if(arr[j]<arr[j+1]){
				temp=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=temp;
				swap=false;
			}
		}
		boundary--;
	}
	cout<<"Printing Array:"<<endl;
	for(int i=0; i<10;i++){
		cout<<arr[i]<< "    ";
	}	
	}
