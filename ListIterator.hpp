#ifndef LISTITERATOR_HPP
# define LISTITERATOR_HPP

# include "List.hpp"
# include "Node.hpp"

namespace ft
{
	template <class T>
	class ListIterator
	{
	protected:
		Node<T> * _ptr;

	public:
		ListIterator(void)
		{};
		ListIterator(ListIterator const & other)
		{
			*this = other;
		};
		ListIterator(Node<T> * ptr) 
		: _ptr(ptr)
		{};
		~ListIterator(void)
		{};
		Node<T> * node(void) const
		{
			return (_ptr);
		};
		ListIterator & operator=(ListIterator const & other)
		{
			_ptr = other._ptr;
			return (*this);
		};
		ListIterator & operator++(void)
		{
			_ptr = _ptr->next;
			return (*this);
		};
		ListIterator & operator--(void)
		{
			_ptr = _ptr->prev;
			return (*this);
		};
		ListIterator operator++(int)
		{
			ListIterator tmp(*this);
			operator++();
			return (tmp);
		};
		ListIterator operator--(int)
		{
			ListIterator tmp(*this);
			operator--();
			return (tmp);
		};
		bool operator==(ListIterator const & other) const
		{
			return (_ptr == other._ptr);
		};
		bool operator!=(ListIterator const & other) const
		{
			return (_ptr != other._ptr);
		};
		bool operator>(ListIterator const & other) const
		{
			return (_ptr > other._ptr);
		};
		bool operator>=(ListIterator const & other) const
		{
			return (_ptr >= other._ptr);
		};
		bool operator<(ListIterator const & other) const
		{
			return (_ptr < other._ptr);
		};
		bool operator<=(ListIterator const & other) const
		{
			return (_ptr <= other._ptr);
		};
		T & operator*(void)
		{
			return (_ptr->data);
		};
		T *operator->(void)
		{
			return (_ptr->data);
		};
		ListIterator operator+(int n) const
		{
			ListIterator tmp(*this);
			tmp += n;
			return (tmp);
		};
		ListIterator operator-(int n) const
		{
			ListIterator tmp(*this);
			tmp -= n;
			return (tmp);
		};
		ListIterator & operator+=(int n)
		{
			while (n < 0)
			{
				(*this)--;
				n++;
			}
			while (n > 0)
			{
				(*this)++;
				n--;
			}
			return (*this);
		};
		ListIterator & operator-=(int n)
		{
			while (n > 0)
			{
				operator--();
				n--;
			}
			while (n < 0)
			{
				operator++();
				n++;
			}
			return (*this);
		};
	};
	
	template <class T>
	class ConstListIterator
	{
	protected:
		Node<T> * _ptr;

	public:
		ConstListIterator(void)
		{};
		ConstListIterator(ConstListIterator const & other)
		{
			*this = other;
		};
		ConstListIterator(Node<T> * ptr)
		: _ptr(ptr)
		{};
		~ConstListIterator(void)
		{};
		Node<T> * node(void) const
		{
			return (_ptr);
		};
		ConstListIterator & operator=(ConstListIterator const & other)
		{
			_ptr = other._ptr;
			return (*this);
		};
		ConstListIterator & operator++(void)
		{
			_ptr = _ptr->next;
			return (*this);
		};
		ConstListIterator & operator--(void)
		{
			_ptr = _ptr->prev;
			return (*this);
		};
		ConstListIterator operator++(int)
		{
			ConstListIterator tmp(*this);
			operator++();
			return (tmp);
		};
		ConstListIterator operator--(int)
		{
			ConstListIterator tmp(*this);
			operator--();
			return (tmp);
		};
		bool operator==(ConstListIterator const & other) const
		{
			return (_ptr == other._ptr);
		};
		bool operator!=(ConstListIterator const & other) const
		{
			return (_ptr != other._ptr);
		};
		bool operator>(ConstListIterator const & other) const
		{
			return (_ptr > other._ptr);
		};
		bool operator>=(ConstListIterator const & other) const
		{
			return (_ptr >= other._ptr);
		};
		bool operator<(ConstListIterator const & other) const
		{
			return (_ptr < other._ptr);
		};
		bool operator<=(ConstListIterator const & other) const
		{
			return (_ptr <= other._ptr);
		};
		const T & operator*(void)
		{
			return (_ptr->data);
		};
		const T *operator->(void)
		{
			return (_ptr->data);
		};
		ConstListIterator operator+(int n) const
		{
			ConstListIterator tmp(*this);
			tmp += n;
			return (tmp);
		};
		ConstListIterator operator-(int n) const
		{
			ConstListIterator tmp(*this);
			tmp -= n;
			return (tmp);
		};
		ConstListIterator & operator+=(int n)
		{
			while (n < 0)
			{
				(*this)--;
				n++;
			}
			while (n > 0)
			{
				(*this)++;
				n--;
			}
			return (*this);
		};
		ConstListIterator & operator-=(int n)
		{
			while (n > 0)
			{
				operator--();
				n--;
			}
			while (n < 0)
			{
				operator++();
				n++;
			}
			return (*this);
		};
	};

