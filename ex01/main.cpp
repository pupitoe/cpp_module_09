/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:34:08 by tlassere          #+#    #+#             */
/*   Updated: 2024/06/21 16:35:06 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static void	use_rpn(std::string str)
{
	RPN	tester;

	tester.use(str);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		use_rpn(argv[1]);
	else
		std::cout << "Bad argument :(" << std::endl;
	return (0);
}
