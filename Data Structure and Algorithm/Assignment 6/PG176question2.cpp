#include <iostream>
#include <iomanip>
using namespace std;

class NodeContact{
	public:
		string name, phoneNo;
		NodeContact *next;
		
		NodeContact(string a, string b){
			name = a;
			phoneNo = b;
		}
		NodeContact() {}
};

class List{
	private:
		NodeContact *head;
		
	public:
		List();
		bool IsEmpty();
		void InsertNode(string a, string b);
		int FindNode(string a);
		int DeleteNode (string a);
		void DisplayList();
};

List::List(){
	head = NULL;
}

bool List::IsEmpty(){
	return head == NULL;
}

void List::InsertNode(string a, string b){
	int currindex = 0;
	NodeContact *currNode = head;
	NodeContact *prevNode = NULL;
	while (currNode && a > currNode->name && b > currNode->phoneNo){
		prevNode = currNode;
		currNode = currNode->next;
		currindex++;
	} 
	
	NodeContact *newNode = new NodeContact;
	newNode->name = a;
	newNode->phoneNo = b;
	
	if (currindex == 0){
		newNode->next = head;
		head = newNode;
	} else {
		newNode->next = prevNode->next;
		prevNode->next = newNode;
	}
}

int List::FindNode(string a){
	int currIndex = 1;
	NodeContact *currNode = head;
	
	while (currNode && a != currNode->name){
		currNode = currNode->next;
		currIndex++;
	}
	
	if (currNode)
		return currIndex;
	else 
		return 0;
}

int List::DeleteNode(string a){
	int currIndex = 1;
	NodeContact *prevNode = NULL;
	NodeContact *currNode = head;
	
	while (currNode && a != currNode->name){
		prevNode = currNode;
		currNode = currNode->next;
		currIndex++;
	}
	
	if (currNode){
		if (prevNode){
			prevNode->next = currNode->next;
			delete currNode;
		} else {
			head = currNode->next;
			delete currNode;
		}
		return currIndex;
	} 
	return 0;
}

void List::DisplayList(){
	int num = 0;
	NodeContact *currNode = head;
	while (currNode != NULL){
		cout << left << "Name: " << setw(20) << currNode->name << "PhoneNO: " << currNode->phoneNo << endl;
		currNode = currNode->next;
		num++;
	}
	cout << endl << "Number of elements in the list: " << num << endl << endl;
}

int main(){
	List list;
	//insert nodes
	list.InsertNode("Nadia Hana", "0127888888");
	list.InsertNode("Ahmad Fariz", "0192222222");
	list.InsertNode("Patrik", "011111111");
	list.InsertNode("Faiz Hilmi", "012222222");
	
	//print all the elements
	list.DisplayList();
		
	list.DeleteNode("Faiz Hilmi");
	list.DisplayList();
	
	return 0;
}
