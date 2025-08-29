#include<iostream>
using namespace std;
int main(){
    int *arr;
    int size;
    cout<<"ENTER SIZE OR ARRAY: "<<endl;
    cin>>size;
    arr=new int[size];
    cout<<"INTIALIZING IT BY ZERO "<<endl;
    for(int i=0;i<size;i++){
        arr[i]=0;
    }
    int ele;
    cout<<"Enter the no of element u want to edit "<<endl;
    cin>>ele;
    if(ele>size){
        cout<<"no possible" <<endl;
    }
    else{
    for(int i=0;i<ele;i++){
    int pos;    
    int val;
    cout<<"Enter postion and val "<<endl;
    cin>>pos>>val;
    if(pos<0 || pos>=size){
        cout<<"out of bound "<<endl;
    }
    else{
    arr[pos]=val;
    }
    }
    }
    cout<<"PRINTING the array "<<endl;
    for(int i=0; i<size;i++){
        cout<<arr[i]<<"         ";
    }
    
}
