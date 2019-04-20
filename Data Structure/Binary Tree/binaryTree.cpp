#include "pch.h"
int main()
{
	std::vector<int> vet = {5,12,2,45,41,12,14,10,6,1,45};
	BinaryTree<int> bTree;
	int length = vet.size();
	for (int i = 0; i < length; ++i)
		bTree.create_Tree(vet[i]);
	bTree.postOrder_Tree();
	bTree.inOrder_Tree();
	bTree.preOrder_Tree();
	TreeNode<int> * p1 =  bTree.search_Tree(100);
	if (p1)
		std::cout << p1->value << std::endl;
	else
		std::cout << "sorry" << std::endl;
	TreeNode<int>* p2 = bTree.find_minimun_Tree();
	std::cout << p2->value << std::endl;
	TreeNode<int>* p3 = bTree.find_maximun_Tree();
	std::cout << p3->value << std::endl;
	bTree.drop_value_Tree(1);

}