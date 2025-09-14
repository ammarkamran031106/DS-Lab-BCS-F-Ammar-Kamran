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
		void Insert_Node(int  val,Node *n){
			if(head==NULL){
				head=new Node(val,n);
				tail=head;
			}
			else{
				tail->next=new Node(val,NULL);
				tail=tail->next;
			}
		}
		void printLL(Node *head){
			if(head==NULL){
				return;
			}
			else{
				Node *temp=head;
				while(temp != NULL){
					cout<<temp->data<<"     ";
					temp=temp->next;
				}
			}
		}	
};
void MergeLL(LinkedList *l1,LinkedList *l2){
	if(l1==NULL || l2==NULL){
		return;
	}
	else{
		l1->tail->next=l2->head;
		delete l2;
		cout<<"Succesfully Mergered"<<endl;
		
	}	
}
int main(){
    LinkedList *l1 = new LinkedList();
    LinkedList *l2 = new LinkedList();

    l1->Insert_Node(1, NULL);
    l1->Insert_Node(2, NULL);
    l1->Insert_Node(3, NULL);

    l2->Insert_Node(4, NULL);
    l2->Insert_Node(5, NULL);
    l2->Insert_Node(6, NULL);

    cout << "List 1 before merge: ";
    l1->printLL(l1->head);
    cout << endl;

    cout << "List 2 before merge: ";
    l2->printLL(l2->head);
    cout << endl;

    MergeLL(l1, l2);

    cout << "After merge: ";
    l1->printLL(l1->head);
    cout << endl;

    return 0;
}
