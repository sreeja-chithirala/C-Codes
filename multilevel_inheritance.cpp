/*
Write a program in C++ which creates a multilevel inheritance hierarchy of Person, Employee and Teacher classes and creates instances of each class using new and stores them in an array of Person *. The data members and  member functions of each class should be consistent in all the classes.
Person (name, age) →  Employee (name, age, salary) → Teacher (name, age, salary, year_of_experience)
 
       Example: Teacher is a type of Employee and Employee is a type of Person.
 
You have to select the best base class in order to extend the derived class. Also demonstrate the object creation from all the derived classes defined in the program.
*/

#include<iostream>
#include<string>
using namespace std;

class person
{
	public:
		string name;
		int age;
		person()
		{
			cout << "This is person class!\n";
			cout << "Has attributes name,age.\n";
			cout << "Enter name: ";
			cin >> name;
			cout << "Enter age: ";
			cin >> age;
		}
};

class employee: public person    //employee class derived from person class
{
	public:
		long salary;
		employee()
		{
			cout << "This is employee class derived from person class!\n";
			cout << "It has attribute salary.Enter salary: ";
			cin >> salary;
		}
};

class teacher : public employee  //teacher class derived from employee class
{
	public:
		int experience;
		teacher()
		{
			cout << "This is teacher class derived from employee class!\n";
			cout << "Has attribute experience.Enter the year of experience of teacher: ";
			cin >> experience;
		}
		void printdetails()
		{
			cout << "Name: " << name << "\nAge: " << age << "\nSalary: " << salary << "\nExperience: " << experience << "\n";
		}
};


int main()
{
	int choice,i=0;
	teacher * p[20];
	do
	{
		cout << "teacher object created!\n";
		p[i]=new teacher;
		i++;
		cout << "Do you want to enter another teacher details(yes-1/no-0).Enter: ";
		cin >> choice;	
	}while(choice!=0);
	cout << "\n";
	cout << "Entered teacher details are:\n";
	cout << "\n";
	for(int j=0;j<i;j++)
	{
		p[j]->printdetails();
		cout << "\n";
	}
	return 0;
}
