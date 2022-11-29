#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

// searching
node *mySearch(node *fptr, int sData)
{
    cout << "fptr is " << fptr << "\n\n";
    cout << "sData is " << sData;
    node *temp;
    temp = fptr;
    while (temp)
    {
        if (temp->data == sData)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

int main()
{
    // declerations
    node *current = NULL, *prev = NULL, *first = NULL, *searchM;
    char ch;
    unsigned int marks;

    do
    {
        cout << "----------MENU----------\n";
        cout << "| 1.create node\n";
        cout << "| 2.display\n";
        cout << "| 3.search\n";
        cout << "| 4.sorting\n";
        cout << "| 5.updatation\n";
        cout << "| 6.insertion\n";
        cout << "| 7.deletion\n";
        cout << "| 8.class average\n";
        cout << "| 9.exit\n";
        cout << "enter a number in above options : ";
        cin >> ch;
        switch (ch)
        {
        case '1': // create linked list
            current = new node;
            current->next = NULL;
            cout << "enter the marks of the student : ";
            cin >> current->data;
            if (first == NULL)
            {
                first = prev = current;
            }
            else
            {
                prev->next = current;
                prev = current;
            }
            break;
        case '2': // display linked list
            current = first;

            while (current)
            {
                cout << current->data << "\n";
                current = current->next;
            }
            break;
        case '3': // search linked list
            cout << "enter the marks you want to search : ";
            cin >> marks;
            searchM = mySearch(first, marks);
            if (searchM)
                cout << "Found\n";
            else
                cout << "Not Found\n";
            break;
        case '4': // sort linked list
            break;
        case '5': // update linked list
            break;
        case '6': // insert linked list
            break;
        case '7': // delete linked list
            break;
        case '8': // class average linked list
            break;
        case '9': // exit linked list
            break;
        default:
            break;
        }
    } while (true);

    return 0;
}