#include <iostream>
#include "CFileLastError.h"

bool CFileLastError::b_last_error;

CFileLastError::CFileLastError()
{
	pf_file = NULL;
}

CFileLastError::CFileLastError(std::string sFileName) {
	this->vOpenFile(sFileName);
}

CFileLastError::~CFileLastError()
{	
	if (pf_file != NULL)
		fclose(pf_file);
}

void CFileLastError::vOpenFile(std::string sFileName) {

	this->b_last_error = false;
	// czy na pewno to
	pf_file = fopen(sFileName.c_str(), "w+");
	
	if (pf_file == NULL)
		this->b_last_error = true;
	
}

void CFileLastError::vCloseFile(std::string sFileName) {
	this->b_last_error = false;
	
	if (pf_file == NULL)
		this->b_last_error = true;
	else {
		fclose(pf_file);
		pf_file = NULL;
	}
}

void CFileLastError::vPrintLine(std::string sText) {
	this->b_last_error = false;

	if (pf_file == NULL)
		this->b_last_error = true;
	else
		fprintf(pf_file, "write sth to a file\n");
}

void CFileLastError::vPrintManyLines(std::vector<std::string> sText) {
	this->b_last_error = false;

	if (pf_file == NULL)
		this->b_last_error = true;
	else {
		for (int i = 0; i < (int)sText.size(); i++) {
			this->vPrintLine(sText[i]);
		}

	}
}

