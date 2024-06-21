/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:36:04 by tlassere          #+#    #+#             */
/*   Updated: 2024/06/21 20:35:56 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void)
{
	this->_last_action = PUSH_STACK;
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

void	RPN::add_stack(long nbr)
{
	if (this->_last_action == OPERATOR && this->_rpnizer.size() > 1)
		throw RPN::BadFormat();
	this->_last_action = PUSH_STACK;
	this->_rpnizer.push(nbr);
}

void	RPN::add_op(void)
{
	long	buffer;

	if (this->_rpnizer.size() >= 2)
	{
		buffer = this->_rpnizer.top();
		this->_rpnizer.pop();
		this->_rpnizer.top() += buffer;
	}
}

void	RPN::subtract_op(void)
{
	long	buffer;

	if (this->_rpnizer.size() >= 2)
	{
		buffer = this->_rpnizer.top();
		this->_rpnizer.pop();
		this->_rpnizer.top() -= buffer;
	}
}

void	RPN::multiplie_op(void)
{
	long	buffer;

	if (this->_rpnizer.size() >= 2)
	{
		buffer = this->_rpnizer.top();
		this->_rpnizer.pop();
		this->_rpnizer.top() *= buffer;
	}
}

void	RPN::divisor_op(void)
{
	long	buffer;

	if (this->_rpnizer.size() >= 2)
	{
		buffer = this->_rpnizer.top();
		this->_rpnizer.pop();
		if (buffer == 0)
			throw RPN::BadFormat();
		this->_rpnizer.top() /= buffer;
	}
}

void	RPN::operator_stack(int const c)
{
	this->_last_action = OPERATOR;
	if (this->_rpnizer.size() < 2)
		throw RPN::BadFormat();
	switch (c)
	{
		case '+':
			this->add_op();
			break;
		case '-':
			this->subtract_op();
			break;
		case '*':
			this->multiplie_op();
			break;
		case '/':
			this->divisor_op();
			break;
		default:
			throw RPN::BadFormat();
			break;
	}
}

void	RPN::op_rpm(std::string const& c)
{
	if (c.find_first_of("0123456789") < c.size())
		this->add_stack(c[0] - '0');
	else
		this->operator_stack(c[0]);
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
		if (this->_rpnizer.size() != 1)
			throw RPN::BadFormat();
		std::cout << this->_rpnizer.top() << std::endl;
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
