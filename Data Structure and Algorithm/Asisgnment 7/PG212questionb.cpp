#include <iostream>
using namespace std;

class node{
	public:
		char data;
		node *next;
};

class Stack{
	private:
		node* top;
	
	public:
		Stack() {top = NULL;}
		void push(char);
		void pop();
		bool isEmpty() {return top == NULL;}
};

void Stack::push(char d){
	node *newNode = new node;
	if (newNode == NULL){
		cout << "Out of memory\n";
	}else{
		newNode->data = d;
		newNode->next = top;
		top = newNode;
	}
}

void Stack::pop(){
	node *delNode = new node;
	if (isEmpty()){
		cout << "The stack is empty\n";
	}else{
		delNode= top;
		top = delNode->next;
		delete(delNode);
	}
}

int main(){
	string str;
	getline(cin, str);
	
	Stack list;
	bool cont = true;
	int i=0;
	char ch;
	
	while (i < str.size() && cont){
		ch = str[i];
		if (ch=='(' || ch==')'){
			if (ch=='(')
				list.push(ch);
			else if (list.isEmpty())
				cont = false;
			else
				list.pop();
		}
		i++;
	}
	
	if (list.isEmpty())
		cout << "Balanced" << endl;
	else
		cout << "Not balanced" << endl;
		
	return 0;
}
