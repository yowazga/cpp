/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:58:31 by yowazga           #+#    #+#             */
/*   Updated: 2023/12/21 15:56:28 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamoundTrap.hpp"

DiamoundTrap::DiamoundTrap()
{
	HitPoints = 100;
	EnergyPoints = 50;
	AttackDamage = 30;
	Name = "name";
}
DiamoundTrap::DiamoundTrap(const std::string& name) : ScavTrap(name + "_clap_name")
{
	HitPoints = 100;
	EnergyPoints = 50;
	AttackDamage = 30;
	Name = name;
	std::cout << "DiamoundTrap " << Name << " is born!" << std::endl;
}
DiamoundTrap::~DiamoundTrap()
{
	std::cout << "DiamondTrap " << Name << " is destroyed!" << std::endl;
}
void DiamoundTrap::whoAmI()
{
	std::cout << "My name is " << Name << " and my ClapTrap name is " << FragTrap::Name << std::endl;
}