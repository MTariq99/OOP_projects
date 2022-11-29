// QUESTION NUMBER 10 PROGRAMMING EXERCISE OF CHAPTER 13

#include <iostream>
using namespace std;

class dateType
{
    int dDay, dMonth, dYear;

public:
    dateType() {}
    dateType(unsigned int d, unsigned int m, unsigned int y) : dDay(d), dMonth(m), dYear(y) {}
    void setDate();
    void setDay();
    void setMonth();
    void setYear();
    int getDay() const;
    int getMonth() const;
    int getyear() const;
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
// int dateType::number_of_day()
// {
//     switch (number)
//     {
//     case 1:
//         cout << "number of day in month is 31\n";
//         break;
//     case 2:
//         if (dYear % 4 == 0)
//         {
//             cout << "the number of days is 29 \n";
//         }
//         else
//         {
//             cout << "the number of days is 28 \n";
//         }
//         break;
//     case 3:
//         cout << "the number of days is 31 \n";
//         break;
//     case 4:
//         cout << "the number of days is 30 \n";
//         break;
//     case 5:
//         cout << "the number of days is 31 \n";
//         break;
//     case 6:
//         cout << "the number of days is 30 \n";
//         break;
//     case 7:
//         cout << "the number of days is 31 \n";
//         break;
//     case 8:
//         cout << "the number of days is 31 \n";
//         break;
//     case 9:
//         cout << "the number of days is 30 \n";
//         break;
//     case 10:
//         cout << "the number of days is 31 \n";
//         break;
//     case 11:
//         cout << "the number of days is 30 \n";
//         break;
//     case 12:
//         cout << "the number of days is 31 \n";
//         break;
//     default:
//         cout << "the number of days is 30 \n";
//     }
//     return 0;
// }

class extDateType : public dateType
{
    string month;
    unsigned int numberOfDays, choice;

public:
    extDateType() : month("") {}
    extDateType(unsigned int d, unsigned int m, unsigned int y, string mm, unsigned int year) : month(mm), dateType(d, m, y)
    {
        d = 1;
    }
    void setDate();
    void dispM();
};
void extDateType::setDate()
{
    cout << "In which format do you want to print Date 'March 24, 2013' OR '3-34-2013' \n";
    cout << "1 for 'March 24, 2013'\n2 for '3-34-2013' : ";
    cin >> choice;
    if (choice == 1)
    {
        cin.ignore(10, '\n');
        cout << "enter the name of month : ";
        cin >> month;
    }
    else if (choice == 2)
    {
        dateType::setDate();
    }
}
void extDateType::dispM()
{
    unsigned int year;
    year = dateType::getyear();
    cout << month << " " << year;
}

class dayType
{
    string dayName;

public:
    void firstDayOfMonth();
    string dispFirstDayOfMonth();
};

void dayType::firstDayOfMonth()
{
    cout << "enter the name of day : ";
    cin >> dayName;
}
string dayType::dispFirstDayOfMonth()
{
    return dayName;
}

class calenderType : public extDateType, public dayType
{
    extDateType extDType;
    dayType dType;

public:
    string first_Day_Of_Month();
    void disp_frist_day_of_month();
    void setMonth();
    void setYear();
    string getMonth();
    int getYear();
    int dayNumber();
    void printCalender();
};

string calenderType::first_Day_Of_Month()
{
    dType.firstDayOfMonth();
    return "";
}
void calenderType::disp_frist_day_of_month()
{
    dType.dispFirstDayOfMonth();
}
void calenderType::setYear()
{
    extDType.setYear();
}
void calenderType::setMonth()
{
    extDType.setDate();
}

string calenderType::getMonth()
{
    extDType.dispM();
    return "";
}
int calenderType::getYear()
{
    int year;
    year = extDType.getyear();
    return 0;
}
void calenderType::printCalender()
{
    unsigned int daysInMonth, i, j, k = 1;
    cout << "\n\nenter a number of days in month : ";
    cin >> daysInMonth;
    string day = dType.dispFirstDayOfMonth();
    cout << "  SUN  MON  TUE  WED  THU  FRI  SAT\n";
    for (i = 0; i < 6; i++)
    {
        if (day == "monday")
        {
            k = 2;
            if (i < 2)
            {
                cout << "     ";
            }
        }
        else if (day == "tuesday")
        {
            k = 3;
            if (i < 2)
            {
                cout << "     ";
            }
        }
        else if (day == "wednesday")
        {
            k = 4;
            if (i < 3)
            {
                cout << "     ";
            }
        }
        else if (day == "thursday")
        {
            k = 5;
            if (i < 4)
            {
                cout << "     ";
            }
        }
        else if (day == "friday")
        {
            k = 6;
            if (i < 5)
            {
                cout << "     ";
            }
        }
        else if (day == "saturday")
        {
            k = 7;
            if (i < 6)
            {
                cout << "     ";
            }
        }
        else
        {
            cout << "";
        }
    }

    for (int j = 1; j <= daysInMonth; j++)
    {
        cout << j;
        if (j < 9)
        {
            cout << "     ";
        }
        else
        {
            cout << "     ";
        }
        if (k == 7)
        {

            cout << "\n";
            k = 0;
        }
        k++;
    }
}

// void calenderType::printCalender()
// {
//     unsigned int numberOfDaysInMonth, no, i, j, k = 1;
//     cout << "\n\nenter a number of days in month : ";
//     cin >> no;
//     string day = dType.dispFirstDayOfMonth();
//     cout << "SUN  MON  TUE  WED  THU  FRI  SAT\n";
//     for (i = 1; i <= no; i++)
//     {
//         if (day == "monday")
//         {
//             k = 2;
//             if (i < 2)
//             {
//                 cout << "   ";
//             }
//             else
//             {
//                 cout << i << "    ";
//                 if (k == 7)
//                 {

//                     cout << "\n";
//                     k = 0;
//                 }
//             }
//         }
//         else if (day == "tuesday")
//         {
//             k = 3;
//             if (i < 3)
//             {
//                 cout << "     ";
//             }
//             else
//             {
//                 cout << i << "    ";
//                 if (k == 7)
//                 {

//                     cout << "\n";
//                     k = 0;
//                 }
//             }
//         }
//         else if (day == "wednesday")
//         {
//             k = 4;
//             if (k < 4)
//             {
//                 cout << "     ";
//             }
//             else
//             {
//                 cout << i << "    ";
//                 if (k == 7)
//                 {

//                     cout << "\n";
//                     k = 0;
//                 }
//             }
//         }
//         else if (day == "thursday")
//         {
//             k = 5;
//             if (k < 5)
//             {
//                 cout << "     ";
//             }
//             else
//             {
//                 cout << i << "    ";
//                 if (k == 7)
//                 {

//                     cout << "\n";
//                     k = 0;
//                 }
//             }
//         }
//         else if (day == "friday")
//         {
//             k = 6;
//             if (k < 6)
//             {
//                 cout << "     ";
//             }
//             else
//             {
//                 cout << i << "    ";
//                 if (k == 7)
//                 {

//                     cout << "\n";
//                     k = 0;
//                 }
//             }
//         }
//         else if (day == "saturday")
//         {
//             k = 7;
//             if (k < 7)
//             {
//                 cout << "     ";
//             }
//             else
//             {
//                 cout << i << "    ";
//                 if (k == 7)
//                 {

//                     cout << "\n";
//                     k = 0;
//                 }
//             }
//         }
//         else
//         {
//             cout << "";
//         }
//         k++;
//     }
// }

int main()
{
    calenderType ct;
    ct.first_Day_Of_Month();
    ct.setMonth();
    ct.disp_frist_day_of_month();
    ct.getMonth();
    ct.getYear();
    ct.printCalender();
    return 0;
}