// C program for implementation of Bubble Sort

#include <stdio.h>
#include <stdbool.h>

// A function for swapping the values of two variableS
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for(i = 0; i < n-1; i++)
    {
        swapped = false;
        // Last ith elements are already in place
        for(j = 0; j < n-1-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
                swapped = true;
            }
        }
        // If no two elements were swapped by inner loop, then break
        if(swapped == false)
        {
            break;
        }
    }
}

// A function to print an array
void printArray(int arr[], int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    printf("Sorted Array: \n");
    printArray(arr, n);
    return 0;
}