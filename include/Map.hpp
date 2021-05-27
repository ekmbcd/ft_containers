#ifndef MAP_HPP
#define MAP_HPP

#include "utils.hpp"
#include "MapIterator.hpp"

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > > 
	class Map
	{
	public:
		typedef std::pair<const Key, T> value_type;
		typedef MapIterator<Key, T> iterator;
		typedef ReverseMapIterator<Key, T> reverse_iterator;
		typedef ConstMapIterator<Key, T> const_iterator;
		typedef ConstReverseMapIterator<Key, T> const_reverse_iterator;
		typedef Compare key_compare;

	private:
		TNode<Key, T> * _end;
		Alloc _alloc;

		TNode<Key, T> * _new_node(Key const & key, T const & val)
		{
			TNode<Key, T> * n = new TNode<Key, T>;
			n->pair = std::make_pair(key, val);
			n->left = NULL;
			n->right = NULL;
			n->parent = NULL;
			n->end = false;
			return (n);
		}
		TNode<Key, T> * _new_node()
		{
			TNode<Key, T> * n = new TNode<Key, T>;
			n->pair = NULL;
			n->left = NULL;
			n->right = NULL;
			n->parent = NULL;
			n->end = true;
			return (n);
		}
		void _init()
		{
			_end = _new_node();
			_end->right = _end;
			_end->parent = _end;
		}
		void _free_tree(node n)
		{
			if (n->right)
				_free_tree(n->right);
			if (n->left)
				_free_tree(n->left);
			delete n;
		};

	public:
		explicit Map(const key_compare & comp = key_compare(), const Alloc & alloc = Alloc())
		:_alloc(alloc)
		{

		}

		template <class InputIterator>
		Map(InputIterator first, InputIterator last, const key_compare & comp = key_compare(), const Alloc & alloc = Alloc());

		Map(const Map & x);

		Map & operator=(const map& x);

	};
}

#endif