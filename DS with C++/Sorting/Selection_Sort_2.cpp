#include <iostream>  
  
using namespace std;  

// Swap function
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
  
void selectionSort(int arr[], int n)  
{  
    int i, j, small;  
      
    for (i = 0; i < n-1; i++)    // One by one move boundary of unsorted subarray  
    {  
        small = i; //minimum element in unsorted array  
          
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[small])  
            small = j;  
// Swap the minimum element with the first element  
    swap(&arr[small], &arr[j]);
    }  
}  
  
void printArr(int a[], int n) /* function to print the array */  
{  
    int i;  
    for (i = 0; i < n; i++)  
        cout<< a[i] <<" ";  
}  
  
int main()  
{  
    int a[] = { 80, 10, 29, 11, 8, 30, 15 };  
    int n = sizeof(a) / sizeof(a[0]);  
    cout<< "Before sorting array elements are - "<<endl;  
    printArr(a, n);  
    selectionSort(a, n);  
    cout<< "\nAfter sorting array elements are - "<<endl;    
    printArr(a, n);  
  
    return 0;  
}  