/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:58:48 by yowazga           #+#    #+#             */
/*   Updated: 2023/10/01 15:19:57 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"


Cat::Cat() : Animal("Cat") , brain(new Brain())
{
	std::cout << "cat constructer called" << std::endl;	
}
Cat::Cat(const Cat& other) : Animal(other) , brain(new Brain(*(other.brain)))
{
	std::cout << "copy cat constructer called" << std::endl;
}
Cat::~Cat()
{
	delete brain;
	std::cout << "cat destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		delete brain;
		brain = new Brain(*(other.brain));
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Cat sound" << std::endl;
}