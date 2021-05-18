#include <iostream>
#include <fstream>
using namespace std;

struct catalog{
	char title[50];
	char author[50];
	char publisher[50];
	int yearpublish;
	double price;
};

int main(){
	catalog book;
	char again;
	
	fstream fbook("book.dat", ios::out|ios::binary);
	
	do{
		cout << "Enter the following data about a book: \n";
		cout << "Title:";
		cin.getline(book.title, 50);
		cout << "Author:";
		cin.getline(book.author, 50);
		cout << "Publisher name:";
		cin.getline(book.publisher, 30);
		cout << "Year publish:";
		cin >> book.yearpublish;
		cin.ignore();
		cout << "Price:";
		cin >> book.price;
		cin.ignore();
		
		fbook.write((char *)&book, sizeof(book));
		
		cout << "Do you want to enter another record?(Y/N)";
		cin >> again;
		cin.ignore();
		
		cout << endl;
	} while (again == 'Y' || again == 'y');
	
	fbook.close();
	return 0;
}
