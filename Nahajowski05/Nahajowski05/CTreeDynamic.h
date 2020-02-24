#pragma once
#include "CNodeDynamic.h"
class  CTreeDynamic {
	
public:       
	CTreeDynamic();
	~CTreeDynamic();
	CNodeDynamic *pcGetRoot() { return(pc_root); };
	void  vPrintTree();
	bool  bMoveSubtree(CNodeDynamic *pcParentNode, CNodeDynamic *pcNewChildNode);
	void vSetRoot(CNodeDynamic *root);

private:       
	CNodeDynamic *pc_root; 
};//class  CTreeDynamic