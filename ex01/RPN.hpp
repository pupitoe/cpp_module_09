/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:35:29 by tlassere          #+#    #+#             */
/*   Updated: 2024/06/21 20:44:45 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <exception>

# define OPERATOR 0
# define PUSH_STACK 1

class	RPN
{
	private:
		RPN(RPN const& cpy);
		RPN& operator=(RPN const& cpy);

		std::stack<long>	_rpnizer;
		int					_last_action;

		class	BadFormat: public std::exception
		{
			public:
				const char	*what(void) const throw();
		};

		void	add_op(void);
		void	subtract_op(void);
		void	divisor_op(void);
		void	multiplie_op(void);

		void	op_rpm(std::string const& c);
		void	add_stack(long nbr);
		void	operator_stack(int const c);

	public:
		RPN(void);
		~RPN(void);

		void	use(std::string const& str);
};

#endif
