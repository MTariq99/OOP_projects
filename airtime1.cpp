/*
Programmer Name : Muhammad Tariq
Registration Number : 4338-FBAS-BSSE-F21-B
*/

#include <iostream>
using namespace std;
// airTime class
class airTime
{
    unsigned int hrs, min, sec;

public:
    airTime() : hrs(0), min(0), sec(0) {}
    airTime(unsigned int h, unsigned int m, unsigned int s) : hrs(h), min(m), sec(s) {}
    airTime setTime();          // readData from user
    void display();             // display data
    airTime operator+(airTime); // + (addition) overloading operator
    airTime operator-(airTime); // - (minus) overloading operator
    airTime operator++();       // prefix increment overloading operator
    airTime operator++(int);    // postfix increment overloading operator
    bool operator>(airTime);    // > or (greaterThan) overloading operator
    bool operator<(airTime);    // < or (lessthan) overloading operator
    bool operator>=(airTime);   //  >= or (greaterThanOrEqualTo) overloading operator
    bool operator<=(airTime);   //  <= or (lessThanOrEqualTo) overloading operator
    void timeFormatter();       // set Time to 24 hours format
};                              // end of class

// void airTime::timeFormatter()
// {
//     if (hrs > 0 && hrs >= 60)
//     {
//         hrs = hrs / 60;
//         min += min % 60;
//     }
// }
// member function used to set time
airTime airTime::setTime()
{

    cout << "Enter the Hours for : ";
    cin >> hrs;
    cout << "Enter min for : ";
    cin >> min;
    cout << "Enter secondes for : ";
    cin >> sec;

    airTime T1(hrs, min, sec);
    return T1;
} // end of function

// + operator for adding two objects
airTime airTime::operator+(airTime T2)
{

    airTime temp;
    temp.hrs = hrs + T2.hrs;
    temp.min = min + T2.min;
    temp.sec = sec + T2.sec;

    return temp;
} // end of function

//- operator for subtracting two objects
airTime airTime::operator-(airTime T2)
{
    airTime minus_temp;
    minus_temp.hrs = hrs - T2.hrs;
    minus_temp.min = min - T2.min;
    minus_temp.sec = sec - T2.sec;
    return minus_temp;
} // end of function

// greaterThan overloading operator
bool airTime::operator>(airTime TimeT5)
{
    if (hrs > TimeT5.hrs)
    {
        if (min > TimeT5.min)
        {
            if (sec > TimeT5.sec)
            {
            }
        }
        return 1;
    }
    else
    {
        return 0;
    }
} // end of function

// LessThan operator
bool airTime::operator<(airTime T)
{
    if (hrs < T.hrs)
    {
        if (min < T.min)
        {
            if (sec < T.sec)
            {
            }
        }
        return 1;
    }
    else
    {
        return 0;
    }
} // end of function

// greaterThan or equal overloading operator
bool airTime::operator>=(airTime T)
{

    if (hrs >= T.hrs)
    {
        if (min >= T.min)
        {
            if (sec >= T.sec)
            {
            }
        }
        return 1;
    }
    else
    {
        return 0;
    }
} // end of function

// lessThan or Equal overloading operator
bool airTime::operator<=(airTime T)
{
    if (hrs <= T.hrs)
    {
        if (min <= T.min)
        {
            if (sec <= T.sec)
            {
            }
        }
        return 1;
    }
    else
    {
        return 0;
    }
} // end of function

// prefixIncrement overloading operator
airTime airTime::operator++()
{
    hrs++;
    min++;
    sec++;
    return *this;
} // end of function

// postfix Increment overloading operator
airTime airTime::operator++(int)
{
    ++hrs;
    ++min;
    ++sec;
    return *this;

} // end of function

// member function used to display time
void airTime::display()
{
    cout << "Time : " << hrs << " : " << min << " : " << sec << endl;
} // end of function

airTime addTime();
airTime minusTime();
int greaterThan();
int lessThan();
airTime preIncrement();
airTime postIncrement();
int GreaterThanOrEqual();
int lessThanOrEqual();
void displayTime();
// void setTime();
// void displayTime();
// int SetDepartureTime();
// int setArrivalTime();

