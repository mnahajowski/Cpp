#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
template< typename T >  class  CNodeDynamic {

public:       

	CNodeDynamic();
	~CNodeDynamic();

	void  vSetValue(T  iNewVal) { i_val = iNewVal;  };
	int  iGetChildrenNumber() { return(v_children.size()); };
	void vSetParent(CNodeDynamic *child);

	void  vAddNewChild();

	CNodeDynamic<T>  *pcGetChild(int  iChildOffset);

	void wypisz2(int poziom);
	void vAddNewChild(CNodeDynamic<T> *child);
	CNodeDynamic<T> *pcGetParent(CNodeDynamic<T> *child);
	void  vPrint() { std::cout << " " << i_val; };

	void  vPrintAllBelow();
	void wypisz(CNodeDynamic *root, int poziom);
	void vRemoveChild(int iChildOffset);

	std::string sGetKnownType() {
		std::string  s_type = "Unknown";
		return(s_type);
	};

private:       

	std::vector<CNodeDynamic<T> *>  v_children;
	CNodeDynamic<T> *pc_parent_node;
	T  i_val; 

};//class  CNodeDynamic
template< typename T >
CNodeDynamic<T>::CNodeDynamic() {

	this->i_val = i_val;
	//i_val = 0;
	pc_parent_node = NULL;
}



template< typename T >
CNodeDynamic<T>::~CNodeDynamic()
{
	for (int i = 0; i < (int)this->iGetChildrenNumber(); i++) {
		delete (this->pcGetChild(i));
	}
}

template< typename T >
CNodeDynamic<T> *CNodeDynamic<T>::pcGetChild(int iChildOffset) {
	if (iChildOffset < this->iGetChildrenNumber())
	{
		return v_children[iChildOffset];
	}
	else {
		std::cout << "index out of bound" << std::endl;
		return NULL;
	}
}

template< typename T >
void CNodeDynamic<T>::vAddNewChild() {
	if (this != NULL) {
		this->v_children.push_back(new CNodeDynamic<T>());
		//pcGetChild((int)this->iGetChildrenNumber() - 1)->vSetValue(rand() % 10 + 1);
		pcGetChild((int)this->iGetChildrenNumber() - 1)->pc_parent_node = this;
	}
	else
		std::cout << "index out of bound" << std::endl;
}

template< typename T >
void CNodeDynamic<T>::vPrintAllBelow() {
	this->vPrint();
	for (int i = 0; i < (int)this->iGetChildrenNumber(); i++) {
		this->pcGetChild(i)->vPrintAllBelow();
	}
}

template<>
void CNodeDynamic<std::string>::vSetValue(std::string  iNewVal) {
	i_val = "a";
}
/*
template <>
void CNodeDynamic<std::string>::wypisz(int poziom,std::string napis) {

	
	for (int i = 0; i < poziom; i++) {
		std::cout << "|\t";
	}
	this->vPrint();
	std::cout << "\n";
	for (int i = 0; i < (int)this->iGetChildrenNumber(); i++) {
		if (this->pcGetChild(i) != NULL)
			this->pcGetChild(i)->wypisz(poziom + 1);
	}
}
*/
/*
template <>
void CNodeDynamic<double>::wypisz(int poziom,std::string napis) {


	for (int i = 0; i < poziom; i++) {
		std::cout << "|\t";
	}
	this->vPrint();
	std::cout << "\n";
	for (int i = 0; i < (int)this->iGetChildrenNumber(); i++) {
		if (this->pcGetChild(i) != NULL)
			this->pcGetChild(i)->wypisz(poziom + 1,napis);
	}
}
*/
template< typename T >
void CNodeDynamic<T>::wypisz2(int poziom) {


	for (int i = 0; i < poziom; i++) {
		std::cout << "|\t";
	}
	std::cout << this->sGetKnownType();
	this->vPrint();
	std::cout << "\n";
	for (int i = 0; i < (int)this->iGetChildrenNumber(); i++) {
		if (this->pcGetChild(i) != NULL)
			this->pcGetChild(i)->wypisz2(poziom + 1);
	}
}

template<>
void CNodeDynamic<std::string>::vAddNewChild() {
	if (this != NULL) {
		this->v_children.push_back(new CNodeDynamic<std::string>());
		//pcGetChild((int)this->iGetChildrenNumber() - 1)->vSetValue(rand() % 10 + 1);
		pcGetChild((int)this->iGetChildrenNumber() - 1)->pc_parent_node = this;
	}
	else
		std::cout << "index out of bound" << std::endl;
}
/*
template< typename T >
void CNodeDynamic<T>::vRemoveChild(int iChildOffset) {
	if (iChildOffset < (int)this->iGetChildrenNumber())
	{
		this->v_children.erase(v_children.begin() + iChildOffset);
	}
	else
		std::cout << "index out of bound" << std::endl;
}*/
/*
template <>
std::string CNodeDynamic<double>::sGetKnownType() {
	std::string  s_type = "DOUBLE";
	return(s_type);
}

template <>
std::string CNodeDynamic<std::string>::sGetKnownType() {
	std::string  s_type = "string";
	return(s_type);
}
*/
template <>
std::string CNodeDynamic<int>::sGetKnownType() {
	std::string  s_type = "INT";
	return(s_type);
}

template <>
std::string CNodeDynamic<double>::sGetKnownType() {
	std::string  s_type = "DOUBLE";
	return(s_type);
}

template <>
std::string CNodeDynamic<std::string>::sGetKnownType() {
	std::string  s_type = "string";
	return(s_type);
}

template< typename T >
void CNodeDynamic<T>::vAddNewChild(CNodeDynamic<T> *child) {
	this->v_children.push_back(child);
	pcGetChild((int)this->iGetChildrenNumber() - 1)->pc_parent_node = this;
}

template< typename T >
void CNodeDynamic<T>::vSetParent(CNodeDynamic<T> *child) {
	if (child == NULL)
		std::cout << "index out of bound" << std::endl;
	else
		child->pc_parent_node = this;
}

template< typename T >
CNodeDynamic<T> *CNodeDynamic<T>::pcGetParent(CNodeDynamic<T> *child) {
	if (child->pc_parent_node == NULL)
		return NULL;
	else
		return child->pc_parent_node;
}

/*
void CNodeStatic::wypisz(CNodeStatic *root, int poziom) {

	for (int i = 0; i < poziom; i++) {
		std::cout << "|\t";
	}
	root->vPrint();
	std::cout << "\n";
	for (int i = 0; i < (int)root->iGetChildrenNumber(); i++) {
		if (root->pcGetChild(i) != NULL)
			root->wypisz(root->pcGetChild(i), poziom + 1);
	}

}*/

