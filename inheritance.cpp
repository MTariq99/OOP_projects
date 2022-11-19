#include <iostream>
using namespace std;

class employee
{
    unsigned int empID, empAge;
    float empSalary;
    string empName;
    char empGender;

public:
    employee() : empID(0), empAge(0), empSalary(0.0)
    {
        empName = " ";
        empGender = 'g';
    }
    void sett();
    void get();
};

void employee::sett()
{
    cout << "Enter employee ID : ";
    cin >> empID;
    cout << "Enter employee name : ";
    cin >> empName;
    cout << "enter employee gender  M  for Male and F for Female : ";
    cin >> empGender;
    cout << "enter employee age : ";
    cin >> empAge;
    cout << "enter employee salary : ";
    cin >> empSalary;
}
void employee::get()
{
    cout << "\n\nemployee ID is : " << empID << "\n";
    cout << "employee name is : " << empName << "\n";
    cout << "employee gender is : " << empGender << "\n";
    cout << "enmployee age is : " << empAge << "\n";
    cout << "employee salary is : " << empSalary << "\n";
}

// Inheriting manager class from parent employee class
class manager : public employee
{
    string empDesignation;
    unsigned int empClubDues;

public:
    // manager(unsigned int eID,string eName , char g , unsigned int eAge ,float eSalary,string empDesig ,unsigned int eClubDues) :emp(eID,eAge,eSalary,eName,g),empDesignation(empDesig),empClubDues(eClubDues){}
    void mSetter();
    void mGetter();
};
// manager class inherited from parent class employee
void manager::mSetter()
{
    employee::sett();
    cout << "enter the designation of manager : ";
    cin >> empDesignation;
    cout << "enter the manager club dues : ";
    cin >> empClubDues;
}
void manager::mGetter()
{
    employee::get();
    cout << "employee designation is : " << empDesignation << "\n";
    cout << "manager club dues are : " << empClubDues << "\n";
} // end of manager class

class scientist : public employee
{
    string field;
    unsigned int noOfPublications;

public:
    void sSetter();
    void sGetter();
};

void scientist::sSetter()
{
    employee::sett();
    cout << "enter the field of scientist : ";
    cin >> field;
    cout << "enter the number of publications of scientist : ";
    cin >> noOfPublications;
}
void scientist::sGetter()
{
    employee::get();
    cout << " the field of scientist : " << field << "\n";
    cout << " the number of publications of scientist : " << noOfPublications << "\n";
}

class labour : public employee
{
    unsigned int dailyWage;
    string lShift;

public:
    void lSetter();
    void lGetter();
};
void labour::lSetter()
{
    employee::sett();
    cout << "enter the dailyWage of labour : ";
    cin >> dailyWage;
    cout << "enter the shift of labour : ";
    cin >> lShift;
}
void labour::lGetter()
{
    employee::get();
    cout << "dailyWage of labour is : " << dailyWage;
    cout << "duty shift of labour is : " << lShift;
}

int main()
{
    employee emp;
    manager mg;
    scientist ss;
    labour ll;
    // emp.get();
    unsigned int option;

    do
    {

        cout << "1 set manager's data\n";
        cout << "2 display manager's data\n";
        cout << "3 set scientist data\n";
        cout << "4 display scientist data\n";
        cout << "5 set labour data\n";
        cout << "6 display labour data\n";
        cout << "7 exit program\n";
        cout << "enter a number in above options : ";
        cin >> option;

        switch (option)
        {
        case 1:
            mg.mSetter();
            break;
        case 2:
            mg.mGetter();
            break;
        case 3:
            ss.sSetter();
            break;
        case 4:
            ss.sGetter();
            break;
        case 5:
            cout << "set labour Data : \n\n";
            ll.lSetter();
            break;
        case 6:
            cout << "displaying labour data : \n\n";
            ll.lGetter();
            break;
        case 7:
            cout << "program terminated successfully\n";
            exit(1);
            break;
        default:
            cout << "invalid input\n";
            break;
        }
    } while (option != 7);

    // manager mg;
    // mg.mSetter();
    // mg.mGetter();

    // scientist ss;
    // ss.sSetter();
    // ss.sGetter();

    return 0;
}