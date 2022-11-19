// QUESTION NUMBER 6 PROGRAMMING EXERCISE OF CHAPTER 13

#include <iostream>
using namespace std;
#define SIZE 2

class personType
{
    string firstName;
    string lastName;

public:
    personType()
    {

        firstName = "";
        lastName = "";
    };
    void setName();
    void print() const;
    string getFirstName();
    string getLastName();
};
void personType::setName()
{
    cout << "enter first name : ";
    cin >> firstName;
    cout << "enter last name : ";
    cin >> lastName;
}

string personType::getFirstName()
{

    return firstName;
}
string personType::getLastName()
{
    return lastName;
}

void personType::print() const
{
    cout << "first name : " << firstName << "\n";
    cout << "last name : " << lastName << "\n";
}

class extPersonType : public personType
{
    char pt;
    string phoneNumber;

public:
    void setData();
    void dispData();
};

void extPersonType::setData()
{
    personType::setName();
    cout << "f for 'familyMember' F for 'Friend' b for 'bussinessAssociates' : ";
    cin >> pt;
    cout << "enter the phone number : ";
    cin >> phoneNumber;
}
void extPersonType::dispData()
{
    personType::print();
    if (pt == 'f')
    {
        cout << "person type : "
             << "family member \n";
    }
    else if (pt == 'F')
    {
        cout << "person type : "
             << "Friend \n";
    }
    else
    {
        cout << "person type : "
             << "bussiness associate person \n";
    }
    cout << "phone number : " << phoneNumber << "\n";
}

class addressType : public extPersonType
{
    string st_address, city, state;
    unsigned int ZIP_code;

public:
    void setCompleteDetails();
    void dispSetCompleteDetails();
};

void addressType::setCompleteDetails()
{
extPersonType:
    setData();
    cin.ignore(10, '\n');
    cout << "enter the city name : ";
    getline(cin, city);
    cout << "enter street address : ";
    getline(cin, st_address);
    cout << "enter the state name : ";
    getline(cin, state);
}
void addressType::dispSetCompleteDetails()
{
    extPersonType::dispData();
    cout << "street address : " << st_address << "\n";
    cout << "city name : " << city << "\n";
    cout << "state name : " << state << "\n";
}

class dateType
{
    unsigned int dDay, dMonth, dYear;

public:
    dateType() : dDay(0), dMonth(0), dYear(0) {}
    void setDate();
    void setDay();
    void setMonth();
    void setYear();
    int getDay() const;
    int getMonth() const;
    int getyear() const;
    void printDate();
};

void dateType::setDate()
{

    cout << "enter the date : ";
    cin >> dDay;
    if (dDay > 0 && dDay < 31)
    {
        cout << "enter the month : ";
        cin >> dMonth;
        if (dMonth > 0 && dMonth <= 12)
        {
            cout << "enter the year : ";
            cin >> dYear;
        }
        else
        {
            cout << "sorry!\ninvalid Month\n";
        }
    }
    else
    {
        cout << "sorry!\ninvalid date\n";
    }
}

void dateType::setDay()
{
    cout << "enter the date : ";
    cin >> dDay;
}
void dateType::setMonth()
{
    cout << "enter days in  Month : ";
    cin >> dMonth;
}
void dateType::setYear()
{
    cout << "enter the Year : ";
    cin >> dYear;
}
int dateType::getDay() const
{
    return dDay;
}
int dateType::getMonth() const
{
    return dMonth;
}
int dateType::getyear() const
{
    return dYear;
}

void dateType::printDate()
{
    cout << "date of birth : " << dDay << "-" << dMonth << "-" << dYear << "\n";
}

class addressBookType : public addressType, public dateType
{
    addressType addType, addArr[SIZE];
    dateType dType, birthDay[SIZE];

public:
    void setCompleteAddress();
    void dispCompleteAddress();
    bool srchPerson(addressBookType addArr[], string);
    // void sortPerson(addressBookType sortLName[]);
    bool personBirthday(addressBookType birthday[], int);
};

