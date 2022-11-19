#include <iostream>
#include <iomanip>
using namespace std;

class student
{
    unsigned int regNumber;
    string studentName;
    string studentFatherName;
    float GPA;

public:
    student()
    {
        this->studentName = ' ';
        this->regNumber = 0;
        this->studentFatherName = ' ';
        this->GPA = 0.0;
    };
    void readData();
    void display();
    bool search(int);
};

student *createDb(student stu[], int, int);
int displayStudentsRecord(student stud[], int);
int updateAStudent();
int searchAStudent(student s[], int);
int appendNewRecord();
int deleteAStudent(student st[], int, int);

int main()
{
    int option, numberOfStudent;
    student students[1];

    do
    {
        cout << "Welcome to the main Manu \n\n\n";
        cout << "1 Create DataBase \n";
        cout << "2 Add new Record  \n";
        cout << "3 search A student \n";
        cout << "4 Update A student \n";
        cout << "5 Delete A student \n";
        cout << "6 display students Record \n";
        cout << "7 Exit the program \n";
        cout << "Enter A number in above Options : ";
        cin >> option;
        int length = sizeof(students) / sizeof(students[0]);
        student *arr;
        switch (option)
        {
        case 1:
            cout << "Welcome to the DataBase \n";
            cout << "Enter the number of students you want to Add : ";
            cin >> numberOfStudent;
            student *arr = createDb(students, numberOfStudent, length); // s->123, s->release get 321
            cout << "Arr = " << arr;
            cout << "Students = " << students;
            // get new array
            // point studets array to new arr.
            break;
            // case 2:
            //     appendNewRecord();
            //     break;
            // case 3:
            //     cout << "Welcome to the Search\n";
            //     searchAStudent(students, numberOfStudent);
            //     break;
            // case 4:
            //     updateAStudent();
            //     break;
            // case 5:
            //     cout << "Welcome to the Delete page \n";
            //     cout << "Enter the registration number you want to delete : ";
            //     cin >> delRegNo;
            //     deleteAStudent(students, delRegNo, numberOfStudent);
            //     break;
            // case 6:
            //     cout << "Welcome to the Display Screen \n\n";
            //     displayStudentsRecord(students, numberOfStudent);
            //     break;
            // case 7:
            //     cout << "\n Program is terminated successfully \n\n";
            //     exit(1);
            //     break;

        default:
            break;
        }

    } while (option != 7);

    return 0;
}

void student::readData()
{

    cout << "Enter the Registration Number of the Student : ";
    cin >> regNumber;
    cout << "Enter the Name of the Student : ";
    cin >> studentName;
    cout << "Enter the Father Name of the Student : ";
    cin >> studentFatherName;
    cout << "Enter the GPA of student : ";
    cin >> GPA;
    // cout << "Enter the date of birth of student : ";
    // cin >> DOB.day;
    // cout << "Enter the month of birth of Student : ";
    // cin >> DOB.month;
    // cout << "Enter the year of birth of Student : ";
    // cin >> DOB.year;
    // cout << "Enter the date of Admission of student : ";
    // cin >> DOB.day;
    // cout << "Enter the month of Admission of Student : ";
    // cin >> DOB.month;
    // cout << "Enter the year of Admission of Student : ";
    // cin >> DOB.year;
}

void student::display()
{
    cout << setw(10) << regNumber << setw(25) << studentName << setw(22) << studentFatherName << setw(21) << GPA << endl
         << endl;
}

bool student::search(int RegistrationNumber)
{
    if (regNumber == RegistrationNumber)
    {
        return true;
    }
    else
    {
        return false;
    }
}

student *createDb(student st[], int numberOfStudents, int length)
{

    student newArr[length + 1];

    // add data.
    // create new array with length + 1
    // old array shitf to new array.
    // return new array.
    int len = sizeof(newArr) / sizeof(newArr[0]);

    if (length == 1)
    {
        cout << "Old one \n";
        newArr[0].readData();
    }
    else
    {
        // loop old data -> new
        for (int i = 0; i < length; i++)
        {
            newArr[i] = st[i];
            newArr[i].display();
        }
        for (int i = len - 1; i < len; i++)
        {
            newArr[i].readData();
        }
    }
    cout << "st = " << st << endl;
    cout << "New = " << newArr;

    return newArr;
}