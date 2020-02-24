#pragma once
#include "CNodeDynamic.h"
template< typename T >class  CTreeDynamic {
	
public:       
	CTreeDynamic<T>() {};
	~CTreeDynamic();
	CNodeDynamic<T> *pcGetRoot() { return(pc_root); };
	void  vPrintTree();
	bool  bMoveSubtree(CNodeDynamic<T> *pcParentNode, CNodeDynamic<T> *pcNewChildNode);
	void vSetRoot(CNodeDynamic<T> *root);
	std::string sGetKnownType() {
		std::string  s_type = "Unknown";
		return(s_type);
	};
	void wypisz2();

private:       
	CNodeDynamic<T> *pc_root;

};//class  CTreeDynamic
template< typename T >
CTreeDynamic<T>::~CTreeDynamic()
{
	delete pc_root;
}

template< typename T >
void CTreeDynamic<T>::vPrintTree() {
	pc_root->vPrintAllBelow();
}

template< typename T >
void CTreeDynamic<T>::vSetRoot(CNodeDynamic<T> *root) {
	pc_root = root;
}
template<>
void CTreeDynamic<std::string>::vSetRoot(CNodeDynamic<std::string> *root) {
	pc_root = root;
}

template< typename T >
bool CTreeDynamic<T>::bMoveSubtree(CNodeDynamic<T> *pcParentNode, CNodeDynamic<T> *pcNewChildNode) {

	if (pcNewChildNode->pcGetParent(pcNewChildNode) != NULL) {
		for (int i = 0; i < pcNewChildNode->pcGetParent(pcNewChildNode)->iGetChildrenNumber(); i++) {
			if ((pcNewChildNode->pcGetParent(pcNewChildNode)->pcGetChild(i)) == pcNewChildNode) {
				pcNewChildNode->pcGetParent(pcNewChildNode)->vRemoveChild(i);
			}
		}
	}

	pcParentNode->vAddNewChild(pcNewChildNode);

	return true;
}

template <>
std::string CTreeDynamic<int>::sGetKnownType() {
	std::string  s_type = "INT";
	return(s_type);
}

template <>
std::string CTreeDynamic<double>::sGetKnownType() {
	std::string  s_type = "DOUBLE";
	return(s_type);
}

template <>
void CTreeDynamic<std::string>::wypisz2() {
	//this->pcGetRoot.wypisz(this->pcGetRoot(), sGetKnownType());
	this->pcGetRoot()->wypisz2(0);
	
}
template <>
void CTreeDynamic<double>::wypisz2() {
	this->pcGetRoot()->wypisz2(0);
}

