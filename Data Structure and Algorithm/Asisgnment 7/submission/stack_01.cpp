#include <iostream>
#include <conio.h>
using namespace std;

#define MAXSTACK 10
class Stack{
	private:
		int top;
		char data[MAXSTACK];
	
	public:
		Stack();
		bool isFull();
		bool isEmpty();
		void push(char);
		char pop();
};

Stack::Stack(){
	top = -1;
}

bool Stack::isFull(){
	return top == (MAXSTACK-1);
}

bool Stack::isEmpty(){
	return top == -1;
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

char Stack::pop(){
	if (!isEmpty()){
		char item = data[top];
		top--;
		return item;
	}else{
		return '*';
	}
}

void printPop(char item){
	if (item == '*'){
		cout << "Pop operation fail-stack is empty!" << endl;
	}else{
		cout << "Popped item: " << item << endl;
	}
}

int main(){
	Stack aStack;
	aStack.push('a');
	aStack.push('b');
	aStack.push('c');
	
	printPop(aStack.pop());
	printPop(aStack.pop());
	printPop(aStack.pop());
	printPop(aStack.pop());
	
	return 0;
}
