//Implement a stack using Dynamic Memory Allocation.

#include<iostream>
using namespace std;

struct node   //node for the linked list of stack
{
	int data;
	struct node *link;
};

class stack
{
	public:
		node * top = NULL; 
		stack()    //stack constructor
		{
			cout << "STACK OPERATIONS:\n";
		    cout << "1.Push element into stack.\n";
		    cout << "2.Pop element from the stack.\n";
		    cout << "3.Display stack.\n";
		    cout << "4.Exit.\n";
		}
		
		void push(int num)   //pushing an elemnt into the stack is similar to adding element at the beginning of linked list
		{
			node * p = new node;
			p->data=num;
			p->link=NULL;
			
			if(top==NULL)
			{
				top=p;
			}
			else
			{
				p->link=top;
				top=p;
			}
			cout << num << " inserted.\n";
		}
		
		void pop()   //popping an element from the stack is similar to deleting an element at the beginning of linked list
		{
			node *t;
            if(top==NULL)
                cout << "Empty list.\n";
            else
            {
    	        t=top;
    	        top=top->link;
    	        t->link=NULL;
    	        cout << t->data << " deleted.\n";
    	        delete t;
        	}
		}
		
		void display()
		{
			if(top==NULL)
			{
				cout << "Stack is empty.\n";
			}
			else
			{
			cout << "The stack is: ";  //printing stack
        	node *q =top;
			while(q->link!=NULL)
			{
				cout << q->data << "->";
				q=q->link; 
			}
			cout << q->data << "\n";
		    }
		}
};

int main()
{
	int choice;
	stack obj;  //declaring the stack object
	do
	{
		cout << "Enter your choice: ";
		cin >> choice;
		switch(choice)
		{
			case 1: int num;
			        cout << "Enter the element to be pushed: ";
			        cin >> num;
			        obj.push(num);
			        break;
			case 2: obj.pop();
			        break;
			case 3: obj.display();
			        break;
			case 4: cout << "End of program!";
			        break;
		}
	}while(choice!=4);
	return 0;
}
