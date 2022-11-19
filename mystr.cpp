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
    myString() {}
    void setter();
    myString operator+(myString concStr);
    void getter();
    int myStrLen();
    bool myStrSearch(myString&);
    myString myStrDelete(myString &);
    int myStrStat();
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
    return 0;
}
bool myString::myStrSearch(myString &searchStr)
{
    bool match;
    unsigned int strLen = searchStr.myStrLen();
    cout << "strLen length is " << strLen << "\n";
    int searchLen = 0, i = 0, searchPos = 0, j;
    while (searchStr.str[i] != '\0')
    {
        searchLen++;
        i++;
    }
    for (int i = 0; i < strLen; i++)
        if (str[i] == searchStr.str[0])
        {
            int k = i;
            match = true;
            for (j = 1; j < searchLen; j++)
                if (str[++k] != searchStr.str[j])
                {
                    match = false;
                    break;
                }
            if (match)
            {
                return i;
                break;
            }
            else
            {
                return -1;
            }
        }
    return 0;
}

// bool myString::myStrSearch(myString searchStr)
// {
//     bool match
//    unsigned int strLen = strlen(str);
//     int searchLen = 0, i = 0, searchPos = 0;
//     while (searchStr.str[i] != '\0')
//     {
//         searchLen++;
//         i++;
//     }
//     for (i = 0; i < strLen; i++)
//     {

//         if (str[i] == searchStr.str[searchPos])
//         {
//             // ++searchPos;
//             return true;
//             int k = i;
//             for(int j =1; j<searchLen;j++){
//                if(str[i]!=searchStr.str[++k]){
//                 return false;
//                 break;

//                }
//                if(true)
//                 break;

//             }

//         //     if (searchPos == searchLen)
//         //     {
//         //         cout << "\nmatch found : \n";
//         //         cout << searchStr.str << "\n\n\n";
//         //         return true;
//         //         break;
//         //     }
//         // }
//         // else
//         // {
//         //     searchPos = 0;
//         // }
//     }

//     return 0;
// }
myString myString::operator+(myString concStr)
{
    // strcat(str, concStr.str);
    // strcpy(temp.str, str);
    int i, strLen = 0, wordLen = 0;
    strLen = strlen(str);
    wordLen = strlen(concStr.str);
    cout << "concStr : " << concStr.str << "\n";
    for (i = 0; i <= wordLen; i++)
    {
        str[strLen + i] = concStr.str[i];
    }
    return *this;
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
    // if (strlen(str) > strlen(strGreater.str))
    // if (str > strGreater.str)
    // {
    //     return true;
    // }
    // else
    // {
    //     return false;
    // }
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
    // if (str <= lessThanOrEq.str)
    // {
    //     return true;
    // }
    // else
    // {
    //     return false;
    // }
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
    // if (str == equalTo.str)
    // {
    //     return true;
    // }
    // else
    // {
    //     return false;
    // }
    // return 0;
}

myString myString::myStrDelete(myString &delStr)
{

    unsigned int delWL, strLen, i, position;
    strLen = delStr.myStrLen();
    cout << "str length " << strLen << "\n";
    while (delStr.str[i] != '\0')
    {
        delWL++;
        i++;
    }
    delWL + 1;
    position = myStrSearch(delStr);
    if (position == -1)
    {
        cout << "word not found \n";
    }
    else
    {
        for (i = position; i < strLen - delWL; i++)
        {
            str[i - 1] = delStr.str[i + delWL];
            cout << "word deleted from string\n";
        }
    }

    return *this;
}

myString concat();
myString delWord();
int greaterThan();
int lessThanOrEqual();
int equalTo();

int main()
{
    myString myStr, fullStr, newArr, searchStr, delW, deletedword;
    unsigned int option;
    // char searchStr[MAX];
    do
    {
        cout << "\n\n\n1 Set values\n";
        cout << "2 Length of the array \n";
        cout << "3 display Array \n";
        cout << "4 search a string or character\n";
        cout << "5 concatinate two strings\n";
        cout << "6 display concatinated word\n";
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
            myStr.setter();
            break;
        case 2:
            cout << "\n\n\n";
            myStr.myStrLen();
            cout << "\n\n\n";

            break;
        case 3:
            myStr.getter();
            break;
        case 4:
            cout << "Search A string  : ";
            newArr.setter();
            myStr.myStrSearch(newArr);
            cout << "\n\n";
            break;

        case 5:
            fullStr = concat();
            cout << "\n\n";
            break;
        case 6:
            cout << "display concatinated strings : \n";
            fullStr.getter();
            cout << "\n\n\n";
            break;
        case 7:
            cout << "string array stats \n";
            myStr.myStrStat();
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
            delW.setter();
            deletedword.myStrDelete(delW);
            deletedword.getter();
            // delWord();
            // cout << "enter word to delete from an array : ";
            // delWord.setter();
            // deletedword = delWord.myStrDelete(delWord);
            // cout << "\n";
            // deletedword.getter();
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
myString concat()
{
    myString str1, str2, str3;
    cout << "Enter first string : \n";
    str1.setter();
    cout << "Enter second string : \n";
    str2.setter();
    cout << "\n";
    str3 = str1 + str2;

    return str3;
}
int greaterThan()
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

    return 0;
}
int lessThanOrEqual()
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
    return 0;
}

int equalTo()
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
    return 0;
}

// myString delWord()
// {
//     myString del, newArr, updatedArr;
//     newArr.setter();
//     updatedArr = del.myStrDelete(newArr);
//     cout << "new Array is : \n";
//     cout << "\n\n";
//     updatedArr.getter();

//     return updatedArr;
// }
