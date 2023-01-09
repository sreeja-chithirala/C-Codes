#include<iostream>
using namespace std;

void search_array(int);   //declaring a function to search an element in an array

int A[20],n,s;      //declaring the array and no of elements(n) globally so that they can be used by all functions

int main()
{
	int i,search;   //declaring other variables
	cout << "Let us enter elements in an array.\n";
	cout << "How many elements you would like to enter in an array: ";
	cin >> n;
	cout << "Enter " << n << " elements into an array : ";    //taking the elements into the array from the user
	for(i=0;i<n;i++)
	{
		cin >> A[i];
	}
	do
	{
	cout << "Enter the element to be searched in those elements: ";
	cin >> search;
	search_array(search); //calling the search_array funtion by passing 'search' to check whether the element in the search variable is present or not  in the array
	cout << "Do you want to find another element (1-yes / 0-no) : ";
	cin >> s;
	}while(s != 0);
	return 0 ;     
}

void search_array(int search)    //defining the search_array function
{
	int j;
	for(j=0;j<n;j++)   //We will check the variable num with all the elements in the array one by one
	{
		if(A[j] == search) //if  at any time num is equal to an element in the array we will print that the element is in the array and break from the loop
		{
		   cout << "Element " << search << " is present in the array\n";
		   break;
	    }
	}
	if(j == n) //since the condition is checked after the 'for' loop is executed if j is still equal to n then we can say that the for loop never breaked 
	{
		cout << "Element " << search << " is not in the array\n"; //thus we print that there is no such element in the array. 
	}
	
}
