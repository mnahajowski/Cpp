#include "CTreeStatic.h"
#include "CNodeStatic.h"

CTreeStatic::CTreeStatic()
{
	
}

CTreeStatic::CTreeStatic(CNodeStatic *root)
{
	c_root = *root;
}

CTreeStatic::~CTreeStatic()
{
}

void CTreeStatic::vPrintTree() {
	c_root.vPrintAllBelow();
}

void CTreeStatic::vSetRoot(CNodeStatic *root) {
	this->c_root = *root;
}

bool CTreeStatic::bMoveSubtree(CNodeStatic *pcParentNode, CNodeStatic *pcNewChildNode) {

	
	
	if (pcNewChildNode->pcGetParent(pcNewChildNode) != NULL) {
		for (int i = 0; i < pcNewChildNode->pcGetParent(pcNewChildNode)->iGetChildrenNumber(); i++) {
			if ((pcNewChildNode->pcGetParent(pcNewChildNode)->pcGetChild(i)->vGetValue()) == pcNewChildNode->vGetValue()) {
				pcParentNode->vAddNewChild(pcNewChildNode);
				pcNewChildNode->pcGetParent(pcNewChildNode)->vRemoveChild(i);
				//pcOldParentNode->vPrintAllBelow();
				std::cout << "\n";
			}
		}
	}
	std::cout << "\n";
	return true;
}

void CTreeStatic::wypisz(CNodeStatic *root) {
	root->wypisz(root, 0);
}
