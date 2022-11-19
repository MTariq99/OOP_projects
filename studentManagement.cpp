#include <iostream>
#include <iomanip>
using namespace std;
#define SIZE 70
// date struct
struct myDate
{
    unsigned int day;
    unsigned int month;
    unsigned int year;
}; // end of struct

// student class
class student
{
    unsigned int regNumber;
    string studentName;
    string studentFatherName;
    myDate DOB;
    myDate DOA;
    float GPA;

public:
    student() {}
    student(unsigned int regNo, string stuName, string stuFName, float G) : regNumber(regNo), GPA(G)
    {
        studentName = stuName;
        studentFatherName = stuFName;
    }
    void readData();
    void display();
    bool search(int);
}; // end of student class
// class member function for Reading data from user
void student::readData()
{
    cin.ignore();
    cout << "Enter the Registration Number of the Student : ";
    cin >> regNumber;
    cin.ignore();
    cout << "Enter the Name of the Student : ";
    cin >> studentName;
    cin.ignore();
    cout << "Enter the Father Name of the Student : ";
    cin >> studentFatherName;
    cin.ignore();
    cout << "Enter the date of birth of student : ";
    cin >> DOB.day;
    cout << "Enter the month of birth of Student : ";
    cin >> DOB.month;
    cout << "Enter the year of birth of Student : ";
    cin >> DOB.year;
    cout << "Enter the date of Admission of student : ";
    cin >> DOA.day;
    cout << "Enter the month of Admission of Student : ";
    cin >> DOA.month;
    cout << "Enter the year of Admission of Student : ";
    cin >> DOA.year;
    cout << "Enter the GPA of student : ";
    cin >> GPA;
} // end of readData function

// member function of studentClass for displaying Data
void student::display()
{
    cout << setw(10) << regNumber << setw(21) << studentName << setw(23) << studentFatherName << setw(17) << DOB.day << "-" << DOB.month << "-" << DOB.year << setw(15) << DOA.day << "-" << DOA.month << "-" << DOA.year << setw(17) << GPA << endl
         << endl;
} // end of display function

// member function of student class for searching a student
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
} // end of search function

// userDefined functions
int createDataBase(student students[], int, int &);
int appendNewRecord(student students[], int &);
void displayStudentsRecord(student stu[], int &);
int searchAStudent(student stu[], int, int &);
int updateStudentRecord(student stu[], int, int &);
int deleteAStudent(student stu[], int, int &);

// main function
int main()
{
    student students[SIZE];
    int totalRegisteredStudents = 0;
    int option;
    int numberOfStudents;
    int numberOfNewStudents;
    int RegNumOfStudent;
    int regNumberOfStudentToBeUpdated;
    int delRegNumber;
    do
    {
        cout << "\n--------------------------------------------\n";
        cout << "|        Welcome to the main Manu          |\n";
        cout << "|        1 Create DataBase                 |\n";
        cout << "|        2 Add New Record                  |\n";
        cout << "|        3 Search A student                |\n";
        cout << "|        4 Display Student Record          |\n";
        cout << "|        5 Update Student Record           |\n";
        cout << "|        6 Delete Student Record           |\n";
        cout << "|        7 Terminate the program           |\n";
        cout << "|                                          |";
        cout << "\n--------------------------------------------\n";
        cout << "Enter A Number in the Above Options : ";
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Welcome To The Main Manu\n\n";
            cout << "How Many Students Do You Want To Register : ";
            cin >> numberOfStudents;
            createDataBase(students, numberOfStudents, totalRegisteredStudents);
            break;
        case 2:
            cout << "Welcome to the Registration";
            appendNewRecord(students, totalRegisteredStudents);
            break;
        case 3:
            cout << "Welcome to the Search\n";
            cout << "Enter the Registration Number Of the student you want to search : ";
            cin >> RegNumOfStudent;
            searchAStudent(students, RegNumOfStudent, totalRegisteredStudents);
            break;
        case 4:
            cout << "Welcome To The Display\n\n";
            displayStudentsRecord(students, totalRegisteredStudents);
            break;
        case 5:
            cout << "welcome to the Updating Student Record\n";
            cout << "Enter the Registration Number of the Student You want to update : ";
            cin >> regNumberOfStudentToBeUpdated;
            updateStudentRecord(students, regNumberOfStudentToBeUpdated, totalRegisteredStudents);
            break;
        case 6:
            cout << "Welcome To the Deleting Record UI\n";
            cout << "Enter the Registration Number of the student you want to Delete : ";
            cin >> delRegNumber;
            deleteAStudent(students, delRegNumber, totalRegisteredStudents);
            break;
        case 7:
            cout << "Program is terminated successfully\n";
            exit(1);
            break;

        default:
            break;
        }

    } while (option != 7);

    return 0;
} // end of main function

