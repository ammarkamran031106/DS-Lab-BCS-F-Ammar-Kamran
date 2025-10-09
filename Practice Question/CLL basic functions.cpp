#include<iostream>
using namespace std;
class Node{
	public:
		Node *next;
		int data;
		Node(){
			next=NULL;
			data=0;
		}
		Node(int val){
			next=NULL;
			data=val;
		}
};
class CL{
	Node *head;
	Node *tail;
	public:
		CL(){
			head=NULL;
			tail=NULL;
		}
		void addathead(int val){
			Node *newnode=new Node(val);
			if(head==NULL){
				head=tail=newnode;
				tail->next=head;
			}
			else{
				newnode->next=head;
				head=newnode;
				tail->next=head;
			}
		}
		void insertattail(int val){
			Node *newnode=new Node(val);
			if(head== NULL){
				head=tail=newnode;
				tail->next=head;
			}
			else{
				tail->next=newnode;
				tail=newnode;
				tail->next=head;
			}
		}
		void insertatmid(int val,int x){
			Node *newnode=new Node(val);
			if(head==NULL){
				tail=head=newnode;
				tail->next=head;
			}
			else{
				Node *temp=head;
			while(temp->next != head && temp->next->data!=x){
					temp=temp->next;
					}
				if(temp->next != head && temp->next->data==x ){
						Node *n=temp->next->next;
						temp->next=newnode;
						newnode->next=n;
					}
			}
		}
		void deletenode(int x){
			//if want to delete at head 
			if(head==NULL){
				return;
			}
			else if(head->data==x){
			Node *temp=head;
			head=temp->next;
			delete temp;}
			else{
				Node *temp=head;
				while(temp->next !=head && temp->next->data !=x){
					temp=temp->next;
				}
				if(temp->next !=head && temp->next->data == x){
					Node *del=temp->next;
					temp->next=temp->next->next;
					delete del;
				}
			}
		}
		void printLL(){
			Node *temp=head;
			while(temp->next !=head ){
				cout<<temp->data<<"    ";
				temp=temp->next;
				}
			cout<<temp->next->data;
			cout<<endl;
		
		}
};
int main(){
	CL l1;
	l1.addathead(5);
	l1.addathead(4);
	l1.addathead(3);
	l1.addathead(2);
	l1.addathead(1);
	l1.printLL();
	l1.insertattail(6);
	l1.printLL();
	l1.insertatmid(7,5);
	l1.printLL();
	cout<<"Deleting node "<<endl;
	l1.deletenode(4);
	l1.printLL();
}
