//Create a class with two functions-one recursive and one non recursive. Either of these function should be capable of calculating the factorial of a number.

#include<iostream>
using namespace std;

class fact               //class fact
{
	int num;
	public:
		fact()             //constructor
		{
			long a1,a2;
			cout << "Enter a number: ";
			cin >> num;
			a1=fac(num);
			cout << "From non-recursive function:\n";
			cout << "Factorial of " << num << " is " << a1 << "\n"; 
			a2=rec_fac(num);
			cout << "From recursive function:\n";
			cout << "Factorial of " << num << " is " << a2 << "\n"; 
		}
		long fac(int num)         //non-recursive function to calculate the factorial 
		{
			long i,ans=1;
			for(i=2;i<=num;i++)
			{
				ans=ans*i;
			}
		    return ans;
		}
		long rec_fac(int num)      //recursive function to calculate the factorial
		{
			if(num==1)
			   return 1;
			else
			   return num*rec_fac(num-1);
		}
};

int main()
{
	int choice;
	do
	{
		fact f;             //declaring an object f of class fact
		cout << "Do you want to enter another number(1-yes/0-no): ";
		cin >> choice;
	}while(choice!=0);
	cout << "End!";
}
