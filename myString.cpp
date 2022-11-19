#include <iostream>
#include <string.h>
#include <conio.h>
#include <limits>
using namespace std;
#define MAX 80

class myString
{
    char str[MAX];

public:
    myString(){};
    void setter();
    void getter();
    int myStrLen();
    int myStrSearch(myString &);
    void myStrDelete(myString &);
    int myStrStat();
    myString operator+(myString &);
    myString operator-(myString &);
    bool operator>(myString);
    bool operator<=(myString);
    bool operator==(myString);
};
void myString::setter()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.getline(str, MAX);
}
void myString::getter()
{
    cout << "\n\n"
         << str << "\n\n\n";
}
int myString::myStrLen()
{
    int len = 0;
    int i = 0;
    while (str[i] != '\0')
    {
        len++;
        i++;
    }
    // cout << len << "\n\n";
    return len;
}
myString myString::operator+(myString &concStr)
{
    int i, strLen = 0, wordLen = 0;
    strLen = myStrLen();
    wordLen = concStr.myStrLen();
    cout << "size of char string : " << strLen << "\n";
    cout << "size of word  : " << wordLen << "\n";
    for (i = 0; i <= wordLen; i++)
    {
        str[strLen + i] = concStr.str[i];
    }
    return *this;
}

myString myString::operator-(myString &delStr)
{
    unsigned int strLen = 0, wordLen = 0, i = 0, wordPos = 0, pos = -1;
    wordLen = delStr.myStrLen();
    strLen = myStrLen();
    cout << "strLen : " << strLen << "\n";
    cout << "wordlen : " << wordLen << "\n";
    for (i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] == delStr.str[wordPos])
        {
            pos = i;
        }
    }
    cout << "Postion is on Index: " << pos << endl
         << endl;

    if (pos != -1)
    {
        for (int j = pos + wordLen; j <= strLen; j++)
        {
            str[pos] = str[j];
        }
    }
    else
    {
        cout << "String not found" << endl;
    }

    return *this;
}

