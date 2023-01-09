/*
Suppose that you want to maintain information about different vehicles. You are supposed to create a base class called Vehicle that comprises two data members make and model. Further, extend the base class to create another two subclasses. One namely ‘Car’ with data members price, seating capacity and fuel type. And another ‘bike’ class with data members cylinders, number of gears, and fuel tank size. Further, create another subclass for Audi having a data member to store the horse power. Next, make a subclass BajajBike having a data member engine power in cc. 
You have to select the best base class in order to extend the derived class. Also demonstrate the object creation from all the derived classes defined in the program.
*/

#include<iostream>
#include<string>
using namespace std;

class vehicle
{
	public:
		string model;
		vehicle()
		{
			cout << "Constructor in vehile class is called!\n";
			cout << "It has attribute model.Enter model: ";
			cin >> model;
		}
		void printdetails()
		{
			cout << "This is vehicle class(first base class)\n";
			cout << "The details of the object are " << model;
		}
};

class car : public vehicle
{
	public:
		long price;
		int seat_capacity;
		string fuel_type;
		car()
		{
			cout << "Constructor in car class is called!\n";
			cout << "It has attributes namely price,seat_capacity & fuel_type\n";
			cout << "Enter price of car: ";
			cin >> price;
			cout << "Enter seat_capacity: ";
			cin >> seat_capacity;
			cout << "Enter fuel_type: ";
			cin >> fuel_type;
		}
		void printdetails()
		{
			cout << "This is car class(second base class derived from vehicle class)\n";
			cout << "The details of the object are "<< model << " " <<  price << " " << seat_capacity << " " << fuel_type  << "\n";  
		}
};

class bike : public vehicle
{
	public:
		int cylinders;
		int gears;
		int fuel_tanksize;
		bike()
		{
			cout << "Constructor in bike class is called\n";
			cout << "It has attributes cylinders,gears,fuel_tanksize\n";
			cout << "Enter no of cylinders: ";
			cin >> cylinders;
			cout << "Enter no of gears: ";
			cin >> gears;
			cout << "Enter the fuel tank size: ";
			cin >>fuel_tanksize;
		}
		void printdetails()
		{
			cout << "This is bike class(second base class derived from vehicle class)\n";
			cout << "The details of the object are "<< model << " " <<  cylinders << " " << gears << " " << fuel_tanksize  << "\n";  
		}
};

class audi : public car
{
	public:
		int horse_power;
		audi()
		{
			cout << "Constructor in audi class is called!\n";
			cout << "It has attribute horse_power.Enter the horse_power: ";
			cin >> horse_power;
	    }
	    void printdetails()
		{
			cout << "This is audi class(derived from car class)\n";
			cout << "It has all the attributes of vehicle and car classes\n";
			cout << "The details of the object are \n";
			cout << "Model: " <<  model << "\nPrice: " <<  price << "\nseat capacity: " << seat_capacity << "\nfuel type: " << fuel_type  <<"\nhorse power: "<< horse_power<< "\n";  
		}
};

class bajajbike : public bike
{
	public:
		int engine_power;
		bajajbike()
		{
			cout << "Constructor in bajajbike class is called\n";
			cout << "It has attribute engine_power.Enter engine_power: ";
			cin >> engine_power;
		}
		void printdetails()
		{
			cout << "This is bajajbike class(derived from bike class)\n";
			cout << "It has all the attributes of vehicle and bike classes\n";
			cout << "The details of the object are \n";
			cout << "Model: "<< model << "\nNo of cylinders: " <<  cylinders << "\nNo of gears: " << gears << "\nfuel tank size: " << fuel_tanksize << "\nengine power: " << engine_power << "\n";  
		}
};


int main()
{
	int choice;
	do
	{
		cout << "Select a vehicle to add its details\n";
	    cout << "1. audi\n"; 
        cout << "2. bajajbike\n";
    	cout << "3. exit\n";
    	cout << "Enter your choice: ";
    	cin >> choice;
    	switch(choice)
    	{
    		case 1: {
			            cout << "audi object is declared!\n";
			            audi A;
			            cout << "printing the details of the object created where the calling function printdetails() is present in both base and derived classes.Due to function overriding the redefined function in derived class will be  called\n";
			            A.printdetails();
    		            break;  
				    }
    		case 2: {
    			        cout << "bajaj bike oblect is declared!\n";
    		            bajajbike B;
    		            cout << "printing the details of the object created where the calling function printdetails() is present in both base and derived classes.Due to function overriding the redefined function in derived class will be  called\n";
			            B.printdetails();
    		            break;
			        }
			case 3: cout << "End of program!";        
		}
	}while(choice!=3);
	
	return 0;
}
