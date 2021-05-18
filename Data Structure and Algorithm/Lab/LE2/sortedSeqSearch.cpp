#include <iostream>
using namespace std;

int partition(int d[], int first, int last){
	
	int pivot, temp, cutPoint;
	int bottom, top, loop;
	
	loop = 1;
	bottom = first;
	top = last;
	
	pivot = d[bottom];
	
	while(loop){
		while (d[bottom]<pivot)
			bottom++;
		while (d[top]>pivot)
			top--;
			
		if (bottom<top){
			temp = d[bottom];
			d[bottom] = d[top];
			d[top] = temp;
		} else {
			cutPoint = top;
			loop = 0;
		}
	}
	return cutPoint;
}

void quickSort(int d[], int first, int last){
	int cut;
	if (first < last){
		cut = partition(d, first, last);
		quickSort(d, first, cut);
		quickSort(d, cut+1, last);
	}
}

int SequenceSearch(int search_key, int array[], int array_size){
	
	quickSort(array, 0, array_size-1);
	
	int index=-1;
	
	for (int p=0; p<array_size; p++){
		if (array[p] == search_key){
			index = p;
			break;
		}
	}
	
	return index;
}

int main(){
	
	int data[10] = {49, 21, 34, 35, 40, 7, 15, 26, 12, 4};
	
	int ind = SequenceSearch(37, data, 10);
	
	for (int i=0; i<10; i++)
		cout << data[i] << " ";
	
	cout << endl;
	cout << ind;
	
	return 0;
}
