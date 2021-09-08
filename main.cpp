#include "list.h"
#include <iostream>

using namespace list;

int main() {
	List my_list{};

	add(my_list, 10);
	add(my_list, 21);
	add(my_list, 32);
	add(my_list, 43);
	add(my_list, 65);
	add(my_list, 32);
	
	std::cout << "Iterating all elements" << '\n';
	int len{ count(my_list) };
	for (int i = 0; i < len; ++i)
	{
		std::cout << "The element at " << i << " is " << get(my_list, i) << '\n';
	}
	std::cout << '\n';

	std::cout  << "Deleting element at 1 and at 4" << '\n';
	del(my_list, 1);
	del(my_list, 4);
	for (int i = 0; i < len; ++i)
	{
		// Getting unexisting elements may lead to undefined behavior
		std::cout << "The element at " << i << " is " << get(my_list, i) << '\n';
	}	
	std::cout << '\n';
	
	std::cout << "Deleting all list" << '\n';
	del(my_list);
	std::cout << "There are " << count(my_list) << " elements"<< '\n';
	std::cout << '\n';

	std::cout << "Adding a couple of elements again" << '\n';
	add(my_list, 8);
	add(my_list, 37);
	std::cout << "Now there are " << count(my_list) << " elements" << '\n';


	// Remember to clean everything before leaving
	del(my_list);

	return 0;
}