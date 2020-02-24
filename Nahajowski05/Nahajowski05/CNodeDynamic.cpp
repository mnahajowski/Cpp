#include "CNodeDynamic.h"

int CNodeDynamic::index = 0;

CNodeDynamic::CNodeDynamic()
{
	i_val = 0; 
	pc_parent_node = NULL;
}


CNodeDynamic::~CNodeDynamic()
{
	for (int i = 0; i < (int)this->iGetChildrenNumber(); i++) {
		delete (this->pcGetChild(i));
	}

}

CNodeDynamic *CNodeDynamic::pcGetParent(CNodeDynamic *child) {
	if (child->pc_parent_node == NULL)
		return NULL;
	else
		return child->pc_parent_node;
}


CNodeDynamic *CNodeDynamic::pcGetChild(int iChildOffset) {
	if (iChildOffset <  this->iGetChildrenNumber())
	{
		return v_children[iChildOffset];
	}
	else {
		std::cout << "index out of bound" << std::endl;
		return NULL;
	}

}

void CNodeDynamic::vAddNewChild() {
	if (this != NULL) {
		this->v_children.push_back(new CNodeDynamic());

		pcGetChild((int)this->iGetChildrenNumber() - 1)->vSetValue(index);
		pcGetChild((int)this->iGetChildrenNumber() - 1)->pc_parent_node = this;
		index++;
	}
	else
		std::cout << "index out of bound" << std::endl;
}

void CNodeDynamic::vPrintAllBelow() {
	this->vPrint();
	for (int i = 0; i < (int)this->iGetChildrenNumber(); i++) {
		this->pcGetChild(i)->vPrintAllBelow();
	}
}

void CNodeDynamic::vRemoveChild(int iChildOffset) {
	if (iChildOffset < (int)this->iGetChildrenNumber())
	{
		this->v_children.erase(v_children.begin() + iChildOffset);
	}
	else
		std::cout << "index out of bound" << std::endl;
}

void CNodeDynamic::vAddNewChild(CNodeDynamic *child) {
	this->v_children.push_back(child);
	pcGetChild((int)this->iGetChildrenNumber() - 1)->pc_parent_node = this;
}


void CNodeDynamic::vSetParent(CNodeDynamic *child) {
	if (child == NULL)
		std::cout << "index out of bound" << std::endl;
	else
		child->pc_parent_node = this;
}
