/*
Write a C++ program to implement a linked list with the following operations:
Case S/ C: Singly/Circular Linked List
I - check for empty condition
AF O - adds first element O
AL O - adds last element O
RF - removes the first element
RL - removes the last element
L - returns the last element in the list
F - returns the first element in the list
REV - reverses the linked list
*/
#include<iostream>
using namespace std;

struct node      //declaration of the node for the linked list
{
	int data;
	node * link;
};

class LL         //class linked list
{
	public:
        node* start=NULL;
       //start points to the first element of the linked list
		
		//function to check whether the list is empty or not
		void check_empty()          
        {
	        if(start==NULL)
	        {
		        cout << "true,empty\n";
	        }
	        else
	        {
		        cout << "false,not empty\n";
	        }
        }
		
		//function to add the element at the beginning of the linked list
		void add_beg(int num)         
		{
			node * p = new node;
			p->data=num;
			p->link=NULL;
			
			if(start==NULL)
			{
				start=p;
			}
			else
			{
				p->link=start;
				start=p;
			}
			
			node *q =start;
			while(q->link!=NULL)
			{
				cout << q->data << "->";
				q=q->link; 
			}
			cout << q->data << "->null.\n";
		}
		
		
		//function to add the element at the end of linked list
		void add_end(int num)     
		{
			node * t;
			node * p = new node;
			p->data=num;
			p->link=NULL;
			
			if(start==NULL)
			{
				start=p;
			}
			else
			{
			    t=start;
		        while(t->link!=NULL)
		        {
				    t=t->link;
				}
		        t->link=p;
			}
			
			node *q =start;
			while(q->link!=NULL)
			{
				cout << q->data << "->";
				q=q->link; 
			}
			cout << q->data << "->null.\n";
		}
		
		//function to delete the first element of the linked list
		void del_beg()
		{
		    node *t;
            if(start==NULL)
                cout << "Empty list.\n";
            else
            {
    	        t=start;
    	        start=start->link;
    	        t->link=NULL;
    	        cout << t->data << " deleted.\n";
    	        delete t;
        	}
        	
        	node *q =start;
			while(q->link!=NULL)
			{
				cout << q->data << "->";
				q=q->link; 
			}
			cout << q->data << "->null.\n";
		}
		
		//function to delete the last element of the linked list
		void del_end()
		{
			node *p,*t;
	        if(start==NULL)
	            cout << "Empty list.\n";
	        else
	        {
		        t=start;
		        while(t->link->link!=NULL)
		        {
			        t=t->link;
		        }
		        p=t->link;
		        t->link=NULL;
		        cout << p->data << " deleted.\n";
		        delete p;		
	        }
	        
	        node *q =start;
			while(q->link!=NULL)
			{
				cout << q->data << "->";
				q=q->link; 
			}
			cout << q->data << "->null.\n";
        }
        
        //function to return the first element
        int first()
        {
        	node *q;
        	q=start;
        	return q->data;
		}
		
		//function to return the last element 
        int last()
        {
        	node *p;
        	p=start;
        	while(p->link!=NULL)
        	{
        		p=p->link;
			}
			return p->data;
		}
		
	    //function to reverse the linked list
		void rev()
		{
		    node *prev,*curr,*next;
			curr = start;
			prev=NULL;
			next=NULL;
			while(curr!=NULL)
			{
			 	next=curr->link;
			 	curr->link=prev;
			 	prev=curr;
			 	curr=next;
			}
			start=prev;
			
			cout << "On reversing the linked list ";
			node *q =start;
			while(q->link!=NULL)
			{
				cout << q->data << "->";
				q=q->link; 
			}
			cout << q->data << "->null.\n";	
		}
};


class CL   //class circular linked list
{
	public:

		node * start = NULL;        //start points to the first element of the linked list
		
		//function to check whether the circular list is empty or not
		void check_empty()
        {
        	node *k;
	        if(start==NULL)
	        {
		        cout << "true\n";
	        }
	        else
	        {
		        cout << "false\n";
	        }
        }
		
		//function to add the element at the beginning of the circular linked list
		void add_beg(int num)
		{
			node * p = new node;
			p->data=num;
			p->link=NULL;
			
			if(start==NULL)
			{
				start=p;
				p->link=start;
			}
			else
			{
				node *t = start;
				while(t->link!=start)
				{
					t=t->link;
				}
				p->link=start;
				t->link=p;
				start=p;
			}
			
			node *q =start;
			while(q->link!=start)
			{
				cout << q->data << "->";
				q=q->link; 
			}
			cout << q->data << "->again " << start->data << "\n";
		}
		
		//function to add the element at the end of the circular linked list
		void add_end(int num)
		{
			node * t;
			node * p = new node;
			p->data=num;
			p->link=NULL;
			
			if(start==NULL)
			{
				start=p;
				p->link=start;
			}
			else
			{
			    t=start;
		        while(t->link!=start)
		        {
				    t=t->link;
				}
		        t->link=p;
		        p->link=start;
			}
			
			node *q =start;
			while(q->link!=start)
			{
				cout << q->data << "->";
				q=q->link; 
			}
			cout << q->data << "->again " << start->data << "\n";
		}
		
