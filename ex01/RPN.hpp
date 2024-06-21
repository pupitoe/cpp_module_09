/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:35:29 by tlassere          #+#    #+#             */
/*   Updated: 2024/06/21 15:08:00 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <exception>

class	RPN
{
	private:
		RPN(RPN const& cpy);
		RPN& operator=(RPN const& cpy);

		std::stack<long>	rpnizer;
		class	BadFormat: public std::exception
		{
			public:
				const char	*what(void) const throw();
		};

		void	op_rpm(std::string const& c);
	
	public:
		RPN(void);
		~RPN(void);

		void	use(std::string const& str);
};

#endif
