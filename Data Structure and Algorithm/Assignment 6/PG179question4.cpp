#include <iostream>
using namespace std;

class Node{
	public:
		char data;
		Node* next;
};

class List{
	private:
		Node* head;
		
	public:
		List() {head = NULL;}
		bool isEmpty() {return head==NULL;}
		
		Node* insertNode(char data, int pos);
		void print();
		int number();
		int biggest();
};

Node* List::insertNode(char data, int pos){
	if (pos < 0) return NULL;
	
	Node* currNode = head;
	int currIndex = 1;
	while (currNode && pos > currIndex){
		currNode = currNode->next;
		currIndex++;
	}
	
	if (pos>0 && currNode == NULL) return NULL;
	
	Node* newNode = new Node;
	newNode->data = data;
	
	if (pos == 0){
		newNode->next = head;
		head = newNode;
	} else {
		newNode->next = currNode->next;
		currNode->next = newNode;
	}
	
	return newNode;
}

void List::print(){
	Node* currNode=head;
	
	while(currNode != NULL){
		cout << currNode->data << " ";
		currNode = currNode->next;
	}
}

int List::number(){
	Node* currNode=head;
	int num=0;
	
	while(currNode != NULL){
		currNode = currNode->next;
		num++;
	}
	return num;
}

int List::biggest(){
	Node* currNode=head;
	int maxIndex=0, currIndex=1;
	char biggest = 'A';
	
	while(currNode){
		if (biggest < currNode->data){
			biggest = currNode->data;
			maxIndex = currIndex;
		}
		currNode = currNode->next;
		
		currIndex++;
	}
	return maxIndex;
}

int main(){
	List list;
	list.insertNode('B', 0);
	list.insertNode('R', 1);
	list.insertNode('E', 2);
	list.insertNode('A', 3);
	list.insertNode('D', 4);
	
	list.print();
	cout << "\nThe number of elements in this list is " << list.number() << endl;
	
	cout << "\nThe index(starts with 0) of the largest element in this list is " << list.biggest()-1 << "\n";	
	return 0;
}
