#include "pet.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	Pet rabbit;
	
	rabbit.setName("Buttons");
	rabbit.setAge(3);
	
	rabbit.print();
	
	return 0;
}
