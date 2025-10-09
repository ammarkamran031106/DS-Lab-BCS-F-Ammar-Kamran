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
class LL{
	Node *head;
	public:
		LL(){
			head=NULL;
		}
		void addathead(int val){
			Node *newnode=new Node(val);
			if(head==NULL){
				head=newnode;
			}
			else{
				newnode->next=head;
				head=newnode;
			}
		}
		void insertattail(int val){
			Node *newnode=new Node(val);
			if(head==NULL){
				head=newnode;
			}
			else{
				Node *temp=head;
				while(temp->next != NULL){
					temp=temp->next;
				}
				temp->next=newnode;
				newnode->next=NULL;
			}
		}
		void insertatmid(int val,int x){
			Node *newnode=new Node(val);
			if(head==NULL){
				head=newnode;
			}
			else{
				Node *temp=head;
				while(temp->next !=NULL && temp->next->data != x ){
					temp=temp->next;
				}
				if(temp->next->data==x){
					Node *n=temp->next;
					temp->next=newnode;
					newnode->next=n;
				}
				else{
					cout<<"The target where u want to inseted not found in linked list"<<endl;
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
				while(temp->next !=NULL && temp->next->data !=x){
					temp=temp->next;
				}
				if(temp->next !=NULL && temp->next->data == x){
					Node *del=temp->next;
					temp->next=temp->next->next;
					delete del;
				}
			}
		}
		void printLL(){
			Node *temp=head;
			while(temp!=NULL){
				cout<<temp->data<<"     ";
				temp=temp->next;
			}
			cout<<endl;
		}
};
int main(){
	LL l1;
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
