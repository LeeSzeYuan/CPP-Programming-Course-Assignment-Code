#include <iostream>
#include <fstream>
#include <cstring>
#include "Flight.h"
using namespace std;

Flight::Flight(char *a = "Malaysia", int b=200, float c=50.00, int d=20){
	strcpy(destination, a);
	capacity = b;
	ticketPrice = c;
	no_Passenger = d;
}

void Flight::book(int a, char b[]){
	no_Passenger += a;
	if (no_Passenger<=capacity){
		
		if (strcmp(b, "senior Citizen") == 0)
			totalPayment += a*ticketPrice*0.5;
		 else
			totalPayment += a*ticketPrice;
			
		cout << "No of passenger updated!" << endl;	
		
	} else {
		
		no_Passenger -= a;
		cout << "Capacity exceeded!" << endl;	
		
	}
}

void Flight::cancel(int a){
	no_Passenger -= a;
	
	cout << "A total of " << 0.5*ticketPrice*a << " is refunded" << endl;
	totalPayment -= 0.5*ticketPrice*a;
}

void Flight::checkDetail(){
	cout << "Flight Detail: \n" << "Destination: " <<  destination 
		 << "\tTicket Price: RM" << ticketPrice << "\tCapacity: " << capacity
		 << "\tCurrent No of Passenger: " << no_Passenger << endl;
}
