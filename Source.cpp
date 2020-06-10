#include "Header.h"
template<class T>
Node<T>* BTree<T>::add(Node<T>* root, const T& key)
{
	if (root == nullptr)
	{
		Node<T>* newRoot = new Node<T>(key);
		root = newRoot;
		return root;
	}
	else
	{
		if (key < root->data)
			root->leftPtr = add(root->leftPtr, key);
		else
			root->rightPtr = add(root->rightPtr, key);
	}
	return root;
}

template<class T>
Node<T>* BTree<T>::erase(Node<T>* root, const T& key)
{
	Node<T>* temp = nullptr;

	if (root == nullptr)
		return nullptr;
	else if (key < root->data)
		root->leftPtr = erase(root->leftPtr, key);
	else if (key > root->data)
		root->rightPtr = erase(root->rightPtr, key);
	//удаление в случае наличия одного потомка или отсутствия обоих
	else if (key == root->data)
	{
		temp = root;
		if (root->leftPtr == nullptr)
		{
			temp = root->rightPtr;
			delete root;
			return temp;
		}
		else if (root->rightPtr == nullptr)
		{
			temp = root->leftPtr;
			delete root;
			return temp;
		}
		//удаление при наличии обоих потомков
		Node<T>* tempKids = findEdgeLeft(root->rightPtr);
		root->data = tempKids->data;
		root->rightPtr = erase(root->rightPtr, key);
	}

	return root;
}

//template<class T>
//T& find(Node<T>* root, const T& key)
//{
//
//}

template<class T>
void BTree<T>::print(Node<T>* root)
{
	if (root != nullptr)
	{
		print(root->leftPtr);
		std::cout << root->data << " ";
		print(root->rightPtr);
	}
	else return;
}

template<class T>
void BTree<T>::deleteTree(Node<T>* root)
{
	if (root != nullptr)
	{
		deleteTree(root->leftPtr);
		deleteTree(root->rightPtr);
		delete root;
	}
	else
		return;
}


template<class T>
void BTree<T>::print()
{
	print(root);
}

template<class T>
void BTree<T>::add(const T& key)
{
	root = add(root, key);
}

template<class T>
void BTree<T>::erase(const T& key)
{
	root = erase(root, key);
}

//template<class T>
//const T find(const T&) const

template<class T>
Node<T>* BTree<T>::findEdgeLeft(Node<T>* root)
{
	Node<T>* cur = root;
	while (cur != nullptr && cur->leftPtr != nullptr)
		cur = cur->leftPtr;

	return cur;
}
