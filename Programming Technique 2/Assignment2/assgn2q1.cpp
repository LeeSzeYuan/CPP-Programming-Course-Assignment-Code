#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Passenger
{
	private:
		string name;
		int age;
	
	public:
		Passenger(string, int);
		void printDetails();
};

Passenger::Passenger(string a, int b)
{
	name = a;
	age = b;
}

void Passenger::printDetails()
{
	cout << "Name:\t" << name << "\tAge:\t" << age;
}

class Kids: public Passenger
{
	private:
		string parentName;
	
	public:
		Kids(string, int, string);
		void printDetails(); 
};

Kids::Kids(string a, int b, string c):Passenger(a, b)
{
	parentName = c;
}

void  Kids::printDetails()
{
	Passenger::printDetails();
	cout << "\tParents Name:\t" << parentName << endl;
}

class Adults:public Passenger
{
	private:
		string job;
	
	public:
		Adults(string, int, string);
		void printDetails(); 
};

Adults::Adults(string a, int b, string c): Passenger(a, b)
{
	job = c;
}

void Adults::printDetails()
{
	Passenger::printDetails();
	cout << "\tJob Title:\t" << job << endl;
}

class Time
{
	private:
		int hour, minute;
	
	public:
		Time(int, int);
		int getHour() const {return hour;}
		int getMinute() const {return minute;}
};

Time::Time(int a, int b)
{
	hour = a;
	minute = b;
}

class Flight
{
	private:
		string id, destination;
		Time *depart;
		Time *arrival;
		Passenger *a;
		vector<Passenger *> passangerList;
		
	public:
		Flight(string, string, Time *, Time *);
		void printInfo();
		
		void addPassenger(Passenger *);
};

Flight::Flight(string a, string b, Time *c, Time *d)
{
	id = a;
	destination = b;
	
	//depart = new Time;
	depart = c;
	//arrival = new Time;
	arrival = d;
}

void Flight::printInfo()
{
	cout << "Flight Number:\t" << id << endl;
	cout << "Destination:\t" << destination << endl;
	
	cout << "Departure:\t" << depart->getHour() << ":";
	if (depart->getMinute()<10)
		cout << "0" << depart->getMinute() << endl;
	else
		cout << depart->getMinute() << endl;
	
	cout << "Arrival:\t" << arrival->getHour() << ":";
	if (arrival->getMinute()<10)
		cout << "0" << arrival->getMinute() << endl;
	else
		cout << arrival->getMinute() << endl;	 
	
	cout << endl;
	cout << "Number of Passengers:\t" << passangerList.size() << endl; 
}

void Flight::addPassenger(Passenger *a)
{
	passangerList.push_back(a);
}


int main()
{
	Time *flying;
	flying = new Time(8, 10);
	Time *landing;
	landing = new Time(9, 0);
	
	Flight a("NAS7921", "Johore Bahru", flying, landing);
	
	Adults Ali("Ali", 34, "lecturer");
	Adults Goh("Goh", 25, "Student");
	Kids Azmi("Azmi", 3, "Ali");
	
	a.addPassenger(&Ali);
	a.addPassenger(&Goh);
	a.addPassenger(&Azmi);
	
	a.printInfo();
	
	cout << "Number of Adults:\t" << 2 << endl;
	cout << "Number of Kids:\t\t" << 1 << endl << endl;
	
	cout << "Passenger Details: " << endl;
	Ali.printDetails();
	Goh.printDetails();
	Azmi.printDetails();
		
	return 0;
}
