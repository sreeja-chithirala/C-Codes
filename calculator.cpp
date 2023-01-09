/* 
Write the calculator program with inline functions. Your program should support the following operations.
  Addition             (+)
  Multiplication     (*)
  Arithmetic modulo     (%)
  Decimal to Binary     (B)
  Binary to Decimal     (D)
  2’s complement        (2)
 */

#include <iostream>
using namespace std;

inline int add(int n1,int n2)
{
    return n1+n2;   // adds the two numbers and returns it to the calling function
}

inline int mul(int n1,int n2)
{
  return n1*n2;     //multiplies the two numbers and returns it to the calling function
}

inline int mod(int n1,int n2)
{
  return n1%n2;     //returns the modulus of two numbers and returns to the the calling function
}

inline long binary(long num)   //function definition to convert a number into binary format
{
  int i,rem,p,bin=0;
  if(num<0)       //if the num to be converted into binary is -ve
  {
  	p = -num;      // we are storing it in another variable p as -num
  }
  else
  {
  	p=num;       // else simply as num 
  }
  
  for(i=1;p>0;i=i*10)   //loop is executed until p>0
  {                    //Here i is modified as i*10 at every iteration
    rem=p%2;          //storing the remainder upon dividing p with 2 in 'rem'
    p=p/2;            //updating p to the quotient of p upon dividing with 2 
    bin=bin+rem*i;    //bin is the variable that stores the binary format of 'num' in the form of a number.
  }                   //Here we use i*10 because it changes the place value of 'rem'
  
  if(num<0)
  {
  	bin=bin+10*10*10*10*10*10*10; //Finally, if num is -ve adding another 1 in front of the format as its sign bit
  }
  
  return bin;  //Finally return the bin to the calling function.
}

inline int dec(long num)
{
  int dec,b,d;
  dec=0;      //dec is the variable that stores the decimal number of the binary format
  b=1;
  for(b=1;num>0;b=b*2)    //the binary number 110101 can be converted into a decimal by 1*2^5 + 1*2^4 + 0*2^3 + 1*2^2 + 0*2^1 + 1*2^0
  {
  	d=num%10;             //So every time we will take a digit from the binary 'num' using %operator
  	num=num/10;           // and update the 'num' without that digit by dividing it with 10
  	dec=dec+d*b;          //and then muliply that digit with b ,i.e, as 2powers and finally add that to the resulting 'dec'
  }
  return dec;       //return dec
}

inline void comp(long bin)    //We will get a binary number as input 
{
	if(bin==0)  //for the case of 0 we can directly print here and return
	{
		cout << "1's complement of the number is 00000001\n";
		cout << "2's complement of the number is 00000010\n";
		return;
	}
	int A1[10],O[10],T[10],i,j;
	for(i=0;bin>0;i++)    //loop to store each digit of the binary number in an array
	{
		A1[i]=bin%10;   //we get the digit by % operator and stores that in A[i]
		bin=bin/10;      //updating bin as bin/10
	}
	int n=i;    //This 'n' variable stores the number of digits in the binary number or size of the array
	for(i=i-1,j=0;i>=0;i--,j++)
	{
		O[j]=A1[i];     //reversing the array to get its correct form and this is stored in O[]
	}                   //we will leave 0th index of O[] for other purpose
	
	cout << "1's complement of the number is ";
	for(i=0;i<n;i++)
	{
		if(O[i] == 0)            //we will get the 1's complement of a number by interchanging 1's with 0's and 0's with 1's in binary format
		{                        //This can be achieved by this for loop and also simultaneously prints the 1's complement
		   O[i] = 1;
		   cout << O[i];
	    }
		else
		{
		   O[i] = 0;
		   cout << O[i];
	    }
	}
	cout << "\n";     //Now O[] consists of the 1's complement of 'num'
 	
	for (j=n-1;j>=0;j--)   //In getting 2's complement of a number we will go from right to left of the 1's complement 
    {
        if (O[j] == 1)      //we will interchange 1's with 0's in O[i] until we get 0
            O[j] = 0;
        else
        {                   //when we get 0 we will interchange that with 1 and break the loop
            O[j] = 1;
            break;
        }
    }
    
    cout << "2's complement of the number is ";  //now O[] consists of the 2's complement of the number
    for(i=0;i<n;i++)
    {
        cout << O[i];	
	}
	cout << "\n";
}

int main() 
{
  int n1,n2,ch;
  long num,bin;
  cout << "Select an option from the below:\n";
  cout << "1. Add two numbers.\n ";
  cout << "2. Multiply two numbers.\n ";
  cout << "3. Arithmetic modulus of two numbers.\n ";
  cout << "4. Convert a decimal to binary.\n ";
  cout << "5. Convert a binary to decimal.\n ";
  cout << "6. 1's & '2's complement of a number.\n ";
  cout << "7. Exit.\n";
  do
  {
    cout << "Enter your choice: ";   //taking the choice from the user
  	cin >> ch;
  	switch(ch)
  	{
  		case 1 : cout << "Enter two numbers: ";
  		         cin >> n1 >> n2;
  		         cout << "On addition we get " << add(n1,n2) << "\n";
  		         break;
  		case 2 : cout << "Enter two numbers: ";
  		         cin >> n1 >> n2;
  		         cout << "On multiplication we get " << mul(n1,n2) << "\n";
  		         break;
  		case 3 : cout << "Enter two numbers: ";
  		         cin >> n1 >> n2;
  		         cout << "The arithmetic modulus of the two numbers is " << mod(n1,n2) << "\n";
  		         break;
  		case 4 : cout << "Enter a decimal number: ";
  		         cin >> num;
  		         cout << "The binary format of this number is " << binary(num) << "\n";
  		         break;
  		case 5 : cout << "Enter a binary number: ";
  		         cin >> num;
  		         cout << "Its decimal number is: " << dec(num) << "\n";
  		         break;
  		case 6 : cout << "Enter a decimal number to get its complement forms: ";
  		         cin >> num;
  		         bin = binary(num);
  		         comp(bin);
  		         break;
  		case 7 : cout << "End of program!";
  		         break;
	}
  }while(ch!=7);
  return 0;
}
