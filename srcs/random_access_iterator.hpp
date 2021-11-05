/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 07:54:07 by clorin            #+#    #+#             */
/*   Updated: 2021/10/28 07:55:00 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include "iterator.hpp"

namespace ft
{
	template <typename T>
	class	random_access_iterator : public iterator<ft::random_access_iterator_tag, T>
	{
		private:
			T*	_ptr;

		public:

			typedef T&			reference;
			typedef const T&	const_reference;
			typedef T*			pointer;
			typedef const T*	const_pointer;
			typedef ptrdiff_t	difference_type;


			random_access_iterator(void):_ptr(0) {};	//default constructor
			random_access_iterator(pointer ptr):_ptr(ptr){};
			random_access_iterator(random_access_iterator<T> const &cpy) // constructor by copy
			{
				if (this != &cpy)
					*this = cpy;
			};

			virtual ~random_access_iterator(void){};	// destructor
			random_access_iterator &operator=(random_access_iterator<T> const &cpy)
			{
				if(this != &cpy)
					_ptr = cpy._ptr;
				return (*this);
			}

			// getter
			pointer			base(void) const { return _ptr;};

			//increments
			random_access_iterator	&operator++(void){_ptr++; return(*this);};
			random_access_iterator	operator++(int)
			{
				random_access_iterator old = *this;
				_ptr++;
				return(old);
			};
			random_access_iterator	&operator--(void){_ptr--; return(*this);};
			random_access_iterator 	operator--(int)
			{
				random_access_iterator old = *this;
				_ptr--;
				return(old);
			};

			// +/-
			random_access_iterator	operator+(difference_type op)const{return(_ptr + op);};
			random_access_iterator	operator-(difference_type op)const{return(_ptr - op);};

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
	};
	//overload comparaison
	// same class
	template <class T>
	bool operator==(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template <class T>
	bool operator!=(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template <class T>
	bool operator<(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template <class T>
	bool operator>(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template <class T>
	bool operator>=(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
	{
		return (lhs.base() >= rhs.base());
	}
	
	template <class T>
	bool operator<=(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	//differents iterators
	template <typename T, typename U>
	bool operator==(const random_access_iterator<T> &lhs, const random_access_iterator<U> &rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template <typename T, typename U>
	bool operator!=(const random_access_iterator<T> &lhs, const random_access_iterator<U> &rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template <typename T, typename U>
	bool operator<(const random_access_iterator<T> &lhs, const random_access_iterator<U> &rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template <typename T, typename U>
	bool operator>(const random_access_iterator<T> &lhs, const random_access_iterator<U> &rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template <typename T, typename U>
	bool operator>=(const random_access_iterator<T> &lhs, const random_access_iterator<U> &rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template <typename T, typename U>
	bool operator<=(const random_access_iterator<T> &lhs, const random_access_iterator<U> &rhs)
	{
		return (lhs.base() <= rhs.base());
	}
}	//ft

#endif
