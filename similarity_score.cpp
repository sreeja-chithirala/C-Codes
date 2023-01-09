#include<iostream>
#include<string>
using namespace std;

bool similarity_score(string st1,string st2,double t)   //similarity_score function takes two strings st1,st2 and threshold percentage
{
	int x,i,j,k,count=0;    //initializing the required variables
	int st1count=0;         //count stores the no of words thata are common in two sentences
	int st2count=0;         //st1count & st2count stores the total no of words in the strings st1 & st2 
	double per1,per2;       //per1 & per2 stores the atleast threshold % of the words in st1 that appear in st2 and atleast threshold % of the words in st2 that appear in st1 respectively
	string p;             //string p is used in storing a word 
	
    i=0;	
	while(st1.at(i)!='#')     //this loop is executed to get the no of common words in both strings
	{
		if(i!=0)
		{
			i++;
		}
	    while(st1.at(i)!=' '  &&  st1.at(i)!='#'  &&   st1.at(i)!='.'    &&   st1.at(i)!=',')
	    {
		    p+=st1.at(i);    //st1.at(i) gives the character present at index i in st1.This character is added to the string p which is used to store the word. 
		    i++;
	    }
	    x = st2.find(p);     
		/*we will come out of the loop when the character is ' ' or '#' or '.' or ','.
		Now the string p stores a particular word and find() is used to find whether that word is present in st2 or not.
		x stores the index of the starting letter if the word is present orelse stores -1*/
	    if(x != -1)     
	    {
		    count++;      //if x is no -1 then that word is found and thus count is incremented.
	    }
	    p.erase();     //atlast we erase the word present in string p to store another word later.
	    x=-1;       //updating x to normally store the -1value
    }
    
    
    j=0;
    while(st1.at(j)!='#')    //loop to count no of words in st1
    {
    	if(j!=0)
    	{
    		j++;
		}
    	while(st1.at(j)!=' '  &&    st1.at(j)!='#'   &&    st1.at(j)!='.'   &&   st1.at(j)!=',')
    	{
    		j++;
		}
		st1count++;
	}
	
	
	 k=0;
    while(st2.at(k)!='#')    ///loop to count no of words in st2
    {
    	if(k!=0)
    	{
    		k++;
		}
    	while(st2.at(k)!=' '  &&    st2.at(k)!='#'   &&    st2.at(k)!='.'   &&   st2.at(k)!=',')
    	{
    		k++;
		}
		st2count++;
	}
	
	
	per1=((double)count/st1count)*100;   //calculating the percentage of words in st1 that are similar to st2 
	per2=((double)count/st2count)*100;   //calculating the percentage of words in st2 that are similar to st1
	
	
	
	if(per1>=t && per2>=t)   //if both of them are greater than the given threshold percentage
	{
		return true;         //the method finally returns the true to the calling function
	}
	else
	{
		return false;       //else returns false to the calling function
	}
}

int main()
{
	string  st1,st2;
	bool b;
	double t;
	cout << "Enter two sentences and threshold percentage to know the similarity between the two sentences." << endl;
	cout << "The program is case sensitive"<< endl;
	cout << "Enter the first sentence (Kindly,include # symbol at the end of sentence without any space):\n";  //takes two string from the user
	getline(cin, st1);
	cout << "Enter the second sentence (Kindly,include # symbol at the end of sentence without any space):\n";
	getline(cin, st2);
	cout << "Enter the threshold %: ";   //takes the threshold percentage from the user
	cin >> t;
	b = similarity_score(st1,st2,t);   //calls the similarity_score  function by passing the attributes required
	if(b)   //if the method returns the 'true' its value is 1
	{
		cout << "The similarity_score method returned true" << endl;
		cout << "The two sentences are similar by a threshold percent of " << t ;
	}
	else       //if the method returns 'false' its value is 0
	{
		cout << "The similarity_score method returned false." << endl;
		cout << "The two sentences are not similar by a threshold percent of " << t;
	}
	return 0;
}
