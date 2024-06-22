/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 21:16:54 by tlassere          #+#    #+#             */
/*   Updated: 2024/06/22 20:53:44 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

# include <ctime>
# include <string>

static bool	good_syntax(int argc, char **argv)
{
	std::string	buffer;
	int			i;
	bool		ret;

	i = 0;
	ret = true;
	while (i < argc && ret)
	{
		buffer = argv[i];
		if (buffer.find_first_not_of("0123456789") < buffer.length())
			ret = false;
		i++;
	}
	return (ret);
}

int	main(int argc, char **argv)
{
	//std::clock_t;
	if (argc > 1 && good_syntax(argc - 1, argv + 1))
	{
		//std::time
		ft_sort_vector(argc - 1, argv + 1);
		//std::cout <<  << std::endl;
	}
	else
		std::cout << "Error" << std::endl;
	return (0);
}
