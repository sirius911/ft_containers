/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:14:08 by clorin            #+#    #+#             */
/*   Updated: 2021/11/26 16:18:46 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
		class stack
		{
			public:
				typedef T			value_type;
				typedef Container	container_type;
				typedef size_t		size_type;

				explicit 	stack(const container_type &ctnr = container_type()): c(ctnr){}
				//no constructor by copy and operator=
				// see https://www.cplusplus.com/reference/stack/stack/stack/
				virtual 	~stack() {}
				
				bool		empty(void) const { return c.empty();}
				size_type	size(void) const { return c.size();}

				void		push(const value_type &val)	{c.push_back(val);}
				void		pop(void) {c.pop_back();}

				value_type			&top(void) { return c.back();}
				const value_type	&top(void) const { return c.back();}

			template <class U, class Ctr>
			friend bool operator==(const ft::stack<U, Ctr> &lhs,const ft::stack<U, Ctr> &rhs);

			template <class U, class Ctr>
			friend bool operator!=(const ft::stack<U, Ctr> &lhs,const ft::stack<U, Ctr> &rhs);

			template <class U, class Ctr>
			friend bool operator<(const ft::stack<U, Ctr> &lhs,const ft::stack<U, Ctr> &rhs);

			template <class U, class Ctr>
			friend bool operator<=(const ft::stack<U, Ctr> &lhs,const ft::stack<U, Ctr> &rhs);

			template <class U, class Ctr>
			friend bool operator>(const ft::stack<U, Ctr> &lhs,const ft::stack<U, Ctr> &rhs);

			template <class U, class Ctr>
			friend bool operator>=(const ft::stack<U, Ctr> &lhs,const ft::stack<U, Ctr> &rhs);

			protected:
				Container		c;	// same name as std::stack
		};

		// non-members overloads functions
		template <class T, class Container>
			bool operator==(const ft::stack<T, Container> &lhs,const ft::stack<T, Container> &rhs)
			{return (lhs.c == rhs.c);}

		template <class T, class Container>
			bool operator!=(const ft::stack<T, Container> &lhs,const ft::stack<T, Container> &rhs)
			{return (lhs.c != rhs.c);}

		template <class T, class Container>
			bool operator<(const ft::stack<T, Container> &lhs,const ft::stack<T, Container> &rhs)
			{return (lhs.c < rhs.c);}

		template <class T, class Container>
			bool operator<=(const ft::stack<T, Container> &lhs,const ft::stack<T, Container> &rhs)
			{return (lhs.c <= rhs.c);}
		
		template <class T, class Container>
			bool operator>(const ft::stack<T, Container> &lhs,const ft::stack<T, Container> &rhs)
			{return (lhs.c > rhs.c);}

		template <class T, class Container>
			bool operator>=(const ft::stack<T, Container> &lhs,const ft::stack<T, Container> &rhs)
			{return (lhs.c >= rhs.c);}
} // ft
#endif
