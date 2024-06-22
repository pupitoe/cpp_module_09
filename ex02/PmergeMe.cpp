/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 21:15:00 by tlassere          #+#    #+#             */
/*   Updated: 2024/06/22 18:25:00 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


static bool	ft_is_sorted(std::vector<int> const& content)
{
	std::vector<int>::const_iterator	it;
	std::vector<int>::const_iterator	it_last;
	bool								sorted;

	sorted = false;
	it = content.begin();
	it_last = content.begin();
	if (it != content.end())
		it++;
	while (it != content.end() && *it_last < *it)
	{
		it++;
		it_last++;
	}
	if (it == content.end())
		sorted = true;
	return (sorted);
}

static void	merge_sort_vector_op(std::vector<int>& content, size_t start,
	size_t len)
{
	bool	sorted;
	int		buffer;
	size_t	i;

	sorted = false;
	while (!sorted)
	{
		sorted = true;
		i = 0;
		while (i + 1 < len)
		{
			if (*(content.begin() + i + start)
				> *(content.begin() + i + start + 1))
			{
				buffer = *(content.begin() + i + start);
				*(content.begin() + i + start) =
					*(content.begin() + i + start + 1);
				*(content.begin() + i + start + 1) = buffer;
				sorted = false;
			}
			i++;
		}
	}
}

static void	merge_sort_vector(std::vector<int>& content, size_t start,
	size_t len)
{
	if (len < 2)
		return ;
	merge_sort_vector(content, start, len / 2);
	merge_sort_vector(content, start + len / 2, len / 2 + len % 2);
	merge_sort_vector_op(content, start, len);
}

// todo check doublon
void	ft_sort_vector(int const argc, char **argv)
{
	std::vector<int>	content;
	int					i;
	long				buffer;

	i = 0;
	while (i < argc && i >= 0)
	{
		buffer = std::strtol(argv[i], NULL, 10);
		if (buffer >= 0 && buffer <= __INT_MAX__)
			content.push_back(buffer);
		else
			i = -2;
		i++;
	}
	if (i > 0 && ft_is_sorted(content) == false)
		merge_sort_vector(content, 0, content.size());
}
