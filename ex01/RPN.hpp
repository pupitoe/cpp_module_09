/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:35:29 by tlassere          #+#    #+#             */
/*   Updated: 2024/06/21 14:44:31 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>

class	RPN
{
	private:
		RPN(RPN const& cpy);
		RPN& operator=(RPN const& cpy);

		std::stack<long>	rpnizer;
	
	public:
		RPN(void);
		~RPN(void);
};

#endif
