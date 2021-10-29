/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_reverse_iterator.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 07:54:07 by clorin            #+#    #+#             */
/*   Updated: 2021/10/28 07:55:00 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef VECTOR_REVERSE_ITERATOR_HPP
# define VECTOR_REVERSE_ITERATOR_HPP

namespace ft
{
	template <typename T>
	class	vectorReverseIterator
	{
		private:
			T*	_ptr;

		public:

			vectorReverseIterator(void) {};
			vectorReverseIterator(T* ptr):_ptr(ptr){};
			vectorReverseIterator(vectorReverseIterator<T> const &cpy){ *this = cpy;};
			vectorReverseIterator(vectorIterator<T> const &cpy):_ptr(cpy.operator->()){};
			virtual ~vectorReverseIterator(void){};
			vectorReverseIterator &operator=(vectorReverseIterator const &cpy)
			{
				if(this != &cpy)
					_ptr = cpy._ptr;
				return (*this);
			}

			//increments
			vectorReverseIterator	operator++(void){_ptr--; return(*this);};
			vectorReverseIterator	operator++(int){_ptr--; return(vectorReverseIterator(_ptr + 1));};
			vectorReverseIterator	operator--(void){_ptr++; return(*this);};
			vectorReverseIterator 	operator--(int){_ptr++; return(vectorReverseIterator(_ptr - 1));};

			// +/-
			vectorReverseIterator	operator+(std::ptrdiff_t op){return(vectorReverseIterator(_ptr - op));};
			vectorReverseIterator	operator-(std::ptrdiff_t op){return(vectorReverseIterator(_ptr + op));};

			//+= -= operators
			void	operator+=(std::ptrdiff_t op){_ptr -= op;};
			void	operator-=(std::ptrdiff_t op){_ptr += op;};

			// ->
			T*				operator->()		{return(_ptr);};
			const T* 		operator->() const	{return(_ptr);};

			// Deferencement
			T &	operator*() 		{return (*_ptr);};
			const T & operator*()const 	{return (*_ptr);};

			T & operator[](std::ptrdiff_t op)		{return(_ptr[op]);};
			const T & operator[](std::ptrdiff_t op) const	{return(_ptr[op]);};

			//boolean
			bool operator==(vectorReverseIterator const & b) const	{return (_ptr == b._ptr);};
			bool operator!=(vectorReverseIterator const & b) const	{return (_ptr != b._ptr);};
			bool operator>(vectorReverseIterator const & b) const {return (_ptr > b._ptr);};
			bool operator<(vectorReverseIterator const & b) const {return (_ptr < b._ptr);};
			bool operator>=(vectorReverseIterator const & b) const {return (_ptr >= b._ptr);};
			bool operator<=(vectorReverseIterator const & b) const {return (_ptr <= b._ptr);};
	};
}

#endif
