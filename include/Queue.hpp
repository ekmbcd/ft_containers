#ifndef QUEUE_HPP
# define QUEUE_HPP

#include "List.hpp"

namespace ft
{
	template <class T, class Container = ft::List<T> >
	class Queue
	{
	public:
		typedef Container container_type;

	private:
		container_type c;

		template <class A, class B>
		friend bool	operator==(const Queue<A, B> & lhs, const Queue<A, B> & rhs);
		template <class A, class B>
		friend bool	operator!=(const Queue<A, B> & lhs, const Queue<A, B> & rhs);
		template <class A, class B>
		friend bool	operator<(const Queue<A, B> & lhs, const Queue<A, B> & rhs);
		template <class A, class B>
		friend bool	operator<=(const Queue<A, B> & lhs, const Queue<A, B> & rhs);
		template <class A, class B>
		friend bool	operator>(const Queue<A, B> & lhs, const Queue<A, B> & rhs);
		template <class A, class B>
		friend bool	operator>=(const Queue<A, B> & lhs, const Queue<A, B> & rhs);

	public:
		explicit Queue(const container_type & ctnr = container_type())
		: c(ctnr)
		{};
		Queue(const Queue & other)
		{
			*this = other;
		};
		~Queue()
		{};
		Queue & operator=(const Queue & other)
		{
			this->c = other.c;
			return (*this);
		};
		bool empty() const
		{
			return (c.empty());
		};
		unsigned long size() const
		{
			return (c.size());
		};
		T & front()
		{
			return (c.front());
		};
		const T & front() const
		{
			return (c.front());
		};
		T & back()
		{
			return (c.back());
		};
		const T & back() const
		{
			return (c.back());
		};
		void push(const T & value)
		{
			return (c.push_back(value));
		};
		void pop()
		{
			c.pop_front();
		};
	};
	template <class T, class Container>
	bool operator==(const Queue<T, Container> & lhs, const Queue<T, Container> & rhs)
	{
		return (lhs.c == rhs.c);
	};
	template <class T, class Container>
	bool operator!=(const Queue<T, Container> & lhs, const Queue<T, Container> & rhs)
	{
		return (lhs.c != rhs.c);
	};
	template <class T, class Container>
	bool operator>(const Queue<T, Container> & lhs, const Queue<T, Container> & rhs)
	{
		return (lhs.c > rhs.c);
	};
	template <class T, class Container>
	bool operator<(const Queue<T, Container> & lhs, const Queue<T, Container> & rhs)
	{
		return (lhs.c < rhs.c);
	};
	template <class T, class Container>
	bool operator>=(const Queue<T, Container> & lhs, const Queue<T, Container> & rhs)
	{
		return (lhs.c >= rhs.c);
	};
	template <class T, class Container>
	bool operator<=(const Queue<T, Container> & lhs, const Queue<T, Container> & rhs)
	{
		return (lhs.c <= rhs.c);
	};
};

#endif