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
    scapeGoatTree<int> tree2 = tree;
    cout << "Duplicate (copy ctor)\n";
    tree2.display();
    auto itr_10 = tree2.search(10);
    cout << "(10) " << (itr_10 != tree2.end() ? "" : "Not ") << "Found\n";
    auto itr_11 = tree2.search(11);
    cout << "(11) " << (itr_11 != tree2.end() ? "" : "Not ") << "Found\n";
    tree2.remove(2);
    tree2.remove(10);
    tree2.remove(3);
    inorder(tree2);
    inorder_reverse(tree2);
    // tree2.remove(1);
    tree2.display();
    scapeGoatTree<int> tree3;
    tree3 = tree2;
    tree2.remove(1);
    cout << "Copy assignment (tree3 = tree2)\n";
    cout << "tree\n";
    tree.display();
    cout << "tree2\n";
    tree2.display();
    cout << "tree3\n";
    tree3.display();
    return 0;
}