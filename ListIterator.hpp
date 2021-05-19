#ifndef LISTITERATOR_HPP
# define LISTITERATOR_HPP

# include "List.hpp"
# include "Node.hpp"

namespace ft
{
	
	template <typename T>
	class ConstListIterator;
	template <typename T>
	class ConstReverseListIterator;

	template <typename T>
	class ListIterator
	{
	protected:
		Node<T> * _ptr;

	public:
		ListIterator()
		{};
		ListIterator(ListIterator const & other)
		{
			*this = other;
		};
		ListIterator(Node<T> * ptr) 
		: _ptr(ptr)
		{};
		ListIterator(ConstListIterator<T> other)
		{
			_ptr = other.node();
		};
		~ListIterator()
		{};
		Node<T> * node()
		{
			return (_ptr);
		};
		ListIterator & operator=(ListIterator const & other)
		{
			_ptr = other._ptr;
			return (*this);
		};
		ListIterator & operator++()
		{
			_ptr = _ptr->next;
			return (*this);
		};
		ListIterator & operator--()
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
		// bool operator>(ListIterator const & other) const
		// {
		// 	return (_ptr > other._ptr);
		// };
		// bool operator>=(ListIterator const & other) const
		// {
		// 	return (_ptr >= other._ptr);
		// };
		// bool operator<(ListIterator const & other) const
		// {
		// 	return (_ptr < other._ptr);
		// };
		// bool operator<=(ListIterator const & other) const
		// {
		// 	return (_ptr <= other._ptr);
		// };
		T & operator*()
		{
			return (_ptr->value);
		};
		T * operator->()
		{
			return (_ptr->value);
		};
	// 	ListIterator operator+(int n) const
	// 	{
	// 		ListIterator tmp(*this);
	// 		tmp += n;
	// 		return (tmp);
	// 	};
	// 	ListIterator operator-(int n) const
	// 	{
	// 		ListIterator tmp(*this);
	// 		tmp -= n;
	// 		return (tmp);
	// 	};
	// 	ListIterator & operator+=(int n)
	// 	{
	// 		while (n < 0)
	// 		{
	// 			(*this)--;
	// 			n++;
	// 		}
	// 		while (n > 0)
	// 		{
	// 			(*this)++;
	// 			n--;
	// 		}
	// 		return (*this);
	// 	};
	// 	ListIterator & operator-=(int n)
	// 	{
	// 		while (n > 0)
	// 		{
	// 			operator--();
	// 			n--;
	// 		}
	// 		while (n < 0)
	// 		{
	// 			operator++();
	// 			n++;
	// 		}
	// 		return (*this);
	// 	};
	};
	
	template <typename T>
	class ConstListIterator
	{
	protected:
		Node<T> * _ptr;

	public:
		ConstListIterator()
		{};
		ConstListIterator(ConstListIterator const & other)
		{
			*this = other;
		};
		// ConstListIterator(ListIterator<T> other)
		// {
		// 	_ptr = other.node();
		// };
		ConstListIterator(Node<T> * ptr)
		: _ptr(ptr)
		{};
		~ConstListIterator()
		{};
		Node<T> * node() const
		{
			return (_ptr);
		};
		ConstListIterator & operator=(ConstListIterator const & other)
		{
			_ptr = other._ptr;
			return (*this);
		};
		ConstListIterator & operator++()
		{
			_ptr = _ptr->next;
			return (*this);
		};
		ConstListIterator & operator--()
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
		// bool operator>(ConstListIterator const & other) const
		// {
		// 	return (_ptr > other._ptr);
		// };
		// bool operator>=(ConstListIterator const & other) const
		// {
		// 	return (_ptr >= other._ptr);
		// };
		// bool operator<(ConstListIterator const & other) const
		// {
		// 	return (_ptr < other._ptr);
		// };
		// bool operator<=(ConstListIterator const & other) const
		// {
		// 	return (_ptr <= other._ptr);
		// };
		const T & operator*() const
		{
			return (_ptr->value);
		};
		const T * operator->() const
		{
			return (_ptr->value);
		};
	// 	ConstListIterator operator+(int n) const
	// 	{
	// 		ConstListIterator tmp(*this);
	// 		tmp += n;
	// 		return (tmp);
	// 	};
	// 	ConstListIterator operator-(int n) const
	// 	{
	// 		ConstListIterator tmp(*this);
	// 		tmp -= n;
	// 		return (tmp);
	// 	};
	// 	ConstListIterator & operator+=(int n)
	// 	{
	// 		while (n < 0)
	// 		{
	// 			(*this)--;
	// 			n++;
	// 		}
	// 		while (n > 0)
	// 		{
	// 			(*this)++;
	// 			n--;
	// 		}
	// 		return (*this);
	// 	};
	// 	ConstListIterator & operator-=(int n)
	// 	{
	// 		while (n > 0)
	// 		{
	// 			operator--();
	// 			n--;
	// 		}
	// 		while (n < 0)
	// 		{
	// 			operator++();
	// 			n++;
	// 		}
	// 		return (*this);
	// 	};
	};

