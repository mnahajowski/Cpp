#pragma once
#include <string>
#include <vector>
class CFileErrCode
{
public:
	CFileErrCode();
	CFileErrCode(std::string sFileName);
	~CFileErrCode();

	bool vOpenFile(std::string sFileName);
	bool vCloseFile(std::string sFileName);
	bool vPrintLine(std::string sText);
	bool vPrintManyLines(std::vector<std::string> sText);

private:
	FILE *pf_file;
};//class CFileErrCode
