
// 3.12 (Account Class) Create an Account class that a bank might use to represent customers’ bank
// accounts. Include a data member of type int to represent the account balance. [Note: In subsequent
// chapters, we’ll use numbers that contain decimal points (e.g., 2.75)—called floating-point values—
// to represent dollar amounts.] Provide a constructor that receives an initial balance and uses it to ini-
// tialize the data member. The constructor should validate the initial balance to ensure that it’s greater
// than or equal to 0. If not, set the balance to 0 and display an error message indicating that the initial
// balance was invalid. Provide three member functions. Member function credit should add an
// amount to the current balance. Member function debit should withdraw money from the Account
// and ensure that the debit amount does not exceed the Account’s balance. If it does, the balance
// should be left unchanged and the function should print a message indicating "Debit amount exceed-
// ed account balance." Member function getBalance should return the current balance. Create a
// program that creates two Account objects and tests the member functions of class Account.

#include<iostream>
#include<string>

using namespace std;

class Account{
int accountBalance;
int credit;
int debit;
public:
Account(){}
Account(int ab,int c, int d):accountBalance(ab),credit(c),debit(d){
if(ab>=0){
    accountBalance=ab;
}else if(ab==0){
    accountBalance=0;
    cout<<"error, your account balance is zero"<<endl;
}else{
    cout<<"please enter the correct credentials."<<endl;
}
}


void calculateCredit(){
accountBalance=accountBalance+credit;
cout<<"your balance after acquiring credit is: "<<accountBalance<<endl;
}

void calculateDebit(){
    if(debit<accountBalance){
    accountBalance=accountBalance-debit;
    cout<<"your account balance after withdrawal of money is: "<<accountBalance;
    }else if(debit>accountBalance){
        cout<<"your debit exceeds account balance"<<endl;
    }
}
int getBalance(){
    return accountBalance;
}
};

int main(){
Account a1(50000,3000,2000);
a1.calculateCredit();
a1.calculateDebit();
    return 0;
}