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
class CircularLL{
	public:
		Node *head;
		Node *tail;
		CircularLL(){
			head=NULL;
			tail=NULL;
		}
		static int x;
		void InsertNode(int val,Node *n){
			if(head==NULL){
				head=new Node(val,n);
				tail=head;
				tail->next=head;
				x++;
			}
			else{
				Node *temp=tail;
				temp->next=new Node(val,n);
				tail=temp->next;
				tail->next=head;
				x++;
			}
		}
		void survivalperson(int k){
			if(head==NULL) return;

			Node *temp = tail;       
			while(x > 1){
				for(int count = 1; count < k; ++count){
					temp = temp->next;
				}

				Node *del = temp->next;       
				temp->next = del->next;          
				if(del == head) head = del->next; 
				if(del == tail) tail = temp;      
				delete del;
				x--;
			}
			head = temp->next;
			tail = temp;
			tail->next = head;
		}	
};
int CircularLL:: x=0;
int main() {
    CircularLL l1;

    int N = 7;
    int k = 3;

    for (int i = 1; i <= N; i++) {
        l1.InsertNode(i, NULL);
    }

    l1.survivalperson(k);

    cout << "The survivor person is: " << l1.head->data << endl;

    return 0;
}
