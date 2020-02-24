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
3. Obiekt statyczny mo¿e spaœæ ze stosu a wskaŸnik bêdzie wtedy wskazywa³ na nulla, nie wiedz¹c o tym, mo¿e siê staæ, ¿e bêdziemy
	próbowali ponownie usun¹æ pamiêæ, ktora juz zostala usunieta

	Zamiast wskaŸnika na konkretny typ moglibyœmy przechowywaæ wskaŸnik typu void. Zalet¹ by³oby to, ¿e moglibyœmy wykorzystywaæ go do
	obiektow dowolnego typu. Znacz¹c¹ wad¹ jest jednak to, ¿e przy ka¿dej próbie u¿ycia go trzeba by by³o zrzutowaæ go na odpowiedni
	typ, dla ktorego chccielibysmy go u¿yæ, wiec uzytkownie mogloby byc uciazliwe.
*/