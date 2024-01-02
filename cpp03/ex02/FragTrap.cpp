/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 13:40:28 by yowazga           #+#    #+#             */
/*   Updated: 2023/09/24 17:11:43 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	Name = "name";
	HitPoints = 100;
	EnergyPoints = 100;
	AttackDamage = 30;
}
FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	HitPoints = 100;
	EnergyPoints = 100;
	AttackDamage = 30;	
	std::cout << "FragTrap " << Name << " is born!" << std::endl;
}
FragTrap::~FragTrap()
{
	 std::cout << "FragTrap " << Name << " is destroyed!" << std::endl;
}
FragTrap::FragTrap(const FragTrap& fragtrap)
{
	Name = fragtrap.Name;
	HitPoints = fragtrap.HitPoints;
	EnergyPoints = fragtrap.EnergyPoints;
	AttackDamage = fragtrap.AttackDamage;
	std::cout << "FragTrap " << Name << " is cloned!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& fragtrap)
{
	if (this != &fragtrap)
	{
		Name = fragtrap.Name;
		HitPoints = fragtrap.HitPoints;
		EnergyPoints = fragtrap.EnergyPoints;
		AttackDamage = fragtrap.AttackDamage;
	}
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << Name << " requests a high five!" << std::endl;
}