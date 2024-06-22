/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 21:16:54 by tlassere          #+#    #+#             */
/*   Updated: 2024/06/22 18:49:44 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

# include <ctime>

int	main(int argc, char **argv)
{
	//std::clock_t;
	if (argc > 1)
	{
		//std::time
		ft_sort_vector(argc - 1, argv + 1);
		//std::cout <<  << std::endl;
	}
	return (0);
}
