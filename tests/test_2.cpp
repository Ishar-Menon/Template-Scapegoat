#include "scapeGoatTree.hpp"
#include "tests.hpp"
using namespace std;

namespace test_2
{
void inorder(scapeGoatTree<int> &tree)
{
    scapeGoatTree<int>::iterator begin = tree.begin();
    while (begin != tree.end())
    {
        cout << *begin++ << " ";
    }
    cout << endl;
}

void inorder_reverse(scapeGoatTree<int> &tree)
{
    scapeGoatTree<int>::reverse_iterator begin = tree.rbegin();
    while (begin != tree.rend())
    {
        cout << *begin++ << " ";
    }
    cout << endl;
}

template <typename T>
void inorder2(scapeGoatTree<T> &tree)
{
    typename scapeGoatTree<T>::reverse_iterator end = tree.rend();
    while (end != tree.rbegin())
    {
        cout << *--end << " ";
    }
    cout << endl;
}
} // namespace test_2

/**
 * Iterators, Copy-ctor, and copy assignment:
 * 1. Forward and Reverse Iterators
 * 2. Copy ctor
 * 3. Copy assignment operator
 */
void iter_ctor_asn()
{
    cout << "\n-- Iterators, Copy-ctor, and copy assignment --\n";
    cout << "\nBuilding tree\n";
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
    tree.display();
    cout << "\nIn-order traversal using Forward Iterator: \n> ";
    test_2::inorder(tree);
    cout << "\nReverse In-order traversal using Forward Iterator: \n> ";
    test_2::inorder_reverse(tree);
    cout << "\nIn-order traversal using Reverse Iterator(backwards): \n> ";
    test_2::inorder2<int>(tree);
    cout << "\nUsing copy ctor to create tree1 from tree\n> ";
    scapeGoatTree<int> tree1(tree);
    cout << "Deleting nodes in tree so show no side effects on tree1\n";
    tree.remove(6);
    tree.remove(3);
    cout << "> tree\n ";
    tree.display();
    cout << "> tree1\n ";
    tree1.display();
    cout << "\nUsing copy assignment (tree1 = tree)\n> ";
    tree1 = tree;
    cout << "tree1\n";
    tree1.display();
    cout << "\nDemonstrating self assignment doesn't crash (tree = tree)\n";
    tree = tree;
    cout << "> Didn't fail\n";
    scapeGoatTree<int>::iterator itr_8 = tree1.search(8);
    cout << "\nSearching for [8] in tree1 (returns an iterator if found)\n> ";
    if (itr_8 != tree1.end())
        cout << *itr_8 << " FOUND!!\n";
    else
        cout << "Not found.\n";
}
