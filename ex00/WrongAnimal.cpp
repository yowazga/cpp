/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:09:26 by yowazga           #+#    #+#             */
/*   Updated: 2023/09/30 13:35:49 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Uknown")
{
	std::cout << "WrongAnimal default Constructor" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type)
{
	std::cout << "WrongAnimal Copy Constructor" << std::endl;
}
WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor" << std::endl;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
		this->type = other.type;
	return (*this);
}
void WrongAnimal::makeSound() const
{
	std::cout << "Uknown sound" << std::endl;
}
std::string WrongAnimal::getType() const
{
	return type;
}