#pragma once
#include <string>
#include <vector>
class CFileLastError
{
private: 
	static bool b_last_error;
public:
	static bool bGetLastError() { return (b_last_error); }

	CFileLastError();
	CFileLastError(std::string sFileName);
	~CFileLastError();

	void vOpenFile(std::string sFileName);
	void vCloseFile(std::string sFileName);
	void vPrintLine(std::string sText);
	void vPrintManyLines(std::vector<std::string> sText);

	
private:
	FILE *pf_file;
};//class CFileLastError

