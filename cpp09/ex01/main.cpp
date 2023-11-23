/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:59:11 by yowazga           #+#    #+#             */
/*   Updated: 2023/11/13 10:36:14 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: " << av[0] << " [expression]" << std::endl;
		return 1;
	}
	try
	{
		PRNCalculator calc;
		std::cout << calc.evaluate(av[1]) << std::endl;
	}
	catch(const std::string e)
	{
		std::cerr << e << '\n';
		return 1;
	}
	
}