// C++ program for implementation of Insertion Sort

#include<iostream>
using namespace std;

// A function to implement Insertion Sort
void insertionSort(int arr[], int n)
{
    int i, j, key;
    for(i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1]
        // that are greater than key,
        // to one position ahead of
        // their current position

        while(j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
}

// A function to print an array
void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Original Array: \n";
    printArray(arr, n);
    insertionSort(arr, n);
    cout<<"\nSorted Array: \n";
    printArray(arr, n);
    return 0;
}