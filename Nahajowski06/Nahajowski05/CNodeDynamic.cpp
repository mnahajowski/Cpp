#include "CNodeDynamic.h"
/*
template< typename T >
int CNodeDynamic<T>::index = 0;
*/
//CNodeDynamic<T>::CNodeDynamic(T i_val)


/*CNodeDynamic<T>::~CNodeDynamic()
{
	
}*/
/*
template< typename T >
CNodeDynamic<T> *CNodeDynamic<T>::pcGetParent(CNodeDynamic<T> *child) {
	if (child->pc_parent_node == NULL)
		return NULL;
	else
		return child->pc_parent_node;
}*/
/*
template< typename T >
CNodeDynamic<T> *CNodeDynamic<T>::pcGetChild(int iChildOffset) {
	if (iChildOffset <  this->iGetChildrenNumber())
	{
		return v_children[iChildOffset];
	}
	else {
		std::cout << "index out of bound" << std::endl;
		return NULL;
	}

}*/
//template< typename T >
/*
void CNodeDynamic<T>::vAddNewChild() {
	if (this != NULL) {
		this->v_children.push_back(new CNodeDynamic<T>());

		pcGetChild((int)this->iGetChildrenNumber() - 1)->vSetValue(index);
		pcGetChild((int)this->iGetChildrenNumber() - 1)->pc_parent_node = this;
		index++;
	}
	else
		std::cout << "index out of bound" << std::endl;
}*/
/*
template< typename T >
void CNodeDynamic<T>::vPrintAllBelow() {
	this->vPrint();
	for (int i = 0; i < (int)this->iGetChildrenNumber(); i++) {
		this->pcGetChild(i)->vPrintAllBelow();
	}
}*/
/*
template< typename T >
void CNodeDynamic<T>::vRemoveChild(int iChildOffset) {
	if (iChildOffset < (int)this->iGetChildrenNumber())
	{
		this->v_children.erase(v_children.begin() + iChildOffset);
	}
	else
		std::cout << "index out of bound" << std::endl;
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
*/