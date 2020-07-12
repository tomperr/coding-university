#include <iostream>
#include "../include/LinkedList.hpp"


int main(void)
{
	LinkedList<int> list;
	list.push_back(5);
	list.push_back(6);
	list.push_back(7);
	list.push_back(7);

	list.insert(4, 111);

	list.print();

	list.reverse();
	list.push_back(7);
	list.push_back(456);
	list.remove_value(7);
	list.print();

	return 0;
}
