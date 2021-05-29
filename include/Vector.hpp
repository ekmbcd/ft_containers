#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "VectorIterator.hpp"
# include "utils.hpp"

namespace ft
{
	template <typename T, class Alloc = std::allocator<T> >
	class Vector
	{
	private:
		unsigned int _size;
		unsigned int _capacity;
		T * _array;
		Alloc _allocator;

		void _free()
		{
			if(_array)
				delete [] _array;
			_array = 0;
		}

	public:		
		typedef ft::VectorIterator<T> iterator;
		typedef ft::ConstVectorIterator<T> const_iterator;
		typedef ft::ReverseVectorIterator<T> reverse_iterator;
		typedef ft::ConstReverseVectorIterator<T> const_reverse_iterator;

		explicit Vector(const Alloc &allocator = Alloc())
			: _size(0), _capacity(0), _array(0), _allocator(allocator)
		{};
		template <class InputIterator>
		Vector(InputIterator begin, InputIterator end, const Alloc &allocator = Alloc())
		: _size(0), _capacity(0), _array(0), _allocator(allocator)
		{
			assign(begin, end);
		};
		Vector(unsigned int n, T const & value = T(), const Alloc &allocator = Alloc())
		: _size(0), _capacity(0), _array(0), _allocator(allocator)
		{
			assign(n, value);
		};
		Vector(const Vector &other)
		: _size(0), _capacity(0), _array(0), _allocator(other._allocator)
		{
			*this = other;
		};
		~Vector()
		{
			_free();
		};
		Vector & operator=(const Vector & other)
		{
			_free();
			_allocator = other._allocator;
			_capacity = 0;
			_size = 0;
			_array = 0;
			assign(other.begin(), other.end());
			return (*this);
		};
		T & operator[](unsigned int n)
		{
			return (_array[n]);
		};
		T const & operator[](unsigned int n) const
		{
			return (_array[n]);
		};
		iterator begin()
		{
			return (iterator(_array));
		};
		const_iterator begin() const
		{
			return (const_iterator(_array));
		};
		iterator end()
		{
			return (iterator(_array + _size));
		};
		const_iterator end() const
		{
			return (const_iterator(_array + _size));
		};
		reverse_iterator rbegin()
		{
			return (reverse_iterator(_array + _size - 1));
		};
		const_reverse_iterator rbegin() const
		{
			return (const_reverse_iterator(_array + _size - 1));
		};
		reverse_iterator rend()
		{
			return (reverse_iterator(_array - 1));
		};
		const_reverse_iterator rend() const
		{
			return (const_reverse_iterator(_array - 1));
		};
		void reserve(unsigned int n)
		{
			if (n > _capacity)
			{
				unsigned int i = -1;
				T *	tmp;
				tmp  = new T[n * 2];
				_capacity = n * 2;
				while (++i < _size)
					tmp[i] = _array[i];
				_free();
				_array = tmp;
			}
		};
		void push_back(const T & value)
		{
			if (_size + 1 > _capacity)
				reserve(_size + 1);
			_array[_size] = value;
			_size++;
		};
		unsigned int size() const
		{
			return (_size);
		};
		unsigned int capacity() const
		{
			return (_capacity);
		};
		bool empty() const
		{
			return (_size == 0);
		};
		iterator insert(iterator position, const T & value)
		{
			unsigned int i = 0;
			unsigned int j = _size;
			iterator it = begin();

			while (it + i != position && i < _size)
				i++;
			if (_capacity < _size + 1)
				reserve(_size + 1);
			while (j > i)
			{
				_array[j] = _array[j - 1];
				j--;
			}	
			_array[i] = value;
			_size++;
			
			return (iterator(&_array[i]));
		};
		void insert(iterator position, unsigned int n, const T & value)
		{			
			while (n--)
				position = insert(position, value);
		};
		template <class InputIterator>
		void insert(iterator position, InputIterator begin, InputIterator end)
		{
			while (begin != end)
			{
				position = insert(position, *begin) + 1;
				++begin;
			}
		};
		unsigned long max_size() const
		{
			return (std::numeric_limits<unsigned long>::max() / sizeof(T));
		};
		T & at(unsigned int n)
		{
			if (n >= _size || n < 0)
				throw std::out_of_range("index out of range");
			return _array[n];
		};
		T const & at(unsigned int n) const
		{
			if (n >= _size || n < 0)
				throw std::out_of_range("index out of range");
			return _array[n];
		};
		iterator erase(iterator position)
		{
			iterator cursor = position;
			while (cursor + 1 != end())
			{
				*cursor = *(cursor + 1);
				cursor++;
			}
			_size--;
			return (iterator(position));
		};
		iterator erase(iterator begin, iterator end)
		{
			while (begin != end)
			{
				erase(begin);
				end--;
			}
			return (iterator(begin));
		};
		void clear()
		{
			_free();
			_size = 0;
			_capacity = 0;
		};
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last)
		{
			clear();
			insert(begin(), first, last);
		};
		void assign(unsigned int n, const T & value)
		{
			clear();
			insert(begin(), n, value);
		};
		T & front()
		{
			return _array[0];
		};
		T const & front() const
		{
			return _array[0];
		};
		T & back()
		{
			return _array[_size - 1];
		};
		T const & back() const
		{
			return _array[_size - 1];
		};
		void pop_back()
		{
			if (_size)
				_size--;
		};
		void resize(unsigned int n, T value = T())
		{
			while (n < _size)
				pop_back();
			while (n > _size)
				push_back(value);
		};
		void swap(Vector &other)
		{
			ft::swap(_array, other._array);
			ft::swap(_capacity, other._capacity);
			ft::swap(_size, other._size);
		};
	};
	template <class T>
	void swap(Vector<T> & x, Vector<T> & y)
	{
		x.swap(y);
	};
	template<class T>
	bool operator==(const Vector<T> &a, const Vector<T> &b)
	{
		if (a.size() != b.size())
			return (false);
		unsigned long i = -1;
		while (++i < a.size())
		{
			if (a[i] != b[i])
				return (false);
		}
		return (true);
	};
	template<class T>
	bool operator!=(const Vector<T> & a, const Vector<T> & b)
	{
		return (!(a == b));
	};
	template <class T>
	bool operator<(const Vector<T> & a, const Vector<T> & b)
	{
		unsigned int i;
		unsigned int n;

		if (a.size() > b.size())
			n = b.size();
		else
			n = a.size();
		i = 0;
		while (i < n)
		{
			if (a[i] != b[i])
				return (a[i] < b[i]);
			i++;
		}
		return (a.size() < b.size());
	}
	template <class T>
	bool operator<=(const Vector<T> &a, const Vector<T> &b)
	{
		return (a < b || a == b);
	}
	template <class T>
	bool operator>(const Vector<T> &a, const Vector<T> &b)
	{
		return (!(a < b) && !(a == b));
	}
	template <class T>
	bool operator>=(const Vector<T> &a, const Vector<T> &b)
	{
		return (!(a < b));
	}
};

#endif