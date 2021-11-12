/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:20:17 by clorin            #+#    #+#             */
/*   Updated: 2021/11/12 16:55:32 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include "random_access_iterator.hpp";
#include "pair.hpp"
#include <iostream>


namespace ft
{
    template <class Key, class T, class Compare = less<Key>, class Alloc = std::allocator<pair<const Key, T> > >
    class   map
    {
        public:
            //types
            typedef Key                                             key_type;
            typedef T                                               mapped_type;
            typedef pair<const Key, T>                              value_type;
            typedef Compare                                         key_compare;
            typedef Alloc                                           allocator_type;
            typedef typename Alloc::reference                       reference;
            typedef typename Alloc::const_reference                 const_reference;
            typedef typename ft::random_access_iterator<T>		    iterator;
			typedef typename ft::random_access_iterator<const T>    const_iterator;
            typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
			typedef typename std::size_t									size_type;

            
    };

} // namespace ft

#endif

