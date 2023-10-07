/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 20:30:34 by yowazga           #+#    #+#             */
/*   Updated: 2023/10/01 15:20:45 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), brain(new Brain())
{
	std::cout << "default dog constructer called" << std::endl;
}
Dog::Dog(const Dog& dog) : Animal(dog), brain(new Brain(*(dog.brain)))
{
	std::cout << "Dog copy constructor called" << std::endl;
}
Dog::~Dog()
{
	delete brain;
	std::cout << "Dog Destructor called" << std::endl;
}
Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		delete brain;
		brain = new Brain(*(other.brain));
	}
	return *this;
}
void Dog::makeSound() const
{
	std::cout << "Dog sound" << std::endl;
}