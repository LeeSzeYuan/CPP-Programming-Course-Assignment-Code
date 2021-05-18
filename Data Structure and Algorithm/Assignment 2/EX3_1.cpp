#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int menu();
string file();
void write(string, fstream&);
void read(string, fstream &);

int main(){
	fstream data;
A:
	int option = menu();
	
	if (option == 0){
		cout << "Thanks for using our system!" << endl;
	} else if (option == 2){
		string filename = file();
		write(filename, data);
		data.close();
		
		system("PAUSE");
		system("CLS");
		
		goto A;
	} else if (option == 1){
		string filename = file();
		read(filename, data);
		data.close();
		
		system("PAUSE");
		system("CLS");
		
		goto A;
	} else{
		cout << "Invalid Input! " << endl;
		system("PAUSE");
		system("CLS");
		
		goto A;
	}	
		
	return 0;	
}

int menu(){
	int option;
	cout << "Please choose an option [1-read, 2-write, 0-exit]: ";
	cin >> option;
	
	return option;
}

string file(){
	int option;
	cout << "Please choose the file you like to work on" << endl;
	cout << "1. strings.txt" <<endl;
	cout << "2. symbols.txt" << endl;
	cout << "3. numbers.txt" << endl;
	cout << "option: " ;
	cin >> option;
	
	if (option == 1){
		return "strings.txt";
	} else if (option == 2){
		return "symbols.txt";
	} else if (option == 3){
		return "numbers.txt";
	}
}

void write(string a, fstream &b){
	string data;
	char choice;
	b.open(a.c_str(), ios::out|ios::app);
		
	do {
		cin.ignore();
		cout << "Please enter the data: ";
		getline(cin, data);
		b << data;	
		b << endl;
		
		cout << "Do you want to continue [Y/N]: ";
		cin >> choice;
	} while (choice == 'Y'|| choice =='y');
	
}

void read(string a, fstream &b){
	string data;
	b.open(a.c_str(), ios::in);
	
	cout << "Here is the data inside this file: " << endl;
	cin.ignore();
	getline(b, data);
	
	cout << data << endl;
	while (!b.eof()){
		getline(b, data);
		cout << data << endl;	
	}
}