// userDefined function for creating database for student registration
int createDataBase(student stu[], int NumberOfStudent, int &totalRegisteredStudents)
{

    int i;
    if (totalRegisteredStudents > 70)
    {

        cout << "SORRY!\n Registration has been completed\n";
    }
    else
    {
        if (totalRegisteredStudents == 0)
        {
            totalRegisteredStudents = totalRegisteredStudents + NumberOfStudent;

            for (i = 0; i < NumberOfStudent; i++)
            {
                stu[i].readData();
            }
        }
        else
        {
            for (i = totalRegisteredStudents; i < (totalRegisteredStudents + NumberOfStudent); i++)
            {
                cout << "At Index : " << i << endl;
                stu[i].readData();
            }
            totalRegisteredStudents = totalRegisteredStudents + NumberOfStudent;
        }
    }
    return totalRegisteredStudents;
} // end of createDataBase

// userDefined function for appending 1 student at Time
int appendNewRecord(student stu[], int &totalRegisteredStud)
{

    int i;

    if (totalRegisteredStud > 70)
    {
        totalRegisteredStud = totalRegisteredStud + 1;
        cout << "SORRY!\n Registration has been completed\n";
    }
    else
    {
        for (i = totalRegisteredStud; i < (totalRegisteredStud + 1); i++)
        {
            stu[i].readData();
        }
        totalRegisteredStud = totalRegisteredStud + 1;
    }
    return 0;
} // End of appendNewRecord function

// userDefined function for searching student
int searchAStudent(student studentsInfo[], int RegNumberOfStudent, int &totalRegisteredStudents)
{
    unsigned int found = 0, i = 0;
    cout << endl;
    for (i = 0; i < totalRegisteredStudents; i++)
    {
        // found = studentsInfo[i].search(RegNumberOfStudent);
        if (studentsInfo[i].search(RegNumberOfStudent))
        {
            found++;
            studentsInfo[i].display();
            break;
        }
    }
    if (found == 0)
    {
        cout << "\nSORRY!\n the registration number does not exist\n";
    }
    return 0;
} // end of searchAStudent function

// userDefined function for updating student Record
int updateStudentRecord(student stu[], int regNumberOfStudentToBeUpdated, int &totalRegisteredStudents)
{
    unsigned int found = 0, i;
    cout << endl;

    for (i = 0; i < totalRegisteredStudents; i++)
    {
        if (stu[i].search(regNumberOfStudentToBeUpdated))
        {
            found++;
            stu[i].readData();
            break;
        }
    }
    if (found == 0)
    {
        cout << "SORRY!\nThe Entered Registration Number does not exist\n";
    }
    return 0;
} // end of updateAStudent function

// userDefined function for deleting a
int deleteAStudent(student delstudents[], int delRegNo, int &totalRegisteredStudents)
{

    int i, j, found = 0;
    for (i = 0; i < totalRegisteredStudents; i++)
    {
        if (delstudents[i].search(delRegNo))
        {
            for (j = i; j < (totalRegisteredStudents - 1); j++)
                delstudents[j] = delstudents[j + 1];
            found++;
            i--;
            totalRegisteredStudents--;
        }
    }
    if (found == 0)
        cout << "\nElement doesn't found in the Array!";
    else
        cout << "\nElement Deleted Successfully!";
    cout << endl;
    return 0;
} // end of deleteAStudent function

// userDefined function for displaying Student Record
void displayStudentsRecord(student stu[], int &totalRegisteredStudents)
{
    cout << "-----------------------------------------------------------------------------------\n";
    cout << "\n|registrationNumber|"
         << "|    studentName     |"
         << "| studentFatherName  |"
         << "|  DATE OF BIRTH     |"
         << "|  ADMISSION DATE    |"
         << "|    GPA      |\n";
    for (int i = 0; i < totalRegisteredStudents; i++)
    {
        stu[i].display();
    }
    cout << "-----------------------------------------------------------------------------------\n\n\n";
} // end of displayStudentRecord function