/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 08:12:02 by clorin            #+#    #+#             */
/*   Updated: 2021/11/19 09:18:11 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP

# include "iterator.hpp"
# include "RBTree.hpp"

namespace ft
{
    template <typename T, class N>
	class	bidirectional_iterator : public iterator<ft::bidirectional_iterator_tag, T>
	{

        public:

			typedef T				                        value_type;
			typedef T&				                        reference;
			typedef T*				                        pointer;
			typedef const T&		                        const_reference;
			typedef const T*		                        const_pointer;
			typedef std::ptrdiff_t	                        difference_type;
			typedef std::size_t		                        size_type;
            typedef typename ft::bidirectional_iterator_tag iterator_category;

            typedef N                                       node_type;
            typedef N*                                      node_ptr;

        private:
            node_ptr    _ptr;
            node_ptr    _root;
            node_ptr    _nill;

        public:
            //constructors
            bidirectional_iterator():_ptr(nullptr), _root(nullptr), _nill(nullptr){}    //default
            bidirectional_iterator(node_ptr ptr, node_ptr root, node_ptr nill):_ptr(ptr), _root(root), _nill(nill){}
            bidirectional_iterator(const bidirectional_iterator &cpy):_ptr(cpy._ptr), _root(cpy._root), _nill(cpy._nill){} //copy
            virtual ~bidirectional_iterator(){} //destructor

            bidirectional_iterator &operator=(bidirectional_iterator const &cpy)
            {
                if (this !=&cpy)
                {
                    _ptr = cpy._ptr;
                    _root = cpy._root;
                    _nill = cpy._nill;
                }
                return *this;
            }
    };
}//ft
#endif