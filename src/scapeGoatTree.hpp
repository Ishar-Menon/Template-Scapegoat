#include <bits/stdc++.h>
using namespace std;

class Node
{
private:
    int value_;
    Node *left_;
    Node *right_;
    Node *parent_;
    friend class scapeGoatTree;

public:
    Node(int value = 0, Node *left = nullptr, Node *right = nullptr, Node *parent = nullptr)
        : value_(value), left_(left), right_(right), parent_(parent)
    {
    }
};

class scapeGoatTree
{
private:
    Node *root;
    int numberOfNodes;
    int maxNumberOfNodes; // numberOfNodes <= maxNumberOfNodes <= 2*numberOfNodes
    int insertBSTwithdepth(Node *node);
    void removeBST(int value);
    void rebuild(Node *node);
    Node *buildBalancedTree(Node **nodeArray, int start, int end);
    Node *findScapeGoat(Node *node);
    int addNodesToArray(Node *node, Node **nodeArray, int index);
    int size(Node *node);
    int log3by2(int value);
    void displayHelper(Node *node, int level);
    void printBT(const std::string &prefix, const Node *node, bool isLeft);

public:
    scapeGoatTree()
        : numberOfNodes(0), maxNumberOfNodes(0), root(nullptr)
    {
    }
    void remove(int value); // calls  removeBST and rebuilds if neccessary
    void search(int value);
    void insert(int value);
    void display();
};

/**
 * Function definitions
 * --------------------
 */

int scapeGoatTree::insertBSTwithdepth(Node *node)
{
    numberOfNodes += 1;
    maxNumberOfNodes += 1;

    if (root == nullptr)
    {
        root = node;
        return 0;
    }

    Node *current = root;
    Node *prev = nullptr;
    int depth = 0;
    while (current != nullptr)
    {
        prev = current;
        depth += 1;

        if (node->value_ < current->value_)
            current = current->left_;
        else
            current = current->right_;
    }

    if (node->value_ < prev->value_)
        prev->left_ = node;
    else
        prev->right_ = node;

    node->parent_ = prev;

    return depth;
}

void scapeGoatTree::rebuild(Node *node)
{
    int subTreSize = size(node);
    Node **nodeArray = new Node *[subTreSize];
    addNodesToArray(node, nodeArray, 0);

    Node *parent = node->parent_;

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

Node *scapeGoatTree::buildBalancedTree(Node **nodeArray, int start, int end)
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

Node *scapeGoatTree::findScapeGoat(Node *node)
{
    while ((3 * size(node)) <= (2 * size(node->parent_)))
        node = node->parent_;

    return node->parent_;
}

int scapeGoatTree::addNodesToArray(Node *node, Node **nodeArray, int index)
{
    if (node == nullptr)
        return index;

    index = addNodesToArray(node->left_, nodeArray, index);
    nodeArray[index++] = node;
    return addNodesToArray(node->right_, nodeArray, index);
}

// Number of nodes in subtree rooted at node
int scapeGoatTree::size(Node *node)
{
    if (node == nullptr)
        return 0;

    return size(node->left_) + size(node->right_) + 1;
}

inline int scapeGoatTree::log3by2(int value)
{
    return (int)floor(log(value) / log(3.0 / 2.0));
}

void scapeGoatTree::displayHelper(Node *node, int level)
{
    if (node == nullptr)
        return;

    displayHelper(node->left_, level + 1);
    cout << "value : " << node->value_ << " Level : " << level << endl;
    displayHelper(node->right_, level + 1);
}

// calls insertBSTwithdepth and rebuilds if neccessary
void scapeGoatTree::insert(int value)
{
    Node *newNode = new Node(value);
    int nodeDepth = insertBSTwithdepth(newNode);

    // Check if height is valid
    if (nodeDepth != 0 && nodeDepth > log3by2(maxNumberOfNodes))
    {
        // Find scapegoat and rebuild
        Node *scapeGoat = findScapeGoat(newNode);
        rebuild(scapeGoat);
    }
}

void scapeGoatTree::display()
{
    // displayHelper(root, 0);
    printBT("", root, false);
}

void scapeGoatTree::printBT(const std::string &prefix, const Node *node, bool isLeft)
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