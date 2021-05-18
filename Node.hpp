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
} // namespace ft

#endif