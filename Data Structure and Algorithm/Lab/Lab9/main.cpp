#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "Inventory.h"
using namespace std;

int main(){
	int item, choice, amt;
	
	Inventory List[5];	
	for (int i = 0; i<5; i++){
		List[i].getData();
	}	
	
start:
	cout << "List of item" << endl;
	for (int i = 0; i<5; i++){
		cout << i+1 << ". " ; 
		List[i].printDetail();
	}
	
	cout << endl << "Please choose a item you want [0: for exit]: "; cin >> item;
	
	if (item == 0){
		cout << "Thanks you for using our system" << endl;
		return 0;
	}
	
	system ("CLS");
menu:	
	cout << "Currently selected: " << endl << item << ". "; 
	List[item-1].printDetail();
	
	cout << endl << "Menu" << endl;
	cout << "1. Purchase item" << endl
		 << "2. Purchase item with discount" << endl
		 << "3. Refill stock" << endl
		 << "4. Print detail" << endl
		 << "5. select other item" << endl
		 << "6. Exit the system" << endl << endl;
		 
	cout << "Enter your choice: ";
	cin >> choice;

	
	switch(choice){
		case 1: cout << "Please enter the amount you want to buy: ";cin >> amt;
				List[item-1].buy(amt);
				system("pause");
				system ("CLS");
				goto menu;
				break;
				
		case 2: cout << "Please enter the amount you want to buy: ";cin >> amt;
				List[item-1].discountPrice(amt); 
				system("pause");
				system ("CLS");
				goto menu;
				break;
				
		case 3: List[item-1].addStock();
				cout << "Stock refilled" << endl << endl;
				system("pause");
				system ("CLS");
				goto menu;
				break;
		case 4: cout << "The detail of this product" << endl;
				List[item-1].printDetail();
				cout << endl;
				system("pause");
				system ("CLS");
				goto menu;
				break;
				
		case 5: system ("CLS");
				goto start;
				
		case 6: cout << "Thank you for using our system" << endl;
				break;
	}
	
	
	return 0;
}
