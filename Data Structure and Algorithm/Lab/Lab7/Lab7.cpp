#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

class Account{
	private:
		char accountName[20];
		char accountNumber[20];
		int accountType;
		float accountBalance;
	
	public:
		Account();
		Account(char [], char [], int, float);
		float getBalance() {return accountBalance;}
		void withdraw();
		void deposit();
		void printDetail();
};

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

int main(){
	Account List[10];
	ifstream inp("bank.txt");
	
	if (inp.fail()){
		cout << "File does not exist!" << endl;
		return 0;
	}
	
	char a[20], b[20];
	int c;
	float d;
	
	int i = 0;
	while (inp >> a){
		inp >> b;
		inp >> c;
		inp >> d;
		List[i] = Account(a,b,c,d);
		i++;
	}
	
	for (int j = 0; j < 10; j++){
		List[j].printDetail();
		cout << endl;
	}
	
	inp.close();
	return 0;
}

