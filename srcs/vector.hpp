/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:22:16 by clorin            #+#    #+#             */
/*   Updated: 2021/10/27 19:45:31 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>

# include "vector_iterator.hpp"
# include "vector_reverse_iterator.hpp"
# include "utils.hpp"

namespace ft
{
	template<class T, class Allocator = std::allocator<T> >
	class vector
	{
		public:

			//default (1)
			explicit vector(const Allocator & alloc = Allocator())
			:_alloc(alloc), _ptr(0), _capacity(0), _size_container(0){};


			// fill(2)
			explicit vector(size_t n, const T & val = T(), const Allocator & alloc = Allocator())
			: _alloc(alloc), _ptr(0), _capacity(n), _size_container(n)
			{
				_ptr = _alloc.allocate(n);
				for(size_t i = 0; i < n; i++)
					_alloc.construct(_ptr + i, val);
			}

			//range(3)

			//copy(4)
			explicit vector (vector const &copy)
			: _alloc(copy.get_allocator()), _capacity(copy._capacity), _size_container(0)
			{
				_ptr = _alloc.allocate(_capacity);
				for (ft::vectorIterator<T> it = copy.begin(); it != copy.end(); it++)
					this->push_back(*it);
			};

			vector &operator=(vector const& copy)
			{
				if(*this != copy)
				{
					this->clear();
					for (ft::vectorIterator<T> it = copy.begin(); it != copy.end(); it++)
						this->push_back(*it);
				}
				return(*this);
			};

			virtual ~vector(void)
			{
				this->clear();
				if(_capacity > 0)
					_alloc.deallocate(_ptr, _capacity);
			};

			T			&	operator[](size_t pos)		{return (_ptr[pos]);};
			const T		&	operator[](size_t pos) const{return (_ptr[pos]);};

			void	push_back(const T& value)
			{
				if(_size_container == _capacity)
				{
					size_t	new_capacity = (_size_container > 0)? _size_container * 2 : 1;
					this->reserve(new_capacity);
				}
				_alloc.construct(_ptr + _size_container, value);
				_size_container++;
			};

			// remove element

			void	pop_back()
			{
				if (_size_container > 0)
				{
					_alloc.destroy(_ptr + (_size_container - 1));
					_size_container--;
				}
			};

			void	clear()
			{
				if(_size_container > 0)
				{
					for(ft::vectorIterator<T> it = this->begin(); it != this->end(); it++)
						_alloc.destroy(&(*it));
					_size_container = 0;
				}
			}

			// size
			std::size_t		size() const {return(_size_container);};

			std::size_t		capacity() const {return(_capacity);};

			std::size_t		max_size() const {return(Allocator().max_size());};

			bool	empty() const {return(_size_container == 0);};

			void	resize(std::size_t n, T val = T())
			{
				T	*new_ptr;
				if (n == _size_container)
					return;
				if (n > this->max_size())
					throw(std::length_error("vector::resize"));
				if (n < _size_container)
				{
					for(std::size_t i = n; i < _size_container; i++)
						_alloc.destroy(_ptr + i);
					_capacity = n;
				}
				else
				{
					/* If n is greater than the current container size, 
					the content is expanded by inserting at the end
					as many elements as needed to reach a size of n.
					If val is specified, the new elements are initialized as
					copies of val, otherwise, they are value-initialized.*/
					this->reserve(n);
					for(std::size_t i = _size_container; i < n; i++)
						_alloc.construct(_ptr+i, val);
				}
				_size_container = n;
			};

			void	reserve(size_t n)
			{
				if (n > this->max_size())
					throw (std::length_error("vector::reserve"));
				else if (n > _capacity)
				{
					T			*prev_ptr = _ptr;
					std::size_t	prev_size = _size_container;
					std::size_t	prev_capacity = _capacity;
					_ptr = _alloc.allocate(n);
					_capacity = n;
					for(std::size_t i = 0; i < prev_size; i++)
						_alloc.construct(_ptr + i, *(prev_ptr + i));
					_alloc.deallocate(prev_ptr, prev_capacity);
				}
			};

			//begin() end() back() front()
			ft::vectorIterator<T>		begin()			{return (vectorIterator<T>(_ptr));};
			const ft::vectorIterator<T>	begin() const 	{return (vectorIterator<T>(_ptr));};
			ft::vectorIterator<T>		end()		{return (vectorIterator<T>(_ptr + _size_container));};
			const ft::vectorIterator<T>	end() const {return (vectorIterator<T>(_ptr + _size_container));};
		
			T		&	front()			{return(*_ptr);};
			const T	&	front() const	{return(*_ptr);};
			T		&	back()		{return(*(_ptr + _size_container - 1));};
			const T	&	back() const{return(*(_ptr + _size_container - 1));};

			//rbegin() rend()
			ft::vectorReverseIterator<T>		rbegin()	   {return(vectorReverseIterator<T>(_ptr + _size_container - 1));};
			const ft::vectorReverseIterator<T>	rbegin() const {return(vectorReverseIterator<T>(_ptr + _size_container - 1));};
			ft::vectorReverseIterator<T>		rend()		{return(vectorReverseIterator<T>(_ptr - 1));};
			const ft::vectorReverseIterator<T>	rend() const{return(vectorReverseIterator<T>(_ptr - 1));};

			Allocator	get_allocator()const{return Allocator();};

		private:
			T				*_ptr;
			Allocator		_alloc;
			size_t			_capacity;
			size_t			_size_container; //nb of elem in vector

	};

// Non-member function overloads

template <class T, class Allocator>
	bool operator==(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator> &rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		ft::vectorIterator<T> it_lhs = lhs.begin();
		ft::vectorIterator<T> it_rhs = rhs.begin();
		while(it_lhs != lhs.end() && it_rhs != rhs.end() && *it_lhs == *it_rhs)
		{
			it_lhs++;
			it_rhs++;
		}
		return(it_lhs == lhs.end() && it_rhs == rhs.end());
	}

template <class T, class Allocator>
	bool operator!=(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator> &rhs)
	{
		return (!(lhs == rhs));
	}

template <class T, class Allocator>
	bool operator<(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

template <class T, class Allocator>
	bool operator<=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
	{
		//a<=b	->	!(b < a)
		return (!(rhs < lhs));
	}

template <class T, class Allocator>
	bool operator>(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
	{
		//a>b		->  b<a
		return (rhs < lhs);
	}

template <class T, class Allocator>
	bool operator>=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
	{
		//a>=b	->	!(a<b)
		return (!(lhs < rhs));
	}
}
#endif
