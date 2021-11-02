/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:32:58 by clorin            #+#    #+#             */
/*   Updated: 2021/10/29 18:33:23 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef UTILS_HPP
# define UTILS_HPP

namespace ft
{
	template <class InputIterator1, class InputIterator2>
		bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2)
	{
  		while (first1!=last1)
 		{
    		if (first2==last2 || *first2<*first1) return false;
    		else if (*first1<*first2) return true;
    		++first1; ++first2;
  		}
  		return (first2!=last2);
	}

	template<bool C, class T = void> 
		struct enable_if {};

	template<class T>
		struct enable_if<true, T> 
		{ 
			typedef T type;
		};
}
#endif
