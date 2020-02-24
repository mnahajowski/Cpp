#include <iostream>
#include "Table.h"

void mod_tab(Table *tab, int new_size) {
	tab->setNewSize(new_size);
}

void mod_tab(Table tab, int new_size) {
	tab.setNewSize(new_size);
}

int main() {
	/*
		Table myTable;
		myTable.fill();
		myTable.show();	

		Table *myTable2;
		myTable2 = new Table(myTable);
		(*myTable2).show();
		delete myTable2;

		mod_tab(myTable, 5);
		myTable.show();
		mod_tab(&myTable, 5);
		myTable.show();

		Table *myTable3;
		myTable3 = myTable.pcClone();
		(*myTable3).show();
		delete myTable3;*/


	Table myTable;
	myTable.fill();
	Table *myTable2;
	myTable2 = myTable.pcGotReverted();
	(*myTable2).show();
	delete myTable2;
}
