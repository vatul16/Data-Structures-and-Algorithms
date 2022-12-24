// Implementation of Stack using Linked List

#include <iostream>
using namespace std;

class stack
{
    private:
        struct node
        {
            int data;
            node *link;
        }*top;

    public:
        stack();
        void push(int item);
        int pop();
        ~stack();
};

// initialises data member
stack :: stack()
{
    top = NULL;
}

// adds a new node to the stack as linked list
void stack :: push(int item)
{
    node *temp;
    temp = new node;

    if(temp == NULL)
    {
        cout<<"Stack is full."<<endl;
    }

    temp -> data = item;
    temp -> link = top;
    top = temp;
}

//pops an element from the stack
int stack :: pop()
{
    if(top == NULL)
    {
        cout<<"Stack is empty."<<endl;
    }

    node *temp;
    int item;

    temp = top;
    item = temp -> data;
    top = top -> link;

    delete temp;
    return item;
}

// deallocated memory
stack :: ~stack()
{
    if(top == NULL)
    {
        return;
    }

    node *temp;
    while(top != NULL)
    {
        temp = top;
        top = top -> link;
        delete temp;
    }
}

int main()
{
    stack s;

    s.push(14);
    s.push(-3);
    s.push(18);
    s.push(29);
    s.push(31);
    s.push(16);

    int n = s.pop();

    if(n != NULL)
    {
        cout<<"Item popped: "<<n<<endl;
    }

    n = s.pop();
    if(n != NULL)
    {
        cout<<"Item popped: "<<n<<endl;
    }

    n = s.pop();
    if(n != NULL)
    {
        cout<<"Item popped: "<<n<<endl;
    }

    return 0;
}