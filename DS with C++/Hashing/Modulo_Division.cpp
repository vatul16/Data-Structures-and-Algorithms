// Implement program for hashing using Digit Extraction Method.

#include<iostream>
using namespace std;
#define size 7
int arr[size];

void init()
{
    int i;
    for(i = 0; i < size; i++)
    {
        arr[i] = -1;
    }
}

void insert(int value)
{
    int key = value % size;     // use of modulo division
    if(arr[key] == -1)
    {
        arr[key] = value;
        cout<<value<<" inserted at arr["<<key<<"]"<<endl;
    }
    else
    {
        cout<<"Collision: arr["<<key<<"] has element "<<arr[key]<<" already!"<<endl;
        cout<<"Unable to insert "<<value<<endl;
    }
}

void search(int value)
{
    int key = value % size;
    if(arr[key] == value)
    {
        cout<<"Search Found at index "<<key<<endl;
    }
    else
    {
        cout<<"Search not Found\n";
    }
}

void display()
{
    int i;
    for(i = 0; i < size; i++)
    {
        cout<<"arr["<<i<<"] = "<<arr[i]<<endl;
    }
}

int main()
{
    init();
    insert(10);     // key = 10 % 7 => 3
    insert(4);      // key = 4 % 7 => 4
    insert(2);      // key = 2 % 7 => 2
    insert(3);      // key = 3 % 7 => 3 (collision)

    cout<<"Hash Table\n";
    display();
    cout<<"\nSearching value 4...\n";
    search(4);
    return 0;
}
