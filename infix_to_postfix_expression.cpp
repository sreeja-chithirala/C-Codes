// Write a program to convert an Infix expression to Postfix expression using stack.


#include<iostream>
#include<string>

using namespace std;

string infix,postfix;    //declaring global infix and postfix strings
char st[20];             //declaring the character stack to store operators
int top=-1;              //top points the top of the stack

void push(char item)     //function to push an item into the stack
{
    top++;
    st[top]=item;
}

char pop()              //function to pop an item from the stack
{
    char ch;
    ch=st[top];
    top--;
    return(ch);
}


int priority(char item)         //function to check the priority of the operators
{
	switch(item)
	{
		case '(': return 0;
		case '+':
		case '-': return 1;
		case '*':
		case '/': return 2;
		case '^': return 3;
	}
}

void convert()          //function to convert an infix expression into postfix expression
{
    int i;
    char m;
    for(i=0;i<infix.length();i++)   //now for all the characters in the infix string
    {       
        if(infix[i]>='a' && infix[i]<='z'|| infix[i]>='A'&& infix[i]<='Z'  || infix[i]>='0' && infix[i]<='9')    //if they are alphabets or nummbers        
        {
            postfix.insert(postfix.end(),infix[i]);  //we add them into the postfix string at its end
        }       
        else if(infix[i]=='(')  //if it is an '(' then we push that into stack
        {
            push(infix[i]);
        }        
        else if(infix[i]==')')  //if it is ')' then  
        {
            while(st[top]!='(')  //until we get '('
            { 
				postfix.insert(postfix.end(),pop());   //we will pop all operators from the stack and add them into the postfix string
            }
            m=pop();  //we will pop off  '('  also from the stack 
        }
        else   //if they are other operators then        
        {
            if(top==-1)  //if the stack is empty we push it off into the stack
            {
                push(infix[i]);
            }
            else if(priority(infix[i]) <= priority(st[top])) //otherwise we check the priority of the infix character and character at the top of stack
			{   
                postfix.insert(postfix.end(),pop());  
                while(priority(st[top]) == priority(infix[i]))
				{
                    postfix.insert(postfix.end(),pop());
                    if(top < 0) 
					{
                        break;
                    }
                }
                push(infix[i]);  //the priority of the character to be pushed should be higher than the top of the stack hence we pop off all the characters until that condition and add them into postfix string
            }
            else if(priority(infix[i]) > priority(st[top])) //but if it already greater we directly push them  into the stack
			{
                push(infix[i]);
            }
        }
    }
    while(top!=-1) //after going through the entire string we will check the stack if there are still charcters in it then we pop continuosly and add them into the postfix string
    {
        postfix.insert(postfix.end(),pop());
    }
 
}

int main()
{
    cout << "Enter the infix expression : "; 
    cin >> infix;   //taking the infix expression from the user
    convert();  //calling the convert function
    cout << "The resulting postfix expression is : " <<postfix;
    return 0;
}
