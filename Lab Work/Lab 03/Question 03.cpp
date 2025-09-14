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
	public:
		Node *head;
		Node *tail;
		LinkedList(){
			head=NULL;
			tail=NULL;
		}
		void InsertNode(int val,Node *n){
			if(head==NULL){
				head=new Node(val,n);
				tail=head;
			}
			else{
				tail->next=new Node(val,n);
				tail=tail->next;
			}
		}
		Node* ReverseNodeGroup(Node *n,int k){
			if(head==NULL){
				return 0;
			}
			else{
    			Node* prev = nullptr;
    			Node* curr = n;
    			Node* next = nullptr;
    			int counter=0;
    				while(curr !=NULL && counter < k){
        					next = curr->next;   // save next
        					curr->next = prev;   // reverse link
        					prev = curr;         // move prev forward
        					curr = next;         // move curr forward
    						counter++;}
    				if(next !=NULL){
    					n->next=ReverseNodeGroup(next,k);
					}
    			return prev;
			}
	}
		
};
int main() {
    LinkedList list;

    // Insert nodes into the list
    list.InsertNode(1, NULL);
    list.InsertNode(2, NULL);
    list.InsertNode(3, NULL);
    list.InsertNode(7, NULL);
    list.InsertNode(6, NULL);
    list.InsertNode(4, NULL);
    list.InsertNode(2,NULL);
    list.InsertNode(1,NULL);
    list.InsertNode(9,NULL);
    list.InsertNode(8,NULL);
    cout<<"The Orignal Linked List"<<endl;
    Node *temp1=list.head;
    while(temp1 != NULL){
    	cout<<temp1->data<<"     ";
    	temp1=temp1->next;
	}
	cout<<endl;
    int k = 4; // group size for reversal

    Node* newHead = list.ReverseNodeGroup(list.head, k);
    cout<<"The Reversed Group Linked List"<<endl;
    Node* temp = newHead;
    while (temp != NULL) {
        cout << temp->data << "     ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
