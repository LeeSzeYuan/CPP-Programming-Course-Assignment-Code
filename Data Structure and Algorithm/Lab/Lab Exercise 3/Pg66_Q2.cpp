#include <iostream>
using namespace std;

int fun2(int, int);

int main(){
	cout << fun2(7,3) << endl;
	system("PAUSE");
	
	return 0;
}

int fun2(int x, int n){
	if (n==0)
		return 1;
	else
		return x*fun2(x, n-1);
}
