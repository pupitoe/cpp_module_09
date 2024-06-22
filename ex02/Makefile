# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/10 13:53:46 by tlassere          #+#    #+#              #
#    Updated: 2024/06/22 15:35:40 by tlassere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX			::= c++
CXXFLAGS	::= -Wall -Wextra -Werror -std=c++98
NAME		::= PmergeMe
SOURCES		::= main.cpp PmergeMe.cpp
OBJS		::= $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
