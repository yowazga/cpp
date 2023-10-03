/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:22:04 by yowazga           #+#    #+#             */
/*   Updated: 2023/10/02 12:48:52 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : type("Unkow"){}

AMateria::AMateria(const std::string& type) : type(type) {}

AMateria::AMateria(const AMateria& other) : type(other.type) {}

AMateria::~AMateria(void) {}

AMateria& AMateria::operator=(AMateria const & other)
{	
	(void)other;
	return *this;
}

void AMateria::use(ICharacter& target)
{
	// std::cout << "* This is th	e default use  function of "
	// 			+ type + ", used on " + target.getName() + " *" << std::endl;
}

std::string const & AMateria::getType() const
{
	return this->type;
}