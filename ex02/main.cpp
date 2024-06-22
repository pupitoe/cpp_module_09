/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 21:16:54 by tlassere          #+#    #+#             */
/*   Updated: 2024/06/22 22:18:42 by tlassere         ###   ########.fr       */
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

static void	ft_print(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		std::cout << argv[i] << ((i + 1 < argc)? " ": "");
		i++;
	}
}

static void	ft_print(std::vector<int> const& content)
{
	for (std::vector<int>::const_iterator it = content.begin();
		it != content.end(); it++)
		std::cout << *it << (((it + 1) != content.end())? " ": "");
}

static void	ft_print_result(int argc, char **argv)
{
	std::vector<int> v_result;

	v_result = ft_sort_vector(argc, argv);
	if (ft_is_sorted(v_result))
	{
		std::cout << "Before:\t";
		ft_print(argc, argv);
		std::cout << "\n";
		std::cout << "After:\t";
		ft_print(v_result);
		std::cout << "\n";
	}
	else
		std::cout << "Error" << std::endl;
}

int	main(int argc, char **argv)
{
	//std::clock_t;

	if (argc > 1 && good_syntax(argc - 1, argv + 1))
		ft_print_result(argc - 1, argv + 1);
		//std::time
		//std::cout <<  << std::endl;
	else
		std::cout << "Error" << std::endl;
	return (0);
}
