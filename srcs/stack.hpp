/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:14:08 by clorin            #+#    #+#             */
/*   Updated: 2021/11/11 15:17:34 by clorin           ###   ########.fr       */
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

				explicit 	stack(const container_type &ctnr = container_type()): _c(ctnr){}
				virtual 	~stack() {}

				bool		empty(void) const { return _c.empty();}
				size_type	size(void) const { return _c.size();}

				void		push(const value_type &val)	{_c.push_back(val);}
				void		pop(void) {_c.pop_back();}

				value_type			&top(void) { return _c.back();}
				const value_type	&top(void) const { return _c.back();}

			template <class U, class Ctr>
			friend bool operator==(const ft::stack<T, Ctr> &lhs,
							const ft::stack<T, Ctr> &rhs);

			template <class U, class Ctr>
			friend bool operator!=(const ft::stack<T, Ctr> &lhs,
							const ft::stack<T, Ctr> &rhs);

			template <class U, class Ctr>
			friend bool operator<(const ft::stack<T, Ctr> &lhs,
							const ft::stack<T, Ctr> &rhs);

			template <class U, class Ctr>
			friend bool operator<=(const ft::stack<T, Ctr> &lhs,
							const ft::stack<T, Ctr> &rhs);

			template <class U, class Ctr>
			friend bool operator>(const ft::stack<T, Ctr> &lhs,
							const ft::stack<T, Ctr> &rhs);

			template <class U, class Ctr>
			friend bool operator>=(const ft::stack<T, Ctr> &lhs,
							const ft::stack<T, Ctr> &rhs);

			protected:
				Container		_c;
		};

		// non-members overloads functions
		template <class T, class Container>
			bool operator==(const ft::stack<T, Container> &lhs,
							const ft::stack<T, Container> &rhs)
			{
				return (lhs._c == rhs._c);
			}

		template <class T, class Container>
			bool operator!=(const ft::stack<T, Container> &lhs,
							const ft::stack<T, Container> &rhs)
			{
				return (lhs._c != rhs._c);
			}

		template <class T, class Container>
			bool operator<(const ft::stack<T, Container> &lhs,
							const ft::stack<T, Container> &rhs)
			{
				return (lhs._c < rhs._c);
			}

		template <class T, class Container>
			bool operator<=(const ft::stack<T, Container> &lhs,
							const ft::stack<T, Container> &rhs)
			{
				return (lhs._c <= rhs._c);
			}
		
		template <class T, class Container>
			bool operator>(const ft::stack<T, Container> &lhs,
							const ft::stack<T, Container> &rhs)
			{
				return (lhs._c > rhs._c);
			}

		template <class T, class Container>
			bool operator>=(const ft::stack<T, Container> &lhs,
							const ft::stack<T, Container> &rhs)
			{
				return (lhs._c >= rhs._c);
			}
} // ft
#endif
