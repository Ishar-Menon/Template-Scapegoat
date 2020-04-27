#include "scapeGoatTree.hpp"

void inorder(scapeGoatTree<int> &tree)
{
    scapeGoatTree<int>::iterator begin = tree.begin();
    cout << "Inorder: ";
    while (begin != tree.end())
    {
        cout << *begin++ << " ";
    }
    cout << endl;
}

void inorder_reverse(scapeGoatTree<int> &tree)
{
    scapeGoatTree<int>::reverse_iterator begin = tree.rbegin();
    cout << "Reverse: ";
    while (begin != tree.rend())
    {
        cout << *begin++ << " ";
    }
    cout << endl;
}

int main()
{
    scapeGoatTree<int> tree;
    tree.insert(10);
    tree.insert(2);
    tree.insert(1);
    tree.insert(8);
    tree.insert(4);
    tree.insert(3);
    tree.insert(7);
    tree.insert(5);
    tree.insert(9);
    tree.insert(6);
    inorder(tree);
    inorder_reverse(tree);
    tree.display();
    tree.remove(6);
    tree.remove(11);
    tree.remove(8);
    tree.display();
    tree.remove(2);
    tree.remove(10);
    tree.remove(3);
    inorder(tree);
    inorder_reverse(tree);
    tree.display();
    tree.remove(1);
    tree.display();
    return 0;
}