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

			typedef T&			reference;
			typedef const T&	const_reference;
			typedef T*			pointer;
			typedef const T*	const_pointer;
			typedef ptrdiff_t	difference_type;


			vectorIterator(void) {};
			vectorIterator(pointer ptr):_ptr(ptr){};
			vectorIterator(vectorIterator const &cpy){ *this = cpy;};

			virtual ~vectorIterator(void){};
			vectorIterator &operator=(vectorIterator const &cpy)
			{
				if(this != &cpy)
					_ptr = cpy._ptr;
				return (*this);
			}

			//increments
			vectorIterator	operator++(void){_ptr++; return(*this);};
			vectorIterator	operator++(int){_ptr++; return(vectorIterator(_ptr - 1));};
			vectorIterator	operator--(void){_ptr--; return(*this);};
			vectorIterator 	operator--(int){_ptr--; return(vectorIterator(_ptr +1));};

			// +/-
			vectorIterator	operator+(difference_type op){return(vectorIterator(_ptr + op));};
			vectorIterator	operator-(difference_type op){return(vectorIterator(_ptr - op));};

			//+= -= operators
			void	operator+=(difference_type op){_ptr += op;};
			void	operator-=(difference_type op){_ptr -= op;};

			// ->
			pointer				operator->()		{return(_ptr);};
			const_pointer 		operator->() const	{return(_ptr);};

			// Deferencement
			reference		operator*() 		{return (*_ptr);};
			const_reference	operator*() const 	{return (*_ptr);};

			reference	 	operator[](difference_type op)			{return(_ptr[op]);};
			const_reference operator[](difference_type op) const	{return(_ptr[op]);};

			//boolean
			bool operator==(vectorIterator const & b) const	{return (_ptr == b._ptr);};
			bool operator!=(vectorIterator const & b) const	{return (_ptr != b._ptr);};
			bool operator>(vectorIterator const & b) const {return (_ptr > b._ptr);};
			bool operator<(vectorIterator const & b) const {return (_ptr < b._ptr);};
			bool operator>=(vectorIterator const & b) const {return (_ptr >= b._ptr);};
			bool operator<=(vectorIterator const & b) const {return (_ptr <= b._ptr);};
	};
}

#endif