	template <typename T>
	class ReverseListIterator
	{
	protected:
		Node<T> * _ptr;
		
	public:
		ReverseListIterator()
		{};
		ReverseListIterator(const ReverseListIterator & other)
		{
			*this = other;
		};
		ReverseListIterator(Node<T> * ptr)
		{
			this->_ptr = ptr;
		};
		ReverseListIterator(ConstReverseListIterator<T> other)
		{
			_ptr = other.node();
		};
		~ReverseListIterator()
		{};
		ReverseListIterator & operator++()
		{
			this->_ptr = this->_ptr->prev;
			return (*this);
		};
		ReverseListIterator & operator--()
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
		// bool operator>(const ReverseListIterator & other) const
		// {
		// 	return (_ptr > other._ptr);
		// };
		// bool operator>=(const ReverseListIterator & other) const
		// {
		// 	return (_ptr >= other._ptr);
		// };
		// bool operator<(const ReverseListIterator & other) const
		// {
		// 	return (_ptr < other._ptr);
		// };
		// bool operator<=(const ReverseListIterator & other) const
		// {
		// 	return (_ptr <= other._ptr);
		// };
		T & operator*()
		{
			return (_ptr->value);
		};
		T *operator->()
		{
			return (_ptr->value);
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

	template <typename T>
	class ConstReverseListIterator
	{
	protected:
		Node<T> * _ptr;
		
	public:
		ConstReverseListIterator()
		{};
		ConstReverseListIterator(const ConstReverseListIterator & other)
		{
			*this = other;
		};
		ConstReverseListIterator(Node<T> * ptr)
		{
			this->_ptr = ptr;
		};
		ConstReverseListIterator(ReverseListIterator<T> other)
		{
			_ptr = other.node();
		};
		~ConstReverseListIterator()
		{};
		ConstReverseListIterator & operator++()
		{
			this->_ptr = this->_ptr->prev;
			return (*this);
		};
		ConstReverseListIterator & operator--()
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
		// bool operator>(const ConstReverseListIterator & other) const
		// {
		// 	return (_ptr > other._ptr);
		// };
		// bool operator>=(const ConstReverseListIterator & other) const
		// {
		// 	return (_ptr >= other._ptr);
		// };
		// bool operator<(const ConstReverseListIterator & other) const
		// {
		// 	return (_ptr < other._ptr);
		// };
		// bool operator<=(const ConstReverseListIterator & other) const
		// {
		// 	return (_ptr <= other._ptr);
		// };
		T & operator*()
		{
			return (_ptr->value);
		};
		T *operator->()
		{
			return (_ptr->value);
		};
		// ConstReverseListIterator operator+(int n) const
		// {
		// 	ConstReverseListIterator tmp(*this);
		// 	tmp += n;
		// 	return (tmp);
		// };
		// ConstReverseListIterator operator-(int n) const
		// {
		// 	ConstReverseListIterator tmp(*this);
		// 	tmp -= n;
		// 	return (tmp);
		// };
		// ConstReverseListIterator & operator+=(int n)
		// {
		// 	while (n < 0)
		// 	{
		// 		(*this)--;
		// 		n++;
		// 	}
		// 	while (n > 0)
		// 	{
		// 		(*this)++;
		// 		n--;
		// 	}
		// 	return (*this);
		// };
		// ConstReverseListIterator & operator-=(int n)
		// {
		// 	while (n > 0)
		// 	{
		// 		operator--();
		// 		n--;
		// 	}
		// 	while (n < 0)
		// 	{
		// 		operator++();
		// 		n++;
		// 	}
		// 	return (*this);
		// };
	};
};

#endif