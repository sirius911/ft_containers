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
			typedef	T			value;
			typedef	T&			ref;
			typedef const T&	const_ref;

			explicit vector(const Allocator & alloc = Allocator())
			:_alloc(alloc), _ptr(0), _size_alloc(0), _size_container(0)
			{
				std::cout << "construct by default" << std::endl;
			};

			vector (vector const &copy)
			: _alloc(Allocator()), _size_alloc(0), _size_container(0)
			{
				*this = copy;
			};

			vector &operator=(vector & copy)
			{
				std::cout << "operator="<<std::endl;
				for (ft::vectorIterator<T> it = copy.begin(); it != copy.end(); it++)
					this->push_back(*it);
				return(*this);
			};

			virtual ~vector(void)
			{
				if(_size_alloc > 0)
				{
					_alloc.deallocate(_ptr, _size_alloc);
					_size_alloc = 0;
				}
			};

			ref			operator[](size_t pos)
			{
				return (_ptr[pos]);
			};

			const_ref	operator[](size_t pos)  const
			{
				return (_ptr[pos]);
			};

			void	push_back(const T& value)
			{
				if(_size_alloc == 0)
				{
					_ptr = _alloc.allocate(1);
					_size_alloc++;
				}
				_alloc.construct(_ptr + _size_container, value);
				_size_container++;
			};
		
		private:
			T				*_ptr;
			Allocator		_alloc;
			size_t			_size_alloc;
			size_t			_size_container;

	};
}
#endif

