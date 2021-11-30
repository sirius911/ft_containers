/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 07:54:07 by clorin            #+#    #+#             */
/*   Updated: 2021/11/30 11:07:41 by clorin           ###   ########.fr       */
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

			typedef T										value_type;
			typedef T&										reference;
			typedef T*										pointer;
			typedef const T&								const_reference;
			typedef const T*								const_pointer;
			typedef std::ptrdiff_t							difference_type;
			typedef std::size_t								size_type;
			typedef typename ft::random_access_iterator_tag	iterator_category;


			random_access_iterator(void):_ptr(0) {};	//default constructor
			random_access_iterator(pointer ptr):_ptr(ptr){};
			random_access_iterator(random_access_iterator<T> const &cpy): _ptr(cpy._ptr) {}
			virtual ~random_access_iterator(void){};	// destructor
			random_access_iterator &operator=(random_access_iterator<T> const &cpy)
			{
				if(this != &cpy)
					_ptr = cpy._ptr;
				return (*this);
			}

			//if trying to copy a const_iterator based on a iterator
			operator random_access_iterator<T const>() const{ return random_access_iterator<T const>(_ptr);}

			// getter
			pointer			base(void) const { return _ptr;};

			// relational operator
			bool operator==(const random_access_iterator &src) const {return _ptr == src._ptr;}
			bool operator!=(const random_access_iterator &src) const {return _ptr != src._ptr;}
			bool operator>(const random_access_iterator &src) const {return _ptr > src._ptr;}
			bool operator>=(const random_access_iterator &src) const {return _ptr >= src._ptr;}
			bool operator<(const random_access_iterator &src) const {return _ptr < src._ptr;}
			bool operator<=(const random_access_iterator &src) const {return _ptr <= src._ptr;}

			//relational operator between const and non const iterator
			// must be friend to access protected _ptr in non membre functions
			template <class Ite1, class Ite2>
				friend bool operator==(const random_access_iterator<Ite1> &lhs,const random_access_iterator<Ite2> &rhs);
			template <class Ite1, class Ite2>
				friend bool operator!=(const random_access_iterator<Ite1> &lhs,const random_access_iterator<Ite2> &rhs);
			template <class Ite1, class Ite2>
				friend bool operator>(const random_access_iterator<Ite1> &lhs,const random_access_iterator<Ite2> &rhs);
			template <class Ite1, class Ite2>
				friend bool operator>=(const random_access_iterator<Ite1> &lhs,const random_access_iterator<Ite2> &rhs);
			template <class Ite1, class Ite2>
				friend bool operator<(const random_access_iterator<Ite1> &lhs,const random_access_iterator<Ite2> &rhs);
			template <class Ite1, class Ite2>
				friend bool operator<=(const random_access_iterator<Ite1> &lhs,const random_access_iterator<Ite2> &rhs);

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
			random_access_iterator	operator+(difference_type op)const{return(random_access_iterator<T>(_ptr + op));};
			random_access_iterator	operator-(difference_type op)const{return(random_access_iterator<T>(_ptr - op));};
			difference_type			operator-(random_access_iterator const &src) const {return _ptr - src._ptr;};

			//+= -= operators
			random_access_iterator	&operator+=(difference_type op){_ptr += op; return *this;};
			random_access_iterator	&operator-=(difference_type op){_ptr -= op; return *this;};

			// access
			pointer			operator->()							{return(_ptr);};
			reference		operator*() 							{return (*_ptr);};
			reference	 	operator[](difference_type op) const	{return(_ptr[op]);};
	};
	
	//overload operators
	template <class T>
		ft::random_access_iterator<T> operator+(typename ft::random_access_iterator<T>::difference_type n, ft::random_access_iterator<T> const & rhs)
		{ return rhs + n;};

	template <typename T, typename U>
	ptrdiff_t	operator-(const random_access_iterator<T> &lhs, const random_access_iterator<U> &rhs)
	{
		return (lhs.base() - rhs.base());
	}

	//differents iterators
	template <typename Ite1, typename Ite2>
	bool operator==(const random_access_iterator<Ite1> &lhs, const random_access_iterator<Ite2> &rhs)
	{
		return (lhs._ptr == rhs._ptr);
	}

	template <typename Ite1, typename Ite2>
	bool operator!=(const random_access_iterator<Ite1> &lhs, const random_access_iterator<Ite2> &rhs)
	{
		return (lhs._ptr != rhs._ptr);
	}

	template <typename Ite1, typename Ite2>
	bool operator<(const random_access_iterator<Ite1> &lhs, const random_access_iterator<Ite2> &rhs)
	{
		return (lhs._ptr < rhs._ptr);
	}

	template <typename Ite1, typename Ite2>
	bool operator>(const random_access_iterator<Ite1> &lhs, const random_access_iterator<Ite2> &rhs)
	{
		return (lhs._ptr > rhs._ptr);
	}

	template <typename Ite1, typename Ite2>
	bool operator>=(const random_access_iterator<Ite1> &lhs, const random_access_iterator<Ite2> &rhs)
	{
		return (lhs._ptr >= rhs._ptr);
	}

	template <typename Ite1, typename Ite2>
	bool operator<=(const random_access_iterator<Ite1> &lhs, const random_access_iterator<Ite2> &rhs)
	{
		return (lhs._ptr <= rhs._ptr);
	}
}	//ft

#endif
