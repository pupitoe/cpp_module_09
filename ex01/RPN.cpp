/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:36:04 by tlassere          #+#    #+#             */
/*   Updated: 2024/06/21 15:12:17 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void)
{
	return ;
}

RPN::~RPN(void)
{
	return ;
}

RPN::RPN(RPN const& cpy)
{
	*this = cpy;
	return ;
}

RPN& RPN::operator=(RPN const&)
{
	return (*this);
}

void	RPN::op_rpm(std::string const& c)
{
	static int a = 0;
	std::cout << c << std::endl;
	std::cout << a << std::endl;
	a++;
	(void)c;
}

void	RPN::use(std::string const& str)
{
	size_t	i;

	i = 0;
	try
	{
		while (i < str.length())
		{
			if (str[i] != ' ')
				this->op_rpm(str.substr(i, 1));
			i++;
		}
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}


// exeption
const char	*RPN::BadFormat::what(void) const throw()
{
	return ("Error");
}