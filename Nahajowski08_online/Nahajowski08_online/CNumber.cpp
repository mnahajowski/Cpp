#include "CNumber.h"

CNumber::CNumber()
{
	this->value = new double();
}

CNumber::~CNumber()
{
	if (value != NULL) delete value;
	std::cout << "Destr ";
}

CNumber::CNumber(CNumber &&cOther) {

	c_move(std::move(cOther));
	std::cout << "MOVE ";
}

CNumber::CNumber(const CNumber &cOther) {
	v_copy(cOther);
	std::cout << "Copy ";
}

void CNumber::c_move(CNumber &&cOther) {

	value = cOther.value;
	cOther.value = NULL;

}
void CNumber::v_copy(const CNumber &cOther) {

	this->value = new double(*cOther.value);
}


void CNumber::setValue(double value) {
	*this->value = value;
}

void CNumber::vPrint() {
	std::cout << *this->value << "\n";
}