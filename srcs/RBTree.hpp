/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 12:47:56 by clorin            #+#    #+#             */
/*   Updated: 2021/11/17 08:55:57 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
# define RBTREE_HPP

#include <iostream>
#include <math.h>
#include "utils/utils.hpp"
#include "visual_tree.hpp"

#include <list>

# define C_GREEN 	"\e[32m"
# define C_RED		"\e[31m"
# define C_YELLOW	"\e[33m"
# define C_CYAN		"\e[34m"
# define C_BLACK    "\e[30m\e[47m"
# define C_RESET	"\e[0m"
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

        template<class Key, class Value, class KeyOfValue, class Compare = std::less<Key>, class Alloc = std::allocator<Node<Value> > >
    class   RBTree
    {
        public:
            typedef Value               value_type;
            typedef Key                 key_type;
            typedef Alloc               allocator_type;
            typedef Compare             value_compare;
            typedef Node<value_type>    node_type;
            typedef Node<value_type>*   node_ptr;
            typedef std::size_t         size_type;

        private:
            node_ptr            _root;
            node_ptr            _TNULL;
            value_compare       _comp;
            size_type           _size;
            allocator_type      _alloc;


        public:
            //constructor
            RBTree(const value_compare &comp = value_compare(), const allocator_type alloc = allocator_type()):_size(0),_alloc(alloc)
            {
                _TNULL = _alloc.allocate(1);
                _root = _TNULL;
                _alloc.construct(_TNULL, node_type(value_type(), nullptr, nullptr,nullptr, BLACK));
            }
            virtual     ~RBTree()
            {
                clear_recusive(_root);
                _root = _TNULL;
                _alloc.destroy(_TNULL);
                _alloc.deallocate(_TNULL, 1);
            }

            node_ptr    getRoot(void) const{ return _root;}
            size_type   getSize(void) const{ return _size;}
            node_ptr    getNill(void) const{ return _TNULL;}
            size_type   max_size(void) const {return _alloc.max_size();}

            /*              Min and Max
            *   The minimum value of Value is the leftmost node
            *   The maximun value of Value is the right most node */

            node_ptr    min(void) const
            {
                return min(_root);
            }
            
            node_ptr    min(node_ptr node) const
            {
                if(node == _TNULL)
                    return _root;
                while(node->left != _TNULL)
                    node = node->left;
                return node;
            }

            node_ptr    max(void) const
            {
                return max(_root);
            }

            node_ptr    max(node_ptr node) const
            {
                if(node == _TNULL)
                    return _root;
                while(node->right != _TNULL)
                    node = node->right;
                return node;
            }

            
            // insert the key to the tree in its appropriate position
	        // and fix the tree
            bool        insert(const value_type &data)
            {
                node_ptr    new_node;
                new_node = _alloc.allocate(1);
                _alloc.construct(new_node, node_type(data, nullptr, _TNULL,_TNULL,RED));
                node_ptr    y = nullptr;
                node_ptr    x = _root;
                while (x !=_TNULL)
                {
                    y = x;
                    /*compare with function compar in KeyOfValue of Data */
                    if(_comp(KeyOfValue()(new_node->data), KeyOfValue()(x->data)))
                        x = x->left;    // the new_node have to be on left tree
                    else if(_comp(KeyOfValue()(x->data), KeyOfValue()(new_node->data)))
                        x = x->right;   //the new_code hqve to be right tree
                    else
                    {
                        // no equal key
                        _alloc.destroy(new_node);
                        _alloc.deallocate(new_node, 1);
                        return false;
                    }
                }
                // y is parent of x is a free place
                new_node->parent = y;
                if(y == nullptr)
                    _root = new_node;   //first Node
                else if(_comp(KeyOfValue()(new_node->data), KeyOfValue()(y->data)))
                    y->left = new_node;
                else
                    y->right = new_node;
                _size++;
                //if new_node is a root node, color = BLACK & simply return 
                if(new_node->parent == nullptr)
                {
                    new_node->color = BLACK;
                    return true;
                }

                //if the grandparent is null, OK return
                if(new_node->parent->parent == nullptr)
                    return true;
                //if Parent is black nothing to do
                if(new_node->parent->color == BLACK)
                    return true;
                //balance of tree
                balance(new_node);
                return true;
            }

            value_type  &get_data(node_ptr node = nullptr) const
            {
                if(node == nullptr)
                    node = _root;
                return (node->data);
            }

            int         height(node_ptr node = nullptr) const
            {
                if(node == nullptr)
                    node = _root;
                int hl = 0,hr = 0,h = 0 ;
                if( node == nullptr || node == _TNULL)
                    h = 0;
                else
                {
                    hl = height(node->left);
                    hr = height(node->right);

                	h = (hl > hr ? hl:hr) + 1;
                }
                return h;
            }

            void        print(bool const memory = false) const
            {
                print(memory, _root, "", true);
            }

            bool        deleteNode(const key_type &key)
            {
                return(_deleteNode(key));
            }

            node_ptr    search(const key_type &key) const
            {
                return  search(_root, key);
            }

            static int  max_depth(node_ptr n)
            {
                if (!n) return 0;
                return 1 + std::max(max_depth(n->left), max_depth(n->right));
            }
       
        private:

            node_ptr    search(node_ptr node, const key_type &key) const
            {
                if (node == _TNULL)
                    return _TNULL;
                if (key == KeyOfValue()(node->data))
                    return node;
                if (_comp(key, KeyOfValue()(node->data)))
                    return (search(node->left, key));
                else
                    return (search(node->right, key));
            }

            void    left_rotation(node_ptr  x)
            {
                node_ptr y = x->right; // get y (x right child)

				x->right = y->left; // y old left child is now x new right child
				if (y->left != _TNULL)
					y->left->parent = x;
				y->parent = x->parent; // x old parent is now y new parent
				if (x->parent == nullptr)
					this->_root = y;
                else if (is_left(x))    // x on left or right ?
					x->parent->left = y; 
				else
					x->parent->right = y;
				y->left = x; // x become y left child
				x->parent = y;
            }
            
            void    right_rotation(node_ptr x)
            {
                node_ptr y = x->left;   // y is the left child of x

                x->left = y->right;     // y old right child is now x new left child
                if (y->right != _TNULL)
                    y->right->parent = x;
                y->parent = x->parent;  // x old parent is now y new parent;
                if (x->parent == nullptr)
                    this->_root = y;
                else if (is_right(x))  //x on left or right ?
                    x->parent->right = y;
                else
                    x->parent->left = y;
                y->right = x;
                x->parent = y;
            }

            void    balance_delete(node_ptr node)
            {
                
            }

            void    balance(node_ptr new_node)
            {
                while(new_node->parent->color == RED)
                {
                    //parent is RED
                    if (new_node == _root)
                        break;
                    //check color of uncle
                    node_ptr    u;
                    u = uncle(new_node);
                    if(u->color == RED)
                    {
                        // uncle is RED
                        // Grand parent become red, uncle become black, Parent become black
                        new_node->parent->parent->color = RED;
                        u->color = BLACK;
                        new_node->parent->color = BLACK;
                        new_node = new_node->parent->parent;    // we check the grand_parent
                    }
                    else
                    {
                        //uncle is BLACK
                        if (is_right(new_node->parent))
                        {
                            //parent is on right of grand-parent
                            if(is_left(new_node))
                            {
                                // newNode is a left child
                                new_node = new_node->parent;
                                right_rotation(new_node);
                            }
                            new_node->parent->color = BLACK;
						    new_node->parent->parent->color = RED;
                            left_rotation(new_node->parent->parent);
                        }
                        else if (is_left(new_node->parent))
                        {
                            //parent is on left side of grand-parent
                            if (is_right(new_node))
                            {
                                //new_node is a right child
                                new_node = new_node->parent;
                                left_rotation(new_node);
                            }
                            new_node->parent->color = BLACK;
                            new_node->parent->parent->color = RED;
                            right_rotation(new_node->parent->parent);
                        }
                    }
                    if(new_node == _root)
                        break;
                }
                _root->color = BLACK;
            }

            static node_ptr uncle(node_ptr node)
            {
                node_ptr    p = node->parent;
                if (p->parent == nullptr)   //no grand-parent
                    return (nullptr);       // no uncle
                return (brother(p));
            }

            static node_ptr brother(node_ptr node)
            {
                node_ptr    p = node->parent;
                if (p == nullptr)
                    return nullptr;
                if (node == p->left)
                    return p->right;
                else
                    return p->left;
            }

            static bool    is_left(node_ptr node)
            {
                return (node == node->parent->left);
            }
            static bool    is_right(node_ptr node)
            {
                return (node == node->parent->right);
            }

            /*clear*/
            void        clear_recusive(node_ptr const &node)
            {
                if (node == _TNULL)
                    return;         //stop of recursive
                clear_recusive(node->left);
                clear_recusive(node->right);

                _alloc.destroy(node);
                _alloc.deallocate(node, 1);
                _size--;
            }

            void        replace(node_ptr a, node_ptr b) //replace a with b
            {
                if(a->parent == nullptr)
                    _root = b;
                else if(is_left(a))
                    a->parent->left = b;
                else
                    a->parent->right = b;
                b->parent = a->parent;
            }

            bool        _deleteNode(const key_type &key)
            {
                node_ptr _to_del, _to_control, _tmp;
                Color   saved_color;
                
                _to_del = search(key);
                if (_to_del == _TNULL)
                    return false;
                //std::cout << "Node to destroy = " << &_to_del;
                saved_color = _to_del->color;
                if(_to_del->left == _TNULL)
                {
                    // Only a right children
                    //std::cout << " with only a right children :";
                    _to_control = _to_del->right;
                    // std::cout << " replace ";
                    // if(_to_del->right == _TNULL)
                    //     std::cout << "with _nill\n";
                    // else
                    //     std::cout << "with " << &(_to_del->right)<<std::endl;
                    replace(_to_del, _to_del->right);
                }
                else if(_to_del->right == _TNULL)
                {
                    // only a left children
                    _to_control = _to_del->left;
                    //  std::cout << " with only a left children :";
                    //  std::cout << " replace ";
                    // if(_to_del->left == _TNULL)
                    //     std::cout << "with _nill\n";
                    // else
                    //     std::cout << "with " << &(_to_del->left)<<std::endl;
                    replace(_to_del, _to_del->left);
                }
                else
                {
                    // 2 childrens
                    //is replaced by the minimum of it's right branch
                    //std::cout << " with 2 childrens \n\t";
                    _tmp = min(_to_del->right); //search for the minimum in the right child's branch
                    saved_color = _tmp->color;
                    _to_control = _tmp->right;  // to control right branch
                    if (_tmp->parent == _to_del)//the minimum is 
                        _to_control->parent = _tmp;
                    else
                    {
                        replace(_tmp, _tmp->right);
                        _tmp->right = _to_del->right; //
                        _tmp->right->parent = _tmp;
                    }
                    replace(_to_del, _tmp);
                    _tmp->left = _to_del->left; // to verif if the replace OK
                    _tmp->left->parent = _tmp;
                    _tmp->color = _to_del->color;
                }
                _alloc.destroy(_to_del);
                _alloc.deallocate(_to_del, 1);
                _size--;
                if(saved_color == BLACK)
                    balance_delete(_to_control);
                return true;
            }

            void print(bool memory, node_ptr root, std::string indent="", bool last=true) const
			{
                typedef ft::selectSecond<Value, int>  get_data; 
				if (root != _TNULL)
				{
					std::cout << indent;
					if (last)
					{
						std::cout << "R----";
						indent += "     ";
					}
					else
					{
						std::cout << "L----";
						indent += "|    ";
					}
					std::string sColor = root->color? C_RED:C_BLACK;
					std::cout << sColor << get_data()(root->data) << C_RESET;
                    if(memory)
                        std::cout << " " <<&root;
                    std::cout << std::endl;
					print(memory, root->left, indent, false);
					print(memory, root->right, indent, true);
				}
			}
    };
}

#endif