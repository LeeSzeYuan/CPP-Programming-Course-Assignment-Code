
#include <iostream>
using namespace std;

class nodePhone{
	public:
		string brand, model;
		float price;
		nodePhone *next;
		
		nodePhone(string br, string md, float pr){
			brand = br;
			model = md;
			price = pr;
		}
		nodePhone() {}
		
		void print(){
			cout << model << endl;
		}
};

nodePhone *first = NULL;

int main(){
	//Part A
	nodePhone *ptr1 = new nodePhone("Nokee", "Lumia", 1200.00);
	nodePhone *ptr2 = new nodePhone("HTSee", "Desire", 900.00);
	
	//Part B
	first = ptr2;
	ptr2->next = ptr1;
	ptr1->next = first;
	ptr1->next->model = "Xperia";
	
	ptr2->print();
	return 0;
}
//
//nodePhone* ptr1 = new nodePhone("Nokee", "Lumia", 1200.00);
//nodePhone* ptr2 = new nodePhone("HTSee", "Desire", 900.00);
//
//Part C
//first = current->next;
//delete current;
//
//Part D
//nodePhone* firstNode = first;
//firstNode->next = current->next;
//delete current;
//
//Part E
//cout << "List of Affordable Smart Phones\n\n";
//nodePhone* currNode = first
//while(currNode != Node){
//	cout << fixed << setprecision(2);
//	if (currNode->price < 2000.00){
//		cout << "Brand : " << currNode->brand << endl
//			 << "Model: " << currNode->model << endl
//			 << "Price : RM" << currNode->price << endl;
//			 << "The phone is affordable for student" << endl << endl;
//	}
//	currNode = currNode->next;
//}
