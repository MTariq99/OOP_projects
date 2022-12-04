#include <iostream>
using namespace std;

class person
{
    unsigned int personID, age;
    string name, address;

public:
    virtual void setInfo();
    virtual void displayInfo();
    virtual bool isOutStanding();
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

bool person::isOutStanding()
{
    return (name == "tariq") ? true : false;
}

class student : public person
{
    string degProgram;
    unsigned int samesterID;
    float cgpa;

public:
    void setInfo();
    void displayInfo();
    bool isOutStanding();
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

bool student::isOutStanding()
{
    return (cgpa >= 3.5) ? true : false;
}

class professor : public person
{
    string designation, department;
    float salery;
    unsigned int no_of_publications;

public:
    void setInfo();
    void displayInfo();
    bool isOutStanding();
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

bool professor::isOutStanding()
{
    return (no_of_publications >= 5) ? true : false;
}

int main()
{

    person *prsn = NULL;
    student std;
    professor profssr;
    char ch;
    unsigned int publications;
    float outstanding;

    do
    {
        cout << "\n----------MENU--------------\n";
        cout << " |1.set Student data          |\n";
        cout << " |2.display Student data      |\n";
        cout << " |3.Is Student outstanding|   |\n";
        cout << " |4.set professor data        |\n";
        cout << " |5.display professor data    |\n";
        cout << " |6.Is professor outstanding  |\n";
        cout << " |7.Exit Program              |\n";
        cout << " -----------------------------\n";
        cout << "enter Option : ";
        cin >> ch;
        switch (ch)
        {
        case '1':
            prsn = &std;
            prsn->setInfo();
            cout << "\n\n";
            break;
        case '2':
            prsn = &std;
            prsn->displayInfo();
            cout << "\n\n";
            break;
        case '3':
            prsn = &std;
            outstanding = prsn->isOutStanding();
            if (outstanding)
            {
                cout << "the student is outstanding\n";
            }
            else
            {
                cout << "student is not outStanding\n";
            }
            break;
        case '4':
            prsn = &profssr;
            prsn->setInfo();
            cout << "\n\n";
            break;
        case '5':
            prsn = &profssr;
            prsn->displayInfo();
            cout << "\n\n";
            break;
        case '6':
            prsn = &profssr;
            publications = prsn->isOutStanding();
            if (publications)
            {
                cout << "the professor is outStanding\n";
            }
            else
            {
                cout << "professor is not outstanding\n";
            }
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
