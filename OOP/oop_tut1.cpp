#include <iostream>
#include <string>
using namespace std;

class Bank{
    public:
        string acc_type, name;
        long int balance, acc_no;
       
        Bank(string type, string name, long int balance, long int no){
            acc_type = type;
            this->name = name;
            this->balance = balance;
            acc_no = no;
        }
       
        void deposit(long int credit);
      
        void withdraw(long int debit);
       
        void display();
};

void Bank::display(){
    cout<<"Name: "<<name<<endl;
    cout<<"Account number: "<<acc_no<<endl;
    cout<<"Account Type: "<<acc_type<<endl;
    cout<<"Account Balance: "<<balance<<endl;
}

void Bank::deposit(long int deposit){
    balance = balance + deposit;
    cout<<"Amount debited! New balance is: "<<balance<<endl;
}

void Bank::withdraw(long int debit){
    balance = balance - debit;
    cout<<"Amount debited! New balance is: "<<balance<<endl;
}

int main() {
    long int deposit, withdraw;
    int acc_choice;
   
    Bank account_holder[3] = {
        Bank("Savings", "Neel Kadam", 56000, 7709222770),
        Bank("Current", "Rahul Mehta", 100000, 7709222771),
        Bank("Savings", "Ramesh Patil", 75000, 7709222772)
    };
    int n;
   
    cout<<"Welcome to Bank Portal!\n\n----\n";
   
    do{
        cout<<"\n1 - Information | 2 - Deposit\n3 - Withdraw | 4 - Exit\n\nChoice --> ";
        cin>>n;
        switch(n){
            case 1:
                cout<<"\n1 - Neel Kadam\n2 - Rahul Mehta\n3 - Ramesh\nChoice --> ";
                cin>>acc_choice;
                if(acc_choice < 4){
                    account_holder[acc_choice - 1].display();
                }
                else{
                    cout<<"Invaild Input!"<<endl;
                }
                break;
            case 2:
                cout<<"1 - Neel Kadam\n2 - Rahul Mehta\n3 - Ramesh\nChoice --> ";
                cin>>acc_choice;
                cout<<"Enter the amount to be deposited: ";
                cin>>deposit;
                if(acc_choice < 4){
                    account_holder[acc_choice - 1].deposit(deposit);
                }
                else{
                    cout<<"Invaild Input!"<<endl;
                }
                break;
            case 3:
                cout<<"1 - Neel Kadam\n2 - Rahul Mehta\n3 - Ramesh\nChoice --> ";
                cin>>acc_choice;
                cout<<"Enter the amount to be withdrawn: ";
                cin>>withdraw;
                if(acc_choice < 4){
                    account_holder[acc_choice - 1].withdraw(withdraw);
                }
                else{
                    cout<<"Invaild Input!"<<endl;
                }
               
                break;
        }
    } while(n != 4);
   
    cout<<"Exiting Portal..."<<endl;
    return 0;
}
