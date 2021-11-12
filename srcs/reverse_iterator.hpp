/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 09:00:31 by clorin            #+#    #+#             */
/*   Updated: 2021/11/12 11:25:16 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator.hpp"

namespace ft
{
	template <class Iterator>
	class	reverse_iterator
	{
		protected:
			Iterator	_ptr;

		public:

			typedef Iterator			                                    iterator_type;
            typedef typename iterator_traits<Iterator>::pointer             pointer;
            typedef typename iterator_traits<Iterator>::reference           reference;
            typedef typename iterator_traits<Iterator>::iterator_category   iterator_category;
            typedef typename iterator_traits<Iterator>::value_type          value_type;
            typedef typename iterator_traits<Iterator>::difference_type     difference_type;
            
			reverse_iterator(void) : _ptr() {}
            explicit reverse_iterator(Iterator it): _ptr(it) {}
            template <class U>
			reverse_iterator(reverse_iterator<U> const &other):_ptr(other.base()){};

            //operator reverse_iterator<Iterator const>() const{ return reverse_iterator<Iterator const>(_ptr);}


			virtual ~reverse_iterator(void){};
            template <class U>
			reverse_iterator &operator=(reverse_iterator<U> const &other)
			{
				_ptr = other.base();
				return (*this);
			}

            //getter
            iterator_type       base(void) const
            {
                return _ptr;
            }

            // Deferencement
			reference		operator*() const
            {
                Iterator tmp = _ptr;
                return (*--tmp);
            }
            // ->
			pointer				operator->() const
            {
                return &(this->operator*());
            }
			
            // operator[]
            reference		operator[](difference_type op) const
            {
                return base()[-op -1];
            }
			// const_reference	operator[](difference_type op) const	{return(_ptr[op]);};


			//increments
			reverse_iterator	&operator++(void){_ptr--; return(*this);};
			reverse_iterator	operator++(int)
            {
                reverse_iterator    old = *this;
                _ptr--;
                return(old);
            }
			reverse_iterator	&operator--(void){_ptr++; return(*this);};
			reverse_iterator 	operator--(int)
            {
                reverse_iterator    old = *this;
                _ptr++;
                return(old);
            }

			// +/-
			reverse_iterator	operator+(difference_type op) const {return(reverse_iterator<iterator_type>(_ptr - op));}
			reverse_iterator	operator-(difference_type op) const {return(reverse_iterator<iterator_type>(_ptr + op));}
            difference_type     operator+(const Iterator &src) const {return (_ptr - src._ptr);}
            difference_type     operator-(const Iterator &src) const {return (_ptr + src._ptr);}

			//+= -= operators
			reverse_iterator	&operator+=(difference_type op){_ptr -= op;return(*this);}
			reverse_iterator	&operator-=(difference_type op){_ptr += op;return(*this);}

			// ->
			//pointer				operator->() const		{return(&_ptr);}
			//const_pointer 		operator->() const	{return(&_ptr);};

            template <class Iterator1>
            friend difference_type operator-(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator1> &rhs);
            template< class Iterator1, class Iterator2>
            friend typename reverse_iterator<Iterator1>::difference_type operator-(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs);

            //forbiden
            //difference_type     substract(const reverse_iterator<Iterator> rhs)const {return (rhs.base() - _ptr);}
	};

    //Non member functions : comparaison operators overloads
    template <class Iterator>
        bool operator==(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) {return (lhs.base() == rhs.base());}
    template <class Iterator>
        bool operator!=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) {return (lhs.base() != rhs.base());}
    template <class Iterator>
        bool operator>(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) {return (lhs.base() < rhs.base());}
    template <class Iterator>
        bool operator>=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) {return (lhs.base() <= rhs.base());}
    template <class Iterator>
        bool operator<(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) {return (lhs.base() > rhs.base());}
    template <class Iterator>
        bool operator<=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) {return (lhs.base() >= rhs.base());}

    template <class Iterator1, class Iterator2>
        bool operator==(const reverse_iterator<Iterator1> & lhs, const reverse_iterator<Iterator2> & rhs){return (lhs.base() == rhs.base());}

    template <class Iterator1, class Iterator2>
    bool operator!=(const reverse_iterator<Iterator1> & lhs,
                    const reverse_iterator<Iterator2> & rhs)
    {
        return (lhs.base() != rhs.base());
    }

    template <class Iterator1, class Iterator2>
    bool operator<(const reverse_iterator<Iterator1> & lhs,
                    const reverse_iterator<Iterator2> & rhs)
    {
        return (lhs.base() > rhs.base());
    }

    template <class Iterator1, class Iterator2>
    bool operator<=(const reverse_iterator<Iterator1> & lhs,
                    const reverse_iterator<Iterator2> & rhs)
    {
        return (lhs.base() >= rhs.base());
    }

    template <class Iterator1, class Iterator2>
    bool operator>(const reverse_iterator<Iterator1> & lhs,
                    const reverse_iterator<Iterator2> & rhs)
    {
        return (lhs.base() < rhs.base());
    }

    template <class Iterator1, class Iterator2>
    bool operator>=(const reverse_iterator<Iterator1> & lhs,
                    const reverse_iterator<Iterator2> & rhs)
    {
        return (lhs.base() <= rhs.base());
    }
    /*                 +               */
    template <class Iterator>
    reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &rev_it)
    { return (rev_it + n);}

    template <class Iter1, class Iter2>
    reverse_iterator<Iter1> operator+(typename reverse_iterator<Iter1>::difference_type n, const reverse_iterator<Iter2> &rev_it)
    {return (rev_it + n);}

    /*                -                 */
    template <class Iterator>
    typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    { 
        return ((rhs._ptr - lhs._ptr));
        //return (lhs.operator-(rhs));
    //  return (lhs.substract(rhs));
    }
    
    template< class Iterator1, class Iterator2>
    typename reverse_iterator<Iterator1>::difference_type operator-( const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
    {
        // size_t  a = rhs._ptr;
        // size_t  b = lhs._ptr;
        return ((rhs._ptr - lhs._ptr));
        //return (lhs.operator-(rhs));
        //return (lhs.substract(rhs));
    }
}

#endif
