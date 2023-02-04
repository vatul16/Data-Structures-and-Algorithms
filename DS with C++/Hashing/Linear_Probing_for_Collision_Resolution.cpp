// Implement program for Collision Resolution using Linear Probe.

#include<iostream>
#include<conio.h>
#include<stdlib.h>
#define TABLE_SIZE 10
using namespace std;

int h[TABLE_SIZE] = {};

void insert()
{
    int key, index, i, flag = 0, hkey;
    cout<<"Enter a value to insert into hashtable:";
    cin>>key;
    hkey = key % TABLE_SIZE;

    for(i = 0; i < TABLE_SIZE; i++)
    {
        index = (hkey + i) % TABLE_SIZE;

        if(h[index] == NULL)
        {
            h[index] = key;
            break;
        }
    }
    if(i == TABLE_SIZE)
    {
        cout<<"\nElements cannot be inserted";
    }
}

void search()
{
    int key, index, i, flag = 0, hkey;
    cout<<"\nEnter search element:";
    cin>>key;
    hkey = key % TABLE_SIZE;

    for(i = 0; i < TABLE_SIZE; i++)
    {
        index = (hkey + i) % TABLE_SIZE;
        if(h[index] == key)
        {
            cout<<"\nValue is found at index: "<<index;
            break;
        }
    }
    if(i == TABLE_SIZE)
    {
        cout<<"\nValue is not found";
    }
}

void display()
{
    int i;
    cout<<"\nElement in the hash table are:\n";
    for(i = 0; i < TABLE_SIZE; i++)
    {
        cout<<"\nAt index: "<<i<<"\tvalue:"<<h[i];
    }
}

int main()
{
    int choice, i;
    while(1)
    {
        cout<<"\n1. Insert\n2. Display\n3. Search\n4. Exit\n\nEnter the choice:";
        cin>>choice;
        switch(choice)
        {
            case 1:
                insert();
                break;

            case 2:
                display();
                break;

            case 3:
                search();
                break;

            case 4:
                exit(0);
                break;

            default:
                cout<<"Enter right choice!";
        }
    }
    return 0;
}