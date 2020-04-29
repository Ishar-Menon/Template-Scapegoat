#include "date.hpp"
#include "scapeGoatTree.hpp"
#include "tests.hpp"
#include <algorithm>

namespace date_test
{
void buildTree(scapeGoatTree<MyDate> &tree)
{
    tree.insert(MyDate(31, 1, 2018));
    tree.insert(MyDate(31, 3, 2018));
    tree.insert(MyDate(31, 10, 2020));
    tree.insert(MyDate(31, 8, 2023));
    tree.insert(MyDate(21, 5, 2016));
    tree.insert(MyDate(18, 5, 2019));
    tree.insert(MyDate(22, 8, 2021));
    tree.insert(MyDate(19, 8, 2024));
    tree.insert(MyDate(29, 4, 2020));
}
bool is_future(const MyDate &m)
{
    return m > MyDate(29, 5, 2020);
}
void print_past_future(const MyDate &m)
{
    cout << m << ": "
         << (is_future(m) ? "Future" : "Past")
         << endl;
}
} // namespace date_test

void myDate_tests()
{
    cout << "\n--- User defined MyDate class test ---\n\n";
    scapeGoatTree<MyDate> tree;
    date_test::buildTree(tree);
    cout << "\nThe current tree \n";
    tree.display();
    cout << "Inserting (5, 9, 2014)\n";
    tree.insert(MyDate(5, 9, 2014));
    cout << "Rebuilding...\n";
    tree.display();

    cout << "\nSearching for (8, 5, 2010)...\n";
    auto itr1 = tree.search(MyDate(8, 5, 2010));
    cout << "> Value (8, 5, 2010) " << (itr1 == tree.end() ? "NOTFOUND" : "FOUND") << endl;
    cout << "\nSearching for (21, 5, 2016)...\n";
    auto itr2 = tree.search(MyDate(21, 5, 2016));
    cout << "> Value (21, 5, 2016) " << (itr2 == tree.end() ? "NOTFOUND" : "FOUND") << endl;

    cout << "\nstd::find_if isFuture()\n";
    auto it_2 = std::find_if(begin(tree), end(tree), date_test::is_future);
    std::cout << "> The first future date is " << *it_2 << '\n';

    cout << "\nstd::min_element\n> ";
    cout << *std::min_element(begin(tree), end(tree)) << "\n";

    cout << "\nstd::for_each\n";
    std::for_each(begin(tree), end(tree), date_test::print_past_future);
    cout << "\n";

    cout << "\nstd::count_if isFuture() \n";
    int count = std::count_if(begin(tree), end(tree), date_test::is_future);
    cout << "Count of future dates: " << count << "\n";
}