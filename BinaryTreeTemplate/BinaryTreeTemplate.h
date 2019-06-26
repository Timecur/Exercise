#pragma once

#include <iostream>

using namespace std;

//typedef int DataType;
//
//class BTNode{
//	BTNode(DataType data = 0)
//	:_data(data)
//	, _leftChild(NULL)
//	, _rightChild(NULL)
//	{}
//
//	DataType _data;
//	BTNode* _leftChild;
//	BTNode* _rightChild;
//};
//
//class BinaryTree{
//
//	// ...
//
//	BTNode* _root;
//};

template <typename Type>
class BinaryTree;

template <typename valType>
class BTNode{
	friend class BinaryTree<valType>;
	
	BTNode();
	void insert_value(const valType& data);

private:
	valType _data;
	int _count; // 记录同一值出现次数
	BTNode* _leftChild;
	BTNode* _rightChild;
};

template <typename elemType>
class BinaryTree{
public:
	BinaryTree();
	BinaryTree(const BinaryTree&);
	BinaryTree& operator=(const BinaryTree&);

	void insert_node(const elemType& data);
	inline bool empty(){ return _root == 0; }
	void clear();

	~BinaryTree();

private:
	BTNode<elemType>* _root;
	void copy(BTNode<elemType>* tar, BTNode<elemType>* src);
};
