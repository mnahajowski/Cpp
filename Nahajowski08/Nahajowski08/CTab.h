#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
class CTab
{
public:
	CTab();
	CTab(std::string nazwa, int length);
	CTab(const CTab  &cOther);
	CTab(CTab  &&cOther);
	void setName(std::string name);
	CTab operator = (const CTab  &cOther);
	CTab operator =(CTab &&cOther);
	~CTab();
	const static std::string DEFAULT_NAME;
	const static int DEFAULT_SIZE;
	void fill();
	void vSetValueAt(int iOffset, int iNewVal);
	void vSetValue(int iNewVal);
	void vPrint();
	bool  bSetSize(int iNewSize);
	int  iGetSize() { return(i_size); };
	CTab *pcClone();
	CTab operator+(const CTab &refer);
	void c_move(CTab &&cOther);

	double dGetQuality(double *pdSolution);
	bool bConstraintSatisfied(double *pdSolution);

private:
	void v_copy(const CTab &cOther);

	int *pi_tab;
	int i_size;
	std::string name;
};

