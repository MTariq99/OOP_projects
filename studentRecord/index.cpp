#include <iostream>
using namespace std;
#define SIZE 2

struct student
{
    int studentRegNumber;
    string studentName;
    string studentFatherName;
    float studentCGPA;
};

int createDataBase(student studentInfo[], int);
int appendNewRecord(student tempStudent[], int);
int updateARecord(student updateStudent[]);
int searchAStudent(student searchStudent[]);
void updateStutent(/*data type student, cms*/);
void displayStudent(student studentsList[], int index /*data type student, cms*/);
void showStudents(student studentList[], int size /*data type student*/);
void deleteStudent(student stdInfo[], int);

int main()
{
    int length, deleteRegNo;
    struct student studentInfo[SIZE];
    length = (sizeof(studentInfo) / sizeof(student));

    int option;

    do
    {
        cout << "Length : " << length << endl;
        int studentNumber;
        int y;

        cout << " 1 createDataBase " << endl;
        cout << " 2 Add new Record " << endl;
        cout << " 3 upadata a record" << endl;
        cout << " 4 Delete a Record " << endl;
        cout << " 5 Search a Record " << endl;
        cout << " 6 Show All Students" << endl;
        cout << " 7 Do you want to exit " << endl;
        cout << "Enter a Number accordingly : ";
        cin >> option;

        switch (option)
        {

        case 1:
            cout << "welcome to the database " << endl;
            cout << "how many students do want to register : ";
            cin >> studentNumber;
            length = createDataBase(studentInfo, studentNumber);
            break;
        case 2:
            cout << "want to add new record" << endl;
            length = appendNewRecord(studentInfo, length);
            break;

        case 3:
            cout << "Want to Update a Record " << endl;
            updateARecord(studentInfo);
            break;
        case 4:
            cout << "want to delete a Record" << endl;
            cout << "enter the registration number you want to delete : ";
            cin >> deleteRegNo;
            deleteStudent(studentInfo, deleteRegNo);
            break;
        case 5:
            cout << "welcome toooooooo the search " << endl;
            searchAStudent(studentInfo);
            break;
        case 6:
            cout << "Show All Students" << endl;
            showStudents(studentInfo, length);
            break;
        case 7:
            cout << "program is terminated successfully" << endl;
            exit(1);
            break;
        default:
            cout << "Invailid Input " << endl;
            break;
        }
    } while (true);

    return 0;
}

int createDataBase(student studentInformation[], int studentNumber)
{

    int length = sizeof(studentInformation) / sizeof(studentInformation[0]);

    cout << "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL = " << length;

    // int i;
    // for (i = 0; i < studentNumber; i++)
    // {
    //     cin.ignore();
    //     cout << "Enter the registration number of student " << i + 1 << " : ";
    //     cin >> studentInformation[0].studentRegNumber;
    //     cin.ignore();
    //     cout << "enter the name of student  " << i + 1 << " : ";
    //     cin >> studentInformation[0].studentName;
    //     cin.ignore();
    //     cout << "enter the father  name of student  " << i + 1 << " : ";
    //     cin >> studentInformation[0].studentFatherName;
    //     cin.ignore();
    //     cout << "Enter the CGPA of student " << i + 1 << " : ";
    //     cin >> studentInformation[0].studentCGPA;
    //     cin.ignore();
    // }

    return 1;
}

