// Implementation of Stack using Array

#include <iostream>
using namespace std;
const int MAX = 10;

class stack
{
    private: 
        int arr[MAX];
        int top;

    public:
        stack();
        void push(int item);
        int pop();
};

// initialises data member
stack :: stack()
{
    top = -1;
}

// adds an element to the stack
void stack :: push(int item)
{
    if(top == MAX - 1)
    {
        cout<<"Stack is full."<<endl;
        return;
    }
    top++;
    arr[top] = item;
}

// extracts an element from the stack
int stack :: pop()
{
    if(top == -1)
    {
        cout<<"Stack is empty."<<endl;
        return NULL;
    }
    int data = arr[top];
    top--;
    return data;
}

int main()
{
    stack s;

    s.push(2);
    s.push(-4);
    s.push(8);
    s.push(11);

    int n = s.pop();
    if(n != NULL)
    {
        cout<<"Item popped:"<<n<<endl;
    }

    n = s.pop();
    if(n != NULL)
    {
        cout<<"Item popped:"<<n<<endl;
    }

    n = s.pop();
    if(n != NULL)
    {
        cout<<"Item popped:"<<n<<endl;
    }

    n = s.pop();
    if(n != NULL)
    {
        cout<<"Item popped:"<<n<<endl;
    }

    n = s.pop();
    if(n != NULL)
    {
        cout<<"Item popped:"<<n<<endl;
    }

    return 0;
}