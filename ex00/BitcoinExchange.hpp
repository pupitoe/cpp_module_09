/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:23:00 by tlassere          #+#    #+#             */
/*   Updated: 2024/06/21 00:34:59 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# define SUCCESS 0
# define FAIL 1
# define BAD_FILE 2

# include <map>
# include <iostream>
# include <string>
# include <fstream>
# include <cstdlib>
# include <cmath>

typedef struct s_date
{
	int	year;
	int	month;
	int	day;
}t_date;


class	BitcoinExchange
{
	private:
		BitcoinExchange(BitcoinExchange const& cpy);
		BitcoinExchange& operator=(BitcoinExchange const& cpy);

		std::map<std::string, double> _file_exchange;
		std::map<int, int> _date_asignation;

		int		get_data_exchange(void);
		bool	ft_pars_line(std::string const& str);
		bool	ft_is_valide_date(std::string const& date);
		bool	ft_is_valide_number(std::string const& number);

		void	print_exchange(std::string const& date,
			std::string const& number);

	public:
		BitcoinExchange(void);
		~BitcoinExchange(void);

		void	exchange(std::string const& date, std::string const& number);
		class BadDataCSV: public std::exception
		{
			public:
				const char	*what(void) const throw();
		};
};

#endif
