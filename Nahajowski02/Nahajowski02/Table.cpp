#include "Table.h"
#include <iostream>
//TDD
Table::Table()
{
	this->name = DEFAULT_NAME;
	std::cout << "bezp: " << this->name << "\n";
	this->tab = new int[DEFAULT_SIZE];
	this->length = DEFAULT_SIZE;
}

Table::Table(std::string name, int tab_length) {
	this->name = name;
	std::cout << "parametr" << this->name <<"\n";

	if (tab_length > 0) {
		this->tab = new int[tab_length];
		this->length = tab_length;
	}
	else {
		this->tab = new int[DEFAULT_SIZE];
		this->length = DEFAULT_SIZE;
	}
}
Table::Table(const Table &my_Table) {
	this->name = my_Table.name + "_copy";
	this->tab = new int[my_Table.length];
	this->length = my_Table.length;
	
	for (int i = 0; i < this->length; i++) {
		*((this->tab) + i) = my_Table.tab[i];
	}

	std::cout << "kopiuj: " << this->name << "\n";
}

Table *Table::pcClone() {
	return new Table(*this);
}

Table *Table::pcGotReverted() {
	
	Table *myTable2 = new Table(*this);
	for (int i = 0; i < myTable2->length; i++) {
		*((myTable2->tab)+i)=*((this->tab) + this ->length - i - 1);
	}
	return myTable2;
	
}

Table::~Table()
{
	std::cout << "usuwam: " << this->name << "\n";
	delete [] this->tab;
}
void Table::fill() {
	for (int i = 0; i < this->length; i++) {
		*((this->tab) + i) = i;
	}
}

void Table::show() {
	std::cout << "Wyswietlam : " << this->name << "\n";
	for (int i = 0; i < this->length; i++) {
		std::cout << *((this->tab) + i) << " ";
	}
	std::cout << "\n";
}

void Table::setName(std::string name) {
	this->name = name;
}

bool Table::setNewSize(int new_length)
{
	int *tab_temp = new int[new_length];
	for (int i = 0; i < new_length; i++) {
		*(tab_temp + i) = *((this->tab) + i);
	}
	delete[] this->tab;
	this->tab = tab_temp;
	this->length = new_length;
	return true;
}

int Table::getSize() {
	return this->length;
}