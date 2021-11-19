/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:20:17 by clorin            #+#    #+#             */
/*   Updated: 2021/11/19 19:03:20 by clorin           ###   ########.fr       */
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
            //empty (1)
            explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()):
            _alloc(alloc), _comp(comp), _tree() {}

            

            //copy(3)
            map(const map &cpy)
            {
                insert(cpy.begin(), cpy.end());
            }

            virtual ~map(){}

            map &operator=(const map &cpy)
            {
                    (void)cpy;
            }

            /*    ***************************  Iterators  ************************     
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

            reverse_iterator        rbegin()        {return(reverse_iterator(end()));}
            const_reverse_iterator  rbegin() const  {return (const_reverse_iterator(end()));}

            reverse_iterator        rend()          {return(reverse_iterator(begin()));}
            const_reverse_iterator  rend() const    {return(const_reverse_iterator(begin()));}

            /*  ********************** Capacity ***********************/
            
            bool            empty() const       {return (_tree.getSize() == 0);}
            size_type       size() const        {return _tree.getSize();}
            size_type       max_size() const    {return _tree.max_size();}

            /*  ********************* Element Access ******************/

            mapped_type    &operator[] (const key_type &k)
            {
                _tree.insert(value_type(k, mapped_type()));
                node_ptr    node = _tree.search(k);
                return (node->data.second);
            }


            /*  *********************    Modifiers   ***************** */
            ft::pair<iterator,bool>    insert(const value_type &val)
            {
                bool    succes = _tree.insert(val);
                iterator    it = find(val.first);
                return (ft::pair<iterator, bool>(it, succes));
            }
            iterator                    insert(iterator, const value_type &val)
            {
               return insert(val).first;
            }

            template <class InputIterator>
            void                        insert(InputIterator first, InputIterator last)
            {
                while(first != last)
                    _tree.insert(*(first++));
            }

            void                        erase(iterator position)
            {
                erase((*position).first);
            }

            size_type                   erase(const key_type &k)
            {
               if(_tree.deleteNode(k))
                    return 1;
                else return 0;       
            }

            void                        erase(iterator first, iterator last)
            {
                while(first != last)
                    erase(first++);
            }

            void                        clear()
            {
                erase(begin(), end());
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