bool myString::operator==(myString equalTo)
{
    unsigned int chk, i;
    for (i = 0; str[i] != '\0' || equalTo.str[i] != '\0'; i++)
    {
        if (str[i] != equalTo.str[i])
        {
            chk = 1;
            break;
        }
    }
    if (chk == 1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool myString::operator>(myString strGreater)
{
    myString temp;
    int i;
    for (i = 0; str[i] != 0 || strGreater.str[i] != 0; i++)
    {
        if (str[i] > strGreater.str[i])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return 0;
}

bool myString::operator<=(myString lessThanOrEq)
{

    unsigned int chk, i;
    for (i = 0; str[i] != '\0' || lessThanOrEq.str[i] != '\0'; i++)
    {
        if (str[i] <= lessThanOrEq.str[i])
        {
            chk = 1;
            break;
        }
    }
    if (chk == 1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int myString::myStrStat()
{
    unsigned i = 0, totUpperCase = 0, totLowerCase = 0, totSpecialCharacters = 0, totDigits = 0, totWords = 1;
    while (str[i] != '\0')
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            totUpperCase++;
        }
        else if (str[i] >= 'a' && str[i] <= 'z')
        {
            totLowerCase++;
        }
        else if (str[i] >= 0 && str[i] <= 9)
        {
            totDigits++;
        }
        else if (str[i] == ' ' || str[i] != '\n')
        {
            totWords++;
        }
        else if ((str[i] >= 'A' || str[i] <= 'Z') && (str[i] >= 'a' || str[i] <= 'z') && (str[i] >= 0 || str[i] <= 9))
        {
            totSpecialCharacters++;
        }
        else
        {
            cout << "sorry\n";
        }
        i++;
    }
    cout << "\n\ntotal upparCase alphabats are : " << totUpperCase << "\n";
    cout << "total loweCase alphabats are : " << totLowerCase << "\n";
    cout << "total digits are : " << totDigits << "\n";
    cout << "total words are : " << totWords << "\n";
    cout << "special characters are : " << totSpecialCharacters << "\n\n\n";

    return 0;
}

int myString::myStrSearch(myString &searchStr)
{
    int searchLen = 0, i = 0, searchPos = 0, strLen = 0;
    searchLen = searchStr.myStrLen();
    strLen = myStrLen();
    for (i = 0; i < MAX - searchLen; i++)
    {

        if (str[i] == searchStr.str[searchPos])
        {
            ++searchPos;
            if (searchPos == searchLen)
            {
                cout << "\nmatch found : \n";
                cout << searchStr.str << "\n\n\n";
                break;
            }
        }
        else
        {
            searchPos = 0;
        }
    }
    return 0;
}

void myString::myStrDelete(myString &delStr)
{
    unsigned int strLen = 0, wordLen = 0, i = 0, wordPos = 0, pos = -1;
    wordLen = delStr.myStrLen();
    strLen = myStrLen();
    cout << "strLen : " << strLen << "\n";
    cout << "wordlen : " << wordLen << "\n";
    for (i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] == delStr.str[wordPos])
        {
            pos = i;
        }
    }
    cout << "Postion is on Index: " << pos << endl
         << endl;

    if (pos != -1)
    {
        for (int j = pos + wordLen; j <= strLen; j++)
        {
            str[pos] = str[j];
        }
    }
    else
    {
        cout << "String not found" << endl;
    }
}

void concat();
void greaterThan();
void lessThanOrEqual();
void equalTo();

int main()
{
    myString str, fullStr, str1, deletedword;
    unsigned int option;
    do
    {
        cout << "\n\n\n1 Set values\n";
        cout << "2 Length of the array \n";
        cout << "3 display Array \n";
        cout << "4 search a string or character\n";
        cout << "5 concatinate two strings\n";
        cout << "7 string stats\n";
        cout << "8 GreaterThan\n";
        cout << "9 lessThan or Equal\n";
        cout << "10 delete a word\n";
        cout << "11 strings are equal or not \n";
        cout << "12 exit program\n\n";
        cout << "Enter a Number in Above Options : ";
        cin >> option;

        switch (option)
        {
        case 1:
            str.setter();
            break;
        case 2:
            cout << "\n\n\n";
            str.myStrLen();
            cout << "\n\n\n";

            break;
        case 3:
            str.getter();
            break;
        case 4:
            cout << "Search A string  : ";
            str1.setter();
            str.myStrSearch(str1);
            cout << "\n\n";
            break;

        case 5:
            concat();
            cout << "\n\n";
            break;
        case 7:
            cout << "string array stats \n";
            str.myStrStat();
            cout << "\n\n";
            break;
        case 8:
            cout << "greaterThan strings : \n";
            greaterThan();
            break;
        case 9:
            cout << "greaterThan or Equal \n";
            lessThanOrEqual();
            cout << "\n\n";
            break;
        case 10:
            cout << "enter a word to delete from Array : \n";
            str1.setter();
            deletedword = str - str1;
            deletedword.getter();
            cout << "\n";
            break;
        case 11:
            cout << "strings are equal or not \n";
            equalTo();
            break;
        case 12:
            cout << "\nprogram is terminated successfully\n";
            break;
            exit(1);
            break;
        default:
            cout << "invalid option\n";
            break;
        }
    } while (option != 12);
    return 0;
}
void concat()
{
    myString str1, str2, str3;
    cout << "Enter first string : \n";
    str1.setter();
    cout << "Enter second string : \n";
    str2.setter();
    cout << "\n";
    str3 = str1 + str2;
    cout << "concatinated string are : ";
    str3.getter();
}
void greaterThan()
{
    myString strG1, strG2, strG3;
    cout << "Enter first string for comparison : \n";
    strG1.setter();
    cout << "Enter second string for comparison : \n";
    strG2.setter();
    if (strG1 > strG2)
    {
        cout << "first string is greater than second string : \n\n";
        strG1.getter();
        cout << "\n\n\n";
    }
    else
    {
        cout << "second string is greater than the first string : \n";
        strG2.getter();
    };
}
void lessThanOrEqual()
{
    myString s1, s2;
    cout << "Enter first string for comparison : \n";
    s1.setter();
    cout << "Enter second string for comparison : \n";
    s2.setter();
    if (s1 <= s2)
    {
        cout << "first strings is lessThan or  equal to second string\n";
        s1.getter();
    }
    else
    {
        cout << "second string is greaterThan first string \n";
        s2.getter();
    }
}

void equalTo()
{
    myString str1, str2, eq;
    cout << "Enter first string : \n";
    str1.setter();
    cout << "Enter second string : \n";
    str2.setter();

    if (str1 == str2)
    {
        cout << "both strings are equal \n";
    }
    else
    {
        cout << "strings are not equal \n";
    }
}
