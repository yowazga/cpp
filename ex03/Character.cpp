/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:37:28 by yowazga           #+#    #+#             */
/*   Updated: 2023/10/07 13:555:01 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name("Uknown")
{
	for (int i = 0; i < 4; i++)
		inventory[i] = 0;
}

Character::Character(const std::string& name) : name(name)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = 0;
}

Character::Character(const Character& other) : name(other.name)
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = 0;
	*this = other;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			delete this->inventory[i];
	}
}

Character& Character::operator=(const Character& other)
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
std::string const & Character::getName() const
{
	return this->name;
}
void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->inventory[i])
		{
			this->inventory[i] = m->clone();
			return ;
		}
	}
	std::cout << "Inventory is full" << std::endl;
}
void Character::unequip(int idx)
{
	if (idx < 0 || idx > 4)
	{
		std::cout << "invalid index" << std::endl;
		return ;
	}
	if (this->inventory[idx])
		delete this->inventory[idx];
}
void Character::use(int idx, ICharacter& target)
{
	if ((idx < 0 || idx > 4) && !this->inventory[idx])
	{
		std::cout << "invalid index" << std::endl;
		return ;
	}
	this->inventory[idx]->use(target);
}