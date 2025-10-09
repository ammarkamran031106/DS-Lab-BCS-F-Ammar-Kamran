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
	Node* cloneList(Node* head1) {
        if (head1== NULL) return NULL;
        Node *newHead = new Node(head1->data);
        Node *curr = newHead;
        Node *temp=head1->next;
        while (temp != NULL) {
            curr->next = new Node(temp->data);
            curr=curr->next;
			temp=temp->next;
        }
        return newHead;
    }
		Node *reverse(Node *head){
			Node *prev=NULL;
			Node *curr=head;
			Node *next=NULL;
			while(curr != NULL){
				next=curr->next;
				curr->next=prev;
				prev=curr;
				curr=next;
			}
			return prev;
		}
		bool checkpalindrome(){
			Node *temp1=head;
			Node *temp2= cloneList(head);
			Node *reversed=reverse(temp2);
			if(temp1==NULL || reversed==NULL){
				return false;
			}
			else{
				while(temp1->next != NULL && reversed->next !=NULL){
					if(temp1->data!=reversed->data){
						return false;
						break;
					}
					else{
						temp1=temp1->next;
						reversed=reversed->next;
					}
				}
				return true;
			}
		}
		
};
int main(){
	LL l1;
	l1.addathead(5);
	l1.addathead(4);
	l1.addathead(3);
	l1.addathead(4);
	l1.addathead(5);
	bool check= l1.checkpalindrome();
	if(check==true){
		cout<<"Linked List is Palindrome "<<endl;
	}
	else{
		cout<<"Linked List is not Palindrome "<<endl;
	}
}
