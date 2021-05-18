#include <iostream>
using namespace std;

class nodeStack{
	public:
		char data;
		nodeStack* next;
};

class Stack{
	private:
		int data;
		nodeStack* top;
	
	public:
		void create();
		void Push();
		void Pop();
		bool isEmpty();
		char stackTop();
};

void Stack::create(){
	top = NULL;
}

bool Stack::isEmpty(){
	return top==NULL;
}

void Stack::Push(){
	nodeStack *newNode = new nodeStack;
	char item;
	cout << "Insert an item: " << endl;
	cin >> item;
	
	if (newNode == NULL){
		cout << "Cannot allocate memory..." << endl;
	}else{
		newNode->data = item;
		newNode->next = top;
		top = newNode;		
	}
}

void Stack::Pop(){
	nodeStack *delnode = new nodeStack;
	
	if (isEmpty()){
		cout << "Sorry, the stack is still empty!" << endl;
	}else{
		delnode = top;
		cout << "Item to be popped from stack is: " << top->data << endl;
		
		top = delnode->next;
		delete(delnode);
	}
}

char Stack::stackTop(){
	if (isEmpty()){
		cout << "Sorry, the stack is still empty!" << endl;
	}else{
		return top->data;
	}
}
int main(){
	cout << "part a" << endl;
	Stack listA;
	
	listA.create();
	listA.Push(); //a
	listA.Push(); //b
	listA.Push(); //c
	listA.Push(); //d
	listA.Push(); //a
	listA.Push(); //b
	listA.Push(); //c
	listA.Push(); //d
	listA.Push(); //e
	listA.Push(); //f
	
	cout << "\npart b" << endl;
	Stack listB;
	
	listB.create();
	listB.Push(); //a
	listB.Push(); //b
	listB.Pop();
	listB.Push(); //c
	listB.Push(); //d
	listB.Pop();
	listB.Push(); //a
	listB.Push(); //b
	
	
	cout << "\npart c" << endl;
	Stack listC;
	
	listC.create();
	listC.Push(); //a
	listC.Push(); //b
	listC.Pop();
	listC.Push(); //c
	listC.Push(); //d
	listC.Pop();
	listC.Push(); //a
	listC.Pop();
	listC.Pop();
	listC.Pop();
	listC.Pop();
	
	return 0;
} 