void addressBookType::setCompleteAddress()
{
    setCompleteDetails();
    setDate();
}

void addressBookType::dispCompleteAddress()
{
    dispSetCompleteDetails();
    printDate();
}
bool addressBookType::srchPerson(addressBookType addArr[], string lName)
{
    bool isFound = false;
    for (int i = 0; i < SIZE; i++)
    {
        if (addArr[i].getLastName() == lName)
        {
            addArr[i].dispCompleteAddress();
            isFound = true;
        }
    }
    return isFound;
}

// void addressBookType::sortPerson(addressBookType sortLName[])
// {
//     string temp;
//     for (int i = 0; i < SIZE; i++)
//     {
//         for (int j = i + 1; j < SIZE; j++)
//         {
//             if (addArr[i] < addArr[j])
//             {
//                 temp = addArr[j];
//                 addArr[i] = addArr[j];
//                 addArr[i] = temp;
//             }
//         }
//     }
//     for (int i = 0; i < SIZE; i++)
//     {
//         addArr[i];
//     }
// }

bool addressBookType::personBirthday(addressBookType birthday[], int bMonth)
{
    int i = 0;
    string fName;
    bool isFound = false;

    for (int i = 0; i < SIZE; i++)
    {
        int m = birthday[i].getMonth();
        if (m == bMonth)
        {
            cout << "\n\n";
            fName = birthday[i].getFirstName();
            cout << "people having same birth month : " << fName;
            // return true;
            isFound = true;
        }
    }
    return isFound;
}

void setData(addressBookType address[]);
void displayData(addressBookType address[]);
void searchPerson(addressBookType add[], string);
// void sortLastName(addressBookType sort[]);
void birthdayInMonth(addressBookType birthday[]);

int main()
{
    addressBookType addBookType[2], birthD;
    unsigned int option;
    string lastName;

    do
    {
        cout << "1 setData\n";
        cout << "2 display data\n";
        cout << "3 search a person\n";
        cout << "4 display peoples have same birth month\n";
        cout << "5 exit program\n";
        cout << "enter an option : ";
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "\n\n\n\n";
            setData(addBookType);
            cout << "\n\n\n\n";
            break;
        case 2:
            cout << "\n\n\n\n";
            displayData(addBookType);
            cout << "\n\n\n\n";
            break;
        case 3:
            cout << "\n\n\n\n";
            cout << "enter the last name of the person : ";
            cin >> lastName;
            searchPerson(addBookType, lastName);
            cout << "\n\n\n\n";
            break;
        case 4:
            cout << "displaying people having same birht month\n";
            birthdayInMonth(addBookType);
            cout << "\n\n\n";
            break;
        case 5:
            cout << "program is terminated successfully\n";
            exit(1);
        default:
            cout << "SORRY!\nINVALID INPUT\n";
            break;
        }
    } while (option != 5);
    return 0;
}

void setData(addressBookType add[])
{
    for (int i = 0; i < 2; i++)
    {
        add[i].setCompleteAddress();
    }
}
void displayData(addressBookType add[])
{
    for (int i = 0; i < 2; i++)
    {
        add[i].dispCompleteAddress();
    }
    cout << endl
         << endl
         << endl;
}

void searchPerson(addressBookType address[], string lastname)
{
    addressBookType add;
    if (!add.srchPerson(address, lastname))
    {
        cout << "not found\n";
        cout << "\n\n\n\n";
    };
}
// void sortLastName(addressBookType sort[])
// {

//     addressBookType sortLN;
//     sortLN.sortPerson(sort);
// }
void birthdayInMonth(addressBookType birthday[])
{
    addressBookType birthMonth;
    unsigned int bMonth;
    cout << "enter the month : ";
    cin >> bMonth;
    if (!birthMonth.personBirthday(birthday, bMonth))
    {
        cout << "not found\n";
    }
}