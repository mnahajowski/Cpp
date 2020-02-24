#pragma once
#include <vector>
#include <iostream>
class CNodeStatic
{
public:

	static int index;


	CNodeStatic();
	~CNodeStatic();
	CNodeStatic(const CNodeStatic &node);
	void DestroyRecursive(CNodeStatic *root);
	void vSetValue(int iNewVal) { i_val = iNewVal; };
	int vGetValue() { return i_val; };
	void vSetParent(CNodeStatic *child);

	
	int iGetChildrenNumber() { return(v_children.size()); };
	void vAddNewChild();
	void vAddNewChild(CNodeStatic *child);
	CNodeStatic *pcGetChild(int iChildOffset);
	CNodeStatic *pcGetParent(CNodeStatic *child);

	void vPrint() { std::cout << " " << i_val; };
	void vPrintAllBelow();
	void vPrintUp();

	void vRemoveChild(int iChildOffset);
	void wypisz(CNodeStatic *root, int poziom);
	void wypisz2(int poziom);

private:
	std::vector<CNodeStatic> v_children;
	CNodeStatic *pc_parent_node;
	int i_val;
};

