#include <iostream>
using namespace std;

class Stack{
	private:
		int top;
		string data[10];
		
	public:
		Stack() {top = -1;};
		bool isFull() {return top == (10-1);}
		bool isEmpty() {return top == -1;}
		bool push(string);
		bool pop();
		string stackTop();
		void print();
};

bool Stack::push(string d){
	if (isFull()){
		return false;
	}else{
		top+=1;
		data[top] = d;
		return true;
	}
}

bool Stack::pop(){
	if (isEmpty()){
		return false;
	}else{
		cout << stackTop() << endl;
		top-=1;
		return true;
	}
}

string Stack::stackTop(){
	return data[top];
}

void Stack::print(){
	if (isEmpty()){
		cout << "The list is empty! \n";
	} else {
		for (int i=0; i<=top; ++i){
			cout << data[i] << " ";
		}
		cout << endl;
	}
}

int main(){
	Stack aStack;
	aStack.push("a");
	aStack.push("b");
	aStack.push("c");
	aStack.print();
	
	cout << "The element that is poped is ";
	aStack.pop();
	aStack.push("d");
	aStack.print();
	
	return 0;
}
