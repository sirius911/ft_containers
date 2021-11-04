/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 09:00:31 by clorin            #+#    #+#             */
/*   Updated: 2021/11/03 09:01:18 by clorin           ###   ########.fr       */
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
			reverse_iterator	operator+(difference_type op){return(reverse_iterator(base() - op));}
			reverse_iterator	operator-(difference_type op){return(reverse_iterator(_ptr + op));}

			//+= -= operators
			reverse_iterator	&operator+=(difference_type op){_ptr -= op;return(*this);}
			reverse_iterator	&operator-=(difference_type op){_ptr += op;return(*this);}

			// ->
			//pointer				operator->() const		{return(&_ptr);}
			//const_pointer 		operator->() const	{return(&_ptr);};

			
			//const_reference operator*() const 	{return (_ptr);};

			// reference		operator[](difference_type op)			{return(_ptr[op]);};
			// const_reference	operator[](difference_type op) const	{return(_ptr[op]);};

			//boolean
			
			bool operator>(reverse_iterator const & b) const {return (_ptr > b._ptr);};
			bool operator<(reverse_iterator const & b) const {return (_ptr < b._ptr);};
			bool operator>=(reverse_iterator const & b) const {return (_ptr >= b._ptr);};
			bool operator<=(reverse_iterator const & b) const {return (_ptr <= b._ptr);};
	};

    //Non member functions : comparaison operators overloads

    template <class Iterator1, class Iterator2>
    bool operator==(const reverse_iterator<Iterator1> & lhs,
                    const reverse_iterator<Iterator2> & rhs)
    {
        return (lhs.base() == rhs.base());
    }

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
			
    template <class It>
    reverse_iterator<It> operator+(typename reverse_iterator<It>::difference_type op,
                                    const reverse_iterator<It> &it)
    {
        return reverse_iterator<It>(it.base - op);
    }

    template< class Iterator1, class Iterator2>
    typename reverse_iterator<Iterator1>::difference_type
    operator-( const reverse_iterator<Iterator1> &lhs,
               const reverse_iterator<Iterator2> &rhs)
    {
        return (rhs.base() - lhs.base());
    }
}

#endif
