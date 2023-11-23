/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:41:47 by yowazga           #+#    #+#             */
/*   Updated: 2023/11/23 15:22:55 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

long get_time_us()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1000000 + tv.tv_usec;
}

void check_args(char **av)
{
	std::stringstream ss;


	ss << "Befor: ";
	for(int i = 0; av[i]; i++)
	{
		char *tmp = av[i];
		char *endptr;
		double value = std::strtod(tmp, &endptr);
		if (*endptr || !*tmp)
			throw std::string("invalid argument: '" + std::string(tmp) + "'");
		if (value - static_cast<int>(value))
			throw std::string("the argumen is not an integer");
		if (value < 0)
			throw std::string("the argumen is negative");
		ss << static_cast<int>(value) << " ";
	}
	std::cout << ss.str() << std::endl;
}

int main(int ac, char **av)
{
	std::vector<int> vec_cont;
	std::deque<int> deque_cont;

	if (ac < 2)
	{
		std::cerr << "useage: ./PmergeMe [list of int numbers]" << std::endl;
		return 1;
	}
	try
	{check_args(++av);}
	catch(const std::string& e)
	{
		std::cerr << "Error: " << e << std::endl;
		exit(1);
	}
	start_container(av, vec_cont, "vector", true);
	start_container(av, deque_cont,	"deque ");
}