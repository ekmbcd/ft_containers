#ifndef LIST_HPP
#define LIST_HPP

#include <memory>
#include "Node.hpp"
#include "ListIterator.hpp"
// #include <iostream>
	
namespace ft
{	
	template <typename T, class Alloc=std::allocator<T> >
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
	/*
		class iterator
		{
		private:
			Node * _ptr;
		public:
			iterator() : _ptr(NULL) {}
			iterator(Node * ptr) : _ptr(ptr) {}
			iterator(iterator const & src): _ptr(src._ptr) {}

			virtual ~iterator() {}

			T & operator * () { return (_ptr->value); }
			T * operator & () { return (_ptr); }
			T * operator ->() { return (_ptr->value); }
			iterator & operator = (iterator & src)
			{
				_ptr = src._ptr;
				return (*this); 
			}
			iterator & operator ++()
			{
				_ptr = _ptr->next;
				return (*this);
			}
			iterator operator ++(int)
			{
				iterator tmp(*this);
				_ptr = _ptr->next;
				return (tmp);
			}
			iterator & operator --() 
			{
				_ptr = _ptr->prev;
				return (*this);
			}
			iterator operator --(int) 
			{
				iterator tmp(*this);
				_ptr = _ptr->prev;
				return (tmp);
			}
			bool operator ==(iterator const & rhs) const 
			{
				return (_ptr == rhs._ptr);
			}
			bool operator !=(iterator const & rhs) const 
			{
				return (_ptr != rhs._ptr);
			}
		};

		class const_iterator : public iterator
		{
		private:
			Node const * _ptr;
			const_iterator() {}
		public:
			const_iterator(Node * ptr) : _ptr(ptr) {}
			~const_iterator() {}
		};
		*/
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
		List(iterator first, iterator last, const allocator_type &alloc=allocator_type())
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
		}
		List & operator=(List const & src)
		{
			clear();
			_init();
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
			return(!(_start));
		}
		unsigned long max_size() const
		{
			return (std::numeric_limits<unsigned long>::max() / (sizeof(Node<T>)));
		};
		Node<T> & front()
		{
			return(*_start);
		}
		Node<T> const & front() const
		{
			return(*_start);
		}
		Node<T> & back()
		{
			return(*(_end->prev));
		}
		Node<T> const & back() const
		{
			return(*(_end->prev));
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
			delete tmp;
		}
		void assign(iterator first, iterator last)
		{
			clear();
			_init();
			while (first != last)
				push_back(*(first++));
		};
		void assign(unsigned int n, const T & val)
		{
			clear();
			_init();
			while (n--)
			{
				push_front(val);
			}
		}
		void clear()
		{
			Node<T> * tmp = _start;
			
			while (tmp && tmp != _end)
			{
				delete tmp;
				tmp = tmp->next;
			}
			delete tmp;
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

		}
		template <class Compare>
  		void merge (List & x, Compare comp)
		{
			
		}
	};

} // namespace ft		

#endif