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
	void show();
	Table(const Table &refer);
	~Table();
	const std::string DEFAULT_NAME = "Table 1";
	const int DEFAULT_SIZE = 10;
	Table *pcClone();
	Table *pcGotReverted();
	int getSize();
private:
	std::string name;
	int length = DEFAULT_SIZE;
	int *tab;

};


