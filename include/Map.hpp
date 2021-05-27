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
		TNode<Key, T> * _root;
		Alloc _alloc;
		key_compare _comp;

		TNode<Key, T> * _new_node(Key const & key, T const & val, TNode<Key, T> parent)
		{
			TNode<Key, T> * n = new TNode<Key, T>;
			n->pair = std::make_pair(key, val);
			n->left = NULL;
			n->right = NULL;
			n->parent = parent;
			// n->end = false;
			return (n);
		}
		TNode<Key, T> * _new_node()
		{
			TNode<Key, T> * n = new TNode<Key, T>;
			n->pair = NULL;
			n->left = NULL;
			n->right = NULL;
			n->parent = NULL;
			// n->end = true;
			return (n);
		}
		void _init()
		{
			_root = _new_node();
		}
		void _free_tree(node n)
		{
			if (n->right)
				_free_tree(n->right);
			if (n->left)
				_free_tree(n->left);
			delete n;
		};
		void _insert(Key const & key, T const & val, TNode<Key, T> n)
		{
			if (key > n.pair.first)
			{
				if (!n.right)
					n.right = _new_node(key, val, n);
				else
					_insert(key, val, n.right);
			}
			else if (key < n.pair.first)
			{
				if (!n.left)
					n.left = _new_node(key, val, n);
				else
					_insert(key, val, n.left);
			}
		}

	public:
		explicit Map(const key_compare & comp = key_compare(), const Alloc & alloc = Alloc())
		:_alloc(alloc), _comp(comp)
		{
			_init();
		}
		template <class InputIterator>
		Map(InputIterator first, InputIterator last, const key_compare & comp = key_compare(), const Alloc & alloc = Alloc())
		:_alloc(alloc), _comp(comp)
		{
			_init();
			insert(first, last);
		}
		Map(const Map<Key, T> & other)
		{
			_init();
			*this = other;
		}
		~Map(void)
		{
			_free_tree(_root);	
		}
		Map & operator=(const map & x)
		{
			clear();
			insert(other.begin(), other.end());
			return (*this);
		}

	};
}

#endif