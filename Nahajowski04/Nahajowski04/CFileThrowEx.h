#pragma once
#include <string>
#include <vector>
class CFileThrowEx
{
public:
	CFileThrowEx();
	CFileThrowEx(std::string sFileName);
	~CFileThrowEx();

	void vOpenFile(std::string sFileName);
	void vCloseFile(std::string sFileName);
	void vPrintLine(std::string sText);
	void vPrintManyLines(std::vector<std::string> sText);


	const static int OPEN_ERROR;
	const static int CLOSE_ERROR;
	const static int PRINT_ERROR;
	const static int PRINT_MANY_ERROR;

private:
	FILE *pf_file;
};//class CFileThrowEx

