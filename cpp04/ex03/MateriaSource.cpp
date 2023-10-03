/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:11:52 by yowazga           #+#    #+#             */
/*   Updated: 2023/10/03 10:32:45 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSorce.hpp"

MateriaSource::MateriaSource()
{
	for(int i = 0; i < 4; i++)
		inventory[i] = NULL;
}
MateriaSource::MateriaSource(MateriaSource const & other)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	*this = other;
}
MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		if (inventory[i])
			delete inventory[i];
}
MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
		{
			delete this->inventory[i];
			this->inventory[i] = 0;
		}
		if (other.inventory[i])
			this->inventory[i] = other.inventory[i]->clone();
	}
	return *this;
}
void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->inventory[i])
		{
			this->inventory[i] = m;
			return ;
		}
		std::cout << "INventory is full" << std::endl;
	}
}
AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
		if (this->inventory[i] && this->inventory[i]->getType() == type)
			return this->inventory[i]->clone();
	std::cout << "Materia of type " + type + "not found" << std::endl;
	return 0;
}