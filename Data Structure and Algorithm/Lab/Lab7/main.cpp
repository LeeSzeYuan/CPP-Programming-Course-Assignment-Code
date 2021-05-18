#include <iostream>
#include <cstring>
#include <fstream>
#include "Account.h"
using namespace std;

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

