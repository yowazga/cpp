/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 10:16:54 by yowazga           #+#    #+#             */
/*   Updated: 2023/09/24 17:01:09 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	Name = "name";
	HitPoints = 10;
	EnergyPoints = 10;
	AttackDamage = 0;
}

ClapTrap::ClapTrap(const std::string& name) : Name(name), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
	std::cout << "ClapTrap " << Name << " is born!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (!HitPoints || !EnergyPoints)
		std::cout << "ClapTrap " << Name << " can't attack, not enough hit points or energy!" << std::endl;
	else
	{
		EnergyPoints--;
		std::cout << "ClapTrap " << Name << " attacks " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
	}
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (!HitPoints)
		std::cout << "ClapTrap " << Name << " can't take damage, already detroyed!" << std::endl;
	else
	{
		HitPoints = (amount > HitPoints) ? 0 : HitPoints - amount;
		std::cout << "ClapTrap " << Name << " takes " << amount << " points of damage!" << std::endl;
		if (!HitPoints)
			std::cout << "ClapTrap " << Name << " is destroed!" << std::endl;
	}
		
}

ClapTrap::ClapTrap(const ClapTrap& claptrap)
{
	Name = claptrap.Name;
	HitPoints = claptrap.HitPoints;
	EnergyPoints = claptrap.EnergyPoints;
	AttackDamage = claptrap.AttackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& claptrap)
{
	Name = claptrap.Name;
	HitPoints = claptrap.HitPoints;
	EnergyPoints = claptrap.EnergyPoints;
	AttackDamage = claptrap.AttackDamage;
	return (*this);
}

void ClapTrap::beRepaird(unsigned int amount)
{
	if (!HitPoints)
		std::cout << "ClapTrap " << Name << " can't be repaird, it's already destroyed!" << std::endl;
	else
	{
		EnergyPoints--;
		HitPoints += amount;
		std::cout << "ClapTrap " << Name << " is repaired for " << amount << " hit points!" << std::endl;
	}
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << Name << " is destroyed!" << std::endl;
}