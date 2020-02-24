#include <iostream>
#include "CNodeStatic.h"
#include "CTreeStatic.h"
#include "CNodeDynamic.h"
#include "CTreeDynamic.h"
void  v_tree_test(CNodeStatic *c_root) { 

	
	c_root->vAddNewChild();
	c_root->vAddNewChild();

	c_root->pcGetChild(0)->vSetValue(1);
	c_root->pcGetChild(1)->vSetValue(2);

	c_root->pcGetChild(0)->vAddNewChild();
	c_root->pcGetChild(0)->vAddNewChild();

	c_root->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	c_root->pcGetChild(0)->pcGetChild(1)->vSetValue(12);

	c_root->pcGetChild(1)->vAddNewChild();
	c_root->pcGetChild(1)->vAddNewChild();

	c_root->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
	c_root->pcGetChild(1)->pcGetChild(1)->vSetValue(22);

	//c_root->vPrintAllBelow();
	
	//c_root->pcGetChild(0)->pcGetChild(1)->vPrintUp();
}
void  v_tree_test(CNodeDynamic *c_root) {


	c_root->vAddNewChild();
	c_root->vAddNewChild();

	c_root->pcGetChild(0)->vSetValue(1);
	c_root->pcGetChild(1)->vSetValue(2);

	c_root->pcGetChild(0)->vAddNewChild();
	c_root->pcGetChild(0)->vAddNewChild();

	c_root->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	c_root->pcGetChild(0)->pcGetChild(1)->vSetValue(12);
	/*
	c_root->pcGetChild(1)->vAddNewChild();
	c_root->pcGetChild(1)->vAddNewChild();

	c_root->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
	c_root->pcGetChild(1)->pcGetChild(1)->vSetValue(22);*/

	//c_root->vPrintAllBelow();

}
int main()
{
	
	/*
	CNodeStatic obj1;
	obj1.vAddNewChild();
	obj1.vAddNewChild();
	//obj1.vPrintAllBelow();
	obj1.pcGetChild(1)->vAddNewChild();
	obj1.vPrintAllBelow();
	std::cout << "\n";
	obj1.pcGetChild(1)->vPrintAllBelow();*/
	//v_tree_test();
	/*
	CTreeStatic obj3;
	v_tree_test(obj3.pcGetRoot());
	obj3.vPrintTree();
	
	//CTreeStatic obj3(&c_root3);
	//c_root3.vPrintAllBelow();
	
	
	//obj1.vSetRoot(&c_root);
	//obj1.vPrintTree();
	//*obj3.pcGetRoot() = c_root3;

	//obj3.vPrintTree();
	std::cout << "\n";
	
	
	//CNodeStatic  c_root4;
	//CTreeStatic obj4(&c_root4);
	//v_tree_test(&c_root4);
	//CTreeStatic obj4(&c_root4);
	CTreeStatic obj4;
	v_tree_test(obj4.pcGetRoot());
	obj4.vPrintTree();

	//*obj4.pcGetRoot() = c_root4;
	//obj4.vPrintTree();

	obj3.bMoveSubtree(obj3.pcGetRoot(), obj4.pcGetRoot()->pcGetChild(0));

	obj3.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vPrintUp();


	std::cout << "\n";
	
	std::cout << "\n";
	obj3.vPrintTree();
	std::cout << "\n";
	obj4.vPrintTree();
	std::cout << "\n";

	CTreeDynamic *obj7 = new CTreeDynamic();
	obj7->vSetRoot(new CNodeDynamic());
	v_tree_test(obj7->pcGetRoot());
	std::cout << "\n";
	obj7->vPrintTree();

	CTreeDynamic *obj8 = new CTreeDynamic();
	obj8->vSetRoot(new CNodeDynamic());
	v_tree_test(obj8->pcGetRoot());
	std::cout << "\n";
	obj8->vPrintTree();

	obj7->bMoveSubtree(obj7->pcGetRoot(), (obj8->pcGetRoot())->pcGetChild(1));
	std::cout << "\n";

	std::cout << "\n";
	obj7->vPrintTree();
	std::cout << "\n";
	obj8->vPrintTree();


	delete obj7;
	delete obj8;
	*/
	
	
	std::cout << "\n";
	CTreeStatic obj10;
	v_tree_test(obj10.pcGetRoot());
	//obj10.vPrintTree();
	std::cout << "\n";
	//std::cout << obj10.pcGetRoot()->vGetValue();
	obj10.wypisz(obj10.pcGetRoot());
	std::cout << "\n";

	obj10.pcGetRoot()->wypisz2(0);


	/*
	CNodeDynamic *c_root = new CNodeDynamic();
	
	c_root->vAddNewChild();
	c_root->vAddNewChild();

	c_root->pcGetChild(0)->vSetValue(1);
	c_root->pcGetChild(1)->vSetValue(2);

	c_root->pcGetChild(0)->vAddNewChild();
	c_root->pcGetChild(0)->vAddNewChild();

	c_root->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	c_root->pcGetChild(0)->pcGetChild(1)->vSetValue(12);

	c_root->pcGetChild(1)->vAddNewChild();
	c_root->pcGetChild(1)->vAddNewChild();

	c_root->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
	c_root->pcGetChild(1)->pcGetChild(1)->vSetValue(22);
	//CTreeDynamic *obj1 = new CTreeDynamic(c_root);
	//c_root->vPrintAllBelow();
	//CTreeDynamic *obj1 = new CTreeDynamic();
	//v_tree_test(obj1.pcGetRoot());
	CTreeDynamic *obj1 = new CTreeDynamic(c_root);
	
	obj1->vPrintTree();
	
	//delete c_root;
	std::cout << "\n";
	CNodeDynamic *c_root2 = new CNodeDynamic();
	CTreeDynamic *obj2 = new CTreeDynamic(c_root2);
	

	

	c_root2->vAddNewChild();
	c_root2->vAddNewChild();

	c_root2->pcGetChild(0)->vSetValue(1);
	c_root2->pcGetChild(1)->vSetValue(2);

	c_root2->pcGetChild(0)->vAddNewChild();
	c_root2->pcGetChild(0)->vAddNewChild();

	c_root2->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	c_root2->pcGetChild(0)->pcGetChild(1)->vSetValue(12);

	c_root2->pcGetChild(1)->vAddNewChild();
	c_root2->pcGetChild(1)->vAddNewChild();

	c_root2->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
	c_root2->pcGetChild(1)->pcGetChild(1)->vSetValue(22);

	obj2->vPrintTree();

	std::cout << "\n";
	obj1->bMoveSubtree(obj1->pcGetRoot(), (obj2->pcGetRoot())->pcGetChild(1));
	std::cout << "\n";

	std::cout << "\n";
	obj1->vPrintTree();
	std::cout << "\n";
	obj2->vPrintTree();
	//c_root.pcGetChild(0)->pcGetChild(1)->vPrintUp();
	
	delete obj1;
	delete obj2;
	
	
	*/
	
}

