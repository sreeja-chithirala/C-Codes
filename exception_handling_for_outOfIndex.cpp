/*
Write an exception handling programming in C++ to Array out of index operation
*/

#include<iostream>
using namespace std;

int main()
{
	int A[5],choice,i=0;
	do
	{
		try
		{
			if(i==5)
			{
				throw i;
			}
			else
			{
				cout << "Enter the element: ";
				cin >> A[i];
				cout << A[i] << " inserted\n";
				i++;
			}
		}catch(int i)
		{
			cout << "Array index out of range!\n";
		}
		cout << "Would you like to enter another element into the array (1-yes/0-no): ";
		cin >> choice;
	}while(choice!=0);
	return 0;
}
