#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

string MONTHS[12] = {"Januari", "Februari", "Mac", "April", "Mei", "Jun", "Julai", "Ogos", "September", "Oktober", "November", "Disember"};

void yearReadings(int a);
void readings(string s, int &a, int &b, int &c, int&d);

int main(){
	ifstream inp("ic.txt");
	string ic;
	int year, month, day, gender;
	char Gcode;
	
	int i=0;
	while(inp>>ic){
		readings(ic, year, month, day, gender);
		Gcode = (gender==1)? 'L':'P';
		
		cout << i+1 << " (" << Gcode << "): " << day << " " << MONTHS[month-1] << " ";
		yearReadings(year);
		
		i++; 
	}	
	return 0;
}

void yearReadings(int a){
	if (a > 20){
		cout << 1900+a << endl;
	} else {
		cout << 2000+a << endl;
	}
}

void readings(string s, int &a, int &b, int &c, int&d){
	stringstream gd, yr, mt, dy;
	
	yr << s.substr(0, 2);
	yr >> a;
		
	mt << s.substr(2, 2);
	mt >> b;
		
	dy << s.substr(4, 2);
	dy >> c;
		
	gd << s.substr(10, 4);
	gd >> d;
	d %= 2;
		
	yr.clear();
	mt.clear();
	dy.clear();
	gd.clear();
}
