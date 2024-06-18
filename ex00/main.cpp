/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:21:21 by tlassere          #+#    #+#             */
/*   Updated: 2024/06/18 22:17:39 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"

int	main(void)
{
	int	status;
	try
	{
		BitcoinExchange	btc;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	status = SUCCESS;
	return (status);
}
