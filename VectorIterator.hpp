#ifndef VECTORITERATOR_HPP
# define VECTORITERATOR_HPP

namespace ft
{
	
	template <typename T>
	class ConstVectorIterator;
	template <typename T>
	class ConstReverseVectorIterator;

	template <typename T>
	class VectorIterator
	{
	protected:
		T * _ptr;

	public:
		VectorIterator()
		{};
		VectorIterator(VectorIterator const & other)
		{
			*this = other;
		};
		VectorIterator(T * ptr) 
		: _ptr(ptr)
		{};
		VectorIterator(ConstVectorIterator<T> other)
		{
			_ptr = other.ptr();
		};
		~VectorIterator()
		{};
		T * ptr()
		{
			return (_ptr);
		};
		VectorIterator & operator=(VectorIterator const & other)
		{
			_ptr = other._ptr;
			return (*this);
		};
		VectorIterator & operator++()
		{
			_ptr++;
			return (*this);
		};
		VectorIterator & operator--()
		{
			_ptr--;
			return (*this);
		};
		VectorIterator operator++(int)
		{
			VectorIterator tmp(*this);
			operator++();
			return (tmp);
		};
		VectorIterator operator--(int)
		{
			VectorIterator tmp(*this);
			operator--();
			return (tmp);
		};
		bool operator==(VectorIterator const & other) const
		{
			return (_ptr == other._ptr);
		};
		bool operator!=(VectorIterator const & other) const
		{
			return (_ptr != other._ptr);
		};
		// bool operator>(VectorIterator const & other) const
		// {
		// 	return (_ptr > other._ptr);
		// };
		// bool operator>=(VectorIterator const & other) const
		// {
		// 	return (_ptr >= other._ptr);
		// };
		// bool operator<(VectorIterator const & other) const
		// {
		// 	return (_ptr < other._ptr);
		// };
		// bool operator<=(VectorIterator const & other) const
		// {
		// 	return (_ptr <= other._ptr);
		// };
		T & operator*()
		{
			return (*_ptr);
		};
		T * operator->()
		{
			return (*_ptr);
		};
		VectorIterator operator+(int n) const
		{
			VectorIterator tmp(*this);
			tmp += n;
			return (tmp);
		};
		VectorIterator operator-(int n) const
		{
			VectorIterator tmp(*this);
			tmp -= n;
			return (tmp);
		};
		VectorIterator & operator+=(int n)
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
		VectorIterator & operator-=(int n)
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
	class ConstVectorIterator
	{
	protected:
		T * _ptr;

	public:
		ConstVectorIterator()
		{};
		ConstVectorIterator(ConstVectorIterator const & other)
		{
			*this = other;
		};
		// ConstVectorIterator(VectorIterator<T> other)
		// {
		// 	_ptr = other.node();
		// };
		ConstVectorIterator(T * ptr)
		: _ptr(ptr)
		{};
		~ConstVectorIterator()
		{};
		T * ptr() const
		{
			return (_ptr);
		};
		ConstVectorIterator & operator=(ConstVectorIterator const & other)
		{
			_ptr = other._ptr;
			return (*this);
		};
		ConstVectorIterator & operator++()
		{
			_ptr++;
			return (*this);
		};
		ConstVectorIterator & operator--()
		{
			_ptr--;
			return (*this);
		};
		ConstVectorIterator operator++(int)
		{
			ConstVectorIterator tmp(*this);
			operator++();
			return (tmp);
		};
		ConstVectorIterator operator--(int)
		{
			ConstVectorIterator tmp(*this);
			operator--();
			return (tmp);
		};
		bool operator==(ConstVectorIterator const & other) const
		{
			return (_ptr == other._ptr);
		};
		bool operator!=(ConstVectorIterator const & other) const
		{
			return (_ptr != other._ptr);
		};
		// bool operator>(ConstVectorIterator const & other) const
		// {
		// 	return (_ptr > other._ptr);
		// };
		// bool operator>=(ConstVectorIterator const & other) const
		// {
		// 	return (_ptr >= other._ptr);
		// };
		// bool operator<(ConstVectorIterator const & other) const
		// {
		// 	return (_ptr < other._ptr);
		// };
		// bool operator<=(ConstVectorIterator const & other) const
		// {
		// 	return (_ptr <= other._ptr);
		// };
		const T & operator*() const
		{
			return (*_ptr);
		};
		const T * operator->() const
		{
			return (*_ptr);
		};
		ConstVectorIterator operator+(int n) const
		{
			ConstVectorIterator tmp(*this);
			tmp += n;
			return (tmp);
		};
		ConstVectorIterator operator-(int n) const
		{
			ConstVectorIterator tmp(*this);
			tmp -= n;
			return (tmp);
		};
		ConstVectorIterator & operator+=(int n)
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
		ConstVectorIterator & operator-=(int n)
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
	class ReverseVectorIterator
	{
	protected:
		T * _ptr;
		
