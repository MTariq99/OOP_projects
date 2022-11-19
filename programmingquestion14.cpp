// QUESTION NUMBER 14 PROGRAMMING EXERCISE CHAPTER 13
#include <iostream>
using namespace std;

class bankAccount
{
    long int accountNumber;
    double balance;

public:
    bankAccount() {}
    bankAccount(long int accNumber, double b) : accountNumber(accNumber), balance(b) {}
    void setData();
    void dispData();
    int getAccNumber();
    double getBalance();
    void depositMoney(int &);
    void withdrawMoney(int &);
};
void bankAccount::setData()
{
    cout << "enter the account number : ";
    cin >> accountNumber;
    cout << "enter account balance : ";
    cin >> balance;
}
double bankAccount::getBalance()
{
    return balance;
}
int bankAccount::getAccNumber()
{
    return accountNumber;
}
void bankAccount::depositMoney(int &money)
{
    balance += money;
}
void bankAccount::withdrawMoney(int &money)
{
    balance -= money;
}
void bankAccount::dispData()
{
    cout << "account number : " << accountNumber << "\n";
    cout << "bank balance : " << balance << "\n";
}

class checkingAccount : public bankAccount
{
    float interest, serviceCharges;
    double minimumBalance;

public:
    checkingAccount() {}
    checkingAccount(float intrst, float sCharges, double mbalance, long int accN, double blnce) : interest(intrst), serviceCharges(sCharges), minimumBalance(mbalance), bankAccount(accN, blnce) {}
    void setInfo();
    void getInterest();
    void getMinimumBalance();
    void getServiceCharges();
    bool isMinimumBalance();
    void withdrawMoney(int &);
    void dispInfo();
};

void checkingAccount::setInfo()
{
    bankAccount::setData();
    cout << "enter the interest rate : ";
    cin >> interest;
    cout << "enter serviceCharges : ";
    cin >> serviceCharges;
    cout << "enter minimum balance : ";
    cin >> minimumBalance;
}
void checkingAccount::getInterest()
{
    cout << "interest rate is : " << interest << "%";
}
void checkingAccount::getMinimumBalance()
{
    cout << "minimum balance is : " << minimumBalance;
}
void checkingAccount::getServiceCharges()
{
    cout << "service charges are : " << serviceCharges;
}
void checkingAccount::withdrawMoney(int &money)
{
    double balance;
    balance = bankAccount::getBalance();
    balance -= money;
}

bool checkingAccount::isMinimumBalance()
{
    bool isMinimum = false;
    double balance;
    balance = bankAccount::getBalance();
    if (balance < minimumBalance)
    {
        isMinimum = true;
    }
    return isMinimum;
}

void checkingAccount::dispInfo()
{
    bankAccount::dispData();
    cout << "interest rate is : " << interest << "%"
         << "\n";
    cout << "service charges are : " << serviceCharges << "\n";
    cout << "minimum balance is : " << minimumBalance << "\n";
}

class savingsAccount : public bankAccount
{
    bankAccount bankAcc;

public:
    void depositMoney();
    void withdrawMoney();
    void dispAccInfo();
};

void savingsAccount::depositMoney()
{
    int money;
    bankAcc.depositMoney(money);
}
void savingsAccount::withdrawMoney()
{
    int money;
    bankAcc.withdrawMoney(money);
}
void savingsAccount::dispAccInfo()
{
    bankAcc.dispData();
}

int main()
{
    int money, option;
    bankAccount bAcc;
    checkingAccount checkAcc;

    do
    {
        cout << "\n\n\n\n1 set Info\n";
        cout << "2 get interest\n";
        cout << "3 get service charges\n";
        cout << "4 get minimum balance\n";
        cout << " 5 is balance minimum than minimumBalance\n";
        cout << "6 withdraw Money\n";
        cout << "7 display data\n";
        cout << "enter an option : ";
        cin >> option;

        switch (option)
        {
        case 1:
            // bAcc.setData();
            checkAcc.setInfo();
            break;
        case 2:
            // cout << "enter money to deposit : ";
            // cin >> money;
            // bAcc.depositMoney(money);
            checkAcc.getInterest();
            break;
        case 3:
            checkAcc.getServiceCharges();
            break;
        case 4:
            checkAcc.getMinimumBalance();
            break;
        case 5:
            double balance;
            balance = checkAcc.isMinimumBalance();
            if (!balance)
            {
                cout << "balance is lessThan the minimum balance\n";
            }
            else
            {
                cout << "not lessThan minimum balance\n";
            }
        case 6:
            cout << "enter the money to withdraw : ";
            cin >> money;
            bAcc.withdrawMoney(money);
            break;
        case 7:
            cout << "\n\n\n";
            checkAcc.dispInfo();
            cout << "\n\n\n";
            break;
        default:
            cout << "invalid\n";
            break;
        }

    } while (option != 8);
}