#include "tests.hpp"
#include <list>
#include <stdlib.h>
#include <iostream>

// template <class T>
// static void print_list(T &list)
// {
// 	typename T::iterator it = list.begin();
// 	typename T::iterator it2;
// 	std::cout << "Size " << list.size() << " : ";
// 	while (it != list.end())
// 	{
// 		std::cout << *it;
// 		it2 = it;
// 		it2++;
// 		if (it2 != list.end())
// 			std::cout << " - ";
// 		it++;
// 	}
// 	std::cout << std::endl;
// }


template <typename T>
bool operator==(ft::List<T> & a, std::list<T> & b)
{
	if (a.size() != b.size())
		return (false);
	if (a.empty() != b.empty())
		return (false);
	typename ft::List<T>::iterator it = a.begin();
	typename std::list<T>::iterator it2 = b.begin();
	while (it != a.end())
	{
		if (*it != *it2)
			return (false);
		++it;
		++it2;
	}
	return (true);
};


struct Greater {
    bool operator()(const int &a, const int &b) {return a < b;}
};

static void constructors()
{
	std::cout << BLUE << "\n>Constructor" << RESET << std::endl;
	int test[] = {0, 1, 2, 3};
	ft::List<int> l1;
	std::list<int> l2;
	check("default", l1 == l2);
	ft::List<int> l3((size_t)10);
	std::list<int> l4((size_t)10);
	check("fill with default value", l3 == l4);
	ft::List<int> l5((size_t)10, 42);
	std::list<int> l6((size_t)10, 42);
	check("fill", l5 == l6);
	ft::List<int> l7(test, test + 4);
	std::list<int> l8(test, test + 4);
	check("range", l7 == l8);
	ft::List<int> l9(l7);
	std::list<int> l10(l8);
	check("copy", l9 == l10);
}

static void copy_operator()
{
	std::cout << BLUE << "\n>Operator =" << RESET << std::endl;
	int test[] = {0, 1, 2, 3};
	ft::List<int> l1(test, test + 4);
	std::list<int> l2(test, test + 4);
	ft::List<int> l3;
	std::list<int> l4;
	l3 = l1;
	l4 = l2;
	check("source", l1 == l3);
	check("copy", l2 == l4);
	l1.push_back(1);
	check("modified source", l1 != l3);
}

static void max_size()
{
	std::cout << BLUE << "\n>Max size" << RESET << std::endl;
	ft::List<int> l1;
	std::list<int> l2;
	ft::List<std::string> l3;
	std::list<std::string> l4;
	check("int", l1.max_size() == l2.max_size());
	check("string", l3.max_size() == l4.max_size());
}

static void front_back()
{
	std::cout << BLUE << "\n>Front / Back" << RESET << std::endl;
	ft::List<int> l1;
	std::list<int> l2;
	check("empty", l1.front() == l1.back());
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l2.push_back(1);
	l2.push_back(2);
	l2.push_back(3);
	check("front", l1.front() == l2.front());
	check("back", l1.back() == l2.back());
}

static void assign()
{
	std::cout << BLUE << "\n>Assign" << RESET << std::endl;
	int test[] = {0, 1, 2, 3};
	ft::List<int> l1;
	std::list<int> l2;
	l1.assign(test, test + 4);
	l2.assign(test, test + 4);
	check("iterator", l1 == l2);
	l1.assign((size_t)10, 42);
	l2.assign((size_t)10, 42);
	check("constant value", l1 == l2);
}

static void push()
{
	std::cout << BLUE << "\n>Push front/back" << RESET << std::endl;
	ft::List<int> l1;
	std::list<int> l2;
	for (int _ = 0; _ < 100; _++)
	{
		if (rand() % 2)
		{
			int n = rand() % 100;
			l1.push_front(n);
			l2.push_front(n);
		}
		else
		{
			int n = rand() % 100;
			l1.push_back(n);
			l2.push_back(n);
		}
	}
	check("front and back", l1 == l2);
}

static void swap()
{
	std::cout << BLUE << "\n>Swap" << RESET << std::endl;
	ft::List<int> l1;
	std::list<int> l2;
	ft::List<int> l3;
	std::list<int> l4;
	l1.push_front(1);
	l1.push_front(2);
	l1.push_front(3);
	l2.push_front(1);
	l2.push_front(2);
	l2.push_front(3);
	l3.push_front(42);
	l4.push_front(42);
	l1.swap(l3);
	l2.swap(l4);
	check("first list", l1 == l2);
	check("second list", l3 == l4);
}

static void resize()
{
	std::cout << BLUE << "\n>Resize / Clear" << RESET << std::endl;
	ft::List<int> l1;
	std::list<int> l2;
	l1.resize(10, 42);
	l2.resize(10, 42);
	check("longer", l1 == l2);
	l1.resize(2, 42);
	l2.resize(2, 42);
	check("shorter", l1 == l2);
	l1.resize(0, 0);
	l2.resize(0, 0);
	check("zero", l1 == l2);
	l1.resize(2, 42);	
	l1.clear();
	l2.resize(2, 42);
	l2.clear();
	check("clear", l1 == l2);
}

