/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:21:40 by yowazga           #+#    #+#             */
/*   Updated: 2023/10/02 12:40:59 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {}

Cure::Cure(Cure const & other) : AMateria(other)
{
	*this = other;
}
Cure::~Cure(void) {}

Cure& Cure::operator=(Cure const & other)
{
		(void)other;
		return *this;
}
AMateria* Cure::clone(void)  const
{
	AMateria* m = new Cure();
	return m;
}
void Cure::use(ICharacter & target)
{
	// std::cout << "* heals " + target.getName() + "'s wounds *" << std::endl;
}