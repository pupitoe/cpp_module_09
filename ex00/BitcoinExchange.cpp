/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:37:44 by tlassere          #+#    #+#             */
/*   Updated: 2024/06/18 16:04:17 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

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

void	BitcoinExchange::ft_pars_line(std::string const& str)
{
	std::cout << str << std::endl;
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
