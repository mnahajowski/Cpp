#include <iostream>
#include "CFileLastError.h"
#include "CFileThrowEx.h"
#include "CFileErrCode.h"

void opening(CFileLastError *obj1, CFileThrowEx *obj2, CFileErrCode *obj3) {

	bool myError_temp = false;
	bool err_code_temp = false;

	for (int i = 0; i < 10; i++) {

		obj1->vOpenFile("obiekt4.txt");
		myError_temp = obj1->bGetLastError();
		std::cout << "lasterror : " << myError_temp << "\n";

		try {
			obj2->vOpenFile("obiekt5.txt");
		}
		catch (int e) {
			std::cout << "An exception #" << e << "\n";
		}
		//std::cout << "jestem3\n";

		err_code_temp = obj3->vOpenFile("obiekt6.txt");
		std::cout << "err code : " << err_code_temp << "\n";
	}
}

int main()
{

	std::vector <std::string> Text;
	for (int i = 0; i < 5; i++) {
		Text.push_back("a"); 
	}/*
	bool myError = false;
	CFileLastError obj1;
	obj1.vOpenFile("obiekt1.txt");
	myError = obj1.bGetLastError();
	//obj1.vPrintLine("no elo");
	obj1.vPrintManyLines(Text);
	myError = obj1.bGetLastError();
	obj1.vCloseFile("obiekt1.txt");
	myError = obj1.bGetLastError();
	std::cout << "jestem";*/
	/*
	try {

		CFileThrowEx obj2;
		//obj2.vPrintManyLines(Text);
		obj2.vOpenFile("obiekt2.txt");
		//obj2.vPrintLine("no elo");
		obj2.vPrintManyLines(Text);
		obj2.vCloseFile("obiekt2.txt");
	}
	catch (int e) {
		std::cout << "An exception #" << e << "\n";
	}
	*/
	CFileLastError obj4;
	CFileThrowEx obj5;
	CFileErrCode obj6;
	bool myError_temp = false;
	bool err_code = false;

	opening(&obj4, &obj5, &obj6);
	/*
	for (int i = 0; i < 10; i++) {

		obj4.vOpenFile("obiekt4.txt");
		myError_temp = obj4.bGetLastError();
		std::cout << myError_temp;

		try {
			obj5.vOpenFile("obiekt5.txt");
		}
		catch (int e) {
			std::cout << "An exception #" << e << "\n";
		}

		err_code = obj6.vOpenFile("obiekt6.txt");
		std::cout << err_code;
	}
	*/
}

