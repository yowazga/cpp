/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 09:53:49 by yowazga           #+#    #+#             */
/*   Updated: 2023/10/02 12:09:23 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {}

Ice::Ice(Ice const & other) : AMateria(other)
{
	*this = other;
} 

Ice::~Ice(void) {}

Ice& Ice::operator=(Ice const & other)
{
	(void)other;
	return *this;
}
AMateria* Ice::clone(void) const
{
	AMateria* m = new Ice();
	return m;
}
void Ice::use(ICharacter & target)
{
	// std::cout << "* shoots an ice bolt at " + target.getName() + " *" << std::endl;
}