/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:35:20 by clorin            #+#    #+#             */
/*   Updated: 2021/11/02 11:35:47 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

/**********************************************************************************
 *				 						IS_INTEGRAL
 * the structure of is_integral for a Type is:
 * 			- type
 * 			- bool
 * 
 * who is stocked in the structure integral_constant for each type.
 * integral_constant is inherits from is_integral_helper to check the differents
 * type.
 * *******************************************************************************/

namespace ft
{
	template <typename T, bool is_integral = false >
		struct is_integral_helper
		{
			typedef T	type;
			static const bool value = is_integral;
		};


	// DEFAULT TEMPLATE -> RETURN FALSE
	template <typename>
		struct integral_constant : public is_integral_helper<void> {};

	// after, all type overloads the structure
	template <>
		struct integral_constant<bool>: public is_integral_helper<bool, true> {};
	template <>
		struct integral_constant<const bool>: public is_integral_helper<const bool, true> {};
	template <>
		struct integral_constant<char>: public is_integral_helper<char, true> {};
	template <>
		struct integral_constant<char16_t>: public is_integral_helper<char16_t, true> {};
	template <>
		struct integral_constant<char32_t>: public is_integral_helper<char32_t, true> {};
	template <>
		struct integral_constant<int>: public is_integral_helper<int, true> {};
	template <>
		struct integral_constant<const int>: public is_integral_helper<const int, true> {};

	/*------ continue with 
	**  - bool
    **  - char
    **  - char16_t
    **  - char32_t
    **  - wchar_t
    **  - signed char
    **  - short int
    **  - int
    **  - long int
    **  - long long int
    **  - unsigned char
    **  - unsigned short int
    **  - unsigned int
    **  - unsigned long int
    **  - unsigned long long int

	and their const 
	*/

	template <typename T>
		struct is_integral
		: public ft::integral_constant<T> { };    
}

#endif
