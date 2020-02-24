#pragma once
#include <string>
class Test
{
public:
	Test();
	~Test();

	void setValue(int number);
	const static int PRINT_ERROR;
	int getValue();

private:
	int value;
};

