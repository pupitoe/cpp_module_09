/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:37:44 by tlassere          #+#    #+#             */
/*   Updated: 2024/06/21 01:48:13 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static std::map<int, int> get_map_month(void)
{
	std::map<int, int>	ret;
	int					c_day;
	
	for (int i = 1; i <= 12; i++)
	{
		c_day = 31;
		if (i == 4 || i == 6 || i == 9 || i == 11)
			c_day = 30;
		else if (i == 2)
			c_day = 29;
		ret.insert(std::pair<int, int>(i, c_day));
	}
	return (ret);
}

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

static t_date	ft_get_date(std::string const& date)
{
	t_date	res = {0, 0, 0};

	if (date.length() == 10 && date[4] == '-' && date[7] == '-')
	{
		res.year = std::strtol(date.c_str(), NULL, 10);
		res.month = std::strtol(date.c_str() + 5, NULL, 10);
		res.day = std::strtol(date.c_str() + 8, NULL, 10);
	}
	return (res);
}

BitcoinExchange::BitcoinExchange(void)
{
	this->_date_asignation = get_map_month();
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

bool	BitcoinExchange::ft_is_valide_date(std::string const& date)
{
	bool				res;
	std::map<int, int>	date_month;
	t_date	date_int;

	res = false;
	if (date.length() == 10 && ft_count_occurence(date, '-') == 2
		&& date.find_first_not_of("0123456789-") > date.length())
	{
		date_int = ft_get_date(date);
		if (date_int.month > 0 && date_int.month <= 12
			&& date_int.day > 0
			&& date_int.day <= this->_date_asignation[date_int.month])
			res = true;
	}
	return (res);	
}

bool	BitcoinExchange::ft_is_valide_number(std::string const& number)
{
	bool	ret;
	double	check_overflow;

	ret = false;
	check_overflow = std::strtod(number.c_str(), NULL);
	if (number.length() > 0
		&& number.find_first_not_of("0123456789.") > number.length()
		&& ft_count_occurence(number, '.') <= 1
		&& number[number.length() -1] != '.' && check_overflow != HUGE_VAL)
		ret = true;
	return (ret);
}

bool	BitcoinExchange::ft_pars_line(std::string const& str)
{
	bool		valide_line;
	std::string	date;
	std::string	value;
	
	valide_line = false;
	if (str.length() > 11 && str[10] == ',')
	{
		date = str.substr(0, 10);
		value = str.c_str() + 11;
		if (this->ft_is_valide_date(date) && this->ft_is_valide_number(value))
		{
			try
			{
				this->_file_exchange.insert(std::pair<std::string, double>(date,
					std::strtod(value.c_str(), NULL)));
				valide_line = true;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
	}
	return (valide_line);
}

int	BitcoinExchange::get_data_exchange(void)
{
	int	status;
	std::fstream	fdata;
	std::string		cline;

	status = FAIL;
	fdata.open("./data.csv", std::fstream::ios_base::in);
	if (fdata.fail() == false)
	{
		std::getline(fdata, cline);
		while (fdata.fail() == false && fdata.eof() == false && status == FAIL)
		{
			if (std::getline(fdata, cline)
				&& this->ft_pars_line(cline) == false)
				status = BAD_FILE;
		}
		if (fdata.eof())
			status = SUCCESS;
		fdata.close();
	}
	if (status != SUCCESS)
		throw BitcoinExchange::BadDataCSV();
	return (status);
}

static double	get_value_it(std::map<std::string, double> *data,
	std::string const& date, std::string& replace)
{
	double									associed_data;
	std::map<std::string, double>::iterator	it;

	associed_data = -1;
	try
	{
		data->insert(std::pair<std::string, double>(date, 69));
		it = data->find(date);
		if (it != data->begin())
		{
			--it;
			associed_data = it->second;
			replace = it->first;
		}
		else
			std::cout << "No value match :(" << std::endl;
		data->erase(date);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (associed_data);
}

void	BitcoinExchange::print_exchange(std::string const& date,
	std::string const& number)
{
	double	associed_data;
	std::string	replace_date;

	associed_data = -1;
	replace_date = date;
	if (this->_file_exchange[date])
		associed_data = this->_file_exchange[date];
	else
		associed_data = get_value_it(&this->_file_exchange, date, replace_date);
	if (associed_data != -1)
		std::cout << replace_date << " => " << number << " => " <<
			std::strtod(number.c_str(), NULL) * associed_data << std::endl;
}

void	BitcoinExchange::exchange(std::string const& date,
	std::string const& number)
{
	double	buffer;

	buffer = std::strtod(number.c_str(), NULL);
	if (this->ft_is_valide_date(date))
	{
		if (buffer >= 0)
		{
			if (buffer < 1000)
			{
				if (this->ft_is_valide_number(number))
					this->print_exchange(date, number);
				else
					std::cout << "Error: bad input => " << number << std::endl;
			}
			else
				std::cout << "Error: too large a number." << std::endl;	
		}
		else
			std::cout << "Error: not a positive number." << std::endl;
	}
	else
		std::cout << "Error: bad input => " << date << std::endl;
}

// expetion

const char	*BitcoinExchange::BadDataCSV::what(void) const throw()
{
	return ("The file 'data.csv' have a problem");
}
