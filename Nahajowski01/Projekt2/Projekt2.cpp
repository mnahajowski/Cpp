#include <iostream>
#include "Nagłówek.h"
int main() {
	int table_size;
	int dim_size_x, dim_size_y;
	int **pi_table = NULL;
	int **wsk = NULL;


	std::cout << "Witamy w kreatorze alokowania tablicy, prosze podac rozmiar tablicy\n";

	std::cin >> table_size;
	if (!testing_correct(table_size))
		exit(-1);

	v_alloc_table_add_5(table_size);

	std::cout << "\nProsze podac wymiary tablicy dwuwymiarowej\n";

	std::cin >> dim_size_x;
	if (!testing_correct(dim_size_x))
		exit(-1);

	std::cin >> dim_size_y;
	if (!testing_correct(dim_size_y))
		exit(-1);


	if (pi_table == wsk)
		std::cout << "Wskazuje na NULL\n";	// test czy poczatkowo wskaznik wskazuje na NULL

	b_alloc_table_2_dim(&pi_table, dim_size_x, dim_size_y);	// alokacja tablicy


	if (pi_table == wsk)
		std::cout << "\nWskazuje na NULL\n";
	else
		std::cout << "\nUdalo sie zaalokowac\n";	// test czy udalo sie zaalokowac tablice

	b_dealloc_table_2_dim(&pi_table, dim_size_x, dim_size_y);		// wywolanie dealokacji tablicy

	return 0;
}