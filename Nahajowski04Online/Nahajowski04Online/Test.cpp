#include "Test.h"

const int Test::PRINT_ERROR = 1;

Test::Test()
{
}


Test::~Test()
{
}

void Test::setValue(int number) {
	if (number > 10 || number < -10)
		throw PRINT_ERROR;
	else
		this->value = number;
}

int Test::getValue() {
	return this->value;
}


