#pragma once
#include "scapeGoatTree.hpp"

template <class T>
class scapeGoatTree<T>::Iterator
{
private:
	Node<T> *node_it_, *root;

public:
	using iterator_category = bidirectional_iterator_tag;
	using value_type = T;
	using difference_type = int;
	using pointer = T *;
	using reference = T &;
	explicit Iterator(Node<T> *node_it = nullptr, Node<T> *root = nullptr) : node_it_(node_it), root(root) {}
	bool operator==(const Iterator &rhs) const { return node_it_ == rhs.node_it_; }
	bool operator!=(const Iterator &rhs) const { return !(*this == rhs); }
	reference operator*() { return node_it_->value_; }
	Iterator &operator++();
	Iterator operator++(int);
	Iterator &operator--();
	Iterator operator--(int);
};

template <class T>
class scapeGoatTree<T>::revIterator
{
private:
	Node<T> *node_it_, *root;

public:
	using iterator_category = bidirectional_iterator_tag;
	using value_type = T;
	using difference_type = int;
	using pointer = T *;
	using reference = T &;
	explicit revIterator(Node<T> *node_it = nullptr, Node<T> *root = nullptr) : node_it_(node_it), root(root) {}
	bool operator==(const revIterator &rhs) const { return node_it_ == rhs.node_it_; }
	bool operator!=(const revIterator &rhs) const { return !(*this == rhs); }
	reference operator*() { return node_it_->value_; }
	revIterator &operator++();
	revIterator operator++(int);
	revIterator &operator--();
	revIterator operator--(int);
};

template <typename T>
typename scapeGoatTree<T>::Iterator &scapeGoatTree<T>::Iterator::operator++()
{
	node_it_ = scapeGoatTree<T>::inorder_successor(node_it_, root);
	return *this;
}

template <typename T>
typename scapeGoatTree<T>::Iterator scapeGoatTree<T>::Iterator::operator++(int)
{
	Iterator temp(*this);
	++(*this);
	return temp;
}

template <typename T>
typename scapeGoatTree<T>::Iterator &scapeGoatTree<T>::Iterator::operator--()
{
	if (node_it_ == nullptr)
		node_it_ = scapeGoatTree<T>::maxValue(root);
	else
		node_it_ = scapeGoatTree<T>::inorder_predecessor(node_it_, root);
	return *this;
}

template <typename T>
typename scapeGoatTree<T>::Iterator scapeGoatTree<T>::Iterator::operator--(int)
{
	Iterator temp(*this);
	--(*this);
	return temp;
}

template <typename T>
typename scapeGoatTree<T>::revIterator &scapeGoatTree<T>::revIterator::operator++()
{
	node_it_ = scapeGoatTree<T>::inorder_predecessor(node_it_, root);
	return *this;
}

template <typename T>
typename scapeGoatTree<T>::revIterator scapeGoatTree<T>::revIterator::operator++(int)
{
	revIterator temp(*this);
	++(*this);
	return temp;
}

template <typename T>
typename scapeGoatTree<T>::revIterator &scapeGoatTree<T>::revIterator::operator--()
{
	if (node_it_ == nullptr)
		node_it_ = scapeGoatTree<T>::minValue(root);
	else
		node_it_ = scapeGoatTree<T>::inorder_successor(node_it_, root);
	return *this;
}

template <typename T>
typename scapeGoatTree<T>::revIterator scapeGoatTree<T>::revIterator::operator--(int)
{
	revIterator temp(*this);
	--(*this);
	return temp;
}
