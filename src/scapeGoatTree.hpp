#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int value_;
    Node *left_;
    Node *right_;
    Node *parent_;
    Node()
    {
        value_ = 0;
        left_ = right_ = parent_ = NULL;
    }
    Node(int value, Node *left, Node *right, Node *parent)
    {
        value_ = value;
        left_ = left;
        right_ = right;
        parent_ = parent;
    }
};

class scapeGoatTree
{
private:
    Node *root;
    int numberOfNodes;
    int maxNumberOfNodes; // numberOfNodes <= maxNumberOfNodes<= 2*numberOfNodes
    void insertBSTwithdepth(int value);
    void removeBST(int value);
    void rebuild(Node *node);
    Node *buildBalancedTree(Node **nodeArray, int start, int end);
    Node *findScapeGoat(Node *node);
    void addNodesToArray(Node *node, Node **nodeArray, int index);
    int size(Node *node); // Number of nodes in subtree rooted at node

public:
    void insert(int value); // calls insertBSTwithdepth and rebuilds if neccessary
    void remove(int value); // calls  removeBST and rebuilds if neccessary
    void search(int value);
};