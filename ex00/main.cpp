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

static void	ft_reader(BitcoinExchange& btc, std::fstream const&)
{
	//std::string	cline;

	//std::getline(file, cline);
	//while (file.fail() == false && file.eof() == false)
	//{
	//	if (std::getline(file, cline))
			
	//}
	btc.exchange("2009-12-01", "4");
}

static int	ft_btc(std::string const& path)
{
	int status;

	status = FAIL;
	try
	{
		BitcoinExchange	btc;
		std::fstream	file;

		file.open(path.c_str(), std::ios_base::in);
		if (file.fail() == false)
		{
			ft_reader(btc, file);
			file.close();
			status = SUCCESS;
		}
		else
			std::cout << "Error: could not open file." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (status);
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
