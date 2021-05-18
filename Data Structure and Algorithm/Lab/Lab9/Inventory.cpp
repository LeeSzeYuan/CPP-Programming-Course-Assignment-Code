#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "Inventory.h"
using namespace std;

ifstream inp("inventory.txt");

Inventory::Inventory(){
	strcpy(itemName, "default");
	strcpy(itemKod, "-");
	itemPrice = 0.0;	
	qttyInStock = 0;
	totalEarned = 0;
}

void Inventory::getData(){
	char name[20], kod[20];
	float price;
	char c[2];
	
	inp.getline(name, 19, ',');
	inp.getline(kod, 19, ',');
	inp >> price;
	inp.getline(c, 1, '\n');
	
	strcpy(itemName, name);
	strcpy(itemKod, kod);
	itemPrice = price;
}

void Inventory::buy(int a){
	if (qttyInStock < a){
		cout << "Out of stock!!!" << endl << endl;
		return;
	}
	qttyInStock -= a;
	totalEarned += a*itemPrice;
	
	cout << "We have sell a total of " << a << " of " << itemName << " and earned " << a*itemPrice << " in total" << endl << endl;
}

void Inventory::addStock(){
	int amt;
	cout << "Please enter the amount you want to add in: ";
	cin >> amt;
	
	qttyInStock += amt;
}

void Inventory::discountPrice(int a){
	if (qttyInStock < a){
		cout << "Out of stock!!!" << endl << endl;
		return;
	}
	
	float rate;
	cout << "Please enter the discount rate in percentage(example: 10): ";
	cin >> rate;
	rate /= 100;
	
	qttyInStock -= a;
	totalEarned += a*itemPrice*(1-rate);
	
	cout << "With " << rate*100 << "% discount rate, We have sell a total of " << a << " of " 
		 << itemName << " and earned " << a*itemPrice*(1-rate) << " in total" << endl << endl;
}

void Inventory::printDetail(){
	cout << fixed << setprecision(2);
	cout << left << setw(20) << itemName << "Kod: " << itemKod << "\tPrice: RM" 
		 << itemPrice << "\t\tQuantity: " << qttyInStock << "\tEarned: RM" << totalEarned << endl;
}
