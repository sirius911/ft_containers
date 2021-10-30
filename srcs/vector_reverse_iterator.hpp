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

			typedef T&			reference;
			typedef const T&	const_reference;
			typedef T*			pointer;
			typedef const T*	const_pointer;
			typedef ptrdiff_t	difference_type;

			vectorReverseIterator(void) {};
			vectorReverseIterator(pointer ptr):_ptr(ptr){};
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
			vectorReverseIterator	operator+(difference_type op){return(vectorReverseIterator(_ptr - op));};
			vectorReverseIterator	operator-(difference_type op){return(vectorReverseIterator(_ptr + op));};

			//+= -= operators
			void	operator+=(difference_type op){_ptr -= op;};
			void	operator-=(difference_type op){_ptr += op;};

			// ->
			pointer				operator->()		{return(_ptr);};
			const_pointer 		operator->() const	{return(_ptr);};

			// Deferencement
			reference		operator*() 		{return (*_ptr);};
			const_reference operator*() const 	{return (*_ptr);};

			reference		operator[](difference_type op)			{return(_ptr[op]);};
			const_reference	operator[](difference_type op) const	{return(_ptr[op]);};

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
