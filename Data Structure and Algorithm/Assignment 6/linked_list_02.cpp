#include <iostream>
#include <string>
using namespace std;

class Node{
	public:
		Node(string);
		string name;
		Node* next;
};

Node::Node(string n){
	name = n;
}

void listNodes(Node* head){
	Node* current = head;
	while(current){
		cout << current->name << endl;
		current= current->next;
	}
	cout << endl;
}

void deleteNodes(Node* head){
	Node* prev;
	Node* current = head;
	while(current){
		prev = current;
		current = current->next;
		cout << "Delete " << prev->name << endl;
	}
}

int main(){
	string names[] = {"James", "Guido", "Larry", "Yuki", "Martin", "Rasmus"};
	
	Node* head = NULL;
	Node* newNode = NULL;
	Node* prevNode = NULL;
	
	for (int i=0; i<6; i++){
		newNode = new Node(names[i]);
		newNode->next = NULL;
		if (head==NULL){
			head=newNode;
		} else {
			prevNode->next = newNode;
		}
		
		prevNode =  newNode;
	}
	
	cout << "The original list: " << endl;
	listNodes(head);
	
	Node* n = head;
	Node* pre = NULL;
	for (int i=0; i<6; i++){
		if (n->name != "Yuki"){
			pre = n;
			n = n->next;
		} else {
			pre->next = n->next;
			delete n;
		}
	}
	
	cout << "The list after \"Yuki\"is deleted: " << endl;
	listNodes(head);
	
	Node* james = head;
	Node* guido = james->next;
	Node* larry = guido->next;
	
	head = guido;
	guido->next = james;
	james->next = larry;
	
	cout << "The list after swapping the nodes \"James\" and \"Guido\": " << endl;
	listNodes(head);
	
	deleteNodes(head);
	
	return 0;
}
