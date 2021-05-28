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
		typedef TNode<Key, T> node;

	private:
		node * _root;
		node * _end;
		Alloc _alloc;
		key_compare _comp;

		node * _new_node(Key const & key, T const & val, node * parent)
		{
			node * n = new TNode<Key, T>;
			n->pair = std::make_pair(key, val);
			n->left = NULL;
			n->right = NULL;
			n->parent = parent;
			// n->end = false;
			return (n);
		}
		node * _new_node()
		{
			node * n = new TNode<Key, T>;
			n->left = NULL;
			n->right = NULL;
			n->parent = NULL;
			// n->end = true;
			return (n);
		}
		void _init()
		{
			_root = _new_node();
			_end = _new_node();
			_end->parent = _root;
			_root->right = _end;
		}
		void _free_tree(node * n)
		{
			if (n->right)
				_free_tree(n->right);
			if (n->left)
				_free_tree(n->left);
			delete n;
		};
		void _insert(Key const & key, T const & val, node * n)
		{
			if (n == _end)
			{
				_end->parent->right = _new_node(key, val, _end->parent);
				_end->parent = _end->parent->right;
			}
			else if (key > n->pair.first)
			{
				if (!n->right)
					n->right = _new_node(key, val, n);
				else
					_insert(key, val, n->right);
			}
			else if (key < n->pair.first)
			{
				if (!n->left)
					n->left = _new_node(key, val, n);
				else
					_insert(key, val, n->left);
			}
		}
		int _count(node * n) const
		{
			int i = 0;
			if (n->left)
				i += _count(n->left) + 1;
			if (n->right && n->right != _end)
				i += _count(n->right) + 1;
			return (i);
		}
		node * _find_key(Key const & k, node * n)
		{
			if (!n || n == _end)
				return (0);
			else if (k > n->pair.first)
				return (_find_key(k, n->right));
			else if (k < n->pair.first)
				return (_find_key(k, n->left));
			else
				return(n);
		}
		void _rebuild(node * n, bool first=false)
		{
			std::cout << n << "\n";
			
			if (!n)
				return ;
			std::cout << ">>" << n->pair.first <<"\n";		
			if (n->parent->left == n)
				n->parent->left = 0;
			else
				n->parent->right = 0;
			std::pair<Key, T> tmp = n->pair;
			_rebuild(n->right);
			_rebuild(n->left);

			delete n;
			if (n != _end && !first)
				_insert(tmp.first, tmp.second, _root);
		}
		void _set_end()
		{
			node * tmp = _root;
			while (tmp->right)
				tmp = tmp->right;
			if (tmp != _end)
			{
				std::cout << "create end\n";
				_end = _new_node();
				_end->parent = tmp;
				tmp->right = _end;
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
		Map & operator=(const Map & x)
		{
			clear();
			insert(x.begin(), x.end());
			return (*this);
		}
		iterator begin()
		{
			node * tmp;
			tmp = _root->right;
			while (tmp->left)
				tmp = tmp->left;
			return(iterator(tmp));
		}
		const_iterator begin() const
		{
			node * tmp;
			tmp = _root->right;
			while (tmp->left)
				tmp = tmp->left;
			return(const_iterator(tmp));
		}
		iterator end()
		{
			return(iterator(_end));
		}
		const_iterator end() const
		{
			return(const_iterator(_end));
		}
		reverse_iterator rbegin()
		{
			return (reverse_iterator(_end->parent));
		};
		const_reverse_iterator rbegin() const
		{
			return (const_reverse_iterator(_end->parent));
		};
		reverse_iterator rend()
		{
			return (reverse_iterator(_root));
		};
		const_reverse_iterator rend() const
		{
			return (const_reverse_iterator(_root));
		};
		bool empty() const
		{
			return(_root->right == _end);
		}
		unsigned long size() const
		{
			return(_count(_root));
		}
		unsigned long max_size() const
		{
			return (std::numeric_limits<unsigned long>::max() / (sizeof(ft::TNode<Key, T>)));
		}
		T & operator[] (const Key & k)
		{
			node * tmp = _find_key(k, _root->right);
			if (!tmp)
			{
				insert(std::make_pair(k, T()));
				tmp = _find_key(k, _root->right);
			}
			return(tmp->pair.second);
		}
		std::pair<iterator, bool> insert (const value_type & val)
		{
			node * tmp;
			if ((tmp = _find_key(val.first, _root->right)))
				return(std::make_pair(iterator(tmp), false));
			_insert(val.first, val.second, _root->right);
			tmp = _find_key(val.first, _root->right);
			return(std::make_pair(iterator(tmp), true));
		}
		iterator insert (iterator position, const value_type & val)
		{
			node * tmp;
			if ((tmp = _find_key(val.first, _root->right)))
				return(tmp);
			_insert(val.first, val.second, position.node());
			tmp = _find_key(val.first, position.node());
			return(tmp);
		}
		template <class InputIterator>
		void insert (InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				insert(*first);
				++first;
			}
		}
		void erase (iterator position)
		{
			_rebuild(position.node(), true);
			_set_end();

		}
		unsigned int erase (Key const & k);
		void erase (iterator first, iterator last);








		void print()
		{
			_debug(_root->right);
		}
		void _debug(node * n)
		{
			if (n->left)
				_debug(n->left);
			std::cout << n->pair.first << " " << n->pair.second << std::endl;	
			if (n->right && n->right != _end)
				_debug(n->right);
		}

		void clear()
		{
			_free_tree(_root);
			_init();
		}

	};
}

#endif