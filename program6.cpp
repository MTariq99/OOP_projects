#include <iostream>
using namespace std;

class personType
{
    char firstName[30];
    char lastName[30];

public:
    personType()
    {
        char firstName = '\0';
        char lastName = '\0';
    }
    void print();
    void setName();
    string getFirstName();
    string getLastName();

    void searhPerson();
};
void personType::setName()
{
    cout << "enter first name : ";
    cin >> firstName;
    cout << "enter the last name : ";
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
void personType::print()
{
    cout << "first name is : " << firstName << "\n";
    cout << "last name is : " << lastName << "\n";
}

class addressType : public personType
{
    string st_address, city, state;
    unsigned int ZIP_code;

public:
    void setAdd();
    void dispAdd();
};
void addressType::setAdd()
{
    personType::setName();
    cout << "enter the street address : ";
    cin >> st_address;
    cout << "enter the city name : ";
    cin >> city;
    cout << "enter the state name : ";
    cin >> state;
    cout << "enter the zip code : ";
    cin >> ZIP_code;
}
void addressType::dispAdd()
{
    personType::print();
    cout << "street address : " << st_address << "\n";
    cout << "city name : " << city << "\n";
    cout << "state name : " << state << "\n";
    cout << "city ZIP code : " << ZIP_code << "\n";
}

class dateType : public personType
{
    unsigned int day, month, year;

public:
    dateType() {}
    void setDate();
    void dispDate();
};
void dateType::setDate()
{
    cout << "enter the day of birth : ";
    cin >> day;
    cout << "enter the month of birth : ";
    cin >> month;
    cout << "enter the year of birth : ";
    cin >> year;
}
void dateType::dispDate()
{
    cout << "date of birth is : " << day << "-" << month << "-" << year;
}

class extPersonType : public personType
{
    char pt;
    string phoneNumber;

public:
    extPersonType() {}
    void setInfo();
    void dispInfo();
};
void extPersonType::setInfo()
{
    personType::setName();
    cout << "please enter 'f' for family 'F' for friend and 'b' for bussiness : ";
    cin >> pt;
    cout << "enter the phone number : ";
    cin >> phoneNumber;
}
void extPersonType::dispInfo()
{
    personType::print();
    cout << "family member type : " << pt << "\n";
    cout << "phone number is : " << phoneNumber << "\n";
}

int main()
{
    // personType pt;
    extPersonType ept;
    ept.setInfo();
    ept.dispInfo();

    string fn, ln;

    return 0;
}
