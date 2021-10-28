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

namespace ft
{
	template<class T, class Allocator = std::allocator<T> >
	class vector
	{
		public:
			/*		TYPEDEF			*/
/*			typedef	T			value;
			typedef	T&			ref;
			typedef const T&	const_ref;*/

			explicit vector(const Allocator & alloc = Allocator())
			:_alloc(alloc), _ptr(0), _capacity(0), _size_container(0){};

			vector (vector const &copy)
			: _alloc(Allocator()), _capacity(0), _size_container(0)
			{
				*this = copy;	//TODO verifie deep copy in STL
			};

			vector &operator=(vector & copy)
			{
				for (ft::vectorIterator<T> it = copy.begin(); it != copy.end(); it++)
					this->push_back(*it);
				return(*this);
			};

			virtual ~vector(void)
			{
				this->clear();
				if(_capacity > 0)
				{
					_alloc.deallocate(_ptr, _capacity);
					_capacity = 0;
				}
			};

			T		&	operator[](size_t pos)
			{
				return (_ptr[pos]);
			};

			T		&	operator[](size_t pos)  const
			{
				return (_ptr[pos]);
			};

			void	push_back(const T& value)
			{
				if(_size_container == _capacity)
				{
					size_t	new_capacity = (_size_container > 0)? _size_container * 2 : 1;
					this->reserve(new_capacity);
				}
				/*if(_capacity == 0)
				{
					_ptr = _alloc.allocate(1);
					_capacity++;
				}*/
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
				if (n < _size_container)
				{
					for(std::size_t i = n; i < _size_container; i++)
						_alloc.destroy(_ptr + i);
					_capacity = n;
					_size_container = n;
				}
				else
				{
					/* If n is greater than the current container size, 
					the content is expanded by inserting at the end
					as many elements as needed to reach a size of n.
					If val is specified, the new elements are initialized as
					copies of val, otherwise, they are value-initialized.*/

				}
			};

			void	reserve(size_t n)
			{
				if (n > this->max_size())
					throw (std::length_error("vector::reserve"));
				if (n > _capacity)
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

			//begin() end()
			ft::vectorIterator<T>	begin()			{return (vectorIterator<T>(_ptr));};
			ft::vectorIterator<T>	begin() const 	{return (vectorIterator<T>(_ptr));};
			ft::vectorIterator<T>	end()		{return (vectorIterator<T>(_ptr + _size_container));};
			ft::vectorIterator<T>	end() const {return (vectorIterator<T>(_ptr + _size_container));};
		
		private:
			T				*_ptr;
			Allocator		_alloc;
			size_t			_capacity;
			size_t			_size_container; //nb of elem in vector

	};
}
#endif

