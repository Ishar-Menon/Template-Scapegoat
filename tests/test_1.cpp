#include "scapeGoatTree.hpp"
#include "tests.hpp"

/**
 * Basic Operations:
 * 1. Insert
 * 2. Search
 * 3. Remove
 * 4. Display
 */
void basic_operations()
{
    scapeGoatTree<int> tree;
    cout << "Basic Operations:\n";
    cout << "1.Insert:\n";
    cout << "Inserting 10\n";
    tree.insert(10);
    cout << "Inserting 2\n";
    tree.insert(2);
    cout << "Inserting 1\n";
    tree.insert(1);
    cout << "Inserting 8\n";
    tree.insert(8);
    cout << "Inserting 4\n";
    tree.insert(4);
    cout << "Inserting 3\n";
    tree.insert(3);
    cout << "Inserting 7\n";
    tree.insert(7);
    cout << "Inserting 5\n";
    tree.insert(5);
    cout << "Inserting 9\n";
    tree.insert(9);
    cout << "The current tree \n";
    tree.display();
    cout << "Inserting 6 \n";
    tree.insert(6);
    cout << "Rebuilding tree...\n";
    tree.display();
    cout << "Searching for 8...\n";
    auto itr1 = tree.search(8);
    cout << "Value 8 " << (itr1 == tree.end() ? "NOTFOUND" : "FOUND") << endl;
    cout << "Searching for 14...\n";
    auto itr2 = tree.search(14);
    cout << "Value 14 " << (itr2 == tree.end() ? "NOTFOUND" : "FOUND") << endl;
    cout << "Removing 6 \n";
    tree.remove(6);
    cout << "Removing 11 \n";
    tree.remove(11);
    cout << "Removing 8 \n";
    tree.remove(8);
    tree.display();
    cout << "Removing 2 \n";
    tree.remove(2);
    cout << "Removing 10 \n";
    tree.remove(10);
    tree.display();
    cout << "Removing 3 \n";
    tree.remove(3);
    tree.display();
    cout << "Removing 1 \n";
    tree.remove(1);
    cout << "Rebuilding...\n";
    tree.display();
}
