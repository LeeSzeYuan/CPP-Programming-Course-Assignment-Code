#include <iostream>
#include <fstream>
#include <iomanip>
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
	
	fstream fbook("book.dat", ios::in|ios::binary);
	if (!fbook){
		cout << "Error opening file";
		return 0;
	}
	
	cout << "These are the book information in the file:\n";
	
	fbook.read((char *)&book, sizeof(book));
	 while (!fbook.eof()){
		cout << "Title: " << book.title << endl;
		cout << "Author: " << book.author << endl;
		cout << "Publisher name: " << book.publisher << endl;
		cout << "Year publish: " << book.yearpublish << endl;
		cout << "Price: " << fixed << setprecision(2) << book.price << endl << endl;
		
		fbook.read((char *)&book, sizeof(book));
	}
	
	fbook.close();
	cout << "Done" << endl;
	return 0;
}
