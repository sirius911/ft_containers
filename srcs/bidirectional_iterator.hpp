/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 08:12:02 by clorin            #+#    #+#             */
/*   Updated: 2021/11/19 12:15:19 by clorin           ###   ########.fr       */
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
            bidirectional_iterator(const bidirectional_iterator &cpy):_ptr(cpy._ptr), _root(cpy._root), _nill(cpy._nill){} //copy
            virtual ~bidirectional_iterator(){} //destructor

            bidirectional_iterator(node_ptr ptr, node_ptr root, node_ptr nill):_ptr(ptr), _root(root), _nill(nill){}
            
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

            /*      Access      */
            reference       operator*()      { return this->_ptr->data;}
            const_reference operator*() const { return _ptr->data;}

            pointer         operator->()       {return &(operator*());}
            const_pointer   operator->() const {return &(operator*());}

            /*increment */

            bidirectional_iterator  &operator++(void)
            {
                if (_ptr != _nill)
                _ptr = successor(_ptr);
                return *this;
            }
            bidirectional_iterator  operator++(int)
            {
                bidirectional_iterator  old(*this);
                this->operator++();
                return old;
            }

            /*  decrement   */
            bidirectional_iterator  &operator--(void)
            {
                if(_ptr == _nill)
                    _ptr = max(_root);
                else
                    _ptr = predecessor(_ptr);
                return *this;
            }

            bidirectional_iterator  operator--(int)
            {
                bidirectional_iterator  old(*this);
                this->operator--();
                return old;
;            }

            private:
                node_ptr    successor(node_ptr node)
                {
                    if(node->right != _nill)        // if there is a right children 
                        return min(node->right);    // the successor is the minimun of right childern
                    node_ptr    y = node->parent;
                    while(y != NULL && node == y->right)
                    {
                        node = y;
                        y = y->parent;
                    }
                    if (y == NULL)
                        return _nill;
                    return y;
                }

                node_ptr    predecessor(node_ptr node)
                {
                    if(node->left != _nill)         //if ther is a left children
                        return (max(node->left));   // predecessor is th maximun of left children
                    node_ptr    y = node->parent;
                    while(y != NULL && node == y->left)
                    {
                        node = y;
                        y = y->parent;
                    }
                    return y;
                }

                node_ptr    min(node_ptr node)
                {
                    while(node->left != _nill)
                        node = node->left;
                    return (node);
                }

                node_ptr    max(node_ptr node)
                {
                    while(node->right != _nill)
                        node = node->right;
                    return node;
                }
    };
}//ft
#endif