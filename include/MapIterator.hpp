#ifndef MAPITERATOR_HPP
# define MAPITERATOR_HPP
# include "utils.hpp"


namespace ft
{
	template <class Key, class T>
	class MapIterator
	{
	public:
		typedef std::pair<Key, T> value_type;
		typedef TNode<Key, T> * nodeptr;

	private:		
		nodeptr _ptr;

		nodeptr _next(nodeptr ptr)
		{
			nodeptr tmp;
			if (!ptr->right)
			{
				tmp = ptr;
				while (tmp->parent && tmp == tmp->parent->right)
					tmp = tmp->parent;
				tmp = tmp->parent;
			}
			else
			{
				tmp = ptr->right;
				while (tmp->left)
					tmp = tmp->left;
			}
			return (tmp);
		};
		nodeptr _prev(nodeptr ptr)
		{
			nodeptr tmp;

			if (!ptr->left)
			{
				tmp = ptr;
				while (tmp->parent && tmp == tmp->parent->left)
					tmp = tmp->parent;
				tmp = tmp->parent;
			}
			else
			{
				tmp = ptr->left;
				while (tmp->right)
					tmp = tmp->right;
			}
			return (tmp);
		};
	public:
		MapIterator()
		: _ptr(0)
		{};
		MapIterator(const nodeptr ptr)
		: _ptr(ptr)
		{};
		MapIterator(const MapIterator & other)
		{
			*this = other;
		};
		MapIterator & operator=(const MapIterator & other)
		{
			_ptr = other._ptr;
			return (*this);
		};
		nodeptr node()
		{
			return (_ptr);
		};
		value_type & operator*()
		{
			return (_ptr->pair);
		};
		value_type * operator->()
		{
			return (&_ptr->pair);
		};
		bool operator==(const MapIterator<Key, T> & other)
		{
			return (_ptr == other._ptr);
		};
		bool operator!=(const MapIterator<Key, T> & other)
		{
			return (!(*this == other));
		};
		// bool operator>(const MapIterator<Key, T> & other)
		// {
		// 	return (_ptr > other._ptr);
		// };
		// bool operator<(const MapIterator<Key, T> & other)
		// {
		// 	return (_ptr < other._ptr);
		// };
		// bool operator>=(const MapIterator<Key, T> & other)
		// {
		// 	return (_ptr >= other._ptr);
		// };
		// bool operator<=(const MapIterator<Key, T> & other)
		// {
		// 	return (_ptr <= other._ptr);
		// };
		MapIterator & operator++()
		{
			_ptr = _next(_ptr);
			return (*this);
		};
		MapIterator & operator--()
		{
			_ptr = _prev(_ptr);
			return (*this);
		};
		MapIterator operator++(int)
		{
			MapIterator tmp(*this);
			this->operator++();
			return (tmp);
		};
		MapIterator operator--(int)
		{
			MapIterator tmp(*this);
			this->operator--();
			return (tmp);
		};
	};
	template <class Key, class T>
	class ConstMapIterator
	{
	public:
		typedef std::pair<Key, T> value_type;
		typedef TNode<Key, T> * nodeptr;

	private:
		nodeptr _ptr;

		nodeptr _next(nodeptr ptr)
		{
			nodeptr tmp;

			if (!ptr->right)
			{
				tmp = ptr;
				while (tmp->parent && tmp == tmp->parent->right)
					tmp = tmp->parent;
				tmp = tmp->parent;
			}
			else
			{
				tmp = ptr->right;
				while (tmp->left)
					tmp = tmp->left;
			}
			return (tmp);
		};
		nodeptr _prev(nodeptr ptr)
		{
			nodeptr tmp;

			if (!ptr->left)
			{
				tmp = ptr;
				while (tmp->parent && tmp == tmp->parent->left)
					tmp = tmp->parent;
				tmp = tmp->parent;
			}
			else
			{
				tmp = ptr->left;
				while (tmp->right)
					tmp = tmp->right;
			}
			return (tmp);
		};

