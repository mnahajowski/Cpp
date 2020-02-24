// Nahajowski08_online.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CNumber.h"

int main()
{
	CNumber numb1;
	numb1.setValue(5.7);
	numb1.vPrint();

	CNumber numb2(numb1);
	numb2.vPrint();

	CNumber numb3(std::move(numb1));
	numb3.vPrint();



}