		//function to delete the first element of the circular linked list
		void del_beg()
		{
		    node *temp,*t;
            if(start==NULL)
                cout << "Empty list.\n";
            else
            {
    	        t=start;
    	        while(t->link!=start)
    	        {
    	        	t=t->link;
    	        }
    	        temp=start;
				start=start->link;
    	        t->link=start;
    	        temp->link=NULL;
    	        cout << temp->data << " deleted.\n";
    	        delete temp;
        	}
        	node *q =start;
			while(q->link!=start)
			{
				cout << q->data << "->";
				q=q->link; 
			}
			cout << q->data << "->again " << start->data << "\n";
        	
		}
		
		//function to delete the last element of the circular linked list
		void del_end()
		{
			node *p,*t;
	        if(start==NULL)
	            cout << "Empty list.\n";
	        else
	        {
		        t=start;
		        while(t->link->link!=start)
		        {
			        t=t->link;
		        }
		        p=t->link;
		        p->link=NULL;
		        t->link=start;
		        cout << p->data << " deleted.\n";
		        delete p;		
	        }
	        
	        node *q =start;
			while(q->link!=start)
			{
				cout << q->data << "->";
				q=q->link; 
			}
			cout << q->data << "->again " << start->data << "\n";
        }
        
        //function to return the first element of the circular linked list
        int first()
        {
        	node *q;
        	q=start;
        	return q->data;
		}
		
		//function to return the last element of circular linked list
        int last()
        {
        	node *p;
        	p=start;
        	while(p->link!=start)
        	{
        		p=p->link;
			}
			return p->data;
		}
		
		//function to reverse the circular linked list
		void rev()
		{
		    node *prev,*curr,*next;
			curr = start;
			prev=NULL;
			do
			{
			 	next=curr->link;
			 	curr->link=prev;
			 	prev=curr;
			 	curr=next;
			}while(curr!=start);
			start->link=prev;
			start=prev;
			
			cout << "On reversing the circular linked list ";
			node *q =start;
			while(q->link!=start)
			{
				cout << q->data << "->";
				q=q->link; 
			}
			cout << q->data << "->again " << start->data << "\n";
		}
};






int main()
{
	int choice1,choice2,num,item;
	do
	{
	cout << "Select an option:\n";
	cout << "1.Perform operations on linked list\n";
	cout << "2.Perform operations on circular linked list\n";
	cout << "3.exit.\n";
	cout << "Enter the choice : ";
	cin >> choice1;
	LL obj1;   //declaring the objects of the class lists
	CL obj2;
	
	switch(choice1)
	{
		case 1 :
			cout << "LINKED LIST OPERATIONS::\n";
	        cout << "1.Check for the empty condition.\n";
	        cout << "2.Enter element at the beginning.\n";
	        cout << "3.Enter element at the end.\n";
	        cout << "4.Remove first element.\n";
	        cout << "5.Remove  last element.\n";
	        cout << "6.Return first element.\n";
	        cout << "7.Return last element.\n";
	        cout << "8.Reverse linked list.\n";
	        cout << "9.End\n";	       
	        do
	        {
	        cout << "Choice: ";	
	        cin >> choice2;
	        switch(choice2)
	        {
		        case 1: obj1.check_empty();
				        break;
		        case 2: cout << "Enter the value: ";
		                cin >> num;
		                obj1.add_beg(num);
				        break;
		        case 3: cout << "Enter the value: ";
		                cin >> num;
		                obj1.add_end(num);
				        break;
		        case 4: obj1.del_beg();
				        break;
		        case 5: obj1.del_end();
				        break;
		        case 6: item=obj1.first();
		                cout << item << " is the first element.\n";
				        break;
		        case 7: item=obj1.last();
		                cout << item << " is the last element.\n";
				        break;
		        case 8: obj1.rev();
				        break;
		        case 9: cout << "End of linked list operations.\n";
		                break;
	        }
	        }while(choice2!=9);
	        break;
	        
	        
	    case 2 :
	    	cout << "CIRCULAR LINKED LIST OPERATIONS::\n";
	        cout << "1.Check for the empty condition.\n";
	        cout << "2.Enter element at the beginning.\n";
	        cout << "3.Enter element at the end.\n";
	        cout << "4.Remove first element.\n";
	        cout << "5.Remove  last element.\n";
	        cout << "6.Return the last element.\n";
	        cout << "7.Return first element.\n";
	        cout << "8.Reverse circular linked list.\n";
	        cout << "9.End.\n";	       
	        do
	        {
	        cout << "Choice: ";	
	        cin >> choice2;
	        switch(choice2)
	        {
		        case 1: obj1.check_empty();
				        break;
		        case 2: cout << "Enter the value: ";
		                cin >> num;
		                obj2.add_beg(num);
				        break;
		        case 3: cout << "Enter the value: ";
		                cin >> num;
		                obj2.add_end(num);
				        break;
		        case 4: obj2.del_beg();
				        break;
		        case 5: obj2.del_end();
				        break;
		        case 6: item=obj2.first();
		                cout << item << " is the first element.\n";
				        break;
		        case 7: item=obj2.last();
		                cout << item << " is the last element.\n";
				        break;
		        case 8: obj2.rev();
				        break;
		        case 9: cout << "End of circular linked list operations.\n";
		                break;
	        }
	        }while(choice2!=9);
	        break;
	        
	        
	    case 3 : 
		    cout << "End of program!";
	        break;
	}
	}while(choice1!=3);
}
