#include "List.hpp"
#include "ListIterator.hpp"
#include <iostream>

int main()
{
	ft::List<int> a;
	std::cout << "SIZE = " << a.size() << std::endl;
	a.push_front(1);
	std::cout << "SIZE = " << a.size() << std::endl;
	a.push_front(2);
	a.push_front(3);
	a.push_back(0);

	std::cout << "SIZE = " << a.size() << std::endl;
	ft::List<int>::iterator i = a.begin();
	std::cout << "start: " << *i << std::endl;
	ft::List<int>::iterator c = a.end();
	std::cout <<  "end: " << *c << std::endl;

	std::cout << std::endl;
	while (i != a.end())
	{
		std::cout << *i++ << " ";
	}
	std::cout << std::endl;

}