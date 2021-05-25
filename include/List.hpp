#ifndef LIST_HPP
#define LIST_HPP

#include <limits>
#include <memory>
#include "utils.hpp"
#include "ListIterator.hpp"

// #include <iostream>
	
namespace ft
{	
	template <typename T, class Alloc = std::allocator<T> >
	class List
	{
	private:
		Node<T> * _start;
		Node<T> * _end;
		Alloc _alloc;

		Node<T> * _new_node(T const & val)
		{
			Node<T> * n = new Node<T>;
			n->value = val;
			n->next = NULL;
			n->prev = NULL;
			return (n);
		}
		Node<T> * _new_node()
		{
			Node<T> * n = new Node<T>;
			n->value = T();
			n->next = NULL;
			n->prev = NULL;
			return (n);
		}
		void _init()
		{
			_end = _new_node();
			_start = _end;
			_end->prev = _end;
			_end->next = _end;
		}
	
	public:
		typedef Alloc allocator_type;
		typedef ListIterator<T> iterator;
		typedef ConstListIterator<T> const_iterator;
		typedef ReverseListIterator<T> reverse_iterator;
		typedef ConstReverseListIterator<T> const_reverse_iterator;
	
		explicit List(const allocator_type &alloc=allocator_type()) 
		: _alloc(alloc)
		{
			_init();
		}
		explicit List(unsigned int n, T const & val=T(), const allocator_type &alloc=allocator_type())
		: _alloc(alloc)
		{
			_init();
			assign(n, val);
		}
		template <class InputIterator>
		List(InputIterator first, InputIterator last, const allocator_type &alloc=allocator_type())
		: _alloc(alloc)
		{
			_init();
			assign(first, last);
		}
		List(List const & src)
		{
			_init();
			*this = src;
		}
		~List()
		{
			clear();
			delete _end;
		}
		List & operator=(List const & src)
		{
			clear();
			iterator it(src.begin());
			while (it != src.end())
			{
				push_back(*it);
				++it;
			}
			return(*this);
		}
		unsigned long size() const
		{
			iterator i(_start);
			if (i == NULL)
				return (0);
			unsigned long n = 0;
			while (i++ != _end)
				n++;
			return (n);
		}
		iterator begin()
		{
			return(iterator(_start));
		}
		const_iterator begin() const
		{
			return(const_iterator(_start));
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
			return(_end->prev);
		}
		reverse_iterator rend()
		{
			return(_end);
		}
		bool empty() const
		{
			return(!(size()));
		}
		unsigned long max_size() const
		{
			return (std::numeric_limits<unsigned long>::max() / (sizeof(Node<T>)));
		};
		T & front()
		{
			return(_start->value);
		}
		T const & front() const
		{
			return(_start->value);
		}
		T & back()
		{
			return(_end->prev->value);
		}
		T const & back() const
		{
			return(_end->prev->value);
		}
		void push_front(T const & val)
		{
			Node<T> * tmp = _new_node(val);
			if (_start == _end)
			{
				_start = tmp;
				_start->next = _end;
				_start->prev = _end;
				_end->prev = _start;
				_end->next = _start;
			}
			else
			{
				_start->prev = tmp;
				_end->next = tmp;
				tmp->prev = _end;
				tmp->next = _start;
				_start = tmp;
			}
		}
		void pop_front()
		{
			if (_start == _end)
				return;
			_start = _start->next;
			delete _end->next;
			_end->next = _start;
		}
		void push_back(T const & val)
		{
			Node<T> * tmp = _new_node(val);
			if (_start == _end)
			{
				_start = tmp;
				_start->next = _end;
				_start->prev = _end;
				_end->prev = _start;
				_end->next = _start;
			}
			else
			{
				tmp->prev = _end->prev;
				_end->prev->next = tmp;
				tmp->next = _end;
				_end->prev = tmp;
			}
		}
		void pop_back()
		{
			if (_start == _end)
				return;
			Node<T> * tmp = _end->prev;
			tmp->prev->next = _end;
			_end->prev = tmp->prev;
			if (tmp == _start)
				_start = _end;
			delete tmp;
		}
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last)
		{
			clear();
			while (first != last)
				push_back(*(first++));
		};
		void assign(unsigned int n, const T & val)
		{
			clear();
			while (n--)
				push_front(val);
		}
		void clear()
		{
			Node<T> * tmp = _start;
			Node<T> * next = _start->next;

			while (tmp && tmp != _end)
			{
				delete tmp;
				tmp = next;
				next = next->next;
			}
			delete tmp;
			_init();
		}
		iterator insert(iterator position, const T & val)
		{
			if (position == begin())
			{
				push_front(val);
				return (begin());
			}
			if (position == end())
			{
				push_back(val);
				return (end());
			}
			Node<T> * after = position.node();
			Node<T> * before = after->prev;
			Node<T> * tmp = _new_node(val);
			tmp->next = after;
			tmp->prev = before;
			before->next = tmp;
			after->prev = tmp;
			return (iterator(tmp));
		}
		void insert(iterator position, unsigned int n, const T & val)
		{
			while (n--)
				insert(position, val);
		}
    	void insert(iterator position, iterator first, iterator last)
		{
			while (first != last)
			{
				position = insert(position, *(first++));
				if (position != end())
					position++;
			}
		}
		iterator erase (iterator position)
		{
			if (position == begin())
			{
				pop_front();
				return (begin());
			}
			if (position == end())
			{
				pop_back();
				return (end());
			}
			Node<T> * tmp = position.node();
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			delete tmp;
			return(iterator(tmp->next));
		}
		iterator erase (iterator first, iterator last)
		{
			while (first != last)
				erase(first++);
			return (last);
		}
		void swap(List & x)
		{
			ft::swap(*this, x);
		}
		void resize (unsigned int n, T const & val = T())
		{
			while (n < size())
				pop_back();	
			while (n > size())
				push_back(val);
		}
		void splice(iterator position, List & x)
		{
			splice(position, x, x.begin(), x.end());
		}
		void splice(iterator position, List & x, iterator i)
		{
			insert(position, *i);
			x.erase(i);
		}
		void splice(iterator position, List & x, iterator first, iterator last)
		{
			insert(position, first, last);
			x.erase(first, last);
		}
		void remove(const T & value)
		{
			iterator c = begin();
			while (c != end())
			{
				if (*c == value)
					c = erase(c);
				else
					c++;
			}
		}
		template <class Predicate>
  		void remove_if (Predicate pred)
		{
			iterator c = begin();
			while (c != end())
			{
				if (pred(*c))
					c = erase(c);
				else
					c++;
			}
		}
		void unique()
		{
			iterator c = begin();
			T tmp;
			while (c != end())
			{
				tmp = *c;
				++c;
				while (c != end() && *c == tmp )
				{
					c = erase(c);
				}
			}
		}
		template <class BinaryPredicate>
		void unique(BinaryPredicate binary_pred)
		{
			iterator prev = begin();
			iterator next = ++begin();
			while (next != end())
			{
				if (binary_pred(*prev, *next))
					erase(next);
				else
					prev = next;
				++next;
			}
		}
		void merge (List & x)
		{
			if (&x == this)
				return;
			splice(end(), x);
			sort();
		}
		template <class Compare>
  		void merge (List & x, Compare comp)
		{
			if (&x == this)
				return;
			splice(end(), x);
			sort(comp);
		}
		void sort()
		{
			iterator prev = begin();
			iterator next;

			while (prev.node()->next != end().node())
			{
				next = prev.node()->next;
				while (next != end())
				{
					if (*next < *prev)
						ft::swap(*prev, *next);
					++next;
				}
				++prev;
			}
		}
		template <class Compare>
		void sort(Compare comp)
		{
			iterator prev = begin();
			iterator next;
			
			while (prev.node()->next != end().node())
			{
				next = prev.node()->next;
				while (next != end())
				{
					if (comp(*prev, *next))
						ft::swap(*prev, *next);
					++next;
				}
				++prev;
			}
		}
		void reverse()
		{
			iterator head = begin();
			iterator tail = --end();
			unsigned int n = size() / 2;
			T tmp;

			while (n--)
			{
				tmp = *head;
				*head = *tail;
				*tail = tmp;
				++head;
				--tail;
			}
		}
	};
	template <typename T>
	void swap(List<T> & x, List<T> & y)
	{
		x.swap(y);
	};
	template<typename T>
	bool operator==(List<T> const & lhs, List<T> const & rhs) 
	{
		if (lhs.size() != rhs.size())
			return (false);
		typename List<T>::const_iterator tmp1 = lhs.begin();
		typename List<T>::const_iterator tmp2 = rhs.begin();
		while (tmp1 != lhs.end())
		{
			if (*(tmp1++) != *(tmp2++))
				return (false);
		}
		return (true);
	};
	template<typename T>
	bool operator!=(List<T> const & lhs, List<T> const & rhs) 
	{
		return (!(lhs == rhs));
	};
	template<typename T>
	bool operator<(List<T> const & lhs, List<T> const & rhs) 
	{
		if (lhs.size() < rhs.size())
			return (true);
		if (lhs.size() > rhs.size())
			return (false);
		typename List<T>::const_iterator tmp1 = lhs.begin();
		typename List<T>::const_iterator tmp2 = rhs.begin();
		while (tmp1 != lhs.end())
		{
			if (*tmp1 != *tmp2)
				return (*tmp1 < *tmp2);
			++tmp1;
			++tmp2;
		}	
		return (false);
	};
	template<typename T>
	bool operator<=(List<T> const & lhs, List<T> const & rhs) {
		return (!(rhs < lhs));
	};
	template<typename T>
	bool operator>(List<T> const & lhs, List<T> const & rhs) {
		return (rhs < lhs);
	};
	template<typename T>
	bool operator>=(List<T> const & lhs, List<T> const & rhs) {
		return (!(lhs < rhs));
	};

} // namespace ft		

#endif