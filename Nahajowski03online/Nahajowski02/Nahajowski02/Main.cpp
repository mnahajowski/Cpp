#include <iostream>
#include "Table.h"
const int OFFSET_ADD = 51;

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
		myTable.vPrint();

		Table *myTable2;
		myTable2 = new Table(myTable);
		(*myTable2).vPrint();
		delete myTable2;

		mod_tab(myTable, 5);
		myTable.vPrint();
		mod_tab(&myTable, 5);
		myTable.vPrint();

		Table *myTable3;
		myTable3 = myTable.pcClone();
		(*myTable3).vPrint();
		delete myTable3;*/
		
			/*
			Table  c_tab_0;
			Table c_tab_1;
			c_tab_0.setNewSize(6);
			c_tab_1.setNewSize(4);
			c_tab_0 = c_tab_1;
			//c_tab_1 = c_tab_0;*/
			
		/*
		Table  c_tab_0, c_tab_1;
		c_tab_0.setNewSize(6);
		c_tab_1.setNewSize(4);
		
		c_tab_0.vSetValue(1);
		c_tab_1.vSetValue(OFFSET_ADD);
		c_tab_0.vPrint();
		c_tab_1.vPrint();
		*/
		/*
		Table c_tab_2 = c_tab_0 -= 1;
		c_tab_2.vPrint();*/
	/*
		Table c_tab_0, c_tab_1;
		c_tab_0.setNewSize(2);
		c_tab_1.setNewSize(1);
		c_tab_0.vSetValue(11);
		c_tab_0.vSetValue(21);

		Table c_tab_3 = (c_tab_0 + c_tab_1) + 77;
		c_tab_3.vPrint();
		*/
		/*

		c_tab_0 = c_tab_1;
		c_tab_0.vPrint();
		c_tab_1.vPrint();
		c_tab_1.vSetValueAt(2, 123);
		c_tab_0.vPrint();
		c_tab_1.vPrint();*/
		
		//int number = 77;
		Table  c_tab_0, c_tab_1;
		c_tab_0.setNewSize(3);
		c_tab_1.setNewSize(2);

		c_tab_0.vSetValue(11);
		c_tab_1.vSetValue(21);
		c_tab_0.vPrint();
		c_tab_1.vPrint();
		//Table c_tab_4 = c_tab_0 + 77;
		//c_tab_4.vPrint();
		Table c_tab_2 = c_tab_0 + c_tab_1 + 77;
		c_tab_2.vPrint();
}

/* 1
Program skompilował się ale jego działanie zakończyło się errorem. Wynika to z tego, że w momencie, gdy dokonujemy "c_tab_0 = c_tab_1;"
to wskaźnik z c_tab_1 jest przypisywany do c_tab_0. Kończy się to pierwszym wyciekiem pamięci, ponieważ od tego momentu nic nie wskazuje 
na c_tab_1. Gdy blok programu kończy się, usuwane są wszystkie obiekty statyczne, jednakże napisany przez nas destruktor miał za zadanie 
zrobić delete na wskaźniku tablicy intów. Co za tym idzie, w obecnej sytuacji, gdy zarówno c_tab_0 jak i c_tab_1 wskazują na to samo miejsce, 
to w momencie gdy usuwamy c_tab_1 (delete na wskaznik) to nie jest już nasza pamięć. Gdy próbujemy usunąć wtedy drugi obiekt destruktor 
wywołuje delete na ten sam wskaźnik, który już wcześniej został usunięty i stąd error (próba usunięcia czegoś co nie jest naszą pamięcią).

2
Na pierwszy rzut oka program zakończył działanie poprawnie.  Sytuacja jest podobna, 2 wskaźniki wskazują na jedno miejsce. Jednak pamięć przeznaczona
na te obiekty nie jest w trakcie programu zwalniana. Podobny efekt możemy osiągnąć po prostu usuwając linię z "delete [] this->tab;" z destruktora.
W tym przypadku mamy do czynienia z wyciekiem pamięci (program pozbędzie się tego dopiero po zakończeniu programu). Pozwala to zauważyć, że pomimo teoretycznie
prawidłowego zakończenia programu mamy do czynienia z błędami w zarządzaniu pamięcią.

*/