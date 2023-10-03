/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:42:49 by yowazga           #+#    #+#             */
/*   Updated: 2023/10/01 15:19:44 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Unknown")
{
	std::cout << "Default Animal constucter called" << std::endl;
}

Animal::Animal(const std::string& Type) : type(Type)
{
	std::cout << "Param Animal constucter called" << std::endl;
}
Animal::Animal(const Animal& animal) : type(animal.type)
{
	std::cout << "copy Animal constructer called" << std::endl;
}
Animal::~Animal()
{
	std::cout << "Animal destructer called" << std::endl;
}
Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
		this->type = other.type;
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "uknow sound" << std::endl;
}

std::string Animal::getType(void) const
{
	return type;
}