#ifndef LIST_HPP
#define LIST_HPP

#include "Node.hpp"
#include "ListIterator.hpp"
// #include <iostream>
	
namespace ft
{	
	template <typename T>
	class List
	{
	private:
		Node<T> * _new_node(T const & val)
		{
			Node * n = new Node;
			n->value = val;
			n->next = NULL;
			n->prev = NULL;
			return (n);
		}

		Node<T> * _new_node()
		{
			Node * n = new Node;
			n->value = T();
			n->next = NULL;
			n->prev = NULL;
			return (n);
		}

		Node<T> * _start;
		Node<T> * _end;
		
	public:
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
		List() : _start(NULL)
		{
			_end = _new_node();
		}
		// List(List const & src);
		// ~List();

		// List & operator = (List const & src);
		unsigned int size() const
		{
			iterator i(_start);
			if (i == NULL)
				return (0);
			unsigned int n = 0;
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

		void push_front(T const & val)
		{
			Node * tmp;
			tmp = _new_node(val);
			if (!_start)
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

		void push_back(T const & val)
		{
			Node * tmp;
			tmp = _new_node(val);
			if (!_start)
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
	};


} // namespace ft		

#endif