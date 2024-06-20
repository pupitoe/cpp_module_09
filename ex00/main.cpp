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

static void	ft_get_date(std::string const& cline, std::string& date)
{
	size_t		start_date;

	start_date = cline.find_first_not_of(' ');
	if (start_date > cline.length())
		start_date = 0;
	date = cline.substr(start_date, 10);
}

static void	ft_get_value(std::string const& cline, std::string& value)
{
	size_t	start_value;
	size_t	end_value;
	int		buffer;

	start_value = 0;
	end_value = 0;
	buffer = 0;
	while (start_value < cline.length() && (!buffer || buffer == 1
		|| ((buffer >> 1) && cline[buffer] != ' ')))
	{
		if (cline[start_value] == '|')
			buffer |= 1;
		else if (cline[start_value] != ' ' && buffer)
			buffer |= 1 << 1;
		if (buffer >> 1)
			end_value++;
		start_value++;
	}
	value = cline.substr(start_value - end_value, start_value);
}

static void	ft_reader(BitcoinExchange& btc, std::fstream& file)
{
	std::string	cline;
	std::string	date;
	std::string	value;

	std::getline(file, cline);
	while (file.fail() == false && file.eof() == false)
	{
		if (std::getline(file, cline) && cline.length() > 0)
		{
			ft_get_date(cline, date);
			ft_get_value(cline, value);
			btc.exchange(date, value);
			//std::cout << "date: " << date << std::endl;
			//std::cout << "value: " << value << std::endl;
		}
	}
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
