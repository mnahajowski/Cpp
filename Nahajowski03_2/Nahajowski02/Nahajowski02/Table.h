#pragma once
#include <string>

class Table
{
public:
	Table();
	Table(std::string nazwa, int length);
	void setName(std::string name);
	bool setNewSize(int new_length);
	void fill();
	void vSetValueAt(int iOffset, int iNewVal);
	void vSetValue(int iNewVal);
	void vPrint();
	Table(const Table &refer);
	//~Table();
	const static std::string DEFAULT_NAME;
	const static int DEFAULT_SIZE;
	Table *pcClone();
	Table *pcGotReverted();
	int getSize();
	Table operator+(const Table &refer);
	Table operator+(int number);
	//Table operator-=(int liczba);
	//Table operator/=(int liczba);
private:
	std::string name;
	int length = DEFAULT_SIZE;
	int *tab;

};


