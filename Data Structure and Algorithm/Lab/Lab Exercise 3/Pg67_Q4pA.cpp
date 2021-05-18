#include <iostream>
using namespace std;

int GCD(int M, int N);

int main(){
	int ans = GCD(3, 9);
	cout << ans << endl;
	
	return 0;
}

int GCD(int M, int N){
	if (M%N == 0)
		return N;
	else
		return GCD(N, M%N);
}
