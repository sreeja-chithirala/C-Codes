/*
Write an exception handling programming in C++ to demonstrate divide-by-zero operation (e.g., A/(B-C))
*/

#include<iostream>
using namespace std;

int main()
{
	float a,b,c;
	cout << "Enter a,b,c: ";
	cin >> a >> b >> c;
	try
	{
		if(b-c==0)
		{
			throw (b-c);
		}
		else
		{
			cout << "The value of a/(b-c) is " << a/(b-c);
		}
	}catch(float l){
		
		cout << "a/(b-c) is not defined as b-c=0";
	}
	return 0;
}
