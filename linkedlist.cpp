
// PROGRAMMER NAME :  MUHAMMAD TARIQ
// REGISTRATION NUMBER : 4338-FBAS-BSSE-F21
// INSTRUCTOR : SIR MUHAMMAD NADEEM ALI
// DATE 03-DEC-2022

/*
1-this program is able to create nodes
2-search node
3-update any node
4-sort the created nodes in ascending order
5- delete any created node
6- you can insert nodes at the begining or at the end
7- find the average of the class

all the above operations are done in singly linkedlist
*/

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

void insertAtHead(node *&first, int insertData)
{
    node *firstHead = new node;
    firstHead->data = insertData;
    firstHead->next = first;
    if (first == NULL)
    {
        firstHead->next = first;
        first = firstHead;
    }
    else
    {
        first = firstHead;
    }
}

// void insertInMiddle();

void insertAtEnd(node *&first, int atEnd)
{
    node *lastNode = new node;
    lastNode->data = atEnd;
    node *temp = first;
    while (temp->next != NULL)
    {
        cout << "at end " << temp->data << "\n";
        temp = temp->next;
    }
    temp->next = lastNode;
    lastNode->next = NULL;
}

int main()
{
    // declerations
    node *current = NULL, *prev = NULL, *first = NULL, *searchM;
    char ch;
    unsigned int marks, sum, n;
    float average;

    do
    {
        cout << "     \n----------MENU----------\n";
        cout << "     | 1.create node        |\n";
        cout << "     | 2.display            |\n";
        cout << "     | 3.search             |\n";
        cout << "     | 4.sorting            |\n";
        cout << "     | 5.updatation         |\n";
        cout << "     | 6.insertion          |\n";
        cout << "     | 7.deletion           |\n";
        cout << "     | 8.class average      |\n";
        cout << "     | 9.exit               |\n";
        cout << "     ------------------------\n";

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
                cout << "    " << current->data << " ";
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
                  // selecting algorithm for sorting
            node *i, *j;
            int temp;
            for (i = first; i->next != NULL; i = i->next)
            {
                for (j = i->next; j != NULL; j = j->next)
                {
                    if (i->data > j->data)
                    {
                        temp = i->data;
                        i->data = j->data;
                        j->data = temp;
                    }
                }
            }
            break;
        case '5': // update linked list
            cout << "enter the marks you want to update : ";
            cin >> marks;
            searchM = mySearch(first, marks);
            if (searchM)
            {
                cout << "enter the marks you want to update with : ";
                cin >> marks;
                searchM->data = marks;
            }

            break;
        case '6': // insert linked list
            cout << "     \n----------INSERTION MENU----------\n";
            cout << "     | 1.at the Begining        |\n";
            cout << "     | 2.In the Middle          |\n";
            cout << "     | 3.At the End             |\n";
            cout << "     ---------------------------\n";
            cout << "Where Do You Want To Insert : ";
            cin >> ch;
            cout << "\nenter the marks you want to insert : ";
            cin >> marks;
            if (ch == '1')
            {
                insertAtHead(first, marks);
            }
            else if (ch == '2')
            {
            }
            else if (ch == '3')
            {
                insertAtEnd(first, marks);
            }
            else
            {
                cout << "invalid option\n";
            }

            break;
        case '7': // delete linked list
            cout << "     \n----------INSERTION MENU----------\n";
            cout << "     | 1.From the Begining        |\n";
            cout << "     | 2.From the Middle          |\n";
            cout << "     | 3.the End Node             |\n";
            cout << "     ---------------------------\n";
            cout << "Which Node do you want to delete : ";
            cin >> ch;
            node *delTemp;
            if (ch == '1')
            {
                delTemp = first;
                first = first->next;
                delete delTemp;
            }
            else if (ch == '2')
            {
                int i = 0;
                delTemp = prev = first;
                cout << "enter the marks you want to delete : ";
                cin >> marks;
                while (delTemp->next != NULL)
                {
                    if (delTemp->data == marks)
                    {
                        prev->next = delTemp->next;
                        delTemp->next = NULL;
                    }
                    else
                    {
                        prev = delTemp;
                        delTemp = delTemp->next;
                    }
                }
            }
            else if (ch == '3')
            {
                delTemp = first;
                while (delTemp->next != NULL)
                {
                    prev = delTemp;
                    delTemp = delTemp->next;
                }
                if (delTemp == first)
                {
                    first = NULL;
                }
                else
                {
                    prev->next = NULL;
                }
                delete delTemp;
            }

            break;
        case '8': // class average linked list
            while (current)
            {
                sum += current->data;
                current = current->next;
                n++;
            }
            // type Casting from integer to float
            average = static_cast<float>(sum) / n;
            cout << "the class average is   " << average << "\n";
            break;
        case '9': // exit linked list
            break;
        default:
            break;
        }
    } while (true);

    return 0;
}