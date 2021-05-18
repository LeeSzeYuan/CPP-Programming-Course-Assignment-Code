#include <iostream>
using namespace std;

const int size = 10;

class Stack{
	private:
		char data[size];
		int top;
	
	public:
		void createStack();
		bool isFull();
		bool isEmpty();
		char stackTop();
		void push();
		void pop(); 
};

void Stack::createStack(){
	top = -1;
}

bool Stack::isFull(){
	return top == size-1;
}

bool Stack::isEmpty(){
	return top == -1;
}

char Stack::stackTop(){
	if (isEmpty())
		cout << "Sorry, stack is empty!" << endl;
	else{
		return data[top];
	}
}

void Stack::push(){
	char newitem;
	
	cout << "Enter item to be inserted into stack" << endl;
	cin >> newitem;
	
	if (isFull()){
		cout << "Sorry, stack is full!" << endl;
	}else{
		top += 1;
		data[top] = newitem;
	}
}

void Stack::pop(){
	char item;
	
	if (isEmpty()){
		cout << "Sorry, stack is empty!" << endl;;
	} else{
		cout << "Popped value :" << data[top] << endl;
		top -= 1;
	}
}

int main(){
	cout << "part a" << endl;
	Stack listA;
	
	listA.createStack();
	listA.push(); //a
	listA.push(); //b
	listA.push(); //c
	listA.push(); //d
	listA.push(); //a
	listA.push(); //b
	listA.push(); //c
	listA.push(); //d
	listA.push(); //e
	listA.push(); //f
	
	cout << "\npart b" << endl;
	Stack listB;
	
	listB.createStack();
	listB.push(); //a
	listB.push(); //b
	listB.pop();
	listB.push(); //c
	listB.push(); //d
	listB.pop();
	listB.push(); //a
	listB.push(); //b
	
	
	cout << "\npart c" << endl;
	Stack listC;
	
	listC.createStack();
	listC.push(); //a
	listC.push(); //b
	listC.pop();
	listC.push(); //c
	listC.push(); //d
	listC.pop();
	listC.push(); //a
	listC.pop();
	listC.pop();
	listC.pop();
	listC.pop();
	
	return 0;
}
