#pragma once
#include <iostream>
#include <cstdlib>
class CNumber
{
public:
	CNumber();
	CNumber(CNumber  &&cOther);
	CNumber(const CNumber  &cOther);
	~CNumber();
	void c_move(CNumber &&cOther);
	void v_copy(const CNumber &cOther);
	void vPrint();
	void setValue(double value);

private:
	double *value;

};

