// Implementing Heap with different operations performed.

#include<iostream>
#include<math.h>
using namespace std;
int n=0;
void printArray(int arr[],int n)
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;	
}
void maxHeapify(int arr[],int n,int i)
{
	int largest=i;
	int left=(2*i)+1;
	int right=(2*i)+2;
	while(left<n && arr[left]>arr[largest])	
	{
		largest=left;
	}
	while(right<n && arr[right]>arr[largest])
	{
		largest=right;
	}
	if(largest!=i)
	{
		swap(arr[largest],arr[i]);
		maxHeapify(arr,n,largest);
	}
}

void heapSort(int arr[],int N)
{
  	for (int i = N / 2 - 1; i >= 0; i--)
        maxHeapify(arr, N, i);
  
    for (int i = N - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
	cout<<"Sorted Heap: ";
	printArray(arr,n);
}
void insert(int arr[], int& n,int value)
{
	arr[n]=value;
	n=n+1;
	int i=n;
	while(i>0)
	{
		int parent=floor(i/2);
		if(arr[parent]<arr[i])
		{
			swap(arr[parent],arr[i]);
			i=parent;
		}
		else
		{
			return;
		}
	}	
}
void deleteRoot(int arr[],int& n)
{
	int lastElement = arr[n - 1];
    arr[0] = lastElement;
    n = n - 1;
    maxHeapify(arr, n, 0);
}
int main()
{
	int val,arr[100]={0};
	cout<<"Enter the size of Array: ";
	cin>>n;
	cout<<"Elements: ";
	for(int i=0;i<n;i++)
	{
	cin>>val;	
	arr[i]=val;	
	}
	cout<<"1.Heapify\n2.HeapSort\n3.Insert\n4.Delete\n5.Exit\n";
	while(1)
	{
		int ch;
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:for(int i=n/2-1;i>=0;i--)
					{
					maxHeapify(arr,n,i);	
					}
					cout<<"\nAfter Heapify: ";
					printArray(arr,n);
					break;
			case 2: heapSort(arr,n);
					break;
			case 3:int value;
					cout<<"\nEnter the value want to insert: ";
					cin>>value;
					cout<<"\nAfter Insertion:\n";
					insert(arr,n,value);
					heapSort(arr,n);
					break;
			case 4: cout<<"\nElements after deletion: ";
					deleteRoot(arr,n);
					printArray(arr,n);
					break;
			case 5:exit(0);
				   	break;
			default: cout<<"Invalid Input";	
		}
	}	
}