#include <iostream>
#include <fstream>
using namespace std;

void AddData(fstream &);

int main(){
	fstream inout;
	
	AddData(inout);
	
	inout.open("city.txt", ios::in);
	
	if (inout.fail()){
		cout << "File does not exist";
		return 0;
	}
	
	char city[50];
	while(!inout.eof()){
		inout.getline(city, 49);
		cout << city <<endl;
	}
	
	inout.close();
	cout << "Done" << endl;
	
	return 0;
}

void AddData(fstream &a){
	int choice;
	char input[50];
	
	do{
		a.open("city.txt", ios::app);
		cout << "Please enter the name of the city: ";
		
		cin.getline(input, 49);
		
		a << input << endl;
		
		cout << "Do you want to continue? [0-No, 1-Yes]: ";
		cin >> choice;
		cin.ignore();
		
		a.close();
	}while(choice == 1);
	
	cout << endl;
}


