#include<iostream>
using namespace std;

void BubbleSort (int data[], int listSize, int&comp, int&swap, int&num_pass)
{
	bool sorted = false;
	
	comp = 0, swap = 0, num_pass=0;    
	int pass, tempValue;
    for (pass =1; pass < listSize && sorted == false; pass++)
    {      
		// moves the largest element to the
        // end of the array
        sorted = true;
        num_pass += 1;
        
        for (int x = 0; x < listSize - pass; x++)
        {      
			// compare adjacent elements
			comp+=1;
            if ( data[x] > data[x+1] )
			{      // swap elements
	        	tempValue = data[x];
	       		data[x] = data[x+1];
	        	data[x+1] = tempValue;
	        	swap+=1;
	        	sorted = false;
	 		}
        }
    }
}

int main(){
	int comp = 0, swap = 0, pass=0;
	
	int dataArrayA[25] = {100,50,88,30,60,45,25,12,10,5,98,15,65,55,45,70,20,90,66,22,120,48,35,85,2};
	int dataArrayB[25] = {5,8,30,25,35,40,42,50,55,22,24,60,66,70,75,78,80,88,95,100,118,98,120,122,121};
	
	BubbleSort(dataArrayA, 25, comp, swap, pass);
	cout << "Array A: No of Comparison: " << comp << "\t No of Swaps: "  << swap << "\t No of Passes: " << pass <<   endl;
	BubbleSort(dataArrayB, 25, comp, swap, pass);
	cout << "Array B: No of Comparison: " << comp << "\t No of Swaps: "  << swap << "\t No of Passes: " << pass <<   endl;
	
	return 0;
}
