#ifndef PET_H
#define PET_H
#include <iostream>
#include <string>
using namespace std;

class Pet
{
	private:
		string name;
		int age;
	
	public:
		void setName(string n);
		void setAge(int a);
		string getName()
		{return name;}
		int getAge()
		{return age;}
		void print() const;
};
#endif
