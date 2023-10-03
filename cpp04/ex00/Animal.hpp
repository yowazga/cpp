/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:45:18 by yowazga           #+#    #+#             */
/*   Updated: 2023/10/01 16:30:20 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
		Animal(const std::string& Type);
		Animal();
		Animal(const Animal& animal);
		virtual ~Animal();
		Animal& operator=(const Animal& other);
		virtual void makeSound() const;
		std::string getType(void) const;
};

#endif