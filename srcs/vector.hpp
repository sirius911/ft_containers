/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:22:16 by clorin            #+#    #+#             */
/*   Updated: 2021/11/25 13:58:08 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>

# include "random_access_iterator.hpp"
# include "reverse_iterator.hpp"
# include "utils/utils.hpp"
# include "utils/algorithmes.hpp"
# include "utils/is_integral.hpp"

namespace ft
{
	template<class T, class Allocator = std::allocator<T> >
	class vector
	{
		public:
			typedef T														value_type;
			typedef Allocator												allocator_type;
			typedef typename allocator_type::reference						reference;
			typedef typename allocator_type::const_reference				const_reference;
			typedef typename allocator_type::pointer						pointer;
			typedef typename allocator_type::const_pointer					const_pointer;
			typedef typename ft::random_access_iterator<T>					iterator;
			typedef typename ft::random_access_iterator<const T>			const_iterator;
			//typedef typename ft::random_access_const_iterator<T>			const_iterator;
			typedef typename ft::reverse_iterator<iterator> 				reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
			typedef typename std::size_t									size_type;	


			//default (1)
			explicit vector(const Allocator & alloc = Allocator())
			:_alloc(alloc), _ptr(0), _capacity(0), _size_container(0){};

			/**
			 *  @brief Construct a new vector object (fill2)
			 * 	with n elements. Each element is a copy of val.
			 * 
			 * @param n Initial container size
			 * @param val Value to fill the container with. Each element will be initialized to a copy of the value
			 * @param alloc Allocator object
			 * */
			explicit vector(size_t n, const T & val = T(), const Allocator & alloc = Allocator())
			: _alloc(alloc), _ptr(0), _capacity(n), _size_container(n)
			{
				_ptr = _alloc.allocate(n);
				for(size_t i = 0; i < n; i++)
					_alloc.construct(_ptr + i, val);
			};

			//construct range(3)
			template <class InputIterator>
			explicit vector(InputIterator first, InputIterator last,
					const Allocator & alloc = Allocator(), 
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = ft_nullptr_t)
					: _alloc(alloc), _size_container(0)
					{
						difference_type n = ft::distance(first, last);
                		_ptr  = _alloc.allocate(n);
						_capacity = n;
						for(;first != last;first++)
							this->push_back(*first);
					}

			//copy(4)
			explicit vector (vector<T, Allocator> const &copy)
			: _alloc(copy.get_allocator()), _capacity(copy._capacity), _size_container(0)
			{
				_ptr = _alloc.allocate(_capacity);
				for (const_iterator it = copy.begin(); it != copy.end(); it++)
					this->push_back(*it);
			};

			vector &operator=(vector const & copy)
			{
				size_type old_capacity = _capacity;
				if(*this != copy)
				{
					assign(copy.begin(), copy.end());
					if(_capacity < old_capacity)
					{
						this->reserve(old_capacity);
					}
				}
				return(*this);
			};

			virtual ~vector(void)
			{
				this->clear();
				if(_capacity > 0)
					_alloc.deallocate(_ptr, _capacity);
			};

			// assign (fill)
			void	assign(size_t n, const value_type &val)
			{
				this->clear();
				if (n == 0)
					return;
				_size_container = 0;
				if (n > _capacity)
				{
					_alloc.deallocate(_ptr, _capacity);
					_ptr = _alloc.allocate(n);
					_capacity = n;
				}
				while(_size_container < n)
				{
					_alloc.construct(_ptr + _size_container, val);
					_size_container++;
				}
			}

			/**
             * @brief Assigns new contents to the vector, replacing its current contents,
             * and modifying its size accordingly. Any elements held in the container before
             * the call are destroyed and replaced by newly constructed elements (no assignments of elements take place).
             * The new contents are elements constructed from each of the elements in the range between first and last, in the same order.
             *
             * @tparam InputIterator
             * @param first the first element in the range.
             * @param last the last element in the range.
             */
			template <class InputIterator>
			void	assign(InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = ft_nullptr_t)
			{
				this->clear();
				if(_capacity > 0)
					_alloc.deallocate(_ptr, _capacity);
				difference_type n = ft::distance(first, last);
                _ptr  = _alloc.allocate(n);
				_capacity = n;
				for(;first != last;first++)
					this->push_back(*first);
			}
			
			//modifiers
			void	push_back(const T & value)
			{
				if(_size_container == _capacity)
				{
					size_t	new_capacity = (_size_container > 0)? _size_container * 2 : 1;
					this->reserve(new_capacity);
				}
				_alloc.construct(_ptr + _size_container, value);
				_size_container++;
			};

			//insert single element(1)
			iterator	insert(iterator position, const value_type &val)
			{
				//std::cout<<"insert(element)\n";
				difference_type index = position - begin();
				insert(position, 1, val);
				return begin() + index;
			}
			
			//insert fill(2)
			void		insert(iterator position, size_t n, const value_type &val)
			{
				//std::cout << "insert(fill)\n";
				difference_type index = position - begin();
				if(n + _size_container > _capacity)
				{
					// resize
					size_type new_capacity = (_size_container > 0)? (_size_container + n) * 2: n*2;
					if (new_capacity > this->max_size())
							throw (std::length_error("vector::reserve"));
					else
					{
						value_type	*prev_ptr = _ptr;
						size_type	prev_size = _size_container;
						size_type	prev_capacity = _capacity;
						_ptr = _alloc.allocate(new_capacity);
						_capacity = new_capacity;
						difference_type i = 0;
						for(; i < index; i++)
							_alloc.construct(_ptr + i, *(prev_ptr + i));
						size_type z = i;
						for(size_type j = 0; j < n; j++)
						{
							_alloc.construct(_ptr + i, val);
							i++;
						}
						//std::cout << "de z = " << z << " a prev_size = " << prev_size << std::endl;
						for(;z < prev_size; z++)
						{
							//std::cout << *(prev_ptr + z)<< " -> _ptr+"<<i<<std::endl;
							_alloc.construct(_ptr+i, *(prev_ptr + z));
							i++;
						}
						_alloc.deallocate(prev_ptr, prev_capacity);
						_size_container += n;
					}
				}
				else
				{
					if(position == end())
					{
						//std::cout << "at the end !!\n";
						for (size_t i = 0; i < n; i++)
							push_back(val);
					}
					else
					{
						difference_type i = index;
						difference_type ending = _size_container - 1;
					
						//std::cout << "at " << index << " ending = "<< ending <<std::endl;
						
						while(ending > index)
						{
							//std::cout<<"cpy " <<*(_ptr+ending)<< " at " << &(*(_ptr + ending + n)) << std::endl;
							_alloc.construct(_ptr + ending + n, *(_ptr + ending));
							ending--;
						}
						//std::cout<<"cpy " <<*(_ptr+ending)<< " at " << &(*(_ptr + ending + n)) << std::endl;
						_alloc.construct(_ptr + ending + n, *(_ptr + ending));
						i = index;
						for (size_t z = 0; z < n; z++)
						{
							//std::cout<<"cpy "<< val << " at " << &(*(_ptr+i))<<std::endl;
							_alloc.construct(_ptr + i, val);
							i++;	
						}
						_size_container += n;
					}
				}	
			}

			//insert range (3)
			template<class InputIterator>
			void		insert(iterator position, InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = ft_nullptr_t) 
			{
				//std::cout<<"insert(range)\n";
				size_type n = ft::distance(first, last);
				difference_type index = position - begin();
				//std::cout << "n = "<<n << " index = "<<index<<std::endl;
				if(n + _size_container > _capacity)
				{
					// resize
					size_t new_capacity = (_size_container > 0)? (_size_container + n) * 2: n*2;
					if (new_capacity > this->max_size())
							throw (std::length_error("vector::reserve"));
					else
					{
						value_type	*prev_ptr = _ptr;
						std::size_t	prev_size = _size_container;
						std::size_t	prev_capacity = _capacity;
						_ptr = _alloc.allocate(new_capacity);
						_capacity = new_capacity;
						difference_type i = 0;
						for(; i < index; i++)
							_alloc.construct(_ptr + i, *(prev_ptr + i));
						size_type z = i;
						for(;first != last;first++)
						{
							_alloc.construct(_ptr + (i++),*first);
						}
						//std::cout << "de z = " << z << " a prev_size = " << prev_size << std::endl;
						for(;z < prev_size; z++)
						{
							//std::cout << *(prev_ptr + z)<< " -> _ptr+"<<i<<std::endl;
							_alloc.construct(_ptr+i, *(prev_ptr + z));
							i++;
						}
						_alloc.deallocate(prev_ptr, prev_capacity);
						_size_container += n;
					}
				}
				else
				{
					if(position == end())
					{
						//std::cout << "at the end !!\n";
						for(;first != last;first++)
							push_back(*first);
					}
					else
					{
						difference_type i = index;
						difference_type ending = _size_container - 1;
					
						//std::cout << "at " << index << " ending = "<< ending <<std::endl;
						
						while(ending > index)
						{
							//std::cout<<"cpy " <<*(_ptr+ending)<< " at " << &(*(_ptr + ending + n)) << std::endl;
							_alloc.construct(_ptr + ending + n, *(_ptr + ending));
							ending--;
						}
						//std::cout<<"cpy " <<*(_ptr+ending)<< " at " << &(*(_ptr + ending + n)) << std::endl;
						_alloc.construct(_ptr + ending + n, *(_ptr + ending));
						i = index;
						for (;first != last; first++)
						{
							//std::cout<<"cpy "<< *first << " at " << &(*(_ptr+i))<<std::endl;
							_alloc.construct(_ptr + (i++), *first);
						}
						_size_container += n;
					}
				}

			}

			void		swap(vector &x)
			 {
				pointer			tmp_ptr = this->_ptr;
				allocator_type	tmp_allocator_type = this->_alloc;
				size_t			tmp_capacity = this->_capacity;
				size_t			tmp_size_container = this->_size_container;

				this->_alloc = x._alloc;
				this->_ptr = x._ptr;
				this->_capacity = x._capacity;
				this->_size_container = x._size_container;

				x._alloc = tmp_allocator_type;
				x._ptr = tmp_ptr;
				x._capacity = tmp_capacity;
				x._size_container = tmp_size_container;
			 }

			// remove element

			void	pop_back()
			{
				if (_size_container > 0)
				{
					_alloc.destroy(_ptr + (_size_container - 1));
					_size_container--;
				}
			};

			void	clear()
			{
				if(_size_container > 0)
				{
					for(iterator it = this->begin(); it != this->end(); it++)
						_alloc.destroy(&(*it));
					_size_container = 0;
				}
			}

			iterator erase(iterator pos)
			{
				if(empty() || pos == end())
					return end();
				iterator it = begin();
				while(it != pos)
					it++;
				_alloc.destroy(&(*it));
				pointer tmp = &(*(it++));
				pointer ret = tmp;
				while(it != end())
				{
					_alloc.construct(tmp, *it);
					tmp = &(*(it++));
				}
				pop_back();	// destroy the last 
				return iterator(ret);
			}

			iterator erase(iterator first, iterator last)
			{
				size_t nb = ft::distance(first, last);
				if(empty())
					return end();
				iterator it = begin();
				while(it != first)
					it++;
				iterator start = it;
				iterator dest = it;
				while( it != last && it != end())
					_alloc.destroy(&(*(it++)));
				while(it != end())
					_alloc.construct(&(*(start++)), *(it++));
				for(size_t i = 0; i < nb; i++)
					pop_back();
				return (dest);
			}

			// capacity
			std::size_t		size() const {return(_size_container);};

			std::size_t		capacity() const {return(_capacity);};

			std::size_t		max_size() const {return(Allocator().max_size());};

			bool	empty() const {return(_size_container == 0);};

			void	resize(std::size_t n, T val = T())
			{
				if (n == _size_container)
					return;
				if (n > this->max_size())
					throw(std::length_error("vector::resize"));
				if (n < _size_container)
				{
					for(std::size_t i = n; i < _size_container; i++)
						_alloc.destroy(_ptr + i);
					_capacity = n;
				}
				else
				{
					/* If n is greater than the current container size, 
					the content is expanded by inserting at the end
					as many elements as needed to reach a size of n.
					If val is specified, the new elements are initialized as
					copies of val, otherwise, they are value-initialized.*/
					this->reserve(n);
					for(std::size_t i = _size_container; i < n; i++)
						_alloc.construct(_ptr+i, val);
				}
				_size_container = n;
			};

			void	reserve(size_t n)
			{
				if (n > this->max_size())
					throw (std::length_error("vector::reserve"));
				else if (n > _capacity)
				{
					value_type	*prev_ptr = _ptr;
					std::size_t	prev_size = _size_container;
					std::size_t	prev_capacity = _capacity;
					_ptr = _alloc.allocate(n);
					_capacity = n;
					for(std::size_t i = 0; i < prev_size; i++)
						_alloc.construct(_ptr + i, *(prev_ptr + i));
					_alloc.deallocate(prev_ptr, prev_capacity);
				}
			};

			//iterators
			iterator		begin()			{return (iterator(_ptr));};
			const_iterator 	begin() const 	{return (const_iterator(_ptr));};

			iterator		end()		{return (iterator(_ptr + _size_container));};
			const_iterator	end() const {return (const_iterator(_ptr + _size_container));};

			reverse_iterator		rbegin()	   {return(reverse_iterator(end()));};
			const_reverse_iterator	rbegin() const {return(const_reverse_iterator(end()));};

			reverse_iterator		rend()		{return(reverse_iterator(begin()));};
			const_reverse_iterator	rend() const{return(const_reverse_iterator(begin()));};
		
			//elment access
			reference		front()			{return(*_ptr);};
			const_reference	front() const	{return(*_ptr);};
			reference		back()		{return(*(_ptr + _size_container - 1));};
			const_reference	back() const{return(*(_ptr + _size_container - 1));};
			const_reference at(size_t n) const
			{
				checkRange(n);
				return(*(_ptr + n));
			};
			reference at(size_t n) 
			{
				checkRange(n);
				return(*(_ptr + n));
			};
			reference		operator[](size_t pos)		{return (_ptr[pos]);};
			const_reference	operator[](size_t pos) const{return (_ptr[pos]);};

			Allocator	get_allocator()const{return _alloc;};

		private:
			allocator_type		_alloc;
			value_type			*_ptr;
			size_type			_capacity;
			size_type			_size_container; //nb of elem in vector

			void	checkRange(const size_t &n) const
			{
				if (n >= _size_container)
					throw(std::out_of_range("vector::checkRange: n (which is "
						+ ft::to_string(n) + ") >= this->size() (which is "
						+ ft::to_string(this->size()) + ")"));
			}

	};

// Non-member function overloads

template <class T, class Allocator>
	bool operator==(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator> &rhs)
	{
		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

template <class T, class Allocator>
	bool operator!=(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator> &rhs)
	{
		return (!(lhs == rhs));
	}

template <class T, class Allocator>
	bool operator<(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

template <class T, class Allocator>
	bool operator<=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
	{
		//a<=b	->	!(b < a)
		return (!(rhs < lhs));
	}

template <class T, class Allocator>
	bool operator>(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
	{
		//a>b		->  b<a
		return (rhs < lhs);
	}

template <class T, class Allocator>
	bool operator>=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
	{
		//a>=b	->	!(a<b)
		return (!(lhs < rhs));
	}

template <class T, class Allocator>
	void swap(vector<T, Allocator> &x, vector<T, Allocator> &y)
	{
		x.swap(y);
	}
}
#endif
