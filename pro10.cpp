#include <iostream>
using namespace std;

class dateType
{
    int dDay, dMonth, dYear;

public:
    dateType() : dDay(0), dMonth(0), dYear(0) {}
    void setDate();
    void setDay();
    void setMonth();
    void setYear();
    int getDay() const;
    int getMonth() const;
    int getyear() const;
    bool isLeapYear();
    int daysInMonth();
    int numberOfDaysPassed();
    int numberOfDaysRemaining();
    void printDate() const;
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

bool dateType::isLeapYear()
{
    unsigned int year;
    cout << "enter a year to  check :  ";
    cin >> year;
    if (year % 4 == 0)
    {
        cout << "year is Leap\n";
    }
    else
    {
        cout << "not leap year\n";
    }
    return 0;
}

int dateType::daysInMonth()
{

    if (dMonth == 1 || dMonth == 3 || dMonth == 5 || dMonth == 7 || dMonth == 8 || dMonth == 10 || dMonth == 12)
    {
        cout << "31\n";
    }
    else if (dMonth == 4 || dMonth == 6 || dMonth == 9 || dMonth == 11)
    {
        cout << "30\n";
    }
    else if (dYear % 4 == 0 || dMonth == 2)
    {
        cout << "29\n";
    }
    else
    {
        cout << "28\n";
    }
    return 0;
}

int dateType::numberOfDaysPassed()
{
    switch (dMonth)
    {
    case 1:
        cout << "number of days passed " << 31 + dDay;
        break;
    case 2:
        if (dYear % 4 == 0)
        {
            cout << "the number of days passed " << 60 + dDay;
        }
        else
        {
            cout << "the number of days passed " << 59 + dDay;
        }
        break;
    case 3:
        cout << "the number of days passed " << 90 + dDay;
        break;
    case 4:
        cout << "the number of days passed " << 120 + dDay;
        break;
    case 5:
        cout << "the number of days passed " << 151 + dDay;
        break;
    case 6:
        cout << "the number of days passed " << 181 + dDay;
        break;
    case 7:
        cout << "the number of days passed " << 212 + dDay;
        break;
    case 8:
        cout << "the number of days passed " << 243 + dDay;
        break;
    case 9:
        cout << "the number of days passed " << 273 + dDay;
        break;
    case 10:
        cout << "the number of days passed " << 304 + dDay;
        break;
    case 11:
        cout << "the number of days passed " << 334 + dDay;
        break;
    case 12:
        cout << "the number of days passed " << 365;
        break;
    default:
        cout << "sorry!\ninvalid\n";
    }
    return 0;
}
int dateType::numberOfDaysRemaining()
{
    unsigned int year = 365, remaining;
    switch (dMonth)
    {
    case 1:
        cout << "number of days Remaining " << 31 + dDay;
        break;
    case 2:
        if (dYear % 4 == 0)
        {
            remaining = year - (60 + dDay);
            cout << "the number of days Remaining " << year;
        }
        else
        {
            remaining = year - (59 + dDay);
            cout << "the number of days Remaining " << remaining;
        }
        break;
    case 3:
        remaining = year - (90 + dDay);
        cout << "the number of days Remaining " << remaining;
        break;
    case 4:
        remaining = year - (120 + dDay);
        cout << "the number of days Remaining " << remaining;
        break;
    case 5:
        remaining = year - (151 + dDay);
        cout << "the number of days Remaining " << remaining;
        break;
    case 6:
        remaining = year - (181 + dDay);
        cout << "the number of days Remaining " << remaining;
        break;
    case 7:
        remaining = year - (212 + dDay);
        cout << "the number of days Remaining " << remaining;
        break;
    case 8:
        remaining = year - (243 + dDay);
        cout << "the number of days Remaining " << remaining;
        break;
    case 9:
        remaining = year - (273 + dDay);
        cout << "the number of days Remaining " << remaining;
        break;
    case 10:
        remaining = year - (304 + dDay);
        cout << "the number of days Remaining " << remaining;
        break;
    case 11:
        remaining = year - (334 + dDay);
        cout << "the number of days Remaining " << remaining;
        break;
    case 12:

        cout << "the number of days Remaining " << 0;
        break;
    default:
        cout << "sorry!\ninvalid\n";
    }
    return 0;
}

void dateType::printDate() const
{
    cout << "date is : " << dDay << "-" << dMonth << "-" << dYear << "\n";
}
class extDateType : public dateType
{
    string month, year;

public:
    void setD();
    void dispD();
};

void extDateType::setD()
{
    cout << "enter the name of month : ";
    cin >> month;
    cout << "enter the year : ";
    cin >> year;
    cout << "enter the name of day : ";
}
void extDateType::dispD()
{
    cout << month << " " << year;
}
class dayType
{
    string day;

public:
    void setDay();
    void getday();
    string firstdayOfMonth();
    void returnNextDay();
    void returnPrevDay();
    int number_of_day();
};

void dayType::setDay()
{
    cout << "enter the name of day : ";
    cin >> day;
}
void dayType::getday()
{
    cout << day << "\n";
}
string dayType::firstdayOfMonth()
{
    return day;
}
void dayType::returnNextDay()
{
    if (day == "monday")
    {
        cout << "tuesday\n";
    }
    else if (day == "tuesday")
    {
        cout << "wednesday\n";
    }
    else if (day == "wednesday")
    {
        cout << "Thursday\n";
    }
    else if (day == "Thursday")
    {
        cout << "friday\n";
    }
    else if (day == "friday")
    {
        cout << "saturday\n";
    }
    else if (day == "saturday")
    {
        cout << "sunday\n";
    }
    else
    {
        cout << "moday\n";
    }
}
void dayType::returnPrevDay()
{
    unsigned int year;
    if (day == "monday")
    {
        cout << "sunday \n";
    }
    else if (day == "sunday")
    {
        cout << "saturday\n";
    }
    else if (day == "sunday")
    {
        cout << "saturday\n";
    }
    else if (day == "saturday")
    {
        cout << "friday\n";
    }
    else if (day == "friday")
    {
        cout << "thursday\n";
    }
    else if (day == "thursday")
    {
        cout << "wednesday\n";
    }
    else if (day == "wednesday")
    {
        cout << "tuesday\n";
    }
    else
    {
        cout << "Monday\n";
    }
}

class calenderType : public dayType
{
    // unsigned int days_in_month;
    dayType dyType;
    extDateType extDT;

public:
    void setCalander();
    void dispCalender();
};
void calenderType::setCalander()
{
    dyType.setDay();
    extDT.setD();
    extDT.setMonth();
}
void calenderType::dispCalender()
{
    dyType.number_of_day();
    int numbers;
    // cout << "numbers are : " << numbers << "\n";
    int days;
    days = extDT.getMonth();
    string day = dyType.firstdayOfMonth();
    cout << "SUN  MON  TUE  WED  THU  FRI  SAT\n";
    for (int k = 0; k < numbers; k++)
    {
        cout << "  ";
        for (int i = 1; i <= days; i++)
        {
            cout << i << "   ";
            if (i == 7 || i == 14 || i == 21 || i == 28)
            {
                cout << "\n";
            }
        }
    }

    // if (day == "sunday")
    // {
    //     for (int i = 0; i < 6; i++)
    //     {
    //         cout << " ";
    //     }
    // }
    // else if (day == "monday")
    // {
    //     cout << " ";
    // }
    // else if (day == "tuesday")
    // {
    //     for (int i = 0; i < 8; i++)
    //     {
    //         cout << " ";
    //     }
    // }
    // else if (day == "wednesday")
    // {
    //     for (int i = 0; i < 11; i++)
    //     {
    //         cout << " ";
    //     }
    // }
    // else if (day == "thursday")
    // {
    //     for (int i = 0; i < 14; i++)
    //     {
    //         cout << " ";
    //     }
    // }
    // else if (day == "friday")
    // {
    //     for (int i = 0; i < 26; i++)
    //     {
    //         cout << " ";
    //     }
    // }
    // else if (day == "saturday")
    // {
    //     for (int i = 0; i < 20; i++)
    //     {
    //         cout << " ";
    //     }
    // }
}

int main()
{
    calenderType ct;
    ct.setCalander();
    ct.dispCalender();

    return 0;
}