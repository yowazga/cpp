/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:34:03 by yowazga           #+#    #+#             */
/*   Updated: 2023/10/07 13:58:51 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource():count(0) {}

MateriaSource::MateriaSource(const MateriaSource& other) : count(0)
{
	*this = other;
}
MateriaSource::~MateriaSource()
{
	 while (count--)
		delete materias[count];
}
MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	while (count--)
		delete materias[count];
	count = 0;
	while (count < other.count)
	{
		materias[count] = other.materias[count]->clone();
		count++;
	}
	return *this;
}
void MateriaSource::learnMateria(AMateria* m)
{
	if (count < 4)
	{
		materias[count] = m->clone();
		count++;
		return ;
	}
	std::cout << "MateriaSource is full" << std::endl;
}
AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = count - 1; i >= 0; i--)
	{
		if (materias[i]->getType() == type)
			return materias[i]->clone();
	}
	std::cout << "Requested Materia not found" << std::endl;
	return NULL;
}