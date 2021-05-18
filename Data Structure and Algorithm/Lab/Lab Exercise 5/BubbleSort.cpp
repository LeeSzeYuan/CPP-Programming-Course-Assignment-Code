#include <iostream>
using namespace std;

void BubbleSort(int data[], int listSize){
	int tempValue;
	bool is_sorted = false;
	
	for (int i = 1; i < listSize  && !is_sorted; i++){
		is_sorted = true;
		for (int j=0; j<listSize-i; j++){
			if (data[j] > data[j+1]){
				tempValue = data[j+1];
				data[j+1] = data[j];
				data[j] = tempValue;
				is_sorted = false;
			}
		}
	}
}

int main(){
	int data[7] = {3,5,7,6,9,8,12};
	
	BubbleSort(data, 7);
	
	for (int i=0; i<7; i++){
		cout << data[i] << " ";
	}
	
	return 0;
}
