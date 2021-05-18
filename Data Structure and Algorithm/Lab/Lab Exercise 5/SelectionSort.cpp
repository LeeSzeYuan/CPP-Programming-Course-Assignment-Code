#include<iostream>
using namespace std;

void sort(int data[], int n){
	int temp,X,last;
	for(last= n-1 ; last>= 1; last--){
		X=0;
		for(int p =1 ; p<=last;++p){
			if(data[p]<data[X])
			X=p;
		}
		temp = data[last];//last =i
		data[last]=data[X];
		data[X]=temp;
	}
}

int main(){	
	int data[6]={3,5,7,6,8,9};
	int n=6;
	
	sort(data, n);
	
	for(int i = 0 ; i <6 ; i++){
		cout << data[i]<<endl;
	}
	
	
	
}
