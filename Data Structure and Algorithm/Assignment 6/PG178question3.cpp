#include <iostream>
using namespace std;


class Node{
	public:
		int item;
		Node* next;
};

class List{
	private:
		Node *head;
	
	public:
		List() {head = NULL;}
		isEmpty() {return head == NULL;}
		
		Node *insertNode(int data, int pos);
		void display();
		int deleteNode(int data);
};

Node* List::insertNode(int data, int pos){
	if (pos < 0) return NULL;
	int currIndex = 1;
	Node *currNode = head;
	
	while (currNode && pos > currIndex){
		currNode = currNode->next;
		currIndex++;
	}
	
	if (pos > 0 && currNode == NULL) return NULL;
	
	Node *newNode = new Node;
	newNode->item = data;
	
	if (pos==0){
		newNode->next = head;
		head = newNode;
	} else {
		newNode->next = currNode->next;
		currNode->next = newNode;
	}
	
	return newNode;
}

void List::display(){
	Node *currNode = head;
	int num=0;
	
	while (currNode != NULL){
		cout << currNode->item << " ";
		currNode = currNode->next;
		num++;
	}
	cout << endl;
	cout << "The number of element in this list: " << num << "\n\n";
}

int List::deleteNode(int data){
	Node *currNode = head;
	Node *prevNode = NULL;
	int currIndex = 1;
	
	while (currNode->item != data){
		prevNode = currNode;
		currNode = currNode->next;
		currIndex++;
	}
	
	if (currNode == NULL){
		return -1;
	} else {
		if (prevNode){
			prevNode->next = currNode->next;
			delete currNode;
		} else {
			head = currNode->next;
			delete currNode;
		}
		
		return currIndex;
	}
}

int main(){
	List list;
	list.insertNode(2, 0);
	list.insertNode(7, 1);
	
	//question a
	list.insertNode(6, 0);
	list.display();
	list.deleteNode(6);
	
	//question b
	list.insertNode(6, 1);
	list.display();
	list.deleteNode(6);
	
	//question c
	list.insertNode(6, 2);
	list.display();
	list.deleteNode(6);
	
	return 0;
}
