#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main(){
	const int SIZE = 7;
	ofstream fnum("outdata.txt");
	double num[SIZE] = {23.567, 12.901, 825.1234, 1.2};
	
	fnum << fixed << setprecision(2);
	for (int i = 0; i < SIZE; i++){
		fnum << setw(8) << num[i] << endl;
	}
	
	fnum.close();
	return 0;
}
