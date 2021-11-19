/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:20:17 by clorin            #+#    #+#             */
/*   Updated: 2021/11/19 08:44:26 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include "bidirectional_iterator.hpp"
#include "reverse_iterator.hpp"
#include "pair.hpp"
#include "RBTree.hpp"
#include <iostream>


namespace ft
{
    template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key, T> > >
    class   map
    {
        public:
            //types
            typedef Key                                                     key_type;
            typedef T                                                       mapped_type;
            typedef pair<const key_type, mapped_type>                       value_type;
            typedef Compare                                                 key_compare;
            typedef Alloc                                                   allocator_type;
            typedef typename Alloc::reference                               reference;
            typedef typename Alloc::const_reference                         const_reference;
            typedef typename Alloc::pointer                                 pointer;
            typedef typename Alloc::const_pointer                           const_pointer;
            typedef Node<value_type>                                        node_type;
            typedef typename ft::bidirectional_iterator<T, node_type>		      iterator;
			typedef typename ft::bidirectional_iterator<const T, const node_type> const_iterator;
            typedef typename ft::reverse_iterator<iterator> 				reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
			typedef typename std::size_t									size_type;

            typedef ft::RBTree<key_type, value_type,ft::selectFirst<value_type, key_type> > tree_type;

        private:
            allocator_type      _alloc;
            key_compare         _comp;
            tree_type           _tree;
            
    };

} // namespace ft

#endif

