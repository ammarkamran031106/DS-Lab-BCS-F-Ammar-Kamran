#include<iostream>
#include<string.h>
using namespace std;
class Exam{
	string *name;
	string *Exam_date;
	int *score;
	public:
		Exam(){
			name=new string("");
			Exam_date=new string("");
			score=new int;
		}
		
		
		void set_name(string s){
			*name=s;
		}
		void set_date(string s){
			*Exam_date=s;
		}
		void set_score(int x){
			*score=x;
		}
		string *get_name(){
			return name;
		}
		string *get_date(){
			return Exam_date;
		}
		int *get_score(){
			return score;
		}
		void display_detail(){
			cout<<"Name: "<<*name<< "       "<<" Exam Date: "<<*Exam_date<<"		"<<" Score: "<<*score<<endl;
		}
		~Exam(){
			cout<<"Deleting Exam"<<endl;
			delete name;
			delete Exam_date;
			delete score;
		}
	};
int main(){
	Exam a;
	a.set_name("Maths");
	a.set_date("17/8/25");
	a.set_score(45);
	Exam b;
	b=a;
	b.display_detail();
	b.set_name("Physic");
	b.display_detail();
	a.display_detail();
	a.~Exam();
	b.~Exam();
}
