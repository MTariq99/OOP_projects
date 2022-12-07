
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

class node
{

public:
    int data;
    node *next;
    void createNode(node *&firstPtr, node *&prev, node *&current);
    void mySearch(node *firstPtr, int sData);
    void sortList(node *&firstPtr);
    void updateNode(node *&firstPtr, int updataData);
    void insertNode(node *&firstPtr, node *&prev, node *&current, int iData);
    void deleteNode(node *&firstPtr, node *&prev, node *&current, int delData);
    void display(node *&first, node *&current);
    void classAvg(node *&firstPtr, node *&current);
};

// create new Node

// void node::createNode(node *&firstPtr, node *&prev, node *&current)
// {
//     current = new node;
//     current->next = NULL;
//     cout << "enter the marks of the student : ";
//     cin >> current->data;
//     if (firstPtr == NULL)
//     {
//         current = prev = firstPtr;
//     }
//     else
//     {
//         prev->next = current;
//         prev = current;
//     }
// }

// dispaly all Nodes
void node::display(node *&first, node *&current)
{
    current = first;
    while (current)
    {
        cout << current->data << " ";
        current = current->next;
    }
}

// //member function of class node for searching
void node::mySearch(node *fptr, int sData)
{
    node *temp;
    temp = fptr;
    while (temp)
    {
        if (temp->data == sData)
        {
            cout << "found\n";
        }
        temp = temp->next;
    }
}

// member function of class node for inserting a new node
void node::insertNode(node *&firstPtr, node *&prev, node *&current, int idata)
{
    node *iNode = new node;
    iNode->data = idata;
    iNode->next = NULL;
    if (firstPtr == NULL)
    {
        firstPtr = current = iNode;
    }
    else
    {
        current = firstPtr;
        while (current)
        {
            if (iNode->data < current->data)
            {
                prev->next = iNode;
                iNode->next = current;
            }
            else if (current->next == NULL)
            {
                current->next = iNode;
                iNode->next = NULL;
            }
            prev = current;
            current = current->next;
        }
    }
}

// member function of class node for updating a node
void node::updateNode(node *&firstPtr, int updataData)
{
    node *temp;
    temp = firstPtr;
    unsigned int marks;
    cout << "enter the marks you want to update with : ";
    cin >> marks;
    while (temp)
    {
        if (temp->data == updataData)
        {
            temp->data = marks;
        }
        temp = temp->next;
    }
}

// member function of class node for deleting a node
void node::deleteNode(node *&firstPtr, node *&prev, node *&current, int delData)
{
    current = prev = firstPtr;
    while (current)
    {
        if (firstPtr->data == delData)
        {
            current = firstPtr->next;
            firstPtr = prev = current;
        }
        else if (current->data == delData)
        {
            prev->next = current->next;
            prev = current;
        }
        else if (current->data == delData && current->next == NULL)
        {
            prev->next = NULL;
            prev = current;
        }
        prev = current;
        current = current->next;
    }
}

// member function of class node for sorting marks
void node::sortList(node *&firstPtr)
{
    // selecting algorithm for sorting
    node *i, *j;
    int temp;
    for (i = firstPtr; i->next != NULL; i = i->next)
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
}
// member function of class node for class average
void node::classAvg(node *&firstPtr, node *&current)
{
    unsigned int sum = 0, n = 0;
    current = firstPtr;
    float avg;
    while (current->next != NULL)
    {
        sum += current->data;
        n++;
        current = current->next;
    }
    avg = static_cast<float>(sum) / n;
    cout << "the class average is : " << avg << "\n";
}

int main()
{
    // declerations
    node *current = NULL, *prev = NULL, *first = NULL, nde;
    char ch;
    unsigned int marks;
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
            nde.display(first, current);
            break;
        case '3': // search linked list
            cout << "enter the marks you want to search : ";
            cin >> marks;
            nde.mySearch(first, marks);
            break;
        case '4': // sort linked list
            nde.sortList(first);
            break;
        case '5': // update linked list
            cout << "enter the marks you want to update : ";
            cin >> marks;
            nde.updateNode(first, marks);
            break;
        case '6': // insert linked list
            cout << "\nenter the marks you want to insert : ";
            cin >> marks;
            nde.insertNode(first, prev, current, marks);

            break;
        case '7': // delete linked list
            cout << "enter the marks you want to delete : ";
            cin >> marks;
            nde.deleteNode(first, prev, current, marks);
            break;
        case '8': // class average linked list
            nde.classAvg(first, current);
            break;
        case '9': // exit linked list
            exit(0);
            break;
        default:
            break;
        }
    } while (true);

    return 0;
}