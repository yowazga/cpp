/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:15:36 by yowazga           #+#    #+#             */
/*   Updated: 2023/10/05 14:06:28 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : type("default") {}

AMateria::AMateria(const AMateria& src) : type(src.type) {}

AMateria::AMateria(const std::string& Type) : type(Type) {}

AMateria& AMateria::operator=(const AMateria&)
{
	// copying the type doesn't make any sense
	return *this;
}
AMateria::~AMateria() {}

std::string const & AMateria::getType() const
{
	return this->type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "Default AMateria msg on " + target.getName() << std::endl;
}