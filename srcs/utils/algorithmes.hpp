/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithmes.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 08:43:29 by clorin            #+#    #+#             */
/*   Updated: 2021/11/03 08:44:11 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ALGORITHMES_HPP
# define ALGORITHMES_HPP

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

    template <class T, class U>
        bool equal(T first1, T last1, U first2)
        {
            while(first1 != last1)
            {
                if(!(*first1 == *first2))
                    return (false);
                    first1++;
                    first2++;
            }
            return true;
        }

    // TO DO equal(T first1, T last1, U first2, function)
}
#endif
