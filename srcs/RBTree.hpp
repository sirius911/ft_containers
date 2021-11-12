/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 12:47:56 by clorin            #+#    #+#             */
/*   Updated: 2021/11/12 17:05:41 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
# define RBTREE_HPP

#include <iostream>

namespace ft
{
    enum    Color   {BLACK, RED};

    template<class T>
    struct Node
    {
        T               data;
        struct Node    *parent;
        struct Node    *left;
        struct Node    *right;
        Color           color;

        Node (T data, Node* parent, Node *left, Node *right, Color color):data(data), parent(parent), left(left), right(right), color(color){}
    };

        template<class T, class Alloc = std::allocator<Node<T> > >
    class   RBTree
    {
        public:
            typedef T                   value_type;
            typedef Alloc               allocator_type;
            typedef Node<value_type>    node_type;
            typedef Node<value_type>*   node_ptr;
            typedef std::size_t         size_type;

        private:
            node_ptr        _root;
            node_ptr        _TNULL;
            size_type       _size;
            allocator_type  _alloc;


        public:
            //constructor
            RBTree(const allocator_type alloc = allocator_type()):_size(0),_alloc(alloc)
            {
                _TNULL = _alloc.allocate(1);
                _root = _TNULL;
                _alloc.construct(_TNULL, node_type(value_type(), nullptr, nullptr,nullptr, BLACK));
            }
            virtual ~RBTree(){
                //TODO
                }

            // node_ptr    getRoot(void) const{ return _root;}
            // size_type   getSize(void) const{ return _size;}
            
            // insert the key to the tree in its appropriate position
	        // and fix the tree
            void    insert(const value_type &data)
            {
                node_ptr    new_node;
                new_node = _alloc.allocate(1);
                _alloc.construct(new_node, node_type(data, nullptr, _TNULL,_TNULL,RED));
                node_ptr    y = nullptr;
                node_ptr    x = _root;
                while (x !=_TNULL)
                {
                    y = x;
                    if(new_node->data < x->data)
                        x = x->left;
                    else
                        x = x->right;
                }
                // y is parent of x
                new_node->parent = y;
                if(y == nullptr)
                    _root = new_node;
                else if(new_node->data < y->data)
                    y->left = new_node;
                else
                    y->right = new_node;
                
                //if new_node is a root node, simply return
                if(new_node->parent == nullptr)
                {
                    new_node->color = BLACK;
                    return;
                }

                //if the grandparent is null, simpli return
                if(new_node->parent->parent == nullptr)
                    return;
                
                //fix the tree
                
            }
        
    };
}

#endif