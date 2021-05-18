#include <iostream>
using namespace std;

int getCoin();
void calculateCoin(int &, int);
int calculateBalance(int );


int main()
{
	int value, total=0, price=120, balance;
	
	while(total<price)
	{
		value=getCoin();
		calculateCoin(total, value);
		cout << "--------------------------------------" << endl;
	}
	
	balance=calculateBalance(total);
	
	if (balance>0)
	cout << "Please collect your balance" << endl;
	else
	cout << "TERIMA KASIH" << endl;

	return 0;
}

int getCoin()
{
	int c;
	cout << "Please enter the value of coin : ";
	cin >> c;
	
	return c;
}

void calculateCoin(int &totalCoin, int coin)
{
	totalCoin+=coin;
	cout << endl << "Curent total value of coin     : " << totalCoin << endl << "The price of the item          : 120" << endl << endl;
}

int calculateBalance(int totalCoin)
{
	int balance, price=120;
	balance=totalCoin-price;
	cout << "=======================" << endl;
	cout << "The total balance : " << balance << endl;
	cout << "=======================" << endl;
	return balance;
}
