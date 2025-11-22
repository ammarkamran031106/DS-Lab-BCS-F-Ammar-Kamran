#include<iostream>
using namespace std;
class Product{
	string name;
	string descrip;
	float price;
	bool available;
	public:
		Product(string n,string d,float p,bool avail){
			name=n;
			descrip=d;
			price=p;
			available=avail;
		}
		float get_price(){
			return price;
		}
		string get_name(){
			return name;
		}
};
int partition(Product *arr,int start,int end){
	
	int idx=start-1;
	float j= arr[end].get_price();
	
	for (int i=start;i<end;i++){
		if (arr[i].get_price()<=j){
			idx++;
			swap(arr[i],arr[idx]);
		}
	}
	idx++;
	swap(arr[end],arr[idx]);
	return idx;
}


void quickSort(Product *arr,int start, int end){
	
	if (start <end){
		int pivIdx = partition(arr,start,end);
		quickSort(arr,start,pivIdx-1);
		quickSort(arr,pivIdx+1,end);
	}
	
}
void SortedProc(Product* arr){
	
	for(int i=0;i<3;i++){
		cout<<arr[i].get_name()<<" :  $ "<<arr[i].get_price()<<endl;
	}
}

int main(){ 
	Product obj[3] = {
    Product("Product 1", "This is chocolate", 10.99, true),
    Product("Product 2", "This is soft drinks", 11.23, false),
    Product("Product 3", "This is choco fudge brownie", 6.54, true)
};
quickSort(obj,0,2);
cout<<" /////SORTED PRODUCT LIST\\\\\ "<<endl;
SortedProc(obj);

}
