#include <iostream>
#include "CMySmartPointer.h"

void test() {
	CMySmartPointer<std::vector<int>> p1(new std::vector<int>());
	p1->push_back(1);
	p1->push_back(2);
	p1->push_back(3);

	CMySmartPointer<std::vector<int>> p2(p1);

	CMySmartPointer<std::vector<int>> p3(new std::vector<int>(*p1));

	p2 = p3;
	std::cout <<(*p1)[0] << "\n";

}
int main()
{
	//test();

	CMySmartPointer<double> pd(new double);
	std::cout << "Krok1\n";
	
	CMySmartPointer<double> p1(new double);
	p1 = pd;
	
	{
		std::cout << "Krok2\n";
		CMySmartPointer<double> p2(new double);
		p2 = p1;
	}
	{
		std::cout << "Krok3\n";
		CMySmartPointer<double> p3(new double);
		p3 = p1;
	}

	std::cout << "Koniec\n";
}

/*
3. Obiekt statyczny mo�e spa�� ze stosu a wska�nik b�dzie wtedy wskazywa� na nulla, nie wiedz�c o tym, mo�e si� sta�, �e b�dziemy
	pr�bowali ponownie usun�� pami��, ktora juz zostala usunieta

	Zamiast wska�nika na konkretny typ mogliby�my przechowywa� wska�nik typu void. Zalet� by�oby to, �e mogliby�my wykorzystywa� go do
	obiektow dowolnego typu. Znacz�c� wad� jest jednak to, �e przy ka�dej pr�bie u�ycia go trzeba by by�o zrzutowa� go na odpowiedni
	typ, dla ktorego chccielibysmy go u�y�, wiec uzytkownie mogloby byc uciazliwe.
*/