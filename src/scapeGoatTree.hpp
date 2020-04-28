#pragma once
#include <iostream>
#include <cmath>

using namespace std;

template <typename T>
class scapeGoatTree;

template <typename T>
class Node
{
private:
    T value_;
    Node<T> *left_;
    Node<T> *right_;
    Node<T> *parent_;
    friend class scapeGoatTree<T>;

public:
    Node(T value, Node<T> *left = nullptr, Node<T> *right = nullptr, Node<T> *parent = nullptr)
        : value_(value), left_(left), right_(right), parent_(parent)
    {
    }
    Node(Node &rhs)
        : value_(rhs.value_), left_(rhs.left_), right_(rhs.right_), parent_(rhs.parent_)
    {
    }
};

template <typename T>
class scapeGoatTree
{
private:
    Node<T> *root;
    int numberOfNodes;
    int maxNumberOfNodes; // numberOfNodes <= maxNumberOfNodes <= 2*numberOfNodes
    class Iterator;
    class revIterator;
    int insertBSTwithdepth(Node<T> *node);
    void removeBST(int value);
    void rebuild(Node<T> *node);
    Node<T> *buildBalancedTree(Node<T> **nodeArray, int start, int end);
    Node<T> *findScapeGoat(Node<T> *node);
    int addNodesToArray(Node<T> *node, Node<T> **nodeArray, int index);
    Node<T> *BSTdeleteNode(Node<T> *root, int key);
    int size(Node<T> *node);
    int log3by2(int value);
    void displayHelper(Node<T> *node, int level);
    void printBT(const std::string &prefix, const Node<T> *node, bool isLeft);
    void setMinMax();
    Node<T> *minNode;
    Node<T> *maxNode;
    static Node<T> *inorder_successor(Node<T> *current, Node<T> *root);
    static Node<T> *minValue(Node<T> *root);
    static Node<T> *inorder_predecessor(Node<T> *current, Node<T> *root);
    static Node<T> *maxValue(Node<T> *root);
    static Iterator searchHelper(Node<T> *root, Node<T> *current, int value);

public:
    scapeGoatTree()
        : numberOfNodes(0), maxNumberOfNodes(0), root(nullptr), minNode(nullptr), maxNode(nullptr)
    {
    }

    void remove(int value);
    Iterator search(int value);
    void insert(int value);
    void display();

    T getMaxValue();
    T getMinValue();

    using iterator = Iterator;
    using const_iterator = Iterator;
    using reverse_iterator = revIterator;
    using const_reverse_iterator = revIterator;

    Iterator begin();
    Iterator end();
    revIterator rbegin();
    revIterator rend();
};

/**
 * Function definitions
 * --------------------
 */
