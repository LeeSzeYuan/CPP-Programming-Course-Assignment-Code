#include<iostream>
using namespace std;

void swap(int x, int y, int&num_swap){
	int temp = x;
	x = y;
	y = temp;
	num_swap+=1;
}

void selectionSort (int data[], int n, int&comp, int&num_swap, int&num_pass)
{
	comp = 0, num_swap = 0, num_pass = 0;
	for (int last =n-1; last>=1; last--){
		int largestIndex = 0;
		
		num_pass += 1;
		
		for (int p=1; p<=last; p++){
			comp+=1;
			
			if (data[p] > data[largestIndex]){
				largestIndex = p;
			}
		}
		
		swap(data[largestIndex], data[last], num_swap);
	}
}



int main(){
	int comp = 0, swap = 0, pass=0;
	
	int dataArrayA[25] = {100,50,88,30,60,45,25,12,10,5,98,15,65,55,45,70,20,90,66,22,120,48,35,85,2};
	int dataArrayB[25] = {5,8,30,25,35,40,42,50,55,22,24,60,66,70,75,78,80,88,95,100,118,98,120,122,121};
	
	selectionSort(dataArrayA, 25, comp, swap, pass);
	cout << "Array A: No of Comparison: " << comp << "\t No of Swaps: "  << swap << "\t No of Passes: " << pass <<  endl;
	selectionSort(dataArrayB, 25, comp, swap, pass);
	cout << "Array B: No of Comparison: " << comp << "\t No of Swaps: "  << swap << "\t No of Passes: " << pass <<  endl;
	
	return 0;
}
