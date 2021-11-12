/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:14:29 by clorin            #+#    #+#             */
/*   Updated: 2021/11/12 11:26:00 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <cstddef> // pour ptrdiff_t

namespace ft
{
	struct input_iterator_tag{ };
	struct forward_iterator_tag : public input_iterator_tag{ };
	struct bidirectional_iterator_tag : public forward_iterator_tag{ };
	struct random_access_iterator_tag : public bidirectional_iterator_tag{ };

	template <class Category,
			  class T,
			  class Distance = std::ptrdiff_t,
			  class Pointer = T*,
			  class Reference = T&>

	struct iterator
	{
			typedef T			value_type;
			typedef Distance	difference_type;
			typedef Pointer		pointer;
			typedef	Reference	reference;
			typedef	Category	iterator_category;
	};

	/***********************************************************************
	 * 
	 * 								ITERATOR_TRAITS
	 * 
	 * *********************************************************************/

	 /*							Default										*/
	 
	template <class Iterator>
	struct iterator_traits
	{
			typedef	typename	Iterator::difference_type		difference_type;
			typedef	typename	Iterator::value_type			value_type;
			typedef	typename	Iterator::pointer				pointer;
			typedef	typename	Iterator::reference				reference;
			typedef	typename	Iterator::iterator_category		iterator_category;
	};
	
	/*							Specialized									*/
	template <class T>
	struct iterator_traits<T*>
	{
			typedef	ptrdiff_t							difference_type;
			typedef T									value_type;
			typedef T*									pointer;
			typedef	T&									reference;
			typedef	ft::random_access_iterator_tag		iterator_category;
	};

	template <class It>
	struct iterator_traits<const It*>
	{
			typedef	ptrdiff_t							difference_type;
			typedef It									value_type;
			typedef It*									pointer;
			typedef	It&									reference;
			typedef	ft::random_access_iterator_tag		iterator_category;
	};
} // ft::

#endif
