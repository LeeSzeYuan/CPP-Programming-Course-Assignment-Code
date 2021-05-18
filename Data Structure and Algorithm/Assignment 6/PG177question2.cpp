#include <iostream>
#include <iomanip>
using namespace std;

class Node{
	public:
		//part a
		string name;
		string emp_id;
		int age;
		Node* link;
		
		Node(string a,  string b, int c){
			name = a; 
			emp_id = b;
			age = c;
			link = NULL;
		}
		Node(){
			name = "";
			emp_id = "";
			age = 0;
			link = NULL;
		}
		//pat c
		void print(){
			cout << left;
			cout << "Employee Name: " << setw(20) << name 
				 << "\nEmployee ID: " << setw(15) << emp_id 
				 << "\nAge: " << age << endl;
		}
};

int main(){
	//part b
	Node* head = new Node("Aiman", "A1234", 24);
	head->print();
	
	cout << endl;
	
	//part d
	Node* newNode = new Node("Asmah", "A2835", 30);
	newNode->print();
	return 0;
}
