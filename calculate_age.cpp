#include<iostream>
using namespace std;

class student   //declaring class
{
	int rollno;
	char name[30]; 
	long DOB[3];  //here,DOB[] stores values such that DOB[0]->birthdate  , DOB[1]->birthmonth  ,  DOB[2]->birthyear
	long CD[3];   //here,CD[] stores values such that CD[0]->currentdate  , CD[1]->currentmonth  ,  CD[2]->currentyear
    int totalstudent=0;
	
	public:
		void getdata(void);                   //member functions of class student
		void display(void);
		void getagetoday1(student s);
		void getagetoday2(student *p);
		void getagetoday3(student &s);
		void getcurrentdate(void);
    	void displaytotalstudent(void);
};



void student :: getdata(void)     //function to take the basic data such as of name,rollno &dateofbirth of a student from the user 
{
	cout << "Enter name of the student: ";
	cin >> name;
	cout << "Enter roll.no of the student: ";
	cin >> rollno;
	cout << "Enter the date of birth of student in DD MM YYYY(with spaces): ";
	cin >> DOB[0] >> DOB[1] >> DOB[2];
	totalstudent++;
}




void student :: display(void)     //function to display the details of the recently entered student
{
	cout << "The student's name is " << name << "\n";
	cout << "His/Her roll no is " << rollno << "\n";
	cout << "He/She was born on " << DOB[0] << "-" << DOB[1] << "-" << DOB[2] << "\n" ; 
}



void student :: displaytotalstudent(void)    //function to diplay no of student details entered so far
{
	cout << "The number of student objects instantiated so far is " << totalstudent <<"\n";
}




void student :: getcurrentdate(void)  //function to take the current date from the user to calculate the age
{
	cout << "Enter todays date : ";
	cin >> CD[0] >> CD[1] >> CD[2];
}




void student :: getagetoday1(student s)   //function to display age with call by value
{
	int days,months,years;  //below in the monthcode array we entered no of days in each month of the respective index. 
    int monthcode[12]={31,((s.DOB[2]%4==0&&s.DOB[2]%100!=0||s.DOB[2]%400==0||s.CD[2]%4==0&&s.CD[2]%100!=0||s.CD[2]%400==0)?29:28),31,30,31,30,31,31,30,31,30,31}; 
	
	years=s.CD[2]-s.DOB[2];  //no of years is (currentyear-birthyear)
	
	if(s.DOB[1]>s.CD[1])    //if birthmonth is greater than currentmonth
	{
		years--;     //we less the no of years by 1
		months=12-(s.DOB[1]-s.CD[1]);  //and subtract (birthmonth-currentmonth) from 12
	}
	else           //otherwise it is simply (currentmonth-birthmonth)
	{
		months=s.CD[1]-s.DOB[1];
	}
	
	if(s.DOB[0]>s.CD[0])      //if bithdate is greater than currentdate
	{
		months--;   //we less the no of months by 1
		days=monthcode[s.CD[1]-1] - (s.DOB[0]-s.CD[0]);  //and subtract (birthdate-currentdate) from the days of the current month
	}
	else         //otherwise it is simply (currentdate-birthdate)
	{
		days=s.CD[0]-s.DOB[0];
	}
    
    cout << "In call by value\n";
    cout << "The age of the student is " << years << " years , " << months << " months , " << days << " days.\n";
	
}





void student :: getagetoday2(student *p)   //function to display age with call by reference
{
	int days,months,years;  //below in the monthcode array we entered no of days in each month of the respective index. 
    int monthcode[12]={31,((p->DOB[2]%4==0&&p->DOB[2]%100!=0||p->DOB[2]%400==0||p->CD[2]%4==0&&p->CD[2]%100!=0||p->CD[2]%400==0)?29:28),31,30,31,30,31,31,30,31,30,31}; 
	
	years=p->CD[2]-p->DOB[2];  //no of years is (currentyear-birthyear)
	
	if(p->DOB[1]>p->CD[1])    //if birthmonth is greater than currentmonth
	{
		years--;     //we less the no of years by 1
		months=12-(p->DOB[1]-p->CD[1]);  //and subtract (birthmonth-currentmonth) from 12
	}
	else           //otherwise it is simply (currentmonth-birthmonth)
	{
		months=p->CD[1]-p->DOB[1];
	}
	
	if(p->DOB[0]>p->CD[0])      //if bithdate is greater than currentdate
	{
		months--;   //we less the no of months by 1
		days=monthcode[p->CD[1]-1] - (p->DOB[0]-p->CD[0]);  //and subtract (birthdate-currentdate) from the days of the current month
	}
	else         //otherwise it is simply (currentdate-birthdate)
	{
		days=p->CD[0]-p->DOB[0];
	}
    
    cout << "In call by reference\n";
    cout << "The age of the student is " << years << " years , " << months << " months , " << days << " days.\n";
}





void student :: getagetoday3(student &s)  //function to display age with call by address
{
	int days,months,years;  //below in the monthcode array we entered no of days in each month of the respective index. 
    int monthcode[12]={31,((s.DOB[2]%4==0&&s.DOB[2]%100!=0||s.DOB[2]%400==0||s.CD[2]%4==0&&s.CD[2]%100!=0||s.CD[2]%400==0)?29:28),31,30,31,30,31,31,30,31,30,31}; 
	
	years=s.CD[2]-s.DOB[2];  //no of years is (currentyear-birthyear)
	
	if(s.DOB[1]>s.CD[1])    //if birthmonth is greater than currentmonth
	{
		years--;     //we less the no of years by 1
		months=12-(s.DOB[1]-s.CD[1]);  //and subtract (birthmonth-currentmonth) from 12
	}
	else           //otherwise it is simply (currentmonth-birthmonth)
	{
		months=s.CD[1]-s.DOB[1];
	}
	
	if(s.DOB[0]>s.CD[0])      //if bithdate is greater than currentdate
	{
		months--;   //we less the no of months by 1
		days=monthcode[s.CD[1]-1] - (s.DOB[0]-s.CD[0]);  //and subtract (birthdate-currentdate) from the days of the current month
	}
	else         //otherwise it is simply (currentdate-birthdate)
	{
		days=s.CD[0]-s.DOB[0];
	}
    
    cout << "In call by address\n";
    cout << "The age of the student is " << years << " years , " << months << " months , " << days << " days.\n";
	
}





int main() //main function
{
	int ch;
	student s;
    cout << "Select an option.\n";
    cout << "1.Enter new student details.\n";
    cout << "2.Display the recently entered student details\n";
    cout << "3.Display the recently entered student age.\n";
    cout << "4.No of student objects instantiated so far.\n";
    cout << "5.Exit\n";
	do
	{
		cout << "Enter your choice: ";
	    cin >> ch;
		switch(ch)    //switch to call the functions depending on 'ch'
		{
			case 1 : s.getdata();
			         break;
			case 2 : s.display();
			         break;
			case 3 : s.getcurrentdate();
			         s.getagetoday1(s);
			         s.getagetoday2(&s);
			         s.getagetoday3(s);
			         break;
			case 4 : s.displaytotalstudent();
			         break;
			case 5 : cout <<"End of program!";
			         break;
			         
		}
	}while(ch!=5);
	return 0;
}
