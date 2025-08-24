#include<iostream>
using namespace std;
class Box{
	int *number;
	public:
		Box(){
			number=new int;
		}
		Box(int x){
			number=new int(x);
		}
		Box(const Box &obj){
			number=new int(*obj.number);
		}
		void set_number(int x){
			*number=x;
		}
		int *get_number(){
			return number;
		}
		Box& operator=(const Box& obj){
			number=new int(*obj.number);
			return *this;
		}
};
int main(){
	Box a(100);
	cout<<"Deep Copy"<<endl;
	Box b(a);
	cout<<"BOX a Value: "<<*(a.get_number())<<endl;
	cout<<"BOX b Value: "<<*(b.get_number())<<endl;
	cout<<"Updating a BOX value"<<endl;
	a.set_number(50);
	cout<<"Updated BOX a: "<<*(a.get_number())<<endl;
	cout<<"BOX b REMAIN SAME: "<<*(b.get_number())<<endl;
	cout<<"Assignment Operator"<<endl;
	Box c(70);
	Box d;
	d=c;		//assignment operator
	cout<<"BOX c Value: "<<*(c.get_number())<<endl;
	cout<<"BOX d Value: "<<*(d.get_number())<<endl;
	c.set_number(20);		//changing box c doesn't change change box d bcz ofassignment operator else it was changed
	cout<<"Updated BOX c: "<<*(c.get_number())<<endl;
	cout<<"BOX d REMAIN SAME: "<<*(d.get_number())<<endl;


	//if there was now assgnment operator and copy constructor then 
	//shallow copy would have happened and on updating BOX a and BOX c 
	//BOX b and BOX d would also have update their value as pointing to 
	//same address
}
