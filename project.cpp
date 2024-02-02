#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

string name;
int age;
int accNumber;
string account_existance;
string status = "y";


//-----------------------------------------------------------------------------------------------//
struct Account
{
    int accountNumber;
    string accountHolder;
    double balance;
};
vector<Account> accounts ;
int linearSearch( int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i;  
        }
    }
    return -1;  
}
int menu()
{
    int Choice;
    cout<<"\n----Menu----\n";
    cout<<"1.Make deposit\n"
        <<"2.Make Withdrawl\n"
        <<"3.Check Balance\n"
        <<"4.Check Detail\n"
        <<"5.Exit\n";
    cin>>Choice;
    
    if (Choice == 1)
        return 1;
    else if (Choice == 2)
        return 2;
    else if (Choice == 3)
        return 3;
    else if(Choice == 4)
        return 4;
    else if(Choice == 5)
        return 5;
}
int AccNoGenerator()
{
    srand(time(0));
    return(rand());
}
bool eligibility_check()
{
    cout<<"Enter your AGE: ";
    cin>>age;
    if (age >=18){
        return true;
    }
    else{
        cout << "Sorry, you are not eligible for this service at the moment.\n";
        return false;
    }
}
void Deposit(auto accnum)
{
    for(auto &account : accounts)
    {
        if(account.accountNumber == accnum )
        {   
            double depositAmt;
            cout<<"Enter the amount to deposit: ";
            cin>>depositAmt;
            account.balance = account.balance + depositAmt;
            cout<<"Deposit Successful. "<<"\nNew balance: "<<account.balance;


        }
    }
}
void Withdrawl(auto accnum)
{
    for(auto &account : accounts)
    {
        if(account.accountNumber == accnum)
        {
            double withdrawl_amount;
            cout<<"Enter the amount to withdraw: ";
            cin>>withdrawl_amount;
            if (withdrawl_amount > account.balance)
                cout<<"Withdrawl not Possible\nEntered Amount is Greater than Current Balance.";
            else
            { 
                account.balance = account.balance - withdrawl_amount;
                cout<<"Withdrawl Successful. "<<"\nNew balance: "<<account.balance;
            }
        }
    }
}
void check_balance(auto accnum)
{
    for(auto &account : accounts)
    {
        if(account.accountNumber == accnum)
        {
            cout<<"Your current balance: "<<account.balance;
        }
    }
}
void Detail(auto accnum)
{
    for(auto &account : accounts)
    {
        if(account.accountNumber == accnum)
        {
            cout<<"Account Holder Name: "<<account.accountHolder<<endl;
            cout<<"Account Number: "<<account.accountNumber<<endl;
            cout<<"Current Balance: "<<account.balance<<endl;
        }
    }
}
void make_account()
{   Account newAccount;
    cout<<"Enter account holder name: ";
    cin>>newAccount.accountHolder;
    cout<<"Your account number generated is: "<<AccNoGenerator();
    cout<<"\nPlease enter the Account No. generated: ";
    cin>>newAccount.accountNumber;
    cout<<"Account created successfully!";
    newAccount.balance = 0.0;
    accounts.push_back(newAccount);
}    

void Proceding(string name,string status)
{
    cout<<"Does your account already exist[y/n]\n";
    cin>>account_existance;
    if (account_existance=="y")
    {
        int accnum;
        // Ask for Account number and Make Deposits/Withdrawl's
        cout<<"Enter you account number: ";
        cin>>accnum;
        
        int User_choice = menu();
        if(User_choice == 1)
            Deposit(accnum);
        else if(User_choice == 2)
            Withdrawl(accnum); 
        else if(User_choice == 3)
            check_balance(accnum);
        else if(User_choice == 4)
            Detail(accnum);
        else if(User_choice == 5)
            status = "n";
        
        
        
    }
    else if (account_existance=="n")
    {
        // Check eligibility
        // if return fasle print "END"
        if (eligibility_check() == true)
        {
            make_account();
        }
        
    }
}
void thank_you(string name)
{
    cout<<"Thank You, "<<name<<endl;
    cout<<"Visit Again!!"<<endl;

}

// void checkBalance()
// {
    
// }
//-----------------------------------------------------------------------------------------------//


int main()
{ 
    cout<<"Enter your name: ";
    getline(cin, name);
    cout<<"\n"<<"WELCOME "<<name<<"\n";
    cout<<"\n----------------------"<<endl;

    while(status=="y")
    {
        Proceding(name,status);

        cout<<"\nDo you want to continue futher[y/n]: "<<endl;
        cin>>status;
        if (status != "y")
    {
        break; // exit the loop if status is not 'y'
    }
    }
    thank_you(name);
    
}
