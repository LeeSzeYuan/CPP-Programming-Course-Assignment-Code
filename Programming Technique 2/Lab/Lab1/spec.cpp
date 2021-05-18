#include "pet.h"
#include <iostream>
#include <string>
using namespace std;

void Pet::print() const
{
	cout << "Pet' s name: ";
	cout << name << endl;
	cout << "Pet' s age: ";
	cout << age;
}

void Pet::setName(string n)
{
	name=n;
}

void Pet::setAge(int a)
{
	age=a;
}

