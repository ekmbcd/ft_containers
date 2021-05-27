#ifndef STACK_HPP
# define STACK_HPP

# include "Vector.hpp"

namespace ft
{
	template <class T, class Container = ft::Vector<T> >
	class Stack
	{
	public:
		typedef Container container_type;

	private:
		container_type c;

		template <class A, class B>
		friend bool	operator==(const Stack<A, B> & lhs, const Stack<A, B> & rhs);
		template <class A, class B>
		friend bool	operator!=(const Stack<A, B> & lhs, const Stack<A, B> & rhs);
		template <class A, class B>
		friend bool	operator<(const Stack<A, B> & lhs, const Stack<A, B> & rhs);
		template <class A, class B>
		friend bool	operator<=(const Stack<A, B> & lhs, const Stack<A, B> & rhs);
		template <class A, class B>
		friend bool	operator>(const Stack<A, B> & lhs, const Stack<A, B> & rhs);
		template <class A, class B>
		friend bool	operator>=(const Stack<A, B> & lhs, const Stack<A, B> & rhs);

	public:
		explicit Stack(const container_type & ctnr = container_type())
		: c(ctnr)
		{};
		Stack(const Stack & other)
		{
			*this = other;
		};
		~Stack()
		{};
		Stack &operator=(const Stack & other)
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
		T & top()
		{
			return (c.back());
		};
		const T & top() const
		{
			return (c.back());
		};
		void push(const T & value)
		{
			c.push_back(value);
		};
		void pop()
		{
			c.pop_back();
		};
	};
	template <class T, class Container>
	bool operator==(const Stack<T, Container> & lhs, const Stack<T, Container> & rhs)
	{
		return (lhs.c == rhs.c);
	};
	template <class T, class Container>
	bool operator!=(const Stack<T, Container> & lhs, const Stack<T, Container> & rhs)
	{
		return (lhs.c != rhs.c);
	};
	template <class T, class Container>
	bool operator>(const Stack<T, Container> & lhs, const Stack<T, Container> & rhs)
	{
		return (lhs.c > rhs.c);
	};
	template <class T, class Container>
	bool operator<(const Stack<T, Container> & lhs, const Stack<T, Container> & rhs)
	{
		return (lhs.c < rhs.c);
	};
	template <class T, class Container>
	bool operator>=(const Stack<T, Container> & lhs, const Stack<T, Container> & rhs)
	{
		return (lhs.c >= rhs.c);
	};
	template <class T, class Container>
	bool operator<=(const Stack<T, Container> & lhs, const Stack<T, Container> & rhs)
	{
		return (lhs.c <= rhs.c);
	};
};

#endif