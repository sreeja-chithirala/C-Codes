#include<iostream>
using namespace std;

int factorial(int); //declaring the factorial function

int main()
{
	int num,m,f;  //declaring variables
	do
	{
	cout << "Enter the element to get its factorial: ";
	cin >> num;
	f=factorial(num); //calling the factorial function by passing the number
	cout << "factorial of " << num << " is " << f << "\n"; 
	cout << "Do you want to find the factorial of another number(1-yes/0-no): ";
	cin >> m;
    }while(m!=0);
    return 0;
}

int factorial(int f) //defining the factorial function
{
	if(f==0)
	  return(1);   //factorial of n is n*(n-1)*(n-2).........3*2*1
	else
	  return(f*factorial(f-1)); //using this recursion method we can find the factorial
}
