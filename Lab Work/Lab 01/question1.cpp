#include<iostream>
using namespace std;
class BankAccount{
	float balance;
	public:
		
		BankAccount() {
			balance=0.00;
		}
		BankAccount(int x) {
			balance=x;
		}
		BankAccount(BankAccount &account2){
			balance=account2.balance;
		}
		void deduct(float x){
			if(x<=balance){
				balance=balance-x;
			}
			else
			cout<<"low balance"<<endl;
		}
		float get_balance(){
			return balance;
		}
};
int main(){
	BankAccount account1;
	cout<<"Balance of Account 1: " <<account1.get_balance()<<endl;
	BankAccount account2(1000.00);
	cout<<"Balance of Account 2: "<<account2.get_balance()<<endl;
	BankAccount account3(account2);
	cout<<"Balance of Account 3: "<<account3.get_balance()<<endl;
	account3.deduct(200);
	cout<<"Updated Balance of Account 3: "<<account3.get_balance()<<endl;
	cout<<"Balance of Account 2: "<<account2.get_balance()<<endl;
}
