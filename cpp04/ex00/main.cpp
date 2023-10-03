/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:50:10 by yowazga           #+#    #+#             */
/*   Updated: 2023/10/01 15:19:18 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal *meta = new Animal();
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();

	std::cout << "------------------------------" << std::endl;

	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;

	std::cout << "------------------------------" << std::endl;

	cat->makeSound();
	dog->makeSound();

	std::cout << "------------------------------" << std::endl;

	delete meta;
	delete dog;
	delete cat;

	std::cout << "------------------------------" << std::endl;

	const WrongAnimal *wrongmeta = new WrongAnimal();
	const WrongAnimal *wrongcat = new WrongCat();

	std::cout << "------------------------------" << std::endl;
	
	std::cout << wrongcat->getType() << " " << std::endl;

	std::cout << "------------------------------" << std::endl;

	wrongcat->makeSound();
	wrongmeta->makeSound();

	std::cout << "------------------------------" << std::endl;

	delete wrongmeta;
	delete wrongcat;
}