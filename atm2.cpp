/*
Write a program in C++ to store the withdrawal and password changes sequentially (default value as the first node) in the above program using Linked List.


Sample Output for the Above Inputs:


Withdrawal:          10000 -> 2000 -> 3000
Passwd Change:  passwd -> SectionE -> SectionF

*/

#include<iostream>
#include<string>

using namespace std;

struct node1      //declaration of node  for the linked list which stores the withdrawals
{
	long data;
	node1 * link1;
};

struct node2      //declaration of node for the linked list which stores the password changes
{
	string password;
	node2 * link2;
};

class user   //this is a class user
{
	public:
		static node1 * start1 ;   //all these are static variables of the class
		static node2 * start2 ;
		
		static long balance;
	    static string password;
	    
	    static void insert_amount(long withdraw)  //static memeber function to insert the withdrawing amount into the linked list
		{
			node1 * t;
			node1 * p = new node1;
			p->data=withdraw;
			p->link1=NULL;
			
			if(start1==NULL)
			{
				start1=p;
			}
			else
			{
			    t=start1;
		        while(t->link1!=NULL)
		        {
				    t=t->link1;
				}
		        t->link1=p;
			}
		}
		static void insert_password(string password)   //static member function to insert the new password into the list of passwords
		{
			node2 * t;
			node2 * p = new node2;
			p->password=password;
			p->link2=NULL;
			
			if(start2==NULL)
			{
				start2=p;
			}
			else
			{
			    t=start2;
		        while(t->link2!=NULL)
		        {
				    t=t->link2;
				}
		        t->link2=p;
			}
		}
		
	    
		user()    //default constructor of the class user
		{
		    balance=100000;
		    password="sreeja";
		    insert_amount(balance);
		    insert_password(password);
		    cout << "#################################################\n";
	        cout << "*************************************************\n";
	        cout << "#################################################\n";
	        cout << "           WELCOME TO SKH BANK ATM                      \n";
	
	    }
	    
	    user(long withdraw)  //parametrised constructor  for updating balance
	    {
	    	balance=balance-withdraw;
	    	insert_amount(withdraw);
	    	cout << "Please collect your money.\n";
	    }
		
		user(string old_password) //paramatrised constructor for updating the password
		{
			string new_password;
			if(old_password==password)
	    	{
	    	    cout << "Enter your new password: ";
	    	    cin >> new_password;
	    	    password=new_password;
	    	    cout << "Your password was changed successfully\n";
	    	    insert_password(password);
			}
			else
			{
			    cout << "Incorrect old password.Try again\n";
			}
		}
		
		void display_amount()   //function to display the withdrawals history
		{
			node1 *q =start1;
			cout << "History of withdrawals: -> ";
			while(q->link1!=NULL)
			{
				cout << q->data << "->";
				q=q->link1; 
			}
			cout << q->data << "\n";
		}
		
		void display_password()   //function to display the password history
		{
			node2 *q =start2;
			cout << "History of passwords: ->";
			while(q->link2!=NULL)
			{
				cout << q->password << "->";
				q=q->link2; 
			}
			cout << q->password << "\n";
		}
		
		~user()   //destructor
		{
			
		}
};


//definitions of all static member variables
long user::balance=0;
string user::password="sreeja";
node1 * user::start1=NULL;
node2 * user::start2=NULL;



//main function
int main()
{
	user obj1;
	int choice;
	long withdraw;
	string old_password;
	cout << "At the beginning of the program your password is 'sreeja' \n";
	do
	{
		cout << "Hi!. Dear user.\n";
	    cout << "Your account balance is " << obj1.balance << "\n";
	    cout << "Enter '1' for withdrawing amount\n";
	    cout << "Enter '2' for changing password\n";
	    cout << "Enter '3' for checking the history  of withdrawals\n";
	    cout << "Enter '4' for checking the history of passwords\n";
	    cout << "Enter '5' for exit\n";
	    cout << "Enter your choice: ";
	    cin >> choice;
	    switch(choice)
	    {
	    	case 1 : cout << "How much amount you would like to withdraw: ";
	    	         cin >> withdraw;
	    	         {
	    	            user obj2(withdraw);
	    	         }
	    	         break;
	    	case 2 : cout << "Enter your old password: ";
	    	         cin >> old_password;
	    	         {
	    	            user obj3(old_password);
	    	         }
					 break;
			case 3 : obj1.display_amount();
			         break;
			case 4 : obj1.display_password();
			         break;
			case 5 : cout << "Thankyou for using SKH bank\n";
			         cout << "Have a nice day!.\n";
			         break;
		}
    }while(choice!=5);
    return 0;
}
