#include <iostream>
#include <conio.h>

using namespace std;
#define MAXSTACK 10

class Stack{
	private:
		int top;
		char data[MAXSTACK];
		
	public:
		Stack() {top = -1;}
		bool isFull();
		bool isEmpty();
		void push(char);
		void printLIFO();
		void printFIFO();
};

bool Stack::isFull(){
	return top == (MAXSTACK-1);
}

bool Stack::isEmpty(){
	return top==-1;
}

void Stack::push(char item){
	if (!isFull()){
		top++;
		data[top] = item;
		cout << "Push operation success!item: " << item << endl;
	}else{
		cout << "Push operation fail-stack is full!" << endl;
	}
}

void Stack::printFIFO(){
	cout << "FIFO printing\n";
	for (int i=0; i<=top; i++){
		cout << data[i];
	}
	cout << endl;
}

void Stack::printLIFO(){
	cout << "LIFO printing\n";
	for (int i=top; i>=0; i--){
		cout << data[i];
	}
	cout << endl;
}

int main(){
	Stack stack;
	stack.push('a');
	stack.push('b');
	stack.push('c');
	cout << endl;
	stack.printFIFO();
	cout << endl;
	stack.printLIFO();
	getche();
	return 0;
}
