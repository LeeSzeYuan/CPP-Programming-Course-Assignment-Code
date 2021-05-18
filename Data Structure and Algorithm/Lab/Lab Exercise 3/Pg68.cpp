#include <iostream>
using namespace std;

int function_1 (int m,int n){
	if (n==0||n%5 != 0)
		return 1;
	else
		return (m * function_1(m, n-5) + 3);
}

int main(){
	cout << function_1(5, 12) << endl;
	
	return 0;
}
