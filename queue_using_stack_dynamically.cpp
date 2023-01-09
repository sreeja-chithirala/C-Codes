//  Implement a queue using stacks exploiting Dynamic Memory Allocation.

#include<iostream>
using namespace std;

struct node1  //node1 of the linked list of the stack1
{
	int data;
	node1 * link;
};

struct node2  //node2 of the linked list of the stack2
{
	int data;
	node2 * link;
};

node1 * top1=NULL; //top1 of stack1
node2 * top2=NULL; //top2 of stack2
int count=0;  //to keep the count of number of elements

void push1(int num)   //function to push an element into stack1 similar to inserting the element at the beginning of the linked list
{
	node1 * p = new node1;
	p->data=num;
	p->link=NULL;
			
	if(top1==NULL)
	{
		top1=p;
	}
	else
	{
		p->link=top1;
		top1=p;
	}
}

void push2(int num)  //function to push an element into stack2 similar to inserting the element at the beginning of the linked list
{
	node2 * p = new node2;
	p->data=num;
	p->link=NULL;
			
	if(top2==NULL)
	{
		top2=p;
	}
	else
	{
		p->link=top2;
		top2=p;
	}
}

int pop1()   //popping an element from the stack1 similar to deleting an element from the beginning of the linked list
{
	node1 *t;
    t=top1;
    top1=top1->link;
    t->link=NULL;
    int del=t->data;
    delete t;
    return del;
}

int pop2()  //popping an element from the stack2 similar to deleting an element from the beginning of the linked list
{
	node2 *t;
    t=top2;
    top2=top2->link;
    t->link=NULL;
    int del=t->data;
    delete t;
    return del;
}

//queue is (FIFO) first in first out type of data structure but stack is (LIFO) last in first out datastructure


void enqueue()   //Hence when we want to enqueue an element into the queue since we are using 2 stacks we push the element into the stack1 directly
{
	int num;
	cout << "Enter an element to be enqueued: ";
	cin >> num;
	push1(num);
	count++;
	cout << num << " is inserted.\n";
}

void dequeue()  //while dequeuing we have to delete the element that was first enqueued, which is present at the bottom of the stack we cannot remove it directly
{
	int i,d;
	if(top1==NULL)
	{
		cout << "Queue is empty.\n";
	}
	else   
	{
		for(i=0;i<count;i++)  //so we pop each element from the stack1 and push that into stack2 continuously until the bottom of the stack
		{
			push2(pop1());
		}
		d=pop2();  //now we delete the top of the stack2 which is what we have to dequeue
		cout << d << " is dequeued.\n";
		count--;
		for(i=0;i<count;i++)  //after that we again pop the elements from the stack2 and push them back into the stack1
		{
			push1(pop2());
		}
	}
}

void display()
{
	if(top1==NULL)
	{
		cout << "Queue is empty.\n";
	}
	else
	{
	cout << "The queue is: ";
	node1 *q =top1;
	while(q->link!=NULL)  //then print the queue
	{
		cout << q->data << "->";
		q=q->link; 
	}
	cout << q->data << "\n";
    }
}

int main()
{
	int choice;
	cout << "Queue operations: \n";  //taking the operation to be performed on the queue from the user
	cout << "1.Enqueue an element into queue.\n";
	cout << "2.Dequeue an element from queue.\n";
	cout << "3.Display queue.\n";
	cout << "4.Exit\n";
	do
	{
		cout << "Enter: ";
	    cin >> choice;
	    switch(choice)
	    {
		    case 1: enqueue();
		            break;
	 	    case 2: dequeue();
		            break;
		    case 3: display();
		            break;
		    case 4: cout << "End of program!";
		            break;
	    }
	}while(choice!=4);
    return 0;
}
