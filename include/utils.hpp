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
	template <class Key, class T>
	struct TNode
	{
		std::pair<Key, T> pair;
		TNode * left;
		TNode * right;
		TNode * parent;
		bool end;
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