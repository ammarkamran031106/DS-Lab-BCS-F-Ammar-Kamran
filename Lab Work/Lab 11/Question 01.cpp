#include <iostream>
#include <string>
using namespace std;

class
 Node{
 	public:
		string key;
		string value;
		Node* next;
		Node(string k,string v){
		key=k;
		value=v;
		next=NULL;
		}
};

class HashTable{
	private:
	static const int SIZE=10;
	Node* table[SIZE];
	
	int hashFunction(const string& s){
	int sum=0;
	for(int i=0;i<s.length();i++){
		sum= sum+ (int)s[i];
	}
	return sum%SIZE;
	}

public:
	HashTable(){
	for(int i=0;i<SIZE;i++){
	table[i]=NULL;
	}
}

void insert(const string& key,const string& value){
	int index=hashFunction(key);
	Node* n=new Node(key,value);
	n->next=table[index];
	table[index]=n;
	}
	
	void display(){
	for(int i=0;i<SIZE;i++){
	cout<<"Bucket "<<i<<": ";
	Node* c=table[i];
	if(c==NULL) cout<<"EMPTY";
	while(c!=NULL){
	cout<<"["<<c->key<<", "<<c->value<<"] ,";
	c=c->next;
	}
	cout<<endl;
}
}
};

int main(){
	HashTable h;
	h.insert("A","aaaaa");
	h.insert("B","bbbbb");
	h.insert("C","ccccc");
	h.insert("A","zzzzz");
	h.display();
return 0;
}
