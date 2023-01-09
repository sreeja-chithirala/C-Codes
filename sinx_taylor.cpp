#include<iostream>

using namespace std;

int main()
{
	long a,d,n,i;
        double x,sum,fact,term;
	cout << "Let us calculate the value of sinx using taylor series.\n" ;
	cout << "E(n=0) to (a)   (-1)^n*x^(2n+1)/(2n+1)!\n";
	cout << "On expansion the series is of the form x^1/1! - x^3/3! + x^5/5!  -x^7/7! + x^9/9! .......\n";
	cout << "For that enter a large value of a:";
	cin >> a;
	cout << "Enter value of x(in degrees): ";
	cin >> d;
	//The summation E(n=0) to (a)   (-1)^n*x^(2n+1)/(2n+1)!  is the taylor expansion of sinx.
	//For a particular value of 'a' there will be a+1 terms.
        //The expansion of sin(x) is x^1/1! - x^3/3! + x^5/5!  -x^7/7! + x^9/9! .......
	
	
	x = d*(3.14/180);
	sum = x;  //first term is already added to the sum.
	n=3;  //n is initiated as per the requirement of 2nd term
	term = x;  //term variable is also initiated as per the requirement of the the 2nd term.
	fact = 3*2*1;
	for(i=2;i<=a+1;i++) //the loop will execute 'a' times.In each iteration one term will be added to the variable 'sum'.By the end of 'a' iterations the 'a+1' terms of the expansion will be added.
	{
		if(i%2 != 0)// 'i' value represents ith term of the series.
		{
			sum = sum + (term*x*x)/fact;    // every time x^2 is multiplied to the term as the series is of simalar kind with powers 1,3,5,7....
		}
		else
		{
			sum = sum - (term*x*x)/fact;    
		}
		n=n+2;  //n is updated for the next term
		fact = fact*(n-1)*n;//fact is updated for the next term
		term = term*x*x;//term is also updated for the next term
	}

	cout << "The sum of the series or sin(" << x << "rad) is " << sum;
	return 0;
}
