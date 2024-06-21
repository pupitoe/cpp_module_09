/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:36:04 by tlassere          #+#    #+#             */
/*   Updated: 2024/06/21 14:39:44 by tlassere         ###   ########.fr       */
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