/*1. ¯eby wszystkie wêz³y zosta³y usuniête, przed usuniêciem danego wêz³a musimy sprawdziæ, czy posiada on jakieœ dzieci,
	a jeœli tak, wywo³aæ destruktor dla ka¿dego z tych dzieci, wtedy dopiero mo¿na usun¹æ ten wêze³

	2. By wykonaæ vPrintUp() potrzebne nam jest pole, które dla danego wêz³a bêdzie przechowywaæ informacjê o rodzicu danego wêz³a,
		w ten sposób bêdziemy mogli przesuwaæ siê w górê drzewa

3. Klasy CTreeStatic i CNodeStatic powinny byæ w osobnych plikach Ÿród³owych (konwencja programowania, w której ka¿da klasa ma 
	w³asny plik Ÿród³owy)

4. W destruktorze obiektów dynamicznych musimy sami zaj¹æ siê usuniêciem wszystkich wêz³ów, przy obiektach statycznych nie.

5. Metodê bMoveSubTree ³atwiej by³o wykonaæ dla klas CTreeDynamic i CNodeDynamic, przechowywanie obiektów alokowanych statycznie
	ma du¿o wad. Mog¹ siê tworzyæ liczne nadmierne kopie obiektów z listy, które bêd¹ usuwane.
	*/

