#include <iostream>
using namespace std;

int mock(int a, int b)  

    {  
   if (b == 0)  
       return 1;  

       if (b % 2 == 0)  

           return mock(2*a, b/2);  
   
   return mock(2*a, b/2)*a;  
}  

int main(){
//	int b[5] = {21,14,46,35,67};
//	quickSort(b, 0, 4);
	
	cout << mock(2,5);
	
	return 0;
}
