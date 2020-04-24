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
    Node(int value)
    {
        value_ = value;
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
    int insertBSTwithdepth(Node *node)
    {
        numberOfNodes += 1;
        maxNumberOfNodes += 1;

        if (root == NULL)
        {
            root = node;
            return 0;
        }
        Node *current = root;
        Node *prev = NULL;
        int depth = 0;
        while (current != NULL)
        {
            prev = current;
            depth += 1;
            if (node->value_ < current->value_)
            {
                current = current->left_;
            }
            else
            {
                current = current->right_;
            }
        }

        if (node->value_ < prev->value_)
        {
            prev->left_ = node;
        }
        else
        {
            prev->right_ = node;
        }

        node->parent_ = prev;

        return depth;
    }
    void removeBST(int value);
    void rebuild(Node *node)
    {
        int subTreSize = size(node);
        Node **nodeArray = new Node *[subTreSize];
        addNodesToArray(node, nodeArray, 0);

        Node *parent = node->parent_;

        if (parent == NULL)
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
    Node *buildBalancedTree(Node **nodeArray, int start, int end)
    {
        if (end < start)
        {
            return NULL;
        }

        int mid = start + (end - start) / 2;

        nodeArray[mid]->left_ = buildBalancedTree(nodeArray, start, mid - 1);
        nodeArray[mid]->right_ = buildBalancedTree(nodeArray, mid + 1, end);

        if (nodeArray[mid]->left_ != NULL)
        {
            nodeArray[mid]->left_->parent_ = nodeArray[mid];
        }
        else if (nodeArray[mid]->right_ != NULL)
        {
            nodeArray[mid]->right_->parent_ = nodeArray[mid];
        }

        return nodeArray[mid];
    }
    Node *findScapeGoat(Node *node)
    {
        while ((3 * size(node)) <= (2 * size(node->parent_)))
        {
            node = node->parent_;
        }

        return node->parent_;
    }
    int addNodesToArray(Node *node, Node **nodeArray, int index)
    {
        if (node == NULL)
        {
            return index;
        }

        index = addNodesToArray(node->left_, nodeArray, index);
        nodeArray[index++] = node;
        addNodesToArray(node->right_, nodeArray, index);
    }
    // Number of nodes in subtree rooted at node
    int size(Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        return size(node->left_) + size(node->right_) + 1;
    }
    int log3by2(int value)
    {
        return (int)floor(log(value) / log(3.0 / 2.0));
    }
    void displayHelper(Node *node, int level)
    {
        if (node == NULL)
        {
            return;
        }

        displayHelper(node->left_, level + 1);
        cout << "value : " << node->value_ << " Level : " << level << endl;
        displayHelper(node->right_, level + 1);
    }

public:
    scapeGoatTree()
    {
        numberOfNodes = 0;
        maxNumberOfNodes = 0;
        root = NULL;
    }

    // calls insertBSTwithdepth and rebuilds if neccessary
    void insert(int value)
    {
        Node *newNode = new Node(value);
        int nodeDepth = insertBSTwithdepth(newNode);
        // cout << nodeDepth << endl;

        // Check if height is valid
        if (nodeDepth != 0 && nodeDepth > log3by2(maxNumberOfNodes))
        {
            // Find scapegoat and rebuild
            Node *scapeGoat = findScapeGoat(newNode);
            rebuild(scapeGoat);
        }
    }
    void remove(int value); // calls  removeBST and rebuilds if neccessary
    void search(int value);
    void display()
    {
        displayHelper(root, 0);
    }
};