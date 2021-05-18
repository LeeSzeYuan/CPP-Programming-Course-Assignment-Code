#include <iostream>
#include <string>

using namespace std;

class Contact
{
	private:
		string phone;
	
	public:
		Contact(string);
		string getPhone() const {return phone;}
;
};

Contact::Contact(string a = "")
{
	phone = a;
}

//==============================================================

class Car
{
	private:
		string plate;
	
	public:
		Car(string);
		string getPlate() const {return plate;}
};

Car::Car(string a = "")
{
	plate = a;
}

//==============================================================

class Customer
{
	private:
		string name;
		Car *car;
	
	public:
		Contact cont;
		
		Customer(string, string);
		
		string getName() const {return name;}
		string getPhoneNum() const;
		
		string getplate() const;
		
		void setPlate( Car *);
		//friend ostream &operator<<(ostream &, const Customer &);
};

Customer::Customer(string a = "", string b = ""):cont(b)
{
	name = a;
	car = NULL;
}

string Customer::getPhoneNum() const
{
	return cont.getPhone();
}

string Customer::getplate() const
{
	if (car == NULL) 
		return "";
	else
		return car->getPlate();	
}

void Customer::setPlate( Car *c)
{
	this ->car = c;
}

ostream &operator<<(ostream &out, const Customer &obj)
{
	out << "Customer's Name: " << obj.getName() << endl;
	out << "Phone Number: " << obj.getPhoneNum() << endl;
	out << "Rented Car: " << obj.getplate() << endl;
	return out;
}

//===========================================================================================

int main()
{
	Customer *x;
	x = new Customer[2];
	
	Car rented("JSQ245");
	
	x[0] = Customer("Ahmad Kamal","015-75769800");
	x[1] = Customer("Siti Nurdiana Abdullah","014-8889900");
	
	x[0].setPlate(&rented);
	
	
	for (int i = 0; i < 2; i++)
		cout << x[i] << endl;
		
	delete [] x;

	return 0;
}