	public:
		ConstMapIterator()
		: _ptr(0)
		{};
		ConstMapIterator(const nodeptr ptr)
		: _ptr(ptr)
		{};
		ConstMapIterator(const ConstMapIterator & other)
		{
			*this = other;
		};
		ConstMapIterator & operator=(const ConstMapIterator & other)
		{
			_ptr = other._ptr;
			return (*this);
		};
		nodeptr node()
		{
			return (_ptr);
		};
		value_type & operator*() const
		{
			return (_ptr->pair);
		};
		value_type * operator->() const
		{
			return (&_ptr->pair);
		};
		bool operator==(const ConstMapIterator<Key, T> & other)
		{
			return (_ptr == other._ptr);
		};
		bool operator!=(const ConstMapIterator<Key, T> & other)
		{
			return (!(*this == other));
		};
		// bool operator>(const ConstMapIterator<Key, T> & other)
		// {
		// 	return (_ptr > other._ptr);
		// };
		// bool operator<(const ConstMapIterator<Key, T> & other)
		// {
		// 	return (_ptr < other._ptr);
		// };
		// bool operator>=(const ConstMapIterator<Key, T> & other)
		// {
		// 	return (_ptr >= other._ptr);
		// };
		// bool operator<=(const ConstMapIterator<Key, T> & other)
		// {
		// 	return (_ptr <= other._ptr);
		// };
		ConstMapIterator & operator++()
		{
			_ptr = _next(_ptr);
			return (*this);
		};
		ConstMapIterator & operator--()
		{
			_ptr = _prev(_ptr);
			return (*this);
		};
		ConstMapIterator operator++(int)
		{
			ConstMapIterator tmp(*this);
			this->operator++();
			return (tmp);
		};
		ConstMapIterator operator--(int)
		{
			ConstMapIterator tmp(*this);
			this->operator--();
			return (tmp);
		};
	};
	template <class Key, class T>
	class ReverseMapIterator
	{
	public:
		typedef std::pair<Key, T> value_type;
		typedef TNode<Key, T> * nodeptr;

	private:
		nodeptr _ptr;

