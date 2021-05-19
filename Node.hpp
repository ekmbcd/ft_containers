#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

namespace ft
{
	template<typename T>
	struct Node
	{
		T value;
		struct Node * next;
		struct Node * prev;
	};
	template <typename T>
	void	swap(T & a, T & b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	};
} // namespace ft

#endif