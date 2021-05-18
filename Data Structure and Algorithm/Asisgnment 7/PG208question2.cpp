#include <iostream>
using namespace std;

#define SIZE 10
class Stack{
	private:
		int top;
		int data[SIZE];
		
	public:
		Stack() {top = -1;};
		bool isFull() {return top == (SIZE-1);}
		bool isEmpty() {return top == -1;}
		bool push(int);
		bool pop();
		int stackTop() {return data[top];}
		void print();
		
		friend bool sameStack(Stack a, Stack b);
		friend Stack reverseStack(Stack a);
};

bool Stack::push(int d){
	if (isFull())
		return false;
	else{
		top+=1;
		data[top] = d;
		return true;
	}
}

bool Stack::pop(){
	if(isEmpty()){
		return false;
	}else{
		top-=1;
		return true;
	}
}

void Stack::print(){
	for (int i=0; i<=top; ++i){
		cout << data[i] << " ";
	}
}

bool sameStack(Stack a, Stack b){
	bool flag = true;
	if (a.top != b.top){
		return false;
	}
	for (int i=0; i<=a.top; ++i){
		if (a.data[i] != b.data[i])
			flag = false;
	}
	return flag;
}

Stack reverseStack(Stack a){
	Stack b = a;
	for (int i=0; i<=a.top; ++i){
		b.data[i] = a.data[a.top-i];
	}
	return b;
}

int main(){
	Stack a, b;
	a.push(1); b.push(1);
	a.push(2); b.push(2);
	a.push(3); b.push(3);
	a.push(4); b.push(4);
	
	cout << sameStack(a, b) << endl;
	
	Stack rev_a = reverseStack(a);
	rev_a.print();
	
	return 0;
}
