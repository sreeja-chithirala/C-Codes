/*Two strings are anagram of each other, if we can rearrange characters of one string to form another string. All the characters of one string must be present in another string and should appear same number of time in other string. The strings can contain any ASCII characters.
Example: rescued and secured, resign and singer, stone and tones, pears and spare, ELEVEN PLUS TWO and TWELVE PLUS ONE. 
    Write a program using functions, two check if two strings are anagram of each other. 

  Note: Your program should work well for strings of any length.
*/

#include<iostream>
#include<string>

using namespace std;


bool are_anagram(string st1,string st2)    //function are_anagram definition
{
	int i,j,temp;  //declaring the variables required
	string p,q;     
	 
    for(i=0;i<st1.length();i++)    //this loop is for removing the spaces in the string(if any).Because no of spaces in strings don't effect in determining whether they are anagrams or not.They can be equal or not equal in the strings
    {
    	if(st1.at(i)==' ')   //if we encounter a space the loop will continue orelse it is copied into the string p
    	{
    		continue;
		}
		else
		{
			p+=st1.at(i);
		}
	}
	st1=p;  //modifing the st1 with p


	for(j=0;j<st2.length();j++)  //same with the case of st2
    {
    	if(st2.at(j)==' ')
    	{
    		continue;
		}
		else
		{
			q+=st2.at(j);
		}
	}
	st2=q;

	
	
	if(st1.length() != st2.length())   //now if the length of both the strings is not equal,then there is no chance that they can be anagrams of eachother
	{
		return false;   //hence we return false
	}


	//if the lengths of both the strings are equal we will sort the characters in the strings based on their askii values
	
	for (i=0;i<st1.length();i++)          //by bubble sort method we will sort the characters in the strings
	{
	  for (j=0;j<(st1.length())-1;j++)
	  {
        if (st1.at(j) > st1.at(j + 1))
		{ 
		    temp = st1.at(j);
            st1.at(j) = st1.at(j+1);
            st1.at(j+1) = temp;
        }
      }
    }
    
    for (i=0;i<st2.length();i++)
	{
	  for (j=0;j<(st2.length())-1;j++)
	  {
        if (st2.at(j) > st2.at(j + 1))
		{ 
		    temp = st2.at(j);
            st2.at(j) = st2.at(j+1);
            st2.at(j+1) = temp;
        }
      }
    }
 
	
	if(st1==st2)              //after sorting if the strings are equal then we return true
	{
		return true;
	}
	else
	{
		return false;        //else return false
	}
	
	
}


int main()
{
	string st1,st2;
	bool b;
	cout << "Enter two strings to find whether they are anagrams.\n";  //taking two strings from the user
	cout << "Enter string 1(can be a word or a phrase): ";
	getline(cin,st1);
	cout  << "Enter string 2(can be a word or a phrase): ";
	getline(cin,st2);
	b = are_anagram(st1,st2);   //calling the function are_anagram to check whether the strings are anagrams or not
	if(b) //the return value will be boolean 
	{
		cout << "the two strings are anagram of eachother.";
	}
	else
	{
		cout << "the two strings are not anagram of eachother.";
	}
	return 0;
}