template <typename T>
int scapeGoatTree<T>::insertBSTwithdepth(Node<T> *node)
{

    if (root == nullptr)
    {
        root = node;
        minNode = root;
        maxNode = root;
        numberOfNodes += 1;
        maxNumberOfNodes += 1;
        return 0;
    }

    Node<T> *current = root;
    Node<T> *prev = nullptr;
    int depth = 0;
    while (current != nullptr)
    {
        prev = current;
        depth += 1;

        if (node->value_ < current->value_)
            current = current->left_;
        else if (node->value_ > current->value_)
            current = current->right_;
        else
            return -1;
    }

    if (node->value_ < prev->value_)
    {
        prev->left_ = node;
        if (node->value_ < minNode->value_)
        {
            minNode = node;
        }
    }
    else
    {
        prev->right_ = node;
        if (node->value_ > maxNode->value_)
        {
            maxNode = node;
        }
    }
    node->parent_ = prev;
    numberOfNodes += 1;
    maxNumberOfNodes += 1;

    return depth;
}
template <typename T>
void scapeGoatTree<T>::rebuild(Node<T> *node)
{
    int subTreSize = size(node);
    Node<T> **nodeArray = new Node<T> *[subTreSize];
    addNodesToArray(node, nodeArray, 0);

    Node<T> *parent = node->parent_;

    if (parent == nullptr)
    {
        root = buildBalancedTree(nodeArray, 0, subTreSize - 1);
    }
    else if (node->value_ < parent->value_)
    {
        parent->left_ = buildBalancedTree(nodeArray, 0, subTreSize - 1);
        parent->left_->parent_ = parent;
    }
    else
    {
        parent->right_ = buildBalancedTree(nodeArray, 0, subTreSize - 1);
        parent->right_->parent_ = parent;
    }
}
template <typename T>
Node<T> *scapeGoatTree<T>::buildBalancedTree(Node<T> **nodeArray, int start, int end)
{
    if (end < start)
        return nullptr;

    int mid = start + (end - start) / 2;

    nodeArray[mid]->left_ = buildBalancedTree(nodeArray, start, mid - 1);
    nodeArray[mid]->right_ = buildBalancedTree(nodeArray, mid + 1, end);

    if (nodeArray[mid]->left_ != nullptr)
        nodeArray[mid]->left_->parent_ = nodeArray[mid];

    else if (nodeArray[mid]->right_ != nullptr)
        nodeArray[mid]->right_->parent_ = nodeArray[mid];

    return nodeArray[mid];
}
template <typename T>
Node<T> *scapeGoatTree<T>::findScapeGoat(Node<T> *node)
{
    while ((3 * size(node)) <= (2 * size(node->parent_)))
        node = node->parent_;

    return node->parent_;
}
template <typename T>
int scapeGoatTree<T>::addNodesToArray(Node<T> *node, Node<T> **nodeArray, int index)
{
    if (node == nullptr)
        return index;

    index = addNodesToArray(node->left_, nodeArray, index);
    nodeArray[index++] = node;
    return addNodesToArray(node->right_, nodeArray, index);
}

// Number of nodes in subtree rooted at node
template <typename T>
int scapeGoatTree<T>::size(Node<T> *node)
{
    if (node == nullptr)
        return 0;

    return size(node->left_) + size(node->right_) + 1;
}

template <typename T>
inline int scapeGoatTree<T>::log3by2(int value)
{
    return (int)floor(log(value) / log(3.0 / 2.0));
}

template <typename T>
void scapeGoatTree<T>::displayHelper(Node<T> *node, int level)
{
    if (node == nullptr)
        return;

    displayHelper(node->left_, level + 1);
    cout << "value : " << node->value_ << " Level : " << level << endl;
    displayHelper(node->right_, level + 1);
}

// calls insertBSTwithdepth and rebuilds if neccessary
template <typename T>
void scapeGoatTree<T>::insert(int value)
{
    Node<T> *newNode = new Node<T>(value);
    int nodeDepth = insertBSTwithdepth(newNode);

    // Check if height is valid
    if (nodeDepth > 0 && nodeDepth > log3by2(maxNumberOfNodes))
    {
        // Find scapegoat and rebuild
        Node<T> *scapeGoat = findScapeGoat(newNode);
        rebuild(scapeGoat);
    }
}

template <typename T>
void scapeGoatTree<T>::display()
{
    printBT("", root, false);
    cout << '\n';
}

template <typename T>
void scapeGoatTree<T>::printBT(const std::string &prefix, const Node<T> *node, bool isLeft)
{
    if (node != nullptr)
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──");

        // print the value of the node
        std::cout << node->value_ << std::endl;

        // enter the next tree level - left and right branch
        printBT(prefix + (isLeft ? "│   " : "    "), node->left_, true);
        printBT(prefix + (isLeft ? "│   " : "    "), node->right_, false);
    }
}

template <typename T>
Node<T> *scapeGoatTree<T>::BSTdeleteNode(Node<T> *root, int key)
{
    if (root == nullptr)
        return root;

    if (key < root->value_)
        root->left_ = BSTdeleteNode(root->left_, key);

    else if (key > root->value_)
        root->right_ = BSTdeleteNode(root->right_, key);

    else
    {
        if (root->left_ == nullptr)
        {
            numberOfNodes--;
            Node<T> *temp = root->right_;
            if (temp)
                temp->parent_ = root->parent_;
            delete root;
            return temp;
        }
        else if (root->right_ == nullptr)
        {
            numberOfNodes--;
            Node<T> *temp = root->left_;
            if (temp)
                temp->parent_ = root->parent_;
            delete root;
            return temp;
        }

        Node<T> *temp = root->right_;
        while (temp && temp->left_ != nullptr)
            temp = temp->left_;
        root->value_ = temp->value_;
        root->right_ = BSTdeleteNode(root->right_, temp->value_);
    }
    return root;
}

