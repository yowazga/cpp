/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:50:10 by yowazga           #+#    #+#             */
/*   Updated: 2023/10/01 15:20:12 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "===============================" << std::endl;

	delete j;
	delete i;

	std::cout << "===============================" << std::endl;

	Animal *animal[4];
	animal[0] = new Dog();
	animal[1] = new Dog();
	animal[2] = new Cat();
	animal[3] = new Cat();

	std::cout << "===============================" << std::endl;

	std::cout << animal[0]->getType() << std::endl;
	std::cout << animal[1]->getType() << std::endl;
	std::cout << animal[2]->getType() << std::endl;
	std::cout << animal[3]->getType() << std::endl;
	
	std::cout << "===============================" << std::endl;

	for (int i = 0; i < 4; i++)
		delete animal[i];
	
	std::cout << "===============================" << std::endl;
	
	return 0;
}