		nodeptr _next(nodeptr ptr)
		{
			nodeptr tmp;
			if (!ptr->right)
			{
				tmp = ptr;
				while (tmp->parent && tmp == tmp->parent->right)
					tmp = tmp->parent;
				tmp = tmp->parent;
			}
			else
			{
				tmp = ptr->right;
				while (tmp->left)
					tmp = tmp->left;
			}
			return (tmp);
		};
		nodeptr _prev(nodeptr ptr)
		{
			nodeptr tmp;

			if (!ptr->left)
			{
				tmp = ptr;
				while (tmp->parent && tmp == tmp->parent->left)
					tmp = tmp->parent;
				tmp = tmp->parent;
			}
			else
			{
				tmp = ptr->left;
				while (tmp->right)
					tmp = tmp->right;
			}
			return (tmp);
		};
	public:
		ReverseMapIterator()
		: _ptr(0)
		{};
		ReverseMapIterator(const nodeptr ptr)
		: _ptr(ptr)
		{};
		ReverseMapIterator(const ReverseMapIterator & other)
		{
			*this = other;
		};
		ReverseMapIterator & operator=(const ReverseMapIterator & other)
		{
			_ptr = other._ptr;
			return (*this);
		};
		nodeptr node()
		{
			return (_ptr);
		};
		value_type & operator*()
		{
			return (_ptr->pair);
		};
		value_type * operator->()
		{
			return (&_ptr->pair);
		};
		bool operator==(const ReverseMapIterator<Key, T> & other)
		{
			return (_ptr == other._ptr);
		};
		bool operator!=(const ReverseMapIterator<Key, T> & other)
		{
			return (!(*this == other));
		};
		// bool operator>(const ReverseMapIterator<Key, T> & other)
		// {
		// 	return (_ptr > other._ptr);
		// };
		// bool operator<(const ReverseMapIterator<Key, T> & other)
		// {
		// 	return (_ptr < other._ptr);
		// };
		// bool operator>=(const ReverseMapIterator<Key, T> & other)
		// {
		// 	return (_ptr >= other._ptr);
		// };
		// bool operator<=(const ReverseMapIterator<Key, T> & other)
		// {
		// 	return (_ptr <= other._ptr);
		// };
		ReverseMapIterator & operator++()
		{
			_ptr = _prev(_ptr);
			return (*this);
		};
		ReverseMapIterator & operator--()
		{
			_ptr = _next(_ptr);
			return (*this);
		};
		ReverseMapIterator operator++(int)
		{
			ReverseMapIterator tmp(*this);
			this->operator++();
			return (tmp);
		};
		ReverseMapIterator operator--(int)
		{
			ReverseMapIterator tmp(*this);
			this->operator--();
			return (tmp);
		};
	};
	template <class Key, class T>
	class ConstReverseMapIterator
	{
	public:
		typedef std::pair<Key, T> value_type;
		typedef std::pair<Key, T>& value_type &;
		typedef BNode<Key, T>* nodeptr;
	protected:
		nodeptr _ptr;
	private:
		nodeptr _next(nodeptr ptr)
		{
			nodeptr tmp;
			if (!ptr->right)
			{
				tmp = ptr;
				while (tmp->parent && tmp == tmp->parent->right)
					tmp = tmp->parent;
				tmp = tmp->parent;
			}
			else
			{
				tmp = ptr->right;
				while (tmp->left)
					tmp = tmp->left;
			}
			return (tmp);
		};
		nodeptr _prev(nodeptr ptr)
		{
			nodeptr tmp;

			if (!ptr->left)
			{
				tmp = ptr;
				while (tmp->parent && tmp == tmp->parent->left)
					tmp = tmp->parent;
				tmp = tmp->parent;
			}
			else
			{
				tmp = ptr->left;
				while (tmp->right)
					tmp = tmp->right;
			}
			return (tmp);
		};
	public:
		ConstReverseMapIterator()
		: _ptr(0)
		{};
		ConstReverseMapIterator(const nodeptr ptr)
		: _ptr(ptr)
		{};
		ConstReverseMapIterator(const ConstReverseMapIterator & other)
		{
			*this = other;
		};
		ConstReverseMapIterator & operator=(const ConstReverseMapIterator & other)
		{
			_ptr = other._ptr;
			return (*this);
		};
		nodeptr node()
		{
			return (_ptr);
		};
		value_type & operator*() const
		{
			return (_ptr->pair);
		};
		value_type * operator->() const
		{
			return (&_ptr->pair);
		};
		bool operator==(const ConstReverseMapIterator<Key, T> & other)
		{
			return (_ptr == other._ptr);
		};
		bool operator!=(const ConstReverseMapIterator<Key, T> & other)
		{
			return (!(*this == other));
		};
		// bool operator>(const ConstReverseMapIterator<Key, T> & other)
		// {
		// 	return (_ptr > other._ptr);
		// };
		// bool operator<(const ConstReverseMapIterator<Key, T> & other)
		// {
		// 	return (_ptr < other._ptr);
		// };
		// bool operator>=(const ConstReverseMapIterator<Key, T> & other)
		// {
		// 	return (_ptr >= other._ptr);
		// };
		// bool operator<=(const ConstReverseMapIterator<Key, T> & other)
		// {
		// 	return (_ptr <= other._ptr);
		// };
		ConstReverseMapIterator & operator++()
		{
			_ptr = _prev(_ptr);
			return (*this);
		};
		ConstReverseMapIterator & operator--()
		{
			_ptr = _next(_ptr);
			return (*this);
		};
		ConstReverseMapIterator operator++(int)
		{
			ConstReverseMapIterator tmp(*this);
			this->operator++();
			return (tmp);
		};
		ConstReverseMapIterator operator--(int)
		{
			ConstReverseMapIterator tmp(*this);
			this->operator--();
			return (tmp);
		};
	};
};

#endif