static void splice()
{
	std::cout << BLUE << "\n>Splice" << RESET << std::endl;
	ft::List<int> l1((size_t)10, 5);
	std::list<int> l2((size_t)10, 5);
	ft::List<int> l3((size_t)3, 0);
	std::list<int> l4((size_t)3, 0);
	l1.splice(++l1.begin(), l3);
	l2.splice(++l2.begin(), l4);
	check("entire list (dest)", l1 == l2);
	check("entire list (src)", l3 == l4);
	l1.assign((size_t)10, 5);
	l2.assign((size_t)10, 5);
	l3.assign((size_t)3, 0);
	l4.assign((size_t)3, 0);
	l1.splice(l1.begin(), l3, ++l3.begin());
	l2.splice(l2.begin(), l4, ++l4.begin());
	check("single element (dest)", l1 == l2);
	check("single element (src)", l3 == l4);
	l1.assign((size_t)10, 5);
	l2.assign((size_t)10, 5);
	l3.assign((size_t)3, 0);
	l4.assign((size_t)3, 0);
	l1.splice(l1.begin(), l3, ++l3.begin(), --l3.end());
	l2.splice(l2.begin(), l4, ++l4.begin(), --l4.end());
	check("element range (dest)", l1 == l2);
	check("element range (src)", l3 == l4);
}

static bool even(const int& value) { return (value % 2) == 0; } 

static void remove()
{
	std::cout << BLUE << "\n>Remove / Remove if" << RESET << std::endl;
	int test[] = {0, 0, 0, 1, 2, 0, 5, 3, 4, 5, 1, -1, 0, 1};
	ft::List<int> l1(test, test + 14);
	std::list<int> l2(test, test + 14);
	l1.remove(0);
	l1.remove(5);
	l2.remove(0);
	l2.remove(5);
	check("remove", l1 == l2);
	l1.remove_if(even);
	l2.remove_if(even);
	check("remove if", l1 == l2);
}

static void erase()
{
	std::cout << BLUE << "\n>Erase" << RESET << std::endl;
	int test[] = {0, 0, 0, 1, 2, 0, 5, 3, 4, 5, 1, -1, 0, 1};
	ft::List<int> l1(test, test + 14);
	std::list<int> l2(test, test + 14);
	l1.erase(l1.begin());
	l1.erase(--l1.end());
	l1.erase(--l1.end());
	l2.erase(l2.begin());
	l2.erase(--l2.end());
	l2.erase(--l2.end());
	check("single value", l1 == l2);
	l1.erase(++l1.begin(), --l1.end());
	l2.erase(++l2.begin(), --l2.end());
	check("range", l1 == l2);
}

static bool compare(int a, int b) 
{ 
    return (a >= b); 
} 

static void unique()
{
	std::cout << BLUE << "\n>Unique" << RESET << std::endl;
	int test[] = {0, 0, 0, 1, 2, 0, 5, 3, 4, 5, 1, -1, 0, 1};
	ft::List<int> l1(test, test + 14);
	std::list<int> l2(test, test + 14);
	l1.unique();
	l2.unique();
	check("unique", l1 == l2);
	l1.assign(test, test + 14);
	l2.assign(test, test + 14);
	l1.unique(compare);
	l2.unique(compare);
	check("function template", l1 == l2);
}

static bool compare2(int a, int b) 
{ 
    return (a == b); 
} 

static void merge()
{
	std::cout << BLUE << "\n>Merge" << RESET << std::endl;
	int test[] = {1, 2, 3};
	int test2[] = {42, 43, 44};
	ft::List<int> l1(test, test + 3);
	std::list<int> l2(test, test + 3);
	ft::List<int> l3(test2, test2 + 3);
	std::list<int> l4(test2, test2 + 3);
	l1.merge(l3);
	l2.merge(l4);
	check("simple merge (dest)", l1 == l2);
	check("simple merge (src)", l3 == l4);
	l1.assign(test, test + 3);
	l2.assign(test, test + 3);
	l3.assign(test2, test2 + 3);
	l4.assign(test2, test2 + 3);
	l1.merge(l3, compare2);
	l2.merge(l4, compare2);
	check("template merge (dest)", l1 == l2);
	check("template merge (src)", l3 == l4);
}

static void reverse()
{
	std::cout << BLUE << "\n>Reverse" << RESET << std::endl;
	int test[] = {0, 0, 0, 1, 2, 0, 5, 3, 4, 5, 1, -1, 0, 1};
	ft::List<int> l1(test, test + 14);
	std::list<int> l2(test, test + 14);
	l1.reverse();
	l2.reverse();
	check("reverse", l1 == l2);
}

static void operators()
{
	std::cout << BLUE << "\n>Operators" << RESET << std::endl;
	int test[] = {0, 0, 0, 1, 2, 0, 5, 3, 4, 5, 1, -1, 0, 1};
	ft::List<int> l1(test, test + 14);
	std::list<int> l2(test, test + 14);
	ft::List<int> l3(l1);
	std::list<int> l4(l2);
	check("== ", (l1 == l3) == (l2 == l4));
	check("!= ", (l1 != l3) == (l2 != l4));
	check("> ", (l1 > l3) == (l2 > l4));
	check("< ", (l1 < l3) == (l2 < l4));
	check(">= ", (l1 >= l3) == (l2 >= l4));
	check("<= ", (l1 <= l3) == (l2 <= l4));
}

void test_list()
{
	std::srand(time(0));
	std::cout << MAGENTA << BOLD << "\n-------------- LIST -------------" << RESET << std::endl;
	constructors();
	copy_operator();
	max_size();
	front_back();
	assign();
	push();
	swap();
	resize();
	splice();
	remove();
	erase();
	unique();
	merge();
	reverse();
	operators();
}