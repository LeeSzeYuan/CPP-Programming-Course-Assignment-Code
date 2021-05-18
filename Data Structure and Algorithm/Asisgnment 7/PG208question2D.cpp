#include <iostream>
#include <vector>
using namespace std;

class StackNode{
	public:
		int data;
		StackNode* next;
};

class Stack{
	private:
		StackNode *top;
	public:
		Stack() {top = NULL;}
		void push(int);
		int pop();
		int stacktop();
		bool isEmpty() {return top==NULL;}
		void print();
		
		friend bool same(Stack, Stack);
		friend Stack reverseStack(Stack);
};

void Stack::push(int d){
	StackNode *newNode = new StackNode;
	
	if (newNode == NULL){
		cout << "Cannot allocate memory...\n";
	} else{
		newNode->data = d;
		newNode->next = top;
		top = newNode;
	}
}

int Stack::pop(){
	StackNode *delNode = new StackNode;
	int d;
	
	if (isEmpty()){
		cout << "It is empty...\n";
	} else {
		delNode = top;
		d = delNode->data;
		top = delNode->next;
		delete(delNode);
	}
	return d;
}

bool same(Stack a, Stack b){
	bool flag = true;
	StackNode* currNodeA = new StackNode; 
	StackNode* currNodeB = new StackNode;
	
	currNodeA = a.top;
	currNodeB = b.top;
	
	while (currNodeA != NULL && currNodeB != NULL){
		if (currNodeA->data != currNodeB->data){
			flag = false;
		}
		currNodeA = currNodeA->next;
		currNodeB = currNodeB->next;
	}
	return flag;
}

int Stack::stacktop(){
	if (isEmpty()){
		cout << "The stack is empty...\n";
	}else{
		return top->data;
	}
}

void Stack::print(){
	StackNode *currNode = new StackNode;
	currNode = top;
	while (currNode){
		cout << currNode->data << " ";
		currNode = currNode->next;
	}
}

Stack reverseStack(Stack a){
	vector<int> list;
	
	while (!a.isEmpty()){
		list.push_back(a.pop());
	}
	Stack b;
	for (int i=list.size()-1; i>=0; --i){
		b.push(list[i]);
	}
	
	return b;
}


int main(){
	Stack A, B;
	A.push(1); B.push(1);
	A.push(2); B.push(2);
	A.push(3); B.push(3);
	
	if (same(A, B) == 1){
		cout << "Same\n";
	} else{
		cout << "Different\n";	
	}
	
	cout << "\nReversing Stack:... \n";
	Stack C = reverseStack(B);
	C.print();
	
	return 0;
}
