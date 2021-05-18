#include <iostream>
#include <cstring>
#include <fstream>
#include "Account.h"
using namespace std;

Account::Account(){
	strcpy(accountName, "defaultName");
	strcpy(accountNumber, "defaultNumber");
	accountType = 0;
	accountBalance  = 0.0;
}

Account::Account(char A[], char B[] , int C, float D){
	strcpy(accountName, A);
	strcpy(accountNumber, B);
	accountType = C;
	accountBalance  = D;
}

void Account::withdraw(){
	float amt;
	cout << "Please specify the amount you want to withdraw: ";
	cin >> amt;
	
	while (amt > accountBalance || amt < 0){
		cout << "The amount you enter is invalid...Please try again" << endl;
		cout << "Please specify the amount you want to withdraw: ";
		cin >> amt;
	}
	accountBalance -=amt;
	cout << "Amount of " << amt << " has been withdraw from your account" << endl;
}

void Account::deposit(){
	float amt;
	cout << "Please specify the amount you want to deposit: ";
	cin >> amt;
	
	while (amt < 0){
		cout << "The amount you enter is invalid...Please try again" << endl;
		cout << "Please specify the amount you want to deposit: ";
		cin >> amt;
	
	}
	accountBalance +=amt;
	cout << "Amount of " << amt << " has been deposited into your account" << endl;
}

void Account::printDetail(){
	cout << "Account Name:   " << accountName << endl;
	cout << "Account Number: " << accountNumber << endl;
	cout << "Account Type:   " << accountType << endl;
	cout << "Balance:     RM " << accountBalance << endl;
}

