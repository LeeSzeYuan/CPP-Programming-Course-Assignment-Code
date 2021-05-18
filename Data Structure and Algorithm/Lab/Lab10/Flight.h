#ifndef FLIGHT_H
#define FLIGHT_H

class Flight{
	private:
		char destination [20];
		int no_Passenger;
		int capacity;
		char status[20];
		float ticketPrice;
		float totalPayment;
		
	public:
		Flight();
		Flight(char *, int, float, int);
		void book(int, char[]);
		void cancel(int);
		void checkDetail();
};

#endif
