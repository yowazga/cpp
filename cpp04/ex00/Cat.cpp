/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:58:48 by yowazga           #+#    #+#             */
/*   Updated: 2023/10/01 15:19:00 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"


Cat::Cat() : Animal("Cat")
{
	std::cout << "cat constructer called" << std::endl;	
}
Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "copy cat constructer called" << std::endl;
}
Cat::~Cat()
{
	std::cout << "cat destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Cat sound" << std::endl;
}