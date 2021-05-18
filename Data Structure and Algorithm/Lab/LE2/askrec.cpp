#include <iostream>
using namespace std;

int askrec(int x, int y){
	if (y==0)
		return x;
	else 
		return x + askrec(x, y-2);
}

int main(){
	cout << askrec(2,4);
	
	return 0;
}
