/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 07:54:07 by clorin            #+#    #+#             */
/*   Updated: 2021/10/28 07:55:00 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

namespace ft
{
	template <typename T>
	class	vectorIterator
	{
		private:
			T*	_ptr;

		public:

			vectorIterator(void) {};
			vectorIterator(T* ptr):_ptr(ptr){};
			vectorIterator(vectorIterator const &cpy){ *this = cpy;};

			virtual ~vectorIterator(void){};
			vectorIterator &operator=(vectorIterator const &cpy)
			{
				if(this != &cpy)
					_ptr = cpy._ptr;
				return (*this);
			}

			//increments
			vectorIterator	operator++(void) 
			{
				_ptr++; return(*this);
			};
			vectorIterator	operator++(int)
			{
				_ptr++; return(vectorIterator(_ptr - 1));
			};
			vectorIterator	operator--(void)
			{
				_ptr--; return(*this);
			};
			vectorIterator operator--(int)
			{
				_ptr--; return(vectorIterator(_ptr +1));
			};

			//+= -= operators
			void	operator+=(std::ptrdiff_t op)
			{
				_ptr += op;
			};
			void	operator-=(std::ptrdiff_t op)
			{
				_ptr -= op;
			};

			// ->
			T*		operator->()
			{
				return(_ptr);
			};
			T* 		operator->() const
			{
				return(_ptr);
			};


			// Deferencement
			T &	operator*() 		{return (*_ptr);};
			T & operator*()const 	{return (*_ptr);};

			//boolean
			bool operator==(vectorIterator const & b) const
			{
				return (_ptr == b._ptr);
			};
			bool operator!=(vectorIterator const & b) const
			{
				return (_ptr != b._ptr);
			};
			bool operator>(vectorIterator const & b) const
			{
				return (_ptr > b._ptr);
			};
			bool operator<(vectorIterator const & b) const
			{
				return (_ptr < b._ptr);
			};
			bool operator>=(vectorIterator const & b) const
			{
				return (_ptr >= b._ptr);
			};
			bool operator<=(vectorIterator const & b) const
			{
				return (_ptr <= b._ptr);
			};
	};
}

#endif
