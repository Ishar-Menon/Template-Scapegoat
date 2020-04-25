#include "scapeGoatTree.hpp"

int main()
{
    scapeGoatTree tree;
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
    tree.remove(6);
    tree.remove(11);
    tree.remove(8);
    tree.display();
    tree.remove(2);
    tree.remove(10);
    tree.remove(3);
    tree.display();
    tree.remove(1);
    tree.display();
    return 0;
}