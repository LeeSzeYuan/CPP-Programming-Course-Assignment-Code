#include <iostream>
#include <string>
using namespace std;

class Node{
	public:
		Node(int);
		int item;
		Node* prev;
		Node* next;
};

Node::Node(int i){
	item = i;
}

void listNodeForward(Node* head){
	Node* current = head;
	while(current){
		cout << current->item << endl;
		current = current->next;
	}
}

void listNodeBackward(Node* tail){
	Node *current =  tail;
	while(current){
		cout << current->item << endl;
		current = current->prev;
	}
}

void deleteNodes(Node* head){
	Node* prev;
	Node* current = head;
	while(current){
		prev= current;
		current = current->next;
		cout << "Delete " << prev->item << endl;
	}
}

int main(){
	Node* head = NULL;
	Node* tail = NULL;
	
	Node* n1 = new Node(10);
	Node* n2 = new Node(20);
	Node* n3 = new Node(30);
	
	head = n1;
	n1->prev = NULL;
	n1->next = n2;
	
	n2->prev = n1;
	n2->next = n3;
	
	n3->prev = n2;
	n3->next = NULL;
	tail = n3;
	
	cout << "List node start from header:" << endl;
	listNodeForward(head);
	
	cout << "List node start from tail:" << endl;
	listNodeBackward(tail);
	
	deleteNodes(head);
	
	return 0;
}
