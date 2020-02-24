#include "CNodeStatic.h"

int CNodeStatic::index = 0;

CNodeStatic::CNodeStatic() {
	i_val = 0;
	pc_parent_node = NULL;
}


CNodeStatic::~CNodeStatic(){

}

void CNodeStatic::DestroyRecursive(CNodeStatic *root) {
	
}

CNodeStatic *CNodeStatic::pcGetChild(int iChildOffset) {
	if (iChildOffset < (int)this->iGetChildrenNumber())
	{
		return &v_children[iChildOffset];
	}
	else {
		std::cout << "index out of bound" << std::endl;
		return NULL;
	}
	
}

CNodeStatic::CNodeStatic(const CNodeStatic &node) {

	 this->i_val = node.i_val;
	 this->pc_parent_node = node.pc_parent_node;
	 this->v_children = node.v_children;
	 for (int i = 0; i < this->iGetChildrenNumber(); i++) {
		 v_children[i].pc_parent_node = this;
	 }
}

void CNodeStatic::vSetParent(CNodeStatic *child) {
	if(child == NULL)
		std::cout << "index out of bound" << std::endl;
	else
		child->pc_parent_node = this;
}


void CNodeStatic::vAddNewChild() {

	
	if (this != NULL) {
		this->v_children.push_back(CNodeStatic());
		pcGetChild((int)this->iGetChildrenNumber() - 1)->vSetValue(index);
		pcGetChild((int)this->iGetChildrenNumber() - 1)->pc_parent_node = this;
		index++;
	}
	else 
		std::cout << "index out of bound" << std::endl;
}

void CNodeStatic::vPrintUp() {
	if (this != NULL) {
		this->vPrint();
		if (this->pcGetParent(this) != NULL)
			this->pcGetParent(this)->vPrintUp();
	}
}

CNodeStatic *CNodeStatic::pcGetParent(CNodeStatic *child) {
	if (child->pc_parent_node == NULL)
		return NULL;
	else
		return child->pc_parent_node;
}
void CNodeStatic::vPrintAllBelow() {
	this->vPrint();
	for (int i = 0; i < (int)this->iGetChildrenNumber(); i++) {
		if(this->pcGetChild(i) != NULL)
			this->pcGetChild(i)->vPrintAllBelow();
	}
}

void CNodeStatic::vAddNewChild(CNodeStatic *child) {
	this->v_children.push_back(*child);
	pcGetChild((int)this->iGetChildrenNumber() - 1)->pc_parent_node = this;
}

void CNodeStatic::vRemoveChild(int iChildOffset) {
	if (iChildOffset < (int)this->iGetChildrenNumber()) {
		this->v_children.erase(v_children.begin() + iChildOffset);
	}
	else
		std::cout << "index out of bound" << std::endl;
}

void CNodeStatic::wypisz(CNodeStatic *root, int poziom) {
	
	for (int i = 0; i < poziom; i++) {
		std::cout << "|\t";
	}
	root->vPrint();
	std::cout << "\n";
	for (int i = 0; i < (int)root->iGetChildrenNumber(); i++) {
		if (root->pcGetChild(i) != NULL)
			root->wypisz(root->pcGetChild(i), poziom+1);
	}

}

void CNodeStatic::wypisz2(int poziom) {
	for (int i = 0; i < poziom; i++) {
		std::cout << "|\t";
	}
	this->vPrint();
	std::cout << "\n";
	for (int i = 0; i < (int)this->iGetChildrenNumber(); i++) {
		if (this->pcGetChild(i) != NULL)
			this->pcGetChild(i)->wypisz2(poziom + 1);
	}
}
/*
	if (this != NULL) {
		for (int i = 0; i < (int)root->iGetChildrenNumber(); i++) {
			//std::cout <<"jestem";
			if (root->pcGetChild(i) != NULL) {

				for (int i = 0; i < poziom; i++) {
					std::cout << "|";
					//std::cout << poziom;
				}


				//*root.wypisz(this->pcGetChild(i), poziom + 1);
				root->wypisz(this->pcGetChild(i), poziom + 1);
			}
			this->vPrint();
			std::cout << "\n";
			//this->pcGetChild(i)->vPrintAllBelow();
		}
	}
	*/