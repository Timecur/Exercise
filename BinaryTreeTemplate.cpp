#include "BinaryTreeTemplate.h"

//template <typename elemType>
//inline bool BinaryTree<elemType>::empty()
//{
//	return _root == 0;
//}

// 构造函数
template <typename elemType>
inline BinaryTree<elemType>::BinaryTree()
	:_root(0)
{}

// 拷贝构造
template <typename elemType>
inline BinaryTree<elemType>::BinaryTree(const BinaryTree& rhs)
{
	copy(_root, rhs._root);
}

// 赋值运算符重载
template <typename elemType>
inline BinaryTree<elemType>& BinaryTree<elemType>::operator=(const BinaryTree& rhs)
{
	if (this != &rhs){
		clear();
		copy(_root, rhs._root);
	}
	return *this;
}

// 析构函数
template <typename elemType>
inline BinaryTree<elemType>::~BinaryTree()
{
	clear();
}


template <typename valType>
inline BTNode<valType>::BTNode(const valType& data)
	:_data(data)
{
	_count = 1;
	_rightChild = _leftChild = 0;
}

template <typename elemType>
inline void BinaryTree<elemType>::insert_node(const elemType& data)
{
	if (!_root){
		_root = new BTNode<valType>(elemType);
	}
	else
		_root->insert_value(data);
}

template <typename valType>
void BTNode<valType>::insert_value(const valType& data)
{
	// 插入值与某一节点值相等，count+1
	if (data == _data){
		_count++;
		return;
	}

	// 根据规则，插入节点值小于当前节点向左值树插入，否则向右子树插入
	if (data < _data){
		if (!_leftChild)
			_leftChild = new BTNode(data);
		else
			_leftChild->insert_value(data);
	}
	else{
		if (!_rightChild)
			_rightChild = new BTNode(data);
		else
			_rightChild->insert_value(data);
	}
}


