#pragma once
#include <iostream>
#include <vector>
class  CNodeDynamic { 

public:       

	static int index;

	CNodeDynamic();
	~CNodeDynamic();

	void  vSetValue(int  iNewVal) { i_val = iNewVal; };
	int  iGetChildrenNumber() { return(v_children.size()); };
	void vSetParent(CNodeDynamic *child);

	void  vAddNewChild(); 

	CNodeDynamic  *pcGetChild(int  iChildOffset); 
	void vAddNewChild(CNodeDynamic *child);
	CNodeDynamic *pcGetParent(CNodeDynamic *child);
	void  vPrint() { std::cout << " " << i_val; };
	void  vPrintAllBelow();

	void vRemoveChild(int iChildOffset);

private:       

	std::vector<CNodeDynamic *>  v_children;
	CNodeDynamic *pc_parent_node;
	int  i_val; 

};//class  CNodeDynamic