int appendNewRecord(student stu[], int length)
{
    /*
    add new student to an existing list.
    create new (temp) list (students size + 1)
    append existing list to new list and add new student to new list.
    assign new list to existing list.
    */

    int size = length + 1;
    student temp_array[size];

    for (int i = 0; i < length; i++)
    {
        cout << "I assign = " << i << endl;
        temp_array[i] = stu[i];
        cout << "\nF Name : " << stu[i].studentFatherName;
        cout << "\nName : " << stu[i].studentName;
        cout << "\nGPA : " << stu[i].studentCGPA << endl;
    }

    for (int i = size - 1; i < size; i++)
    {
        cin.ignore();
        cout << "Enter the REG NO of new student " << i << " : ";
        cin >> temp_array[i].studentRegNumber;
        cin.ignore();
        cout << "Enter the name of new student : ";
        cin >> temp_array[i].studentName;
        cin.ignore();
        cout << "enter the father name of new student : ";
        cin >> temp_array[i].studentFatherName;
        cin.ignore();
        cout << "enter the CGPA of new student  : ";
        cin >> temp_array[i].studentCGPA;
        cin.ignore();
    }

    // for (int i = 0; i < size; i++)
    // {
    //     cout << "I = " << i << endl;
    //     stu[i] = temp_array[i];
    //     // stu[i].studentFatherName = temp_array[i].studentFatherName;
    //     // stu[i].studentName = temp_array[i].studentName;
    //     // stu[i].studentRegNumber = temp_array[i].studentRegNumber;
    // }
    return 0;
}

int updateARecord(student updateStudent[])
{
    int update;
    cout << "enter the Registration number of student you want to Update : ";
    cin >> update;
    for (int i = 0; i < SIZE; i++)
    {
        if (updateStudent[i].studentRegNumber == update)
        {
            cin.ignore();
            cout << "new student registration number : ";
            cin >> updateStudent[i].studentRegNumber;
            cin.ignore();
            cout << "student new Name : ";
            cin >> updateStudent[i].studentName;
            cin.ignore();
            cout << "Father new Name : ";
            cin >> updateStudent[i].studentFatherName;
            cin.ignore();
            cout << "student new GPA : ";
            cin >> updateStudent[i].studentCGPA;
            break;
            cout << endl
                 << endl;
        }
    }
    return 0;
}

int searchAStudent(student st[])
{
    int i;
    int searchkey;
    cout << "Enter the Registration number of Student : ";
    cin >> searchkey;

    for (i = 0; i < SIZE; i++)
    {
        if (st[i].studentRegNumber == searchkey)
        {
            cout << " at index " << i + 1 << " " << st[i].studentRegNumber << endl;
            cout << " at index " << i + 1 << " " << st[i].studentName << endl;
            cout << " at index " << i + 1 << " " << st[i].studentFatherName << endl;
            cout << " at index " << i + 1 << " " << st[i].studentCGPA << endl;
            break;
        }
    }
    cout << endl
         << endl;

    return 0;
}
void deleteStudent(student stdInfo[], int deleteRegNo)
{
    /*
    Call findStudentIndex(student, cms)
    create new list (existing list size - 1)
    insert record one by one into new from existing list except deleted record.
    */
    deleteRegNo--;
    for (int i = deleteRegNo; i < SIZE; i++)
    {
        if (stdInfo[i].studentRegNumber == deleteRegNo)
        {
            student temp_array = stdInfo[i];
            stdInfo[i] = stdInfo[i + 1];
            stdInfo[i] = temp_array;
        }
    }

    for (int i = 0; i < SIZE - 1; i++)
    {
        cout << stdInfo[i].studentRegNumber << endl;
        cout << stdInfo[i].studentName << endl;
        cout << stdInfo[i].studentFatherName << endl;
        cout << stdInfo[i].studentCGPA << endl;
    }
}

void showStudents(student studentList[], int size /*data type student*/)
{
    /*
    show all students from the list.
    */
    cout << "SSSSSSSSSSSSSSSSSSSSSSSSSSSSS ==== " << size << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "\n\n------------------------------------------------\n";
        cout << "Reg No : " << studentList[i].studentRegNumber << endl;
        cout << "Name   : " << studentList[i].studentName << endl;
        cout << "F Name : " << studentList[i].studentFatherName << endl;
        cout << "CGPA   : " << studentList[i].studentCGPA << endl;
    }
    cout << "\n------------------------------------------------\n";
}

void displayStudent(student studentList[], int index /*data type student, cms*/)
{
    /*
    Call findStudentIndex(student, cms)
    Display student by index in the list.
    */

    cout << "Reg No. " << studentList[index].studentRegNumber << endl;
}
