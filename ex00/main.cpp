/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:21:21 by tlassere          #+#    #+#             */
/*   Updated: 2024/06/20 14:36:30y tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"

static int	ft_reader(BitcoinExchange const& btc, std::fstream const& file)
{

}

static int	ft_btc(std::string const& path)
{
	int status;

	status = FAIL;
	try
	{
		BitcoinExchange	btc;
		std::fstream	file;

		file.open(path, std::ios_base::in);
		if (file.fail() == false)
		{
			
			file.close();
		}
		else
			std::cout << "Error: could not open file." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int	main(int argc, char **argv)
{
	int	status;
	
	status = FAIL;
	if (argc == 2)
		status = ft_btc(argv[1]);
	else
		std::cout << "Error: could not open file." << std::endl;
	return (status);
}
