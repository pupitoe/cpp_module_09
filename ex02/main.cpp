/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 21:16:54 by tlassere          #+#    #+#             */
/*   Updated: 2024/06/24 23:50:38 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

# include <ctime>
# include <iomanip>
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
		if (!buffer.length()
			|| buffer.find_first_not_of("0123456789") < buffer.length())
			ret = false;
		i++;
	}
	return (ret);
}

static void	ft_print(int argc, char **argv)
{
	int	i;

	i = 0;
	std::cout << "Before:\t";
	while (i < argc)
	{
		std::cout << std::strtol(argv[i], NULL, 10)
			<< ((i + 1 < argc)? " ": "");
		i++;
	}
}

static void	ft_print(std::vector<int> const& content)
{
	std::cout << "\nAfter:\t";
	for (std::vector<int>::const_iterator it = content.begin();
		it != content.end(); it++)
		std::cout << *it << (((it + 1) != content.end())? " ": "");
}

static void	ft_print_result_deque(int argc, char **argv)
{
	std::deque<int> d_result;
	std::clock_t	start;
	std::clock_t	end;

	start = std::clock();
	d_result = ft_sort_deque(argc, argv);
	end = std::clock();
	if (ft_is_sorted(d_result) && start != -1 && end != -1)
	{
		std::cout << "Time to process a range of " << argc <<
			" elements with std::deque : "
			<< 1000 * (long double)(end - start) / CLOCKS_PER_SEC << "ms"
			<< std::endl;
	}
	else
		std::cout << "Error with sort of deque" << std::endl;
}

static void	ft_print_result(int argc, char **argv)
{
	std::vector<int> v_result;
	std::clock_t	start;
	std::clock_t	end;	

	start = std::clock();
	v_result = ft_sort_vector(argc, argv);
	end = std::clock();
	std::cout << std::setprecision(10);
	if (ft_is_sorted(v_result) && start != -1 && end != -1)
	{
		ft_print(argc, argv);
		ft_print(v_result);
		std::cout << "\nTime to process a range of " << argc <<
			" elements with std::vector : "
			<< 1000 * (long double)(end - start) / CLOCKS_PER_SEC << "ms"
			<< std::endl;
	}
	else
		std::cout << "Error with sort of vector" << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc > 1 && good_syntax(argc - 1, argv + 1))
	{
		ft_print_result(argc - 1, argv + 1);
		ft_print_result_deque(argc - 1, argv + 1);
	}
	else
		std::cout << "Error" << std::endl;
	return (0);
}
