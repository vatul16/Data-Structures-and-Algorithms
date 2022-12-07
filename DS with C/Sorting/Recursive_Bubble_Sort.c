// C program for implementation of Recursive Bubble Sort

#include <stdio.h>

// A function to swap the values of two variables
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void recursiveBubbleSort(int arr[], int n)
{
    // Base case
    if(n==1)
        return;

    int count = 0;
    // One pass of bubble sort.
    // After this pass, the largest element is moved (or bubbled) to end.
    for(int i = 0; i < n-1; i++)
    {
        if(arr[i] > arr[i+1])
        {
            swap(&arr[i], &arr[i+1]);
            count++;
        }

        // Check if any recursion happens or not
        // If any recursion is not happened then return
        if(n==0)
            return;

        // Largest element is fixed
        // recur for remaining array
        recursiveBubbleSort(arr, n-1);
    }
}

// A function to print an array
void printArray(int arr[], int n)
{
    for(int i= 0; i < n; i++)
        printf("%d\t", arr[i]);
    
    printf("\n");
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    recursiveBubbleSort(arr, n);
    printf("Sorted Array: \n");
    printArray(arr, n);
    return 0;
}