/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 21:16:30 by tlassere          #+#    #+#             */
/*   Updated: 2024/06/22 23:16:00 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <cstdlib>
# include <deque>

bool	ft_is_sorted(std::vector<int> const& content);
bool	ft_is_sorted(std::deque<int> const& content);

std::vector<int>	ft_sort_vector(int const argc, char **argv);
std::deque<int>		ft_sort_deque(int const argc, char **argv);

#endif
