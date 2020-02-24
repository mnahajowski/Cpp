#include "CFileErrCode.h"

CFileErrCode::CFileErrCode() {
	pf_file = NULL;
}
CFileErrCode::CFileErrCode(std::string sFileName) {
	this->vOpenFile(sFileName);

}

CFileErrCode::~CFileErrCode() {
	if (pf_file != NULL)
		fclose(pf_file);
}

bool CFileErrCode::vOpenFile(std::string sFileName) {

	pf_file = fopen(sFileName.c_str(), "w+");
	if (pf_file == NULL)
		return false;
	else
		return true;

}

bool CFileErrCode::vCloseFile(std::string sFileName) {

	if (pf_file == NULL)
		return false;
	else {
		fclose(pf_file);
		pf_file = NULL;
		return true;
	}
}

bool CFileErrCode::vPrintLine(std::string sText) {

	if (pf_file == NULL)
		return false;
	else {
		fprintf(pf_file, "write sth to a file\n");
		return true;
	}
}

bool CFileErrCode::vPrintManyLines(std::vector<std::string> sText) {
	if (pf_file == NULL)
		return false;
	else {
		for (int i = 0; i < (int)sText.size(); i++) {
			this->vPrintLine(sText[i]);
		}
		return true;
	}

}

