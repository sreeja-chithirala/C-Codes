/*
Write a C++ program to implement the Linked List (Insertion, and Deletion) operations using Template. Consider the inputs of different data types to verify the operations.
*/


#include<iostream>
#include<string>
using namespace std;

template <typename T>
struct node     //node for linked list
{
	T data;
	struct node<T>* link;
};

template <typename T>
class LL         //class for linked list
{
	public:
		//start points to the first element of the linked list
		node<T>* start = NULL;
		
		LL()   //constructor
		{
			cout << "LINKED LIST OPERATIONS::\n";
	        cout << "1.Enter element at the beginning.\n";
	        cout << "2.Enter element at the end.\n";
	        cout << "3.Remove first element.\n";
	        cout << "4.Remove  last element.\n";
	        cout << "5.End\n";	       
		}
		
		//function to add the element at the beginning of the linked list
		void add_beg(T num)         
		{
			node<T> * p = new node<T>;
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
			
			node<T> *q =start;
			cout << "LL : ";
			while(q->link!=NULL)
			{
				cout << q->data << "->";
				q=q->link; 
			}
			cout << q->data << "->null.\n";
		}
		
		//function to add the element at the end of linked list
		void add_end(T num)     
		{
			node<T> * t;
			node<T> * p = new node<T>;
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
			
			node<T> *q =start;
			cout << "LL : ";
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
		    node<T> *t;
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
        	
        	if(start!=NULL)
        	{
        	node<T> *q =start;
        	cout << "LL : ";
			while(q->link!=NULL)
			{
				cout << q->data << "->";
				q=q->link; 
			}
			cout << q->data << "->null.\n";
		    }
		}
		
		//function to delete the last element of the linked list
		void del_end()
		{
			node<T> *p,*t;
	        if(start==NULL)
	            cout << "Empty list.\n";
	        else if(start->link==NULL)
	        {
	        	p=start;
	        	cout << p->data << " deleted.\n";
	        	start=NULL;
	        	delete p;
			}
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
	        if(start!=NULL)
	        {
	        node<T> *q =start;
	        cout << "LL : ";
			while(q->link!=NULL)
			{
				cout << q->data << "->";
				q=q->link; 
			}
			cout << q->data << "->null.\n";
		    }
        }			
};

int main()
{
	int choice1,choice2;
	do
	{   //taking the datatype from the user
		cout << "On which datatype would you like to perform the linked list operations: \n";
		cout << "1.int    2.float    3.string   4.Exit\n";
		cout << "Enter the choice: ";
		cin >> choice1;
		switch(choice1)
		{
			case 1: {
				        LL<int> obj;
				        int num;
				        do
				        {
				        	cout << "Enter choice: ";
				            cin >> choice2;
				            switch(choice2)
				            {
				        	    case 1: cout << "Enter the element to be inserted: ";
				        	            cin >>num;
				        	            obj.add_beg(num);
				        	            break;
				        	    case 2: cout << "Enter the element to be inserted: ";
				        	            cin >> num;
				        	            obj.add_end(num);
				        	            break;
				        	    case 3: obj.del_beg();
				        	            break;
				        	    case 4: obj.del_end();
				        	            break;
				        	    case 5: break;
				        	}
						}while(choice2!=5);
			        }
			        break;
		    case 2: {
				        LL<float> obj;
				        float num;
				        do
				        {
				        	cout << "Enter choice: ";
				            cin >> choice2;
				            switch(choice2)
				            {
				        	    case 1: cout << "Enter the element to be inserted: ";
				        	            cin >>num;
				        	            obj.add_beg(num);
				        	            break;
				        	    case 2: cout << "Enter the element to be inserted: ";
				        	            cin >> num;
				        	            obj.add_end(num);
				        	            break;
				        	    case 3: obj.del_beg();
				        	            break;
				        	    case 4: obj.del_end();
				        	            break;
				        	    case 5: break;
				        	}
						}while(choice2!=5);
			        }
			        break;
			case 3: {
				        LL<string> obj;
				        string ele;
				        do
				        {
				        	cout << "Enter choice: ";
				            cin >> choice2;
				            switch(choice2)
				            {
				        	    case 1: cout << "Enter the element to be inserted: ";
				        	            cin >> ele;
				        	            obj.add_beg(ele);
				        	            break;
				        	    case 2: cout << "Enter the element to be inserted: ";
				        	            cin >> ele;
				        	            obj.add_end(ele);
				        	            break;
				        	    case 3: obj.del_beg();
				        	            break;
				        	    case 4: obj.del_end();
				        	            break;
				        	    case 5: break;
				        	}
						}while(choice2!=5);
			        }
			        break;
			case  4: cout << "End of program!";
			         break;
		}
	}while(choice1!=4);
	return 0;
}
