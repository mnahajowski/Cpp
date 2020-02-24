#include "CFileThrowEx.h"
#include <iostream>

const int CFileThrowEx::OPEN_ERROR = 1;
const int CFileThrowEx::CLOSE_ERROR = 2;
const int CFileThrowEx::PRINT_ERROR = 3;
const int CFileThrowEx::PRINT_MANY_ERROR = 4;

CFileThrowEx::CFileThrowEx() {
	pf_file = NULL;
}

CFileThrowEx::CFileThrowEx(std::string sFileName) {
	this->vOpenFile(sFileName);
}

CFileThrowEx::~CFileThrowEx() {
	if (pf_file != NULL)
		fclose(pf_file);
}

void CFileThrowEx::vOpenFile(std::string sFileName) { 
		
	pf_file = fopen(sFileName.c_str(), "w+");
	if (pf_file == NULL)
		throw OPEN_ERROR; 
	
}

void CFileThrowEx::vCloseFile(std::string sFileName) {

	if (pf_file == NULL)
		throw CLOSE_ERROR;
	else {
		fclose(pf_file);
		pf_file = NULL;
	}
}

void CFileThrowEx::vPrintLine(std::string sText) {
	
	if (pf_file == NULL)
		throw PRINT_ERROR;
	else
		fprintf(pf_file, "write sth to a file\n");
}

void CFileThrowEx::vPrintManyLines(std::vector<std::string> sText) {
	if (pf_file == NULL)
		throw PRINT_MANY_ERROR;
	else {
		for (int i = 0; i < (int)sText.size(); i++) {
			this->vPrintLine(sText[i]);
		}
	}

}
