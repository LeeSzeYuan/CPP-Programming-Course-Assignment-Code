#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#define SIZE 40

class Address
{
	private:
		string registrar;
		string country;
	
	public:
		Address();
		void set(string, string);
		string getRegistrar()const{return registrar;}
		string getCountry()const{return country;}
};

Address::Address()
{
	registrar.assign("NULL");
	country.assign("NULL");
}

void Address::set(string a, string b)
{
	registrar.assign(a);
	country.assign(b);
}

class Ship
{
	private:
		string name;
		string yearMade;
		Address *address;
		
	public:
		Ship();
		void print();
		void read();	
};

Ship::Ship()
{
	name.assign("NULL");
	yearMade.assign("NULL");
	address = new Address;
	address->set("NULL", "NULL");
}

void Ship::print()
{
	cout << "Ship Name: " << name << endl;
	cout << "Year Built: " << yearMade << endl;
	cout << "Registered at:" << endl << left << setw(2) << " "
		 << address->getRegistrar() << ", " << address->getCountry() << endl;
}

void Ship::read()
{
	string a, b;
	cout << "Ship Name: "; getline(cin, name);
	cout << "Year Built: "; getline(cin, yearMade);
	
	cout << "The address the ship was registered:" << endl;
	cout << "Registrar Office: "; getline(cin, a);
	cout << "Country: "; getline(cin, b);
	
	address->set(a, b);
}

int main()
{
	int choice, num=0;
	
	Ship *list;
	list = new Ship[SIZE];
	
	do
	{
		cout << "======= MENU =======" << endl
			 << "1. Add a ship" << endl
			 << "2. Dislay ship" << endl
			 << "3. Exit" << endl << endl;
		
		cout << "Choose an operation => ";
		cin >> choice;
		cin.ignore();
		cout << endl;
		
		if (choice == 1)
		{
			cout << "<<< Enter the information of the ship >>>" << endl << endl;
			list[num].read();
			num++;
		}
		else if (choice == 2)
		{
			cout << "<<< Inventory of Ship >>>" << endl << endl;
			cout << "Total ship: " << num << endl << endl;
			cout << "==== Ship List ====" << endl << endl;
			
			for(int i = 0; i < num; i++)
			{
				list[i].print();
				cout << endl;
			}
		}
		else if (choice == 3)
		{
			return 0;
		}
		else
		{
			cout << "Invalid Input! Please try again" << endl << endl;
			continue;
		}
		
		cout << endl << "Press any key to continue . . ." << endl;
		cin.get();
	
	}while(choice != 3);
	
	delete [] list;
	
	return 0;
}
