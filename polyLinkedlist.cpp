#include <iostream>
using namespace std;

class person
{
public:
    unsigned int personID, age;
    string name, address;
    person *next;
    virtual void setInfo();
    virtual void displayInfo();
    virtual void isOutStanding() = 0;
};

void person::setInfo()
{
    cout << "enter the ID : ";
    cin >> personID;
    cin.ignore(30, '\n');
    cout << "enter the Name : ";
    getline(cin, name);
    cout << "enter the Age ";
    cin >> age;
    cin.ignore(30, '\n');
    cout << "enter the address ";
    getline(cin, address);
}
void person::displayInfo()
{
    cout << "ID : " << personID << "\n";
    cout << "Name : " << name << "\n";
    cout << "Age : " << age << "\n";
    cout << "Address : " << address << "\n";
}

void person::isOutStanding() {}

class student : public person
{
    string degProgram;
    unsigned int samesterID;
    float cgpa;

public:
    void setInfo();
    void displayInfo();
    void isOutStanding();
};
void student::setInfo()
{
    person::setInfo();
    cout << "enter the degree program : ";
    getline(cin, degProgram);
    cout << "your Samester : ";
    cin >> samesterID;
    cout << "enter the cgpa : ";
    cin >> cgpa;
}
void student::displayInfo()
{
    person::displayInfo();
    cout << "degree program : " << degProgram << "\n";
    cout << "samester : 0" << samesterID << "\n";
    cout << "cpga : " << cgpa << "\n";
}

void student::isOutStanding()
{
    if (cgpa >= 3.5)
    {
        cout << "student is outStanding\n";
    }
}

class professor : public person
{
    string designation, department;
    float salery;
    unsigned int no_of_publications;

public:
    void setInfo();
    void displayInfo();
    void isOutStanding();
};

void professor::setInfo()
{
    person::setInfo();
    cout << "enter the designation  :";
    getline(cin, designation);
    cout << "enter the department : ";
    getline(cin, department);
    cout << "enter the salery : ";
    cin >> salery;
    cout << "enter the publications : ";
    cin >> no_of_publications;
}

void professor::displayInfo()
{
    person::displayInfo();
    cout << "designation : " << designation << "\n";
    cout << "department : " << department << "\n";
    cout << "salery : " << salery << "\n";
    cout << "number of publications : " << no_of_publications << "\n";
}

void professor::isOutStanding()
{
    if (no_of_publications >= 5)
    {
        cout << "Teacher is outStanding\n";
    }
}

int main()
{

    // student std;
    // professor profssr;
    person *current = NULL, *prev = NULL, *first = NULL;
    int n = 0, s = 0, t = 0;
    char ch;

    do
    {
        cout << "\n----------MENU--------------------\n";
        cout << " |1.set Student data                |\n";
        cout << " |2.set Teacher data                |\n";
        cout << " |3.display all data                |\n";
        cout << " |4.Number of students and Teacher  |\n";
        cout << " |7.Exit Program                    |\n";
        cout << " ------------------------------------\n";
        cout << "enter Option : ";
        cin >> ch;
        switch (ch)
        {
        case '1':

            current->next = NULL;
            if (first == NULL)
            {
                current = prev = first;
            }
            else
            {
                prev->next = current;
                prev = current;
            }
            cout << "\n\n";
            break;
        case '2':
            cout << "\n\n";
            break;
        case '3':
            cout << "\n\n";
            break;
        case '4':
            break;
        case '7':
            cout << "the program is terminated\n";
            exit(0);
            cout << "\n\n";
        default:
            cout << "\nINVALID OPTION\n";
            break;
        }
    } while (ch != '7');

    return 0;
}
