#include <iostream>
using namespace std;
#define MAX 3

class myStack
{
protected:
    int arr[MAX];
    int top;

public:
    myStack(int x = -1) : top(x) {}
    void push(int);
    int pop();
};

void myStack::push(int data)
{
    if (top == MAX - 1)
    {
        cout << "the stack is full\n";
        return;
    }
    arr[++top] = data;
}

int myStack::pop()
{
    if (top == -1)
    {
        cout << "the stack is empty\n";
        return -1;
    }
    return arr[top--];
}

class myStack1 : public myStack
{
public:
    void disp() const;
    int peep();
};

int myStack1::peep()
{
    if (top == -1)
    {
        cout << "the stack is empty\n";
        return -1;
    }
    return arr[top];
}

void myStack1::disp() const
{
    for (int i = 0; i <= top; i++)
    {
        cout << "data in stack at " << i + 1;
        cout << arr[MAX];
    }
}

int main()
{
    myStack s;
    myStack1 s1;
    unsigned int option, data, pop;

    do
    {
        cout << "1 push\n";
        cout << "2 pop\n";
        cout << "3 peep\n";
        cout << "4 display\n";
        cout << "5 exit program\n";
        cout << "enter a number in above option : ";
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "enter a number : ";
            cin >> data;
            s.push(data);
            break;
        case 2:
            pop = s.pop();
            cout << "poped data is : " << pop << "\n\n\n\n";
            break;
        case 3:
            cout << "peeping data \n\n\n";
            s1.peep();
            break;
        case 4:
            cout << "displaying derived class data\n\n\n";
            s1.disp();
            break;
        case 5:
            cout << "program is terminated successfully\n\n\n";
            exit(1);
            break;
        default:
            cout << "SORRY! INVALID NUMBER\n\n\n\n";
            break;
        }

    } while (option != 5);

    return 0;
}