#include "Nag³ówek.h"
#include <iostream>

void v_alloc_table_add_5(int i_Size) {

	int *table;
	table = new int[i_Size];

	for (int i = 0; i < i_Size; i++) {
		table[i] = i + VALUE_CHANGER;
	}


	for (int i = 0; i < i_Size; i++) {
		std::cout << table[i] << " ";
	}

	delete table;
}	// v_alloc_table_add_5

bool b_alloc_table_2_dim(int ***piTable, int dim_size_x, int dim_size_y) {

	*piTable = new int*[dim_size_x];

	for (int i = 0; i < dim_size_x; i++) {
		(*piTable)[i] = new int[dim_size_y];

		for (int j = 0; j < dim_size_y; j++) {
			(*piTable)[i][j] = i * j + 10;
		}
	}	// wypelnienie tablicy cyframi wedlug pewnego wzoru

	for (int i = 0; i < dim_size_x; ++i, std::cout << "\n")
		for (int j = 0; j < dim_size_y; ++j)
			std::cout << (*piTable)[i][j] << '\t';	// wyswietlenie tablicy dwuwymiarowej

	return true;
}	// b_alloc_table_2_dimo

bool b_dealloc_table_2_dim(int ***piTable, int dim_size_x, int dim_size_y) {

	for (int i = 0; i < dim_size_x; i++) {
		delete (*piTable)[i];

	}

	delete *piTable;
	return true;
}	// b_dealloc_table_2d_dim

bool testing_correct(int number) {
	if (!std::cin || number < 0) {
		std::cin.clear();
		std::cout << "\nPodales bledny znak! To nie jest liczba!\n";
		return false;
	}
	else
		return true;
}	// testing_correct




