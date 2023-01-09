/*
Write a program in C++ to create a class with a method using constructor and destructor. The method has to decide whether a given year is a leap year or not.

Note- A year is a leap year if: 
• It has an extra day i.e. 366 instead of 365. 
•It occurs every 4 year e.g. 2008, 2012 are leap years. 
• For every 100 years a special rule applies-1900 is not a leap year but 2000 is a leap year. In those cases, we need to check whether it is divisible by 400 or not.
*/

#include<iostream>
using namespace std;

int num;
class year            //class year
{
	public:
		year()         //constructor for year
		{
			cout << "In constructor:\n";
			cout << "object for checking whether an year is leap or not is created!\n";
			num=0;
			cout << "Enter an year : ";
	        cin >> num;
	        find(num);
		}
		
		void find(int num)  //function to find whether an year is leap year or not (A leap year has 365+1 days)
		{
			if(num%4==0)
			{
				if(num%100==0)
				{
					if(num%400==0)
					{
						cout << num << " is a leap year!\n";
					}
					else
					{
						cout << num << " is not a leap year!\n";
					}
				}
				else
				{
					cout << num << " is a leap year!\n";
				}
			}
			else
			{
				cout << num << " is not a leap year!\n";
			}
		}
		
		~year()               //destructor of year
		{
			cout << "In destructor:\n";
			cout << "objects memory is deleted!\n";
		}
};

int main()
{
	int choice,num;
	do
	{
		{      
	        year A;        //object is declared and goes to the constructor function
	    }                  //when closed brace is found it goes to the destructor function
		cout << "Do you want to enter another year(1-yes//0-no): ";
		cin >> choice;
	}while(choice!=0);
	cout << "End!";
}