	template <class T>
	class ReverseListIterator
	{
	protected:
		Node<T> * _ptr;
		
	public:
		ReverseListIterator(void)
		{};
		ReverseListIterator(const ReverseListIterator & other)
		{
			*this = other;
		};
		ReverseListIterator(Node<T> * ptr)
		{
			this->_ptr = ptr;
		};
		~ReverseListIterator(void)
		{};
		ReverseListIterator & operator++(void)
		{
			this->_ptr = this->_ptr->prev;
			return (*this);
		};
		ReverseListIterator & operator--(void)
		{
			this->_ptr = this->_ptr->next;
			return (*this);
		};
		ReverseListIterator operator++(int)
		{
			ReverseListIterator tmp(*this);
			operator++();
			return (tmp);
		};
		ReverseListIterator operator--(int)
		{
			ReverseListIterator tmp(*this);
			operator--();
			return (tmp);
		};
		bool operator==(const ReverseListIterator & other) const
		{
			return (_ptr == other._ptr);
		};
		bool operator!=(const ReverseListIterator & other) const
		{
			return (_ptr != other._ptr);
		};
		bool operator>(const ReverseListIterator & other) const
		{
			return (_ptr > other._ptr);
		};
		bool operator>=(const ReverseListIterator & other) const
		{
			return (_ptr >= other._ptr);
		};
		bool operator<(const ReverseListIterator & other) const
		{
			return (_ptr < other._ptr);
		};
		bool operator<=(const ReverseListIterator & other) const
		{
			return (_ptr <= other._ptr);
		};
		T & operator*(void)
		{
			return (_ptr->data);
		};
		T *operator->(void)
		{
			return (_ptr->data);
		};
		ReverseListIterator operator+(int n) const
		{
			ReverseListIterator tmp(*this);
			tmp += n;
			return (tmp);
		};
		ReverseListIterator operator-(int n) const
		{
			ReverseListIterator tmp(*this);
			tmp -= n;
			return (tmp);
		};
		ReverseListIterator & operator+=(int n)
		{
			while (n < 0)
			{
				(*this)--;
				n++;
			}
			while (n > 0)
			{
				(*this)++;
				n--;
			}
			return (*this);
		};
		ReverseListIterator & operator-=(int n)
		{
			while (n > 0)
			{
				operator--();
				n--;
			}
			while (n < 0)
			{
				operator++();
				n++;
			}
			return (*this);
		};
	};

	template <class T>
	class ConstReverseListIterator
	{
	protected:
		Node<T> * _ptr;
		
	public:
		ConstReverseListIterator(void)
		{};
		ConstReverseListIterator(const ConstReverseListIterator & other)
		{
			*this = other;
		};
		ConstReverseListIterator(Node<T> * ptr)
		{
			this->_ptr = ptr;
		};
		~ConstReverseListIterator(void)
		{};
		ConstReverseListIterator & operator++(void)
		{
			this->_ptr = this->_ptr->prev;
			return (*this);
		};
		ConstReverseListIterator & operator--(void)
		{
			this->_ptr = this->_ptr->next;
			return (*this);
		};
		ConstReverseListIterator operator++(int)
		{
			ConstReverseListIterator tmp(*this);
			operator++();
			return (tmp);
		};
		ConstReverseListIterator operator--(int)
		{
			ConstReverseListIterator tmp(*this);
			operator--();
			return (tmp);
		};
		bool operator==(const ConstReverseListIterator & other) const
		{
			return (_ptr == other._ptr);
		};
		bool operator!=(const ConstReverseListIterator & other) const
		{
			return (_ptr != other._ptr);
		};
		bool operator>(const ConstReverseListIterator & other) const
		{
			return (_ptr > other._ptr);
		};
		bool operator>=(const ConstReverseListIterator & other) const
		{
			return (_ptr >= other._ptr);
		};
		bool operator<(const ConstReverseListIterator & other) const
		{
			return (_ptr < other._ptr);
		};
		bool operator<=(const ConstReverseListIterator & other) const
		{
			return (_ptr <= other._ptr);
		};
		T & operator*(void)
		{
			return (_ptr->data);
		};
		T *operator->(void)
		{
			return (_ptr->data);
		};
		ConstReverseListIterator operator+(int n) const
		{
			ConstReverseListIterator tmp(*this);
			tmp += n;
			return (tmp);
		};
		ConstReverseListIterator operator-(int n) const
		{
			ConstReverseListIterator tmp(*this);
			tmp -= n;
			return (tmp);
		};
		ConstReverseListIterator & operator+=(int n)
		{
			while (n < 0)
			{
				(*this)--;
				n++;
			}
			while (n > 0)
			{
				(*this)++;
				n--;
			}
			return (*this);
		};
		ConstReverseListIterator & operator-=(int n)
		{
			while (n > 0)
			{
				operator--();
				n--;
			}
			while (n < 0)
			{
				operator++();
				n++;
			}
			return (*this);
		};
	};
};

#endif