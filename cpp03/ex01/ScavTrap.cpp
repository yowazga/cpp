/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 12:07:23 by yowazga           #+#    #+#             */
/*   Updated: 2023/09/24 17:05:31 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	HitPoints = 100;
	EnergyPoints = 50;
	AttackDamage = 20;
	std::cout << "ScavTrap " << Name << " is born!" << std::endl;
}
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << Name << " is destroyed!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (!HitPoints || !EnergyPoints)
		std::cout << "ScavTrap " << Name << " can't attack, not enough hit points or energy!" << std::endl;
	else
	{
		EnergyPoints--;
		std::cout << "ScavTrap " << Name << " attacks " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
	}
}

ScavTrap::ScavTrap(const ScavTrap& scavtrap)
{
	Name = scavtrap.Name;
	HitPoints = scavtrap.HitPoints;
	EnergyPoints = scavtrap.EnergyPoints;
	AttackDamage = scavtrap.AttackDamage;
	std::cout << "ScavTrap " << Name << " iscopied!" << std::endl;
}
ScavTrap& ScavTrap::ScavTrap::operator=(const ScavTrap& scavtrap)
{
	if (this == &scavtrap)
		return *this;
	Name = scavtrap.Name;
	HitPoints = scavtrap.HitPoints;
	EnergyPoints = scavtrap.EnergyPoints;
	AttackDamage = scavtrap.AttackDamage;
	return *this;
}

void ScavTrap::guardGate()
{
	std::cout << "Scavtrap " << Name << " is now in Gatekeeper mode!" << std::endl;
}