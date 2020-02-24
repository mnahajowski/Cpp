// Nahajowski04Online.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Test.h"

int main()
{
	Test obj1;
	
	try {
		obj1.setValue(5);
		std::cout << obj1.getValue() << "\n";
		obj1.setValue(-15);
	}
	catch (int e) {
		std::cout << "An exception #" << e << " Wrong number!" << "\n";
	}

}