template <typename T>
void scapeGoatTree<T>::remove(int value)
{
    root = BSTdeleteNode(root, value);

    if (2 * numberOfNodes < maxNumberOfNodes)
    {
        rebuild(root);
        maxNumberOfNodes = numberOfNodes;
    }

    setMinMax();
}

template <typename T>
typename scapeGoatTree<T>::Iterator scapeGoatTree<T>::searchHelper(Node<T> *root, Node<T> *current, int value)
{
    if (current == nullptr || current->value_ == value)
        return scapeGoatTree<T>::Iterator(current, root);

    if (current->value_ < value)
        return searchHelper(root, current->right_, value);

    return searchHelper(root, current->left_, value);
}

template <typename T>
typename scapeGoatTree<T>::Iterator scapeGoatTree<T>::search(int value)
{
    return searchHelper(root, root, value);
}

template <typename T>
T scapeGoatTree<T>::getMaxValue() { return maxNode->value_; }

template <typename T>
T scapeGoatTree<T>::getMinValue() { return minNode->value_; }

template <typename T>
void scapeGoatTree<T>::setMinMax()
{
    Node<T> *current = root;
    if (current == nullptr)
    {
        minNode = maxNode = nullptr;
        return;
    }

    while (current->left_ != nullptr)
        current = current->left_;

    minNode = current;
    current = root;

    while (current->right_ != nullptr)
        current = current->right_;

    maxNode = current;
}

template <typename T>
Node<T> *scapeGoatTree<T>::minValue(Node<T> *root)
{
    while (root && root->left_ != nullptr)
    {
        root = root->left_;
    }
    return root;
}

template <typename T>
Node<T> *scapeGoatTree<T>::inorder_successor(Node<T> *current, Node<T> *root)
{
    if (current->right_ != nullptr)
        return minValue(current->right_);

    Node<T> *successor = nullptr;
    while (root != nullptr)
    {
        if (current->value_ < root->value_)
        {
            successor = root;
            root = root->left_;
        }
        else if (current->value_ > root->value_)
            root = root->right_;
        else
            break;
    }

    return successor;
}

template <typename T>
Node<T> *scapeGoatTree<T>::maxValue(Node<T> *root)
{
    while (root && root->right_ != nullptr)
    {
        root = root->right_;
    }
    return root;
}

template <typename T>
Node<T> *scapeGoatTree<T>::inorder_predecessor(Node<T> *current, Node<T> *root)
{

    if (current->left_ != nullptr)
        return maxValue(current->left_);

    Node<T> *predecessor = nullptr;

    while (root != nullptr)
    {
        if (current->value_ > root->value_)
        {
            predecessor = root;
            root = root->right_;
        }
        else if (current->value_ < root->value_)
            root = root->left_;
        else
            break;
    }
    return predecessor;
}

#include "iterators.hpp"

template <typename T>
typename scapeGoatTree<T>::Iterator scapeGoatTree<T>::begin()
{
    return scapeGoatTree<T>::Iterator(minNode, root);
}

template <typename T>
typename scapeGoatTree<T>::Iterator scapeGoatTree<T>::end()
{
    return scapeGoatTree<T>::Iterator(nullptr, root);
}

template <typename T>
typename scapeGoatTree<T>::revIterator scapeGoatTree<T>::rbegin()
{
    return scapeGoatTree<T>::revIterator(maxNode, root);
}

template <typename T>
typename scapeGoatTree<T>::revIterator scapeGoatTree<T>::rend()
{
    return scapeGoatTree<T>::revIterator(nullptr, root);
}
