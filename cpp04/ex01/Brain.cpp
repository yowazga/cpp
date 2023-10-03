/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 12:49:11 by yowazga           #+#    #+#             */
/*   Updated: 2023/10/01 16:46:17 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor" << std::endl;
}
Brain::Brain(const Brain& brain)
{
	*this =  brain;
	std::cout << "Brain copy constructor" << std::endl;
}
Brain::~Brain()
{
	std::cout << "Brain destructor" << std::endl;
}
Brain& Brain::operator=(const Brain& brain)
{
	if (this != & brain)
		std::memcpy(ideas, brain.ideas, sizeof(ideas));
	return *this;
}