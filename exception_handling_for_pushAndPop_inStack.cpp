/*
Write a C++ program to implement the PUSH and POP operations of a Stack including exception handling for Overflow and Underflow situations.
*/

#include<iostream>
#define SIZE 5
using namespace std;

int arr[SIZE];
int top=-1;

void push(int num)
{
	try
	{
		if(top==SIZE-1)
		{
			throw top;
		}
		else
		{
			top++;
			arr[top]=num;
			cout << "The stack is: ";
			for(int i=0;i<=top;i++)
			{
				cout << arr[i] << " ";
			}
			cout << "\n"; 
		}
	}catch(int top)
	{
		cout << "Stack overflow!\n";
	}
}

void pop()
{
	try
	{
		if(top==-1)
		{
			throw top;
		}
		else
		{
			cout << arr[top] << " popped.\n";
			top--;
			cout << "The stack is: ";
			if(top!=-1)
			{
			for(int i=0;i<=top;i++)
			{
				cout << arr[i] << " ";
			}
			cout << "\n";
		    }
		}
	}catch(int top)
	{
		cout << "Stack underflow.\n";
	}
}

int main()
{
	int choice,num;
	do
	{
		cout << "1.push   2.pop   3.End\n";
	    cout << "Enter choice: ";
	    cin >> choice;
	    switch(choice)
	    {
	    	case 1: cout << "Enter the element to be pushed: ";
	    	        cin >> num;
	    	        push(num);
	    	        break;
	    	case 2: pop();
	    	        break;
	    	case 3: cout << "End!";
	    	        break;
		}
	}while(choice!=3);
	return 0;
}
