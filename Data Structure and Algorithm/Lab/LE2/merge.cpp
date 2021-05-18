#include <iostream>
using namespace std;


void merge(int data[], int first, int mid, int last, int&comp){
	int tempArray[25];
	
	int first1 = first;
	int last1 = mid;
	int first2 = mid+1;
	int last2 = last;
	int index= first1;
	
	for(; (first1<=last1) && (first2<=last2); index++){
		if (data[first1] < data[first2]){
			tempArray[index] = data[first1];
			first1++;
		} else {
			tempArray[index] = data[first2];
			first2++;
		}
		comp+=1;
	}
	for(;first1 <= last1; first1++, index++){
		tempArray[index] = data[first1];
	}
	for(;first2 <= last2;  first2++, index++){
		tempArray[index] = data[first2];
	}
	for(index=first; index<=last;index++){
		data[index] = tempArray[index];
	}
}

void mergeSort(int data[], int first, int last, int&num_steps, int&num_part, int&comp){
	
	if (first<last){
		int mid = (first+last)/2;
		
		mergeSort(data, first, mid, num_steps, num_part, comp);
		num_steps += 1;
		num_part+=1;
		mergeSort(data, mid+1, last, num_steps, num_part, comp);
		num_steps += 1;
		num_part+=1;
		merge(data, first, mid, last, comp);
		num_steps += 1;
	}
}

void printArray(int data[],int listSize)
{
	for(int i=0; i<listSize;i++)
	{
	cout << " " << data[i];
	}
	cout << endl;
}

int main(){
	int steps=0, num_part=0, comp=0;

	
	int dataArrayA[25] = {100,50,88,30,60,45,25,12,10,5,98,15,65,55,45,70,20,90,66,22,120,48,35,85,2};
	int dataArrayB[25] = {5,8,30,25,35,40,42,50,55,22,24,60,66,70,75,78,80,88,95,100,118,98,120,122,121};
	
	
	steps = 1;
	num_part=0;
	mergeSort(dataArrayA, 0, 24, steps, num_part, comp);
	printArray(dataArrayA,25);
	cout << "Array A: No of Steps: " << steps << "\tNo of partitions: " << num_part << "\tNo of comparisons: " << comp <<endl <<endl;
	
	steps=1;
	num_part=0;
	comp = 0;
	mergeSort(dataArrayB, 0, 24, steps, num_part, comp);
	printArray(dataArrayB,25);
	cout << "Array B: No of Steps: " << steps << "\tNo of partitions: " << num_part << "\tNo of comparisons: " << comp <<endl;
	
	return 0;
}
