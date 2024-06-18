/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:23:00 by tlassere          #+#    #+#             */
/*   Updated: 2024/06/18 15:53:17 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# define SUCCESS 0
# define FAIL 1

# include <map>
# include <iostream>
# include <string>
# include <fstream>

class	BitcoinExchange
{
	private:
		BitcoinExchange(BitcoinExchange const& cpy);
		BitcoinExchange& operator=(BitcoinExchange const& cpy);

		std::map<std::string, double> _file_exchange;

		int				get_data_exchange(void);
		void			ft_pars_line(std::string const& str);

	public:
		BitcoinExchange(void);
		~BitcoinExchange(void);
		
};

#endif
