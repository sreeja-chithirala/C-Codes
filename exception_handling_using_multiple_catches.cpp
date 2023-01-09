/*
Write a C++ program to throw multiple exceptions and define multiple catch statements.
*/

#include<iostream>
using namespace std;

int main()
{
	int num;
	do
	{
		cout <<  "1.int 2.float 3.char 4.string 5.end\n";
		cin >> num;
		try
		{
			if(num==1)
			{
				throw (1);
			}
			else if(num==2)
			{
				throw (4.23f);
			}
			else if(num==3)
			{
				throw ('s');
			}
			else if(num==4) 
			{
				throw ("string");
			}
		}
		catch(int n)
		{
			cout << "This is a int catch block!\n";
		}
		catch(float n)
		{
			cout << "This is a float catch block.\n";
		}
		catch(char n)
		{
			cout << "This is a char catch block.\n";
		}
		catch(...)
		{
			cout << "Thhis is catch all block.\n";
		}
	}while(num!=5);
	return 0;
}
