/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:34:08 by tlassere          #+#    #+#             */
/*   Updated: 2024/06/21 20:49:37 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)
{
	RPN	tester;

	if (argc == 2)
		tester.use(argv[1]);
	else
		std::cout << "Bad argument :(" << std::endl;
	return (0);
}
