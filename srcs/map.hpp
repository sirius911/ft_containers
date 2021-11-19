/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:20:17 by clorin            #+#    #+#             */
/*   Updated: 2021/11/19 11:41:40 by clorin           ###   ########.fr       */
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
            typedef node_type*                                                             node_ptr;
            typedef typename ft::bidirectional_iterator<value_type, node_type>		       iterator;
			typedef typename ft::bidirectional_iterator<const value_type, const node_type> const_iterator;
            typedef typename ft::reverse_iterator<iterator> 				               reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>			               const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type	               difference_type;
			typedef typename std::size_t									               size_type;

            typedef ft::RBTree<key_type, value_type,ft::selectFirst<value_type, key_type> > tree_type;

        private:
            allocator_type      _alloc;
            key_compare         _comp;
            tree_type           _tree;

        public:
            explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()):
            _alloc(alloc), _comp(comp), _tree() {}

            map(const map &cpy):_alloc(cpy._alloc), _comp(cpy._comp), _tree(cpy._tree){} // copy
            virtual ~map(){}

            map &operator=(const map &cpy)
            {
                    
            }

            /*      Iterators       
            *       iterator(_ptr, _root, _nill)
            */

            iterator        begin()
            {
                // return first element so the min key value
                return (iterator(_tree.min(),_tree.getRoot(), _tree.getNill()));
            }

            const_iterator  begin() const
            {
                return (const_iterator(_tree.min(), _tree.getRoot(), _tree.getNill()));
            }
            
            iterator        end()
            {
                return (iterator(_tree.getNill(), _tree.getRoot(), _tree.getNill()));
            }

            const_iterator  end() const
            {
                return (const_iterator(_tree.getNill(), _tree.getRoot(), _tree.getNill()));
            }

            /*      Modifiers    */
            ft::pair<iterator,bool>    insert(const value_type &val)
            {
                bool    succes = _tree.insert(val);
                iterator    it = find(val.first);
                return (ft::pair<iterator, bool>(it, succes));
            }

            /*      operations      */
            iterator        find(const key_type &k)
            {
                node_ptr  node  = _tree.search(k);
                if (node == _tree.getNill())
                    return (end());
                return (iterator(node, _tree.getRoot(), _tree.getNill()));
            }
            const_iterator  find(const key_type &k) const
            {
                node_ptr  node  = _tree.search(k);
                if (node == _tree.getNill())
                    return (end());
                return (const_iterator(node, _tree.getRoot(), _tree.getNill()));
            }
            
    };

} // namespace ft

#endif

