#include <iostream>
using namespace std;

class bankAccount
{
    long int accountNumber;
    unsigned int balance;

public:
    bankAccount() {}
    bankAccount(long int accNumber, unsigned int b) : accountNumber(accNumber), balance(b) {}
    void setData();
    void dispData();
};
void bankAccount::setData()
{
    cout << "enter the account number : ";
    cin >> accountNumber;
    cout << "enter account balance : ";
    cin >> balance;
}