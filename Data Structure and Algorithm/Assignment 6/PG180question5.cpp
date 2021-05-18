#include <iostream>
using namespace std;

class Node{
	public:
		int elem;
		Node* link;
};

class Linked_list{
	private:
		Node* head;
		
	public:
		List() {head = NULL;}
		bool isEmpty() {return head == NULL;}
		
		Node* insertNode(int item);
		void find_pos(int item);
		void print();
};

Node* Linked_list::insertNode(int item){
	Node* prevNode = NULL;
	Node* currNode = head;
	int currIndex = 0;
	
	while (currNode && item > currNode->elem){
		prevNode = currNode;
		currNode = currNode->link;
		currIndex++;
	}
	
	Node* newNode = new Node;
	newNode->elem = item;
	
	if (currIndex==0){
		newNode->link = head;
		head = newNode;
	} else {
		newNode->link = currNode;
		prevNode->link = newNode;
	}
	
	return newNode;
}

void Linked_list::print(){
	Node* currNode=head;
	
	while(currNode != NULL){
		cout << currNode->elem << " ";
		currNode = currNode->link;
	}
}

int main(){
	Linked_list list;
	list.insertNode(40);
	list.insertNode(70);
	list.insertNode(60);
	list.insertNode(45);
	
	list.print();
	return 0;
}

//Part b
//Node *newNode = new (Node);
//newNode->elem = 35;
//
//newNode->link = head;
//head= newNode;

//Part d
//Node *newNode = new (Node);
//newNode->elem = 63;
//
//newNode->link = prevNode->link;
//prevNode->link = newNode;

//Part e
//previousNode->link = NULL;
//delete newNode;
