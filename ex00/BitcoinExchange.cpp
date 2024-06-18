/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:37:44 by tlassere          #+#    #+#             */
/*   Updated: 2024/06/18 17:00:00 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static size_t ft_count_occurence(std::string const& str, int c)
{
	size_t						count;
	std::string::const_iterator	it;

	count = 0;
	it = str.begin();	
	while (it != str.end())
	{
		if (*it == c)
			count++;
		it++;
	}
	return (count);	
}

BitcoinExchange::BitcoinExchange(void)
{
	this->get_data_exchange();
	return ;
}

BitcoinExchange::~BitcoinExchange(void)
{
	return ;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& cpy)
{
	*this = cpy;
	return ;
}

BitcoinExchange&	BitcoinExchange::operator=(BitcoinExchange const&)
{
	return (*this);
}

bool			BitcoinExchange::ft_is_valide_date(std::string const& date)
{
	bool	res;

	res = false;
	if (date.length() == 10 && ft_count_occurence(date, '-') == 2)
	{
		res = true;
	}
	return (res);	
}

void	BitcoinExchange::ft_pars_line(std::string const& str)
{
	this->ft_is_valide_date("ahhhhhhhhh");
	(void)str;
	std::cout << this->ft_is_valide_date("2000-20-10") << std::endl;
	//std::cout << str << std::endl;
}

int	BitcoinExchange::get_data_exchange(void)
{
	int	status;
	std::fstream	fdata;
	std::string		cline;


	status = FAIL;
	fdata.open("./data.csv", std::fstream::ios_base::in);
	std::cout << "lkk" << std::endl;
	while (fdata.fail() == false && fdata.eof() == false)
	{
		if (std::getline(fdata, cline))
			this->ft_pars_line(cline);
	}
	if (fdata.eof())
		status = SUCCESS;
	return (status);
}
