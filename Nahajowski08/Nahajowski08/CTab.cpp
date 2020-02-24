#include "CTab.h"

const int CTab::DEFAULT_SIZE = 10;
//static int counter
const std::string CTab::DEFAULT_NAME = "Table 1";
CTab::CTab()
{
	this->name = DEFAULT_NAME;
	std::cout << "bezp: " << this->name << "\n";
	this->pi_tab = new int[DEFAULT_SIZE];
	this->i_size = DEFAULT_SIZE;
}

CTab::CTab(std::string name, int tab_length) {
	this->name = name;
	std::cout << "parametr " << this->name << "\n";

	if (tab_length > 0) {
		this->pi_tab = new int[tab_length];
		this->i_size = tab_length;
	}
	else {
		this->pi_tab = new int[DEFAULT_SIZE];
		this->i_size = DEFAULT_SIZE;
	}
}

CTab::~CTab()
{
	if (pi_tab != NULL) delete pi_tab;
	std::cout << "Destr ";
}

CTab::CTab(const CTab &cOther) {
	v_copy(cOther);
	std::cout << "Copy ";
}

CTab CTab::operator=(const CTab &cOther) {

	if (this != &cOther) {
		if (pi_tab != NULL) delete pi_tab;
		v_copy(cOther);
	}
	std::cout << "op= ";
	return (*this);
}

CTab CTab::operator=(CTab &&cOther) {

	if (this != &cOther) {
		if (pi_tab != NULL) 
			delete[] pi_tab;

		c_move(std::move(cOther));
	}
	std::cout << "op=move ";
	return (*this);
}


void CTab::c_move(CTab &&cOther) {
	name = cOther.name;
	i_size = cOther.i_size;
	pi_tab = cOther.pi_tab;
	cOther.pi_tab = NULL;
}

void CTab::v_copy(const CTab &cOther) {
	this->name = cOther.name;
	this->pi_tab = new int[cOther.i_size];
	this->i_size = cOther.i_size;

	for (int ii = 0; ii < cOther.i_size; ii++) {
		pi_tab[ii] = cOther.pi_tab[ii];
	}
}

CTab *CTab::pcClone() {
	return new CTab(*this);
}

CTab::CTab(CTab &&cOther) {

	c_move(std::move(cOther));
	std::cout << "MOVE ";
}

CTab cCreateTab() {
	CTab c_result;
	c_result.bSetSize(5);
	return(std::move(c_result));
}

void CTab::fill() {

	for (int i = 0; i < this->i_size; i++) {
		*((this->pi_tab) + i) = rand() % 100;
	}

}

void CTab::vSetValue(int iNewVal) {
	for (int i = 0; i < this->i_size; i++) {
		vSetValueAt(i, iNewVal + i);
	}
}

void CTab::vPrint() {
	std::cout << "Wyswietlam : " << this->name << "\n";
	for (int i = 0; i < this->i_size; i++) {
		std::cout << *((this->pi_tab) + i) << " ";
	}
	std::cout << "\n";
}

void CTab::setName(std::string name) {
	this->name = name;
}


void  CTab::vSetValueAt(int  iOffset, int  iNewVal) {
	*((this->pi_tab) + iOffset) = iNewVal;
}


bool CTab::bSetSize(int new_length)
{
	int *tab_temp = new int[new_length];
	int new_length_temp = new_length;

	if (new_length > this->i_size) {
		new_length_temp = this->i_size;
	}

	for (int i = 0; i < new_length_temp; i++) {
		*(tab_temp + i) = *((this->pi_tab) + i);
	}

	delete[] this->pi_tab;
	this->pi_tab = tab_temp;
	this->i_size = new_length;
	return true;
}
CTab CTab::operator+(const CTab &otherTable) {

	CTab result("Suma", i_size + otherTable.i_size);

	for (int i = 0; i < this->i_size; i++) {
		result.vSetValueAt(i, this->pi_tab[i]);
	}

	for (int iNewIter = this->i_size, iOtherIter = 0; iNewIter < result.i_size; iNewIter++, iOtherIter++)
		result.vSetValueAt(iNewIter, otherTable.pi_tab[iOtherIter]);

	return std::move(result);
}
