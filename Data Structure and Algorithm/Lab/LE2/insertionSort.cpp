#include<iostream>
using namespace std;


void insertionSort (int data[], int n, int&comp, int&num_swap, int&num_pass)
{
	comp = 0, num_swap = 0, num_pass=0;
	
	int item;
	int pass, insertIndex;
	for (pass=1; pass<n; pass++){
		item = data[pass];
		insertIndex = pass;
		
		num_pass+=1;
		
		while((insertIndex>0)&&(data[insertIndex-1]>item)){
			data[insertIndex] = data[insertIndex-1];
			insertIndex--;
			
			num_swap+=1;
			comp+=1;
		}
		if (insertIndex != 0)
			comp+=1;
			
		data[insertIndex] = item;
	}
}



int main(){
	int comp = 0, swap = 0, pass=0;
	
//	int a[5] = {7,8,3,1,6};
//	insertionSort(a, 5, comp, swap, pass);
//	cout << comp << " " << swap << " " << pass << endl;
	
	int dataArrayA[25] = {100,50,88,30,60,45,25,12,10,5,98,15,65,55,45,70,20,90,66,22,120,48,35,85,2};
	int dataArrayB[25] = {5,8,30,25,35,40,42,50,55,22,24,60,66,70,75,78,80,88,95,100,118,98,120,122,121};
	
	insertionSort(dataArrayA, 25, comp, swap, pass);
	cout << "Array A: No of Comparison: " << comp << "\t No of Swaps: "  << swap << "\t No of Passes: " << pass << endl;
	insertionSort(dataArrayB, 25, comp, swap, pass);
	cout << "Array B: No of Comparison: " << comp << "\t No of Swaps: "  << swap << "\t No of Passes: " << pass << endl;
	
	return 0;
}
