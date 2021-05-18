#ifndef ACCOUNT_H
#define ACCOUNT_H

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

#endif
