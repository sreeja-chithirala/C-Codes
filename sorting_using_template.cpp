/*
Write a C++ program to implement the bubble Sorting using Template. Consider the inputs of different data types to sort the data.
*/

#include<iostream>
#include<string>
#define SIZE 100
using namespace std;

template<class T>
void bubble_sort(T arr[SIZE],int n)   //bubble sort function
{   
	T temp;
	int i,j;
	for(i=0;i<n;i++)   //after every iteration the largest of the unsorted part will be placed in its position first as adjacent elements are compared repatatively and swapped accordingly
	{
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	cout << "The sorted array is : ";
	for(i=0;i<n;i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}

int main()
{
	int choice,n;
	do
	{   //taking the datatype from the user
		cout << "Which datatype elements you would like to enter:\n";
	    cout << "1.int   2.float   3.string   4.exit\n";
	    cin >> choice;
	    switch(choice)
	    {
	    	case 1: {
	    		    cout << "How many elements you would like to enter: ";
	                cin >> n;
			        int arr[n];
	    	        cout << "Enter " << n << " elements: ";
	    	        for(int i=0;i<n;i++)
	    	        {
	    	        	cin >> arr[i];
					}
					bubble_sort(arr,n);
				    }
					break;
			case 2: {
				    cout << "How many elements you would like to enter: ";
	                cin >> n;
			        float arr[n];
	    	        cout << "Enter " << n << " elements: ";
	    	        for(int i=0;i<n;i++)
	    	        {
	    	        	cin >> arr[i];
					}
					bubble_sort(arr,n);
				    }
					break;
			case 3: {
				    cout << "How many elements you would like to enter: ";
	                cin >> n;
			        string arr[n];
	    	        cout << "Enter " << n << " elements: ";
	    	        for(int i=0;i<n;i++)
	    	        {
	    	        	cin >> arr[i];
					}
					bubble_sort(arr,n);
				    }
					break;
			case 4: cout << "End of program!";
			        break;
		}
	}while(choice!=4);
	return 0;
}
