#include "CTreeDynamic.h"

CTreeDynamic::CTreeDynamic()
{
	
}


CTreeDynamic::~CTreeDynamic()
{
	delete pc_root;
}

void CTreeDynamic::vPrintTree() {
	pc_root->vPrintAllBelow();
}

bool CTreeDynamic::bMoveSubtree(CNodeDynamic *pcParentNode, CNodeDynamic *pcNewChildNode) {

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

void CTreeDynamic::vSetRoot(CNodeDynamic *root) {
	pc_root = root;
}

