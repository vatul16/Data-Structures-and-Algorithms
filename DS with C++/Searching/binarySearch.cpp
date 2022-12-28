#include <iostream>  
using namespace std;  
int binarySearch(int arr[], int beg, int end, int val)    
{    
    int mid;    
    if(end >= beg)     
    {  
        mid = (beg + end)/2;    
/* if the item to be searched is present at middle */  
        if(arr[mid] == val)    
        {                 
            return mid+1;    
        }    
            /* if the item to be searched is smaller than middle, then it can only be in left subarray */  
        else if(arr[mid] < val)     
        {  
            return binarySearch(arr, mid+1, end, val);    
        }    
        /* if the item to be searched is greater than middle, then it can only be in right subarray */      
        else     
        {  
            return binarySearch(arr, beg, mid-1, val);    
        }         
    }    
    return -1;     
}   
int main() {  
  int arr[] = {1,2,3,9,11,13,17,25,57,90}; // given array  
  int val = 57; // value to be searched  
  int n = sizeof(arr) / sizeof(arr[0]); // size of array  
  int res = binarySearch(arr, 0, n-1, val); // Store result  

  cout<<"The elements of the array are - ";  
  for (int i = 0; i < n; i++)  
    cout<<arr[i]<<" ";    

  cout<<"\nElement to be searched is - "<<val;  

  if (res == -1)  
    cout<<"\nElement is not present in the array";  
  else  
    cout<<"\nElement is present at "<<res<<" position of array";  

  return 0;  
}  