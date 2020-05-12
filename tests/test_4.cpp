#include "complex.hpp"
#include "scapeGoatTree.hpp"
#include "tests.hpp"

void complex_tests()
{
    cout << "\n--- User defined complex class test ---\n\n";
    scapeGoatTree<Complex> tree;
    cout << "Inserting (10 + 5i)\n";
    tree.insert(Complex(10, 5));
    cout << "Inserting (2 + -1i)\n";
    tree.insert(Complex(2, -1));
    cout << "Inserting (1 + 0i)\n";
    tree.insert(Complex(1, 0));
    cout << "Inserting (8 + 5i)\n";
    tree.insert(Complex(8, 5));
    cout << "Inserting (4 + 10i)\n";
    tree.insert(Complex(4, 10));
    cout << "Inserting (4 + 2i)\n";
    tree.insert(Complex(4, 2));
    cout << "Inserting (7 + -7i)\n";
    tree.insert(Complex(7, -7));
    cout << "Inserting (5 + 6i)\n";
    tree.insert(Complex(5, 6));
    cout << "Inserting (9 + -3i)\n";
    tree.insert(Complex(9, -3));
    cout << "\nThe current tree \n";
    tree.display();
    cout << "Inserting (5 + 9i)\n";
    tree.insert(Complex(5, 9));
    cout << "Rebuilding...\n";
    tree.display();
    cout << "\nSearching for 8 + 5i...\n";
    auto itr1 = tree.search(Complex(8, 5));
    cout << "Value 8 + 5i " << (itr1 == tree.end() ? "NOTFOUND" : "FOUND") << endl;
    cout << "\nSearching for 14 + -20i...\n";
    auto itr2 = tree.search(Complex(14, -20));
    cout << "Value 14 + -20i " << (itr2 == tree.end() ? "NOTFOUND" : "FOUND") << endl;
    cout << "Removing 5 + 9i \n";
    tree.remove(Complex(5, 9));
    cout << "Removing 11 + 0i \n";
    tree.remove(Complex(11));
    cout << "Removing 8 + 5i \n";
    tree.remove(Complex(8, 5));
    tree.display();
    cout << "Removing 2 + -1i \n";
    tree.remove(Complex(2, -1));
    cout << "Removing 10 + 5i \n";
    tree.remove(Complex(10, 5));
    tree.display();
    cout << "Removing 4 + 2i \n";
    tree.remove(Complex(4, 2));
    tree.display();
    cout << "Removing 1 + 0i \n";
    tree.remove(Complex(1, 0));
    cout << "Rebuilding...\n";
    tree.display();
}