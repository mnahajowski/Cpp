#pragma once
#include "CRefCounter.h"
#include <vector>
template< typename T > class CMySmartPointer {
public: 
	CMySmartPointer(T  *pcPointer);

	CMySmartPointer(const CMySmartPointer<T>  &pcOther);
	~CMySmartPointer();
	T & operator*() { return(*pc_pointer); };
	T * operator->() { return(pc_pointer); };

	CMySmartPointer operator=(const CMySmartPointer<T> &pcOther);

private: 
	CRefCounter  *pc_counter;
	T  *pc_pointer;


};//class CMySmartPointer
template< typename T >

CMySmartPointer<T>::CMySmartPointer(T  *pcPointer) {
	pc_pointer = pcPointer;
	pc_counter = new CRefCounter();
	pc_counter->iAdd();
}
template< typename T >
CMySmartPointer<T>::CMySmartPointer(const CMySmartPointer  &pcOther) {
	pc_pointer = pcOther.pc_pointer;
	pc_counter = pcOther.pc_counter;
	pc_counter->iAdd();
}//CMySmartPointer(const CMySmartPointer  &pcOther) 

template< typename T >
CMySmartPointer<T>::~CMySmartPointer() {
	
	if (!pc_counter->iDec()) {
		delete  pc_pointer;
		delete  pc_counter;
		std::cout << "Zwolniona pamiec\n";
	}//if (pc_counter->iDec())

	if (pc_counter->iGet() < 1)
		std::cout << "0";
	else
		std::cout << "Po zwolnieniu " << pc_counter->iGet() << "\n";
}

template <typename T>
CMySmartPointer<T> CMySmartPointer<T>::operator=(const CMySmartPointer<T> &pcOther) {


	if (this != &pcOther) {

		this->pc_counter->iDec();

		if (!this->pc_counter) {
			delete this->pc_pointer;
			delete this->pc_counter;
		}
		this->pc_pointer = pcOther.pc_pointer;
		this->pc_counter = pcOther.pc_counter;
		this->pc_counter->iAdd();
	}

	std::cout << "Po przypisaniu " << this->pc_counter->iGet() << "\n";

	return *this;
}