	public:
		ReverseVectorIterator()
		{};
		ReverseVectorIterator(const ReverseVectorIterator & other)
		{
			*this = other;
		};
		ReverseVectorIterator(T * ptr)
		{
			_ptr = ptr;
		};
		ReverseVectorIterator(ConstReverseVectorIterator<T> other)
		{
			_ptr = other.ptr();
		};
		~ReverseVectorIterator()
		{};
		ReverseVectorIterator & operator=(ReverseVectorIterator const & other)
		{
			_ptr = other._ptr;
			return (*this);
		};
		ReverseVectorIterator & operator++()
		{
			_ptr--;
			return (*this);
		};
		ReverseVectorIterator & operator--()
		{
			_ptr++;
			return (*this);
		};
		ReverseVectorIterator operator++(int)
		{
			ReverseVectorIterator tmp(*this);
			operator++();
			return (tmp);
		};
		ReverseVectorIterator operator--(int)
		{
			ReverseVectorIterator tmp(*this);
			operator--();
			return (tmp);
		};
		bool operator==(const ReverseVectorIterator & other) const
		{
			return (_ptr == other._ptr);
		};
		bool operator!=(const ReverseVectorIterator & other) const
		{
			return (_ptr != other._ptr);
		};
		// bool operator>(const ReverseVectorIterator & other) const
		// {
		// 	return (_ptr > other._ptr);
		// };
		// bool operator>=(const ReverseVectorIterator & other) const
		// {
		// 	return (_ptr >= other._ptr);
		// };
		// bool operator<(const ReverseVectorIterator & other) const
		// {
		// 	return (_ptr < other._ptr);
		// };
		// bool operator<=(const ReverseVectorIterator & other) const
		// {
		// 	return (_ptr <= other._ptr);
		// };
		T & operator*()
		{
			return (*_ptr);
		};
		T *operator->()
		{
			return (*_ptr);
		};
		ReverseVectorIterator operator+(int n) const
		{
			ReverseVectorIterator tmp(*this);
			tmp += n;
			return (tmp);
		};
		ReverseVectorIterator operator-(int n) const
		{
			ReverseVectorIterator tmp(*this);
			tmp -= n;
			return (tmp);
		};
		ReverseVectorIterator & operator+=(int n)
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
		ReverseVectorIterator & operator-=(int n)
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
	class ConstReverseVectorIterator
	{
	protected:
		T * _ptr;
		
	public:
		ConstReverseVectorIterator()
		{};
		ConstReverseVectorIterator(const ConstReverseVectorIterator & other)
		{
			*this = other;
		};
		ConstReverseVectorIterator(T * ptr)
		{
			_ptr = ptr;
		};
		ConstReverseVectorIterator(ReverseVectorIterator<T> other)
		{
			_ptr = other.node();
		};
		~ConstReverseVectorIterator()
		{};
		ConstReverseVectorIterator & operator=(ConstReverseVectorIterator const & other)
		{
			_ptr = other._ptr;
			return (*this);
		};
		ConstReverseVectorIterator & operator++()
		{
			_ptr--;
			return (*this);
		};
		ConstReverseVectorIterator & operator--()
		{
			_ptr++;
			return (*this);
		};
		ConstReverseVectorIterator operator++(int)
		{
			ConstReverseVectorIterator tmp(*this);
			operator++();
			return (tmp);
		};
		ConstReverseVectorIterator operator--(int)
		{
			ConstReverseVectorIterator tmp(*this);
			operator--();
			return (tmp);
		};
		bool operator==(const ConstReverseVectorIterator & other) const
		{
			return (_ptr == other._ptr);
		};
		bool operator!=(const ConstReverseVectorIterator & other) const
		{
			return (_ptr != other._ptr);
		};
		// bool operator>(const ConstReverseVectorIterator & other) const
		// {
		// 	return (_ptr > other._ptr);
		// };
		// bool operator>=(const ConstReverseVectorIterator & other) const
		// {
		// 	return (_ptr >= other._ptr);
		// };
		// bool operator<(const ConstReverseVectorIterator & other) const
		// {
		// 	return (_ptr < other._ptr);
		// };
		// bool operator<=(const ConstReverseVectorIterator & other) const
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
		ConstReverseVectorIterator operator+(int n) const
		{
			ConstReverseVectorIterator tmp(*this);
			tmp += n;
			return (tmp);
		};
		ConstReverseVectorIterator operator-(int n) const
		{
			ConstReverseVectorIterator tmp(*this);
			tmp -= n;
			return (tmp);
		};
		ConstReverseVectorIterator & operator+=(int n)
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
		ConstReverseVectorIterator & operator-=(int n)
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