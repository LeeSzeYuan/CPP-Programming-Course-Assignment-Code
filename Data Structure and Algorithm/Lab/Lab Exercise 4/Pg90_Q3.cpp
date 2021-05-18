#include <iostream>
using namespace std;

int main(){
	for (int i = 1; i<=5; i++){      //n
		for (int j=1; j<=i; j++){   //(n/2)(n+1)
			cout << "#";   //(n/2)(n+1)
		}
		cout << endl; //n
	}
	
	return 0;
}
