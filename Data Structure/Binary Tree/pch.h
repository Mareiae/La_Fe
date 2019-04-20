#ifndef PCH_H
#define PCH_H
#include <iostream>
#include <stack>
#include <vector>
/*定义二叉树结点*/
template<class T>
struct TreeNode
{
	T value;
	TreeNode<T> * left_child;
	TreeNode<T> * right_child;
	TreeNode() :value(0), left_child(NULL), right_child(NULL) {};
	explicit TreeNode(const T& x) :value(x), left_child(NULL), right_child(NULL) {}
};
template<class T>
class BinaryTree
{
private:
	TreeNode<T> *pRoot;
public:
	BinaryTree();
	~BinaryTree();
	void create_Tree(T value);	//二叉树创建；
	TreeNode<T>* search_Tree(T value);	//关键查找；
	TreeNode<T>* find_minimun_Tree();	//查找最小值；
	TreeNode<T>* find_maximun_Tree();	//查找最大值；
	void drop_value_Tree(T key);	//结点删除；
	void delete_value_Tree(TreeNode<T>** pt);
	void recursive_preTree(TreeNode<T>* root);	//递归前序遍历；
	void preOrder_Tree();	//非递归前序遍历；
	void recursive_inTree(TreeNode<T>* root);	//递归中序遍历；
	void inOrder_Tree();	//非递归中序遍历；
	void recursive_postTree(TreeNode<T>* root);	//递归后序遍历；
	void postOrder_Tree();	//非递归后序遍历；
};
template<class T>
BinaryTree<T>::BinaryTree() :pRoot(NULL) {}
template<class T>
BinaryTree<T>::~BinaryTree()
{

}
template<class T>
void BinaryTree<T>::create_Tree(T value)	//创建二叉树；
{
	TreeNode<T>* m_node;	//待插入的新节点；
	TreeNode<T>* currentNode;
	bool flag = false;	//记录是否插入了新结点；

	m_node = new TreeNode<T>;
	m_node->value = value;
	m_node->left_child = nullptr;
	m_node->right_child = nullptr;
	if (pRoot == nullptr)
		pRoot = m_node;
	else
	{
		currentNode = pRoot;
		while (!flag)
		{
			if (value < currentNode->value)
			{
				if (currentNode->left_child == nullptr)
				{
					currentNode->left_child = m_node;
					flag = true;
				}
				else
					currentNode = currentNode->left_child;
			}
			else
			{
				if (currentNode->right_child == nullptr)
				{
					currentNode->right_child = m_node;
					flag = true;
				}
				else
					currentNode = currentNode->right_child;
			}
		}
	}
}
template<class T>
TreeNode<T> * BinaryTree<T>::search_Tree(T value)	//搜索关键字元素；
{
	TreeNode<T> *root = pRoot;
	while (root != NULL && value != root->value)
	{
		if (value < root->value)
			root = root->left_child;
		else
			root = root->right_child;
	}
	if (root)
		return root;
	else
		return{};
}
template<class T>
TreeNode<T>* BinaryTree<T>::find_minimun_Tree()	//查找最小值；
{
	TreeNode<T> *root = pRoot;
	while (root->left_child != nullptr)
		root = root->left_child;
	return root;
}
template<class T>
TreeNode<T>* BinaryTree<T>::find_maximun_Tree()	//查找最大值；
{
	TreeNode<T> *root = pRoot;
	while (root->right_child != nullptr)
		root = root->right_child;
	return root;
}
template<class T>
void BinaryTree<T>::drop_value_Tree(T key)	//删除结点；
{
	TreeNode<T> **pn = &pRoot;
	while ((*pn) && (*pn)->value != key)
	{
		if (key < (*pn)->value)
		{
			pn = &(*pn)->left_child;
		}
		if (key > (*pn)->value)
		{
			pn = &(*pn)->right_child;
		}
	}
	delete_value_Tree(pn);
}
template<class T>
void BinaryTree<T>::delete_value_Tree(TreeNode<T>** pn)	//删除结点；
{
	TreeNode<T> *q, *s;
	if ((*pn)->left_child == nullptr && (*pn)->right_child == nullptr)
	{
		*pn = NULL;
	}
	else if((*pn)->left_child == nullptr)
	{
		*pn = (*pn)->right_child;
	}
	else if ((*pn)->right_child == nullptr)
	{
		*pn = (*pn)->left_child;
	}
	else
	{
		q = *pn;
		s = q->left_child;
		while (s->right_child)
		{
			q = s;
			s = s->right_child;
		}
		(*pn)->value = s->value;
		if (q != *pn)
		{
			q->right_child = s->left_child;
		}
		else
			q->left_child = s->left_child;
	}
}
template<class T>
void BinaryTree<T>::recursive_preTree(TreeNode<T>* root)	//递归前序遍历；
{
	if (pRoot->value != NULL)
	{
		std::cout << pRoot->value << "	";
		recursive_preTree(root->left_child);
		recursive_preTree(root->right_child);
	}
}
template<class T>
void BinaryTree<T>::preOrder_Tree()	//非递归前序遍历；
{
	if (pRoot == nullptr)
		return;
	std::stack<TreeNode<T>*> msg;
	msg.push(pRoot);
	TreeNode<T> * pt = NULL;
	while (!msg.empty())
	{
		pt = msg.top();
		msg.pop();
		while (pt)
		{
			std::cout << pt->value << " ";
			if (pt->right_child)
				msg.push(pt->right_child);
			pt = pt->left_child;
		}
	}
	std::cout << std::endl;
}
template<class T>
void BinaryTree<T>::recursive_inTree(TreeNode<T>* root)	//递归中序遍历；
{
	if (pRoot != NULL)
	{
		recursive_inTree(root->left_child);
		std::cout << pRoot->value << " ";
		recursive_inTree(root->right_child);
	}
}
template<class T>
void BinaryTree<T>::inOrder_Tree()	//非递归中序遍历；
{
	if (pRoot == nullptr)
		return;
	TreeNode<T> * root = pRoot;
	std::stack<TreeNode<T>*> msg;
	TreeNode<T> * pre = nullptr;
	while (root || !msg.empty())
	{
		if (root)
		{
			msg.push(root);
			root = root->left_child;
		}
		else
		{
			root = msg.top();
			std::cout << root->value << " ";
			msg.pop();
			root = root->right_child;
		}
	}
	std::cout << std::endl;
}
template<class T>
void BinaryTree<T>::recursive_postTree(TreeNode<T>* root)	//递归后序遍历；
{
	if (pRoot != nullptr)
	{
		recursive_postTree(root->left_child);
		recursive_postTree(root->right_child);
		std::cout << pRoot->value << " ";
	}
}
template<class T>
void BinaryTree<T>::postOrder_Tree()	//非递归后序遍历；
{
	if (pRoot == nullptr)
		return;
	std::stack<TreeNode<T> *> msg;
	msg.push(pRoot);
	TreeNode<T> *root = pRoot->left_child;
	TreeNode<T> *pre = NULL;
	while (!msg.empty())
	{
		while (root && root != pre)
		{
			msg.push(root);
			root = root->left_child;
		}
		if (msg.empty())
			return;
		root = msg.top();
		if(root->right_child && root->right_child != pre)
		{
			root = root->right_child;
		}
		else
		{
			std::cout << root->value << " ";
			pre = root;
			msg.pop();
		}
	}
	std::cout << std::endl;
}

#endif //PCH_H
