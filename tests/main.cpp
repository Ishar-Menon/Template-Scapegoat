#include <iostream>
#include "scapeGoatTree.hpp"
#include "tests.hpp"

using namespace std;

int main()
{
	char choice;
	cout << "\n------------------ MENU ------------------\n"
		 << "1. Basic Operations\n"
		 << "2. Iterators, Copy-ctor, and copy assignment\n"
		 << "3. Generic algorithms\n"
		 << "4. Complex class test\n"
		 << "5. MyDate class test\n"
		 << "6. Random test set\n"
		 << "\nEnter choice: ";
	cin >> choice;
	switch (choice)
	{
	case '1':
		basic_operations();
		break;
	case '2':
		iter_ctor_asn();
		break;
	case '3':
		generic_algo();
		break;
	case '4':
		complex_tests();
		break;
	case '5':
		myDate_tests();
		break;
	default:
		test_0();
		break;
	}
}