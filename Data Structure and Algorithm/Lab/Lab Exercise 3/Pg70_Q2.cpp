#include <iostream>
using namespace std;

int P(int n){
	if (n<5)
		return 3*n;
	else
		return P(n-2)*4+P(n-1)*2;
}

int main(){
	cout << P(2) << endl;
	cout << P(8) << endl;
	cout << P(10) << endl;
	
	return 0;
}
