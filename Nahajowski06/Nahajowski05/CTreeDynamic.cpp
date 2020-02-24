#include "CTreeDynamic.h"
/*
template< typename T >
CTreeDynamic<T>::CTreeDynamic()
{
	
}*/
/*
template< typename T >
CTreeDynamic<T>::~CTreeDynamic()
{
	delete pc_root;
}
*/
/*
template< typename T >
void CTreeDynamic<T>::vPrintTree() {
	pc_root->vPrintAllBelow();
}*/
/*
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
}*/
/**
template< typename T >
void CTreeDynamic<T>::vSetRoot(CNodeDynamic<T> *root) {
	pc_root = root;
}
*/
/*
template <typename T>
std::string CTreeDynamic<T>::sGetKnownType() {
	std::string s_type = "Unknown";
	return s_type;
}

template <>
std::string CTreeDynamic<int>::sGetKnownType() {
	std::string s_type = "INT";
	return s_type;
}
*/
