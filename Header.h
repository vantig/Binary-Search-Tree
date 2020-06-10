#pragma once
#include<iostream>

template<class T>

class Node
{
public:
	Node(const T& _data, Node* lPtr = nullptr, Node* rPtr = nullptr)
		: data(_data), leftPtr(lPtr), rightPtr(rPtr) {};
	~Node() = default;

	T data;
	Node* leftPtr;
	Node* rightPtr;
};

template<class T>

class BTree
{
public:
	BTree() : root(nullptr) {}
	BTree(const T& key) : root(new Node<T>(key)) {}
	~BTree() { deleteTree(root); }

	void print();
	void add(const T&);
	void erase(const T&);
	const T find(const T&) const;

private:
	Node<T>* root;

	Node<T>* add(Node<T>*, const T&);
	Node<T>* erase(Node<T>*, const T&);
	T& find(Node<T>*, const T&);
	void print(Node<T>*);
	void deleteTree(Node<T>*);
	Node<T>* findEdgeLeft(Node<T>*);
};


