#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

struct Stock{
	char name[30];
	float price;
	int quantity;
};

void AddItem();
void DisplayItem();

int menu(){
	int option;
	cout << "1. Add new item in the product file" << endl;
	cout << "2. Display all items" << endl;
	cout << "3. Exit" << endl;
	cout << "Select option: ";
	cin >> option;
	
	return option;
}

int main(){	
A:
	switch(menu()){
		case 1: AddItem();
				system("PAUSE");
				system("CLS");
				goto A;
				break;
		case 2: DisplayItem();
				system("PAUSE");
				system("CLS");
				goto A;
				break;
		default:break;
	}
	
	return 0;
}

void AddItem(){
	fstream db("data.dat", ios::out|ios::binary);
	Stock A;
	char choice;
	
	do{
		cin.ignore();
		cout << endl;
		cout << "<<New Item>>" << endl;
		cout << "Item name: "; cin.getline(A.name, 29);
		cout << "Price per item: RM"; cin >> A.price;
		cout << "Quantity: "; cin >> A.quantity;
		db.write((char *)&A, sizeof(A));
	
		cout << "Do you have more item to add? [Y/N]: "; cin >> choice;
		
	} while (choice == 'y'||choice == 'Y');
	
	db.close();
}


void DisplayItem(){
	Stock A;
	fstream db("data.dat", ios::in|ios::binary);
	fstream file("report.txt", ios::out);
	
	cout << endl;
	if (!db){
		cout << "The file does not exist";
		exit(0);
	} else{
		file << fixed << setprecision(2);
		file << setw(45) << "PRODUCT STOCK REPORT" << endl;
		file << setw(45) << "AiwanShop Enterprise" << endl;
		file << left << setw(5) << "Bil" << setw(20) << "Item Name" <<setw(18) <<  "Price per item" 
			 << setw(13) << "Quantity" << "Total" << endl;
	}
	int i = 1;
	
	while(db.read((char *)&A, sizeof(A))){
		
		file << i <<  setw(4) << "." << setw(26) << A.name 
		 	 << setw(15) << A.price << setw(10) << A.quantity 
		 	 << "RM" << A.price*A.quantity << endl;
		
		i++;
	}
	
	cout << "The report is printed! Please Check the file report.txt" << endl;
	
	db.close();
	file.close();
}
