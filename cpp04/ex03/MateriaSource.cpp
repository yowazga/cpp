/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:11:52 by yowazga           #+#    #+#             */
/*   Updated: 2023/10/02 14:13:34 by yowazga          ###   ########.fr       */
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
	
}
MateriaSource::~MateriaSource()
{
	
}
MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	
}
void MateriaSource::learnMateria(AMateria *)
{
	
}
AMateria* MateriaSource::createMateria(std::string const & type)
{
	
}