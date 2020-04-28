#include "scapeGoatTree.hpp"
#include "tests.hpp"
#include <algorithm>

/**
 * Generic Algorithms tested:
 * 1. std::find
 * 2. std::find_if
 * 3. std::for_each
 * 4. std::is_sorted
 * 5. std::max_element
 * 6. std::min_element
 * 7. std::none_of
 */

void buildTree(scapeGoatTree<int> &tree)
{
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
}

bool IsOdd(int i)
{
    return ((i % 2) == 1);
}

void print_i(int i)
{
    cout << ' ' << i;
}

void generic_algo()
{
    cout << "\n--- Generic Algorithms ---\n";
    cout << "\nBuilding tree\n";
    scapeGoatTree<int> tree;
    buildTree(tree);
    tree.display();
    cout << "\nstd::find  for [8]\n";
    scapeGoatTree<int>::iterator it = find(tree.begin(), tree.end(), 8);
    if (it != tree.end())
        cout << "> Element found : " << *it << '\n';
    else
        cout << "> Element not found.\n";

    cout << "\nstd::find  for [12]\n";
    it = find(tree.begin(), tree.end(), 12);
    if (it != tree.end())
        cout << "> Element found : " << *it << '\n';
    else
        cout << "> Element not found.\n";

    cout << "\nstd::find_if \n> isOdd() with reverse iterator\n";
    auto it_2 = std::find_if(rbegin(tree), rend(tree), IsOdd);
    std::cout << "> The last odd value is " << *it_2 << '\n';

    cout << "\nstd::for_each\n> ";
    std::for_each(begin(tree), end(tree), print_i);
    cout << "\n";

    cout << "\nstd::is_sorted\n> ";
    cout << std::is_sorted(begin(tree), end(tree)) << "\n";

    cout << "\nstd::max_element\n> ";
    cout << *std::max_element(begin(tree), end(tree)) << "\n";

    cout << "\nstd::min_element\n> ";
    cout << *std::min_element(begin(tree), end(tree)) << "\n";

    cout << "\nstd::none_of\n> ";
    if (std::none_of(tree.begin(), tree.end(), [](int i) { return i > 5; }))
        cout << "There are NO elements greater than 5.\n";
    else
        cout << "There are elements greater than 5.\n";

    
}
