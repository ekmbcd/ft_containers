#include <vector>
#include <iostream>
#include "tests/tests.hpp"

bool foo(int a, int b)
{
	return(a==b);
}

int main()
{
	/*
	ft::List<int> const clist;
	 ft::List<int>  a(10, 10);
	// std::cout << "SIZE = " << a.size() << std::endl;
	// std::cout << "empty = " << a.empty() << std::endl;
	ft::ListIterator<int> ads = a.begin();
	std::cout << *ads << std::endl;

	 std::cout << "maxSIZE = " << a.max_size() << std::endl;
	// std::cout << "empty = " << a.empty() << std::endl;
	


	a.push_front(2);	
	
	// ft::Node<int> no = a.front();
	// no.value = 12;
	// std::cout << "end = " << no.value << std::endl;
	a.push_front(3);
	a.push_back(0);
	std::cout << "SIZE = " << a.size() << std::endl;
	ft::List<int>::iterator i = a.begin();
	// ft::List<int>::iterator c = a.end();
	std::cout << "start: " << *i << std::endl;
	ft::List<int>::iterator c = a.end();
	std::cout <<  "end: " << *c << std::endl;

	

	std::cout << std::endl;
	while (i != c)
	{
		std::cout << *i++ << " ";
	}
	std::cout << std::endl;


	ft::List<int> b;
	// b.pop_back();
	b.assign(4, 5);
	std::cout << "SIZE = " << b.size() << std::endl;

	// b.pop_back();
	i = b.end();
	b.insert(--i, 69 );
	i = b.begin();

	while (i != b.end())
	{
		std::cout << *i++ << " ";
	}
	std::cout << std::endl;

	b.erase(++b.begin());
	i = b.begin();

	while (i != b.end())
	{
		std::cout << *i++ << " ";
	}
	std::cout << std::endl;
	*/

	// ft::List<int> a(10, 5);
	// ft::List<int> b(15, 10);
	// ft::ListIterator<int> i = a.begin();
	// std::cout << "A" << std::endl;
	// while (i != a.end())
	// {
	// 	std::cout << *i++ << " ";
	// }
	// std::cout << std::endl;
	// std::cout << "B" << std::endl;
	// i = b.begin();
	// while (i != b.end())
	// {
	// 	std::cout << *i++ << " ";
	// }
	// std::cout << std::endl;
	// std::cout << std::endl;


	// a.swap(b);	
	// std::cout << "A" << std::endl;
	// i = a.begin();
	// while (i != a.end())
	// {
	// 	std::cout << *i++ << " ";
	// }
	// std::cout << std::endl;
	// std::cout << "B" << std::endl;
	// i = b.begin();
	// while (i != b.end())
	// {
	// 	std::cout << *i++ << " ";
	// }
	// std::cout << std::endl;
	// b.splice(b.end(), a);
	// b.unique(foo);
	// std::cout << "B" << std::endl;
	// i = b.begin();
	// while (i != b.end())
	// {
	// 	std::cout << *i++ << " ";
	// }
	// std::cout << std::endl;
	// std::cout << "A" << std::endl;
	// i = a.begin();
	// while (i != a.end())
	// {
	// 	std::cout << *i++ << " ";
	// }
	// std::cout << std::endl;
/*
	ft::List<int> a;
	ft::ListIterator<int> i;
	for (int i = 10; i > 0; i--)
		a.push_back(i);
	std::cout << "A" << std::endl;
	i = a.begin();
	while (i != a.end())
	{
		std::cout << *i++ << " ";
	}
	std::cout << std::endl;
	a.sort();
	std::cout << "A" << std::endl;
	i = a.begin();
	while (i != a.end())
	{
		std::cout << *i++ << " ";
	}
	std::cout << std::endl;
	*/

	test_vector();

}