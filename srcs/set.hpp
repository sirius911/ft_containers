/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:12:44 by clorin            #+#    #+#             */
/*   Updated: 2021/11/22 18:49:38 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

#include "bidirectional_iterator.hpp"
#include "reverse_iterator.hpp"
#include "RBTree.hpp"
#include "pair.hpp"     //to selectKey()

#include <iostream>

namespace ft
{
    template <class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
    class set
    {
        public:

            typedef T                                       key_type;
            typedef T                                       value_type;
            typedef Compare                                 key_compare;
            typedef Alloc                                   allocator_type;
            typedef typename Alloc::reference               reference;
            typedef typename Alloc::const_reference         const_reference;
            typedef typename Alloc::pointer                 pointer;
            typedef typename Alloc::const_pointer           const_pointer;
            
            typedef Node<value_type>                        node_type;
            typedef node_type*                              node_ptr;

            typedef typename ft::bidirectional_iterator<const value_type, const node_type>  iterator;
            typedef typename ft::bidirectional_iterator<const value_type, const node_type>  const_iterator;
            typedef typename ft::reverse_iterator<iterator> 				                reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>			                const_reverse_iterator;

            typedef ft::RBTree<key_type, value_type, selectKey<value_type, key_type>, key_compare>  tree_type;

            /*********** constructors **************/
            //default
            set()
    };
} // ft
#endif