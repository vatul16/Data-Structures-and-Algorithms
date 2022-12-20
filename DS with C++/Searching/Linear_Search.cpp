#include <iostream>  
using namespace std;  

int linearSearch(int arr[], int n, int val) {  
  // Going through array linearly  
  for (int i = 0; i < n; i++)  
    {  
        if (arr[i] == val)  
        return i+1;  
    }  
  return -1;  
}  
int main() {  
  int arr[] = {69, 39, 29, 10, 56, 40, 24, 13, 51}; // given array  
  int val = 56; // value to be searched  
  int n = sizeof(arr) / sizeof(arr[0]); // size of array  
  int res = linearSearch(arr, n, val); // Store result  
  cout<<"The elements of the array are - ";
  cout<<endl;

  for (int i = 0; i < n; i++)  
    cout<<arr[i]<<"\t"; 

  cout<<"\nElement to be searched is - "<<val;

  if (res == -1)  
    cout<<"\nElement is not present in the array";  
  else  
    cout<<"\nElement is present at "<<res<<" position of array";

  return 0;  
}  