/*
Write a C++ program to implement the Stack (PUSH and POP) operations using Template. Consider the inputs of different data types (e.g.: integer, float, string, etc.) to verify the functionalities.
*/


#include<iostream>
#include<string>
using namespace std;

template<class T>
class stack     //stack class
{
	public:
		T st[100];     //depending upon the datatype a stack array is declared 
		int top;
		stack()     //constructor
		{
			top=-1;
			cout << "STACK OPERATIONS:\n";
		    cout << "1.Push element into stack.\n";
		    cout << "2.Pop element from the stack.\n";
		    cout << "3.Display stack.\n";
		    cout << "4.Exit.\n";
		}
		void push()    //inserting an element into the stack
		{
			T element;
			cout << "Enter the element to be pushed: ";
			cin >> element;
			top++;
			st[top]=element;
			cout << element << " pushed.\n";
		}
		void pop()     //deleting an element from the stack
		{
			if(top==-1)
			{
				cout << "stack is empty!.\n";
			}
			else
			{
				cout << st[top] << " popped.\n";
				top--;
			}
		}
		void display()   //displaying the stack
		{
			int i;
			if(top==-1)
			{
				cout << "stack is empty!.\n";
			}
			else
			{
			    cout << "The stack is: ";
			    for(i=top;i>=0;i--)
			    {
				    cout << st[i];
				    if(i)
				    {
				    	cout << "->";
					}
			    }
			   cout << "\n";	
			}
		}
};

int main()
{
	int choice1,choice2;
	do
	{   //taking the datatype from the user
		cout << "On which datatype would you like to perform the stack operations: \n";
		cout << "1.int    2.float    3.string   4.Exit\n";
		cout << "Enter the choice: ";
		cin >> choice1;
		switch(choice1)
		{
			case 1: {
			            stack <int> obj;   //declaring the stack obj
			            do
			            {
			                cout << "Enter: ";
			                cin >> choice2;
					        switch(choice2)
					        {
					            case 1: obj.push();
			                            break;
			                    case 2: obj.pop();
			                            break;
		            	        case 3: obj.display();
			                            break;
			                    case 4: break;		 
					        }
				        }while(choice2!=4);
				    }
				    break;
			case 2: {
			            stack <float> obj;
			            do
			            {
			                cout << "Enter: ";
			                cin >> choice2;
					        switch(choice2)
					        {
					            case 1: obj.push();
			                            break;
			                    case 2: obj.pop();
			                            break;
		            	        case 3: obj.display();
			                            break;
			                    case 4: break;		 
					        }
				        }while(choice2!=4);
				    }
				    break;
			case 3: {
			            stack <string> obj;
			            do
			            {
			                cout << "Enter: ";
			                cin >> choice2;
					        switch(choice2)
					        {
					            case 1: obj.push();
			                            break;
			                    case 2: obj.pop();
			                            break;
		            	        case 3: obj.display();
			                            break;
			                    case 4: break;		 
					        }
				        }while(choice2!=4);
				    }
				    break;
			case 4: cout << "End of program!";
			        break;
		}
	}while(choice1!=4);
	return 0;
}
