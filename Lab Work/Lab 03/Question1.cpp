#include<iostream>
using namespace std;
class Node{
	public:
	int data;
	Node *next;
		Node(){
			data=0;
			next=NULL;
		}
		Node(int val,Node *n){
			data=val;
			next=n;
		}
};
class LinkedList{
	Node *head;
	Node *tail;
	public:
		LinkedList(){
			head=NULL;
			tail=NULL;
		}
		void Insert_Node(int val,Node *n){
			if(head==NULL){
				head=new Node(val,n);
				tail=head;
			}
			else {
            tail->next = new Node(val,n);
            tail =tail->next;
        	}
		}
	Node* reverse(Node* n) {
    Node* prev = nullptr;
    Node* curr = n;
    Node* next = nullptr;
    while (curr != nullptr) {
        next = curr->next;   // save next
        curr->next = prev;   // reverse link
        prev = curr;         // move prev forward
        curr = next;         // move curr forward
    }
    return prev;  // new head of reversed list
}

	bool check_palindrome(){
			if(head ==NULL){
				return true;
			}
			Node *slow=head;
			Node *fast=head;
			while(fast->next !=NULL && fast->next->next!=NULL){
			slow=slow->next;
			fast=fast->next->next;
		}
		
		Node *x=reverse(slow->next);
		Node *n1=head;
		Node *n2=x;
		bool check=true;
		while(n2 != NULL){
			if(n1->data!= n2->data){
				check=false;
				break;
			}
			else{
			n1=n1->next;
			n2=n2->next;}
		}
		return check;
	}
};
int main(){
	LinkedList list;
    list.Insert_Node(1,NULL);
    list.Insert_Node(1,NULL);
    list.Insert_Node(3,NULL);
    list.Insert_Node(2,NULL);
    list.Insert_Node(1,NULL);
	bool check=list.check_palindrome();
    if (check==true){
        cout << "List is Palindrome" << endl;}
    else{
        cout << "List is NOT Palindrome" << endl;}

    return 0;
}
