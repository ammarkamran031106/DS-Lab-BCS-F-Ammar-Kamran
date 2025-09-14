#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node* next;
		Node *prev;
		Node(){
			data=0;
			next=NULL;
			prev=NULL;
		}
		Node(int val,Node *n,Node *p){
			data=val;
			next=n;
			prev=p;
		}
};
class LL{			//Singly To Circular
	public:
	Node *head;
	Node *tail;
		LL(){
			head=NULL;
			tail=NULL;
		}
		void Insert_Node(int val,Node *n,Node *p){
			
			if(head==NULL){
				head=new Node(val,n,p);
				tail=head;
			}
			else {
            tail->next = new Node(val,n,p);
            tail =tail->next;
        	}
    	}
    	void LL_TO_CL(Node *head,Node *tail){
    		tail->next=head;
    		cout<<"Singly Linked List CONVERTED To Circular Linked List"<<endl;
    		Node* temp=head;
    		if(head==NULL){
    			return;
			}
    		do{
    			cout<<temp->data<<"      ";
    			temp=temp->next;
			}while(temp !=head);
			cout<<endl;
		}
		void LL_TO_DL(Node *head,Node *tail){
			if(head==NULL){
				return;
			}
			Node *curr=head;
			Node *prev=NULL;
			while(curr != NULL){
			curr->prev=prev;
			prev=curr;
			curr=curr->next;
			}
		cout<<"Singly Linked List CONVERTED To Doubly Linked List"<<endl;
		Node* temp=tail;
		while(temp!=NULL){
			cout<<temp->data<<"      ";
			temp=temp->prev;
		}	
		}
};
int main() {
    LL list1;
    list1.Insert_Node(1, NULL,NULL);
    list1.Insert_Node(2, NULL,NULL);
    list1.Insert_Node(3, NULL,NULL);
    list1.LL_TO_CL(list1.head,list1.tail);
    LL list2;
    list2.Insert_Node(1,NULL,NULL);
    list2.Insert_Node(2,NULL,NULL);
    list2.Insert_Node(3,NULL,NULL);
    list2.LL_TO_DL(list2.head, list2.tail);
}

