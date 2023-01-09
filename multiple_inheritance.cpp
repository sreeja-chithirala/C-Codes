/*
Write a program in C++ which creates a multiple inheritance hierarchy of Teacher classes derived from both Person, Employee classes. Each class must implement a Show() member function and utilize scope resolution operators.
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
			cout << "Enter name: ";
			cin >> name;
			cout << "Enter age: ";
			cin >> age;
		}
		void show()
		{
			cout << "This is a person class.It has attributes name and age!\n";
			cout << "Name: " << name << "\nAge: "<< age <<"\n";
		}
};

class employee
{
	public:
		long salary;
		employee()
		{
			cout << "Enter salary: ";
			cin >> salary;
		}
		void show()
		{
			cout << "This is a employee class.It has attribute salary!\n";
			cout << "Salary: "<< salary << "\n";
		}
};

class teacher: public person , public employee
{
	public:
		int experience;
		teacher()
		{
			cout << "Enter experience: ";
			cin >> experience;
		}
		void show()
		{
			cout << "This is teacher class derived from both person class and employee class.It has attribute experience.!\n";
			cout << "Experience: " << experience << "\n";
		}
};

int main()
{
	teacher T;
	T.person::show();     //goes to the show function in person class
	T.employee::show();    //goes to the show function in employee class
	T.show();              //goes to the show function in teacher class
	return 0;
}
