#include <iostream>
using namespace std;


int SumOfDigits (int N){
	if (N/10 == 0)
		return N;
	else 
		return (N%10) + SumOfDigits((N - N%10)/10);
}

int main(){
	cout << SumOfDigits(237) << endl;
	cout << SumOfDigits(3518) << endl;
//	cout << SumOfDigits(-237) << endl;
	
	return 0;
}
