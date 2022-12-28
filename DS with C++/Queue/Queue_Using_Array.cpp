// Implementation of Queue using Array

#include<iostream>
using namespace std;
const int MAX = 10;

class queue
{
    private:
        int arr[MAX];
        int front,rear;

    public:
        queue();
        void addq(int item);
        int delq();
};

// initialise data members
queue :: queue()
{
    front = -1;
    rear = -1;
}

// adds an element to the queue
void queue :: addq(int item)
{
    if(rear == MAX-1)
    {
        cout<<"Queue  is full"<<endl;
        return;
    }

    rear++;
    arr[rear] = item;

    if(front == -1)
        front = 0;
}

// removes an element from the queue
int queue :: delq()
{
    int data;

    if(front == -1)
    {
        cout<<"Queue is Empty"<<endl;
        return NULL;
    }

    data = arr[front];
    arr[front] = 0;
    if(front == rear)
        front = rear = -1;
    else
        front++;

    return data;
}

int main()
{
    queue q;
    q.addq(34);
    q.addq(12);
    q.addq(53);
    q.addq(61);

    int n;
    n = q.delq();
    if(n != NULL)
        cout<<"Item deleted: "<<n<<endl;

    n = q.delq();
    if(n != NULL)
        cout<<"Item deleted: "<<n<<endl;

    n = q.delq();
    if(n != NULL)
        cout<<"Item deleted: "<<n<<endl;

    n = q.delq();
    if(n != NULL)
        cout<<"Item deleted: "<<n<<endl;

    n = q.delq();
    if(n != NULL)
        cout<<"Item deleted: "<<n<<endl;

    return 0;
}