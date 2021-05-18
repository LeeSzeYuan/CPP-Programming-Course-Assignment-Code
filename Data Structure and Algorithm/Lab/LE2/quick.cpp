#include <iostream>
using namespace std;

void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  

int partition (int T[], int first, int last, int&comps)  
{  
    int pivot = T[last];
    int i = (first - 1);   
  
    for (int j = first; j <= last - 1; j++)  
    {  
        if (T[j] < pivot)  
        {  
            i++; 
            swap(&T[i], &T[j]); 
            comps++;
        }  
    }  
    swap(&T[i + 1], &T[last]);
    return (i + 1);  
}  

void quickSort(int T[], int first, int last, int&steps, int&parts, int&comps)  
{  
    if (first < last)  
    {  
        int cut = partition(T, first, last, comps);  
  		steps+=1;
		parts+=2;
        quickSort(T, first, cut-1, steps, parts, comps);  
        steps+=1;
        quickSort(T, cut+1, last, steps, parts, comps);  
        steps+=1;
    }  
}  

void print(int data[],int listSize)
{
	for(int i=0; i<listSize;i++)
	{
	cout << data[i] << " " ;
	}
	cout << endl;
}


int main(){

	int steps, parts, comps;
	
	int dataArrayA[25] = {100,50,88,30,60,45,25,12,10,5,98,15,65,55,45,70,20,90,66,22,120,48,35,85,2};
	int dataArrayB[25] = {5,8,30,25,35,40,42,50,55,22,24,60,66,70,75,78,80,88,95,100,118,98,120,122,121};

	steps=1; parts=0,comps=0;
	quickSort(dataArrayA, 0, 24, steps, parts, comps);
	print(dataArrayA, 24);
	cout << "Array A: No of Steps: " << steps << "\tNo of partitions: " << parts << "\tNo of comparisons: " << comps <<  endl;
	cout << endl;
	
	steps=1; parts=0,comps=0;
	quickSort(dataArrayB, 0, 24, steps, parts, comps);	
	print(dataArrayB, 24);
	cout << "Array B: No of Steps: " << steps << "\tNo of partitions: " << parts << "\tNo of comparisons: " << comps <<  endl;


	return 0;
}