int main()
{
    // airTime T1(5, 6, 7);
    airTime T1, T2, T3, Time3, Time4, incremented, postIncr;
    unsigned int option = 0;
    do
    {
        cout << "Welcome To The AirTime Schedule\n";
        cout << "1 Set Local Time\n";
        cout << "2 Add Time\n";
        cout << "3 Minus Time\n";
        cout << "4 GreaterThan\n";
        cout << "5 LessThan\n";
        cout << "6 Display Local  Time\n";
        cout << "7 Display Added  Time\n";
        cout << "8 Display Minus  Time\n";
        cout << "9 prefixIncrement in time\n";
        cout << "10 display prefixIncremented time\n";
        cout << "11 postIncrement\n";
        cout << "12 display postIncrement\n";
        cout << "13 GreaterThan or Equal\n";
        cout << "14 lessThan or Equal\n";
        cout << "15 Exit Program\n";
        cout << "Enter A number In the Above Options : ";
        cin >> option;

        switch (option)
        {
        case 1:
            cout << endl;
            // setTime();
            cout << endl
                 << endl;
            break;
        case 2:
            T3 = addTime();
            break;
        case 3:
            Time3 = minusTime();
            break;
        case 4:
            greaterThan();
            break;
        case 5:
            cout << "\n\n";
            lessThan();
            cout << "\n\n";
            break;

        case 6:
            cout << endl;
            // displayTime();
            cout << endl
                 << endl;
            break;
        case 7:
            cout << "\nWelcome to the display Of Added time\n";
            T3.display();
            break;
        case 8:
            cout << "\ndisplayed minus time\n";
            Time3.display();
            break;
        case 9:
            cout << "want to preIncrement\n";
            incremented = preIncrement();
            cout << endl;
            break;
        case 10:
            cout << "\n displayed prefixIncremente\n";
            incremented.display();
            cout << endl;
            break;
        case 11:
            cout << "postIncrement\n";
            postIncr = postIncrement();
            cout << endl
                 << endl;
            break;
        case 12:
            cout << "displaying postIncrement\n";
            postIncr.display();
            cout << endl
                 << endl;
            break;
        // case 8:
        //     // Time4.display();
        //     break;
        case 13:
            cout << "\nGreaterThan or Equal to\n";
            GreaterThanOrEqual();
            cout << endl;
            break;
        case 14:
            cout << "LessThan or Equal to \n\n";
            lessThanOrEqual();
            cout << endl;
            break;
        case 15:
            displayTime();
            break;
        case 16:
            cout << "Program is terminated successfully\n";
            exit(1);
            break;
        default:
            break;
        }

    } while (option != 16);

    return 0;
}

airTime addTime()
{
    airTime T1, T2, T3;
    cout << endl;
    cout << "\nTime for T1:\n";
    T1 = T1.setTime();
    cout << "\nTime for T1:\n";
    T2 = T2.setTime();
    T3 = T1 + T2;

    return T3;
}
airTime minusTime()
{
    airTime Time1, Time2, Time3;
    cout << endl;
    cout << "\nFor Time T1 : \n";
    Time1 = Time1.setTime();
    cout << "\nFor Time T2 : \n";
    Time2 = Time2.setTime();
    Time3 = Time1 - Time2;
    return Time3;
};

airTime preIncrement()
{
    airTime preIncre, incremented;
    preIncre.setTime();
    ++preIncre;
    return preIncre;
};
airTime postIncrement()
{
    airTime postInc;
    postInc.setTime();
    postInc++;
    return postInc;
}

int greaterThan()
{
    airTime Time5, Time6, Time7;
    cout << "\nFor Time T5 : \n";
    Time5 = Time5.setTime();
    cout << "\nFor Time T6 : \n";
    Time6 = Time6.setTime();

    if (Time5 > Time6)
    {
        cout << "\n\nTimeT5 is greater than TimeT6\n";
        Time5.display();
    }
    else
    {
        cout << "\n\nTimeT6 is greater than TimeT5\n";
        Time6.display();
    };
    return 0;
}

int lessThan()
{
    airTime lesser, greater;
    cout << "Enter Time for  T1 : \n";
    lesser.setTime();
    cout << "Enter Time for T2 : \n";
    greater.setTime();

    if (lesser < greater)
    {
        cout << "\n\nTime T1 is lessThan Time T2 \n";
        lesser.display();
    }
    else
    {
        cout << "\n\nTime T2 is greaterThan Time T1 \n";
        greater.display();
    }
    return 0;
}
int GreaterThanOrEqual()
{
    airTime T1, T2;
    cout << "Enter Time for T1 : \n";
    T1.setTime();
    cout << "Enter Time for T2 : \n";
    T2.setTime();

    if (T1 >= T2)
    {
        if (T1 > T2)
        {
            cout << "T1 is greater than Time T2 \n";
            T1.display();
        }
        else
        {
            cout << "time T1 is Equal To Time T2 \n";
            T1.display();
        }
    }
    else
    {
        cout << "Time T2 is greater than Time T1 \n";
        T2.display();
    }
    return 0;
}
int lessThanOrEqual()
{
    airTime T1, T2;
    cout << "\n\nEnter Time for T1 : \n";
    T1.setTime();
    cout << "\n\nEnter Time for T2 : \n";
    T2.setTime();

    if (T1 <= T2)
    {
        if (T1 < T2)
        {
            cout << "\n\nTime T1 is lessThan Time T2 \n";
            T1.display();
        }
        else
        {
            cout << "\n\nTime T1 is Equal to Time T2 \n";
            T1.display();
        }
    }
    else
    {
        cout << "Time T2 is GreaterThan Time T1 \n";
        T2.display();
    }
    return 0;
}

// void setTime()
// {
//     time_t curr_time;
//     curr_time = time(NULL);
//     tm *tm_local = localtime(&curr_time);
// }
// void displayTime()
// {
//     time_t curr_time;
//     curr_time = time(NULL);
//     tm *tm_local = localtime(&curr_time);
//     cout << "time is setted at : " << ((tm_local->tm_hour + 5) % 12) << ":" << tm_local->tm_min << ":" << tm_local->tm_sec << endl
//          << endl
//          << endl;
// }

void displayTime()
{
    airTime dis;
    cout << "-----------------------------------------------------------------------------------\n";
    cout << "\n|hours|"
         << "|    minutes     |"
         << "| seconds  |\n";
    dis.display();
    cout << "-----------------------------------------------------------------------------------\n\n\n";
}
