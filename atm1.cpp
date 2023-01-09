/*
Write a C++ program for ATM withdrawal System without using any function except main(). Please follow the following details.


1.    Declare and initialize two data member variables, namely, balance and passwd.
2.   On executing the program, it should display a Welcome Message.
3.   Thereafter, prompt the user to enter his/her choice of transaction.
a.       Example:   "Enter '1' to withdraw, Enter '2' to change the password, Enter '3' to exit"
4.   On getting the user’s choice as 1: allow the withdrawal and update the balance. Display the updated balance. Return to the choice prompt.
5.   On getting the user’s choice as 2: Ask the user to enter an old password and new password. If the old password entered by the user matches with the stored password, change the password to a new password. Return to the choice prompt.
6.  On getting the user’s choice as 3: Exit from the program.



Sample Input/Output
./a.out  //Program Execution
====================================================
Welcome to My Bank ATM
Your Account Balance is: 10000
====================================================
Enter '1' to withdraw, Enter '2' to change the password, Enter '3' to exit
====================================================
1
Enter the amount you want to withdraw
2000
Thank You for using My ATM, Please Collect Money
Your Updated Balance is: 8000
====================================================
====================================================
Welcome to My Bank ATM
Your Account Balance is: 8000
====================================================
Enter '1' to withdraw, Enter '2' to change the password, Enter '3' to exit
====================================================
1
Enter the amount you want to withdraw
3000
Thank You for using My ATM, Please Collect Money
Your Updated Balance is: 5000
====================================================
====================================================
Welcome to My Bank ATM
Your Account Balance is: 5000
====================================================
Enter '1' to withdraw, Enter '2' to change the password, Enter '3' to exit
====================================================
2
Enter the old Password...
passwd
Enter the new Password...
sectionE
Password Changed Successfully
====================================================
====================================================
Welcome to My Bank ATM
Your Account Balance is: 5000
====================================================
Enter '1' to withdraw, Enter '2' to change the password, Enter '3' to exit
====================================================
2
Enter the old Password...
sectionE
Enter the new Password...
sectionF
Password Changed Successfully
====================================================
====================================================
Welcome to My Bank ATM
Your Account Balance is: 5000
====================================================
Enter '1' to withdraw, Enter '2' to change the password, Enter '3' to exit
====================================================
2
Enter the old Password...
sectionE
Enter the new Password...
sectionG
Password Cannot be changed as the old password entered is wrong.
====================================================
====================================================
Welcome to My Bank ATM
Your Account Balance is: 5000
====================================================
Enter '1' to withdraw, Enter '2' to change the password, Enter '3' to exit
====================================================
3
Thank You, Have a Great Day :)
====================================================


*/

#include<iostream>
#include<string>

using namespace std;

class user       //this is a class user
{
	public:
		static long balance;
	    static string password;
		user()                    //default constructor of the class user
		{
		    balance=100000;
		    password="sreeja";
		    cout << "######################################################\n";
	        cout << "******************************************************\n";
	        cout << "######################################################\n";
	        cout << "                WELCOME TO SKH BANK ATM                      \n";
	
	    }
	    
	    user(long withdraw)      //parametrised constructor  for updating balance
	    {
	    	balance=balance-withdraw;
	    	cout << "Please collect your money.\n";
	    	cout << "The updated balance of your account is " << balance << endl;
	    	cout << "Thankyou for using SKH ATM" << endl;
	    }
		
		user(string old_password)    //paramatrised constructor for updating the password
		{
			string new_password;
			if(old_password==password)
	    	{
	    	    cout << "Enter your new password: ";
	    	    cin >> new_password;
	    	    password=new_password;
	    	    cout << "Your password was changed successfully\n";
			}
			else
			{
			    cout << "Incorrect old password.Try again\n";
			}
		}
		
		~user()   //destructor
		{
			
		}
};


//definitions of all static member variables
long user::balance=0;
string user::password="sreeja";


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
	    cout << "Enter '3' for exit\n";
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
			case 3 : cout << "Thankyou for using SKH bank\n";
			         cout << "Have a nice day!.\n";
			         break;
		}
    }while(choice!=3);
    return 0;
}
