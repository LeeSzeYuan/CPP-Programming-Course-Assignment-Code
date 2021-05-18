#include <iostream>
#include <fstream>
#include <cstring>
#include "Flight.h"
using namespace std;

int main(){
	//Flight Flight1("Kuching", 150, 120.00, 50); //destination,capacity, ticketprice, no_passenger
	//Flight Flight2;
	//Flight1.checkDetail();
	//Flight2.checkDetail();
	//Flight1.book(20, "senior citizen");//no_passenger, status
	//Flight2.cancel(2);//no_passenger
	
	Flight *Flight1 = new Flight("Kuching", 150, 120.00, 50);

	char st[20];
	int choice, num;
	
	cout << "Welcome to Flight Service"<<endl;
	cout<< "1. To book flight\n2. To cancel flight\n3. Check Detail"<<endl;
	cout << "Choice : " ; 
	
	cin>> choice;
	cout << endl;
	
	switch (choice){
		case 1 :	cout << "The Number of Passenger : " ;
					cin>> num;
					cout << "Status of the Passengers : " ; 
					cin.ignore();
					cin.getline(st,19);
					Flight1->book(num, st);
					
					cout << endl;
					Flight1->checkDetail();
					break;
					
		case 2 :	cout << "The Number of Passenger cancel booking : " ;
					cin>> num;
					Flight1->cancel(num);
					cout << endl;
					Flight1->checkDetail();
					break;
					
		case 3 :	Flight1->checkDetail();
			
		default:	break;
	}

	delete Flight1;
	return 0;
	/*
	Flight Flight1("Kuching", 150, 120.00, 50); //destination,capacity, ticketprice, no_passenger
	Flight Flight2;
	Flight1.checkDetail();
	Flight2.checkDetail();
	Flight1.book(20, "senior citizen");//no_passenger, status
	Flight2.cancel(2);//no_passenger
	
	Flight *Flight3 = new Flight;
	
	int choice, num;
	cout << "Welcome to Flight Service"<<endl;
	cout<< "To book flight please enter 1 \nTo cancel Price please enter 2"<<endl;
	cout << "Choice : " ; 
	cin>> choice;
	
	Flight3->cancel(1);
	Flight3->checkDetail();
	delete Flight3;
	return 0;
	
	*/
}
