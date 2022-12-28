// Implementation of Queue using Linked List (Linked Queue)

#include<iostream>
using namespace std;

class queue
{
    private:
        struct node
        {
            int data;
            node *link;
        }*front, *rear;

    public:
        queue();
        void addq(int item);
        int delq();
        ~queue();
};

// initialises data member
queue :: queue()
{
    front = rear = NULL;
}

// adds an element to the queue
void queue :: addq(int item)
{
    node *temp;

    temp = new node;

    if(temp == NULL)
    {
        cout<<"Queue is full"<<endl;
    }

    temp -> data = item;
    temp -> link = NULL;

    if(front == NULL)
    {
        rear = front = temp;
        return;
    }

    rear -> link = temp;
    rear = rear -> link;
}

// removes an element from the queue
int queue :: delq()
{
    if(front == NULL)
    {
        cout<<"Queue is empty"<<endl;
        return NULL;
    }

    node *temp;
    int item;

    item = front -> data;
    temp = front;
    front = front -> link;

    delete temp;
    return item;
}

// deallocates memory
queue :: ~queue()
{
    if(front == NULL)
    {
        return;
    }

    node *temp;
    while(front != NULL)
    {
        temp = front;
        front = front -> link;
        delete temp;
    }
}

int main()
{
    queue q;

    q.addq(34);
    q.addq(12);
    q.addq(53);
    q.addq(61);

    int n = q.delq();
    if(n != NULL)
        cout<<"Item extracted: "<<n<<endl;

    n = q.delq();
    if(n != NULL)
        cout<<"Item extracted: "<<n<<endl;

    n = q.delq();
    if(n != NULL)
        cout<<"Item extracted: "<<n<<endl;

    return 0;
}