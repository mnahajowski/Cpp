#pragma once
#include "CNodeStatic.h"
class CTreeStatic
{
public:
	CTreeStatic();
	CTreeStatic(CNodeStatic *root);
	~CTreeStatic();

	CNodeStatic  *pcGetRoot() { return(&c_root); }
	void  vPrintTree();
	void vSetRoot(CNodeStatic *root);
	bool  bMoveSubtree(CNodeStatic *pcParentNode, CNodeStatic *pcNewChildNode);
	void wypisz(CNodeStatic *root);
private:
	CNodeStatic  c_root;
};

