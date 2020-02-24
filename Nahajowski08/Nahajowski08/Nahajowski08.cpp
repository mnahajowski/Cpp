// Nahajowski08.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CTab.h"

int main()
{


	CTab myTable;
	myTable.fill();
	myTable.vPrint();

	CTab myTable2("Dwa", 10);
	myTable2.fill();
	myTable2.vPrint();

	
	CTab myTable3 = std::move(myTable2);
	myTable3.vPrint();
	//std::cout << "\n\n\n";
	
	CTab myTable4;
	myTable4.fill();
	myTable4.vPrint();
	
	//std::cout << "\n\n\n";
	myTable4 = std::move(myTable3);
	myTable4.vPrint();
	
	//std::cout << "\n\n\n";

	CTab myTable5;
	myTable5.fill();
	myTable5.vPrint();

	myTable4 = myTable5;
	myTable4.vPrint();

	CTab myTable6;
	myTable6.fill();
	myTable6.vPrint();

	myTable4 = myTable5 + myTable6;
	myTable4.vPrint();

}

/*
Maleje liczba kopii tablicy wewnêtrznej, kopiowanie samo w sobie nie jest wywo³ywane, po przeniesieniu do innego, stary
obiekt jest usuwany. Nie bêdzie zatem kopii tablicy wewnêtrznej.
*/
