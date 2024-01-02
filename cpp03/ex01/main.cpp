/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 10:17:01 by yowazga           #+#    #+#             */
/*   Updated: 2023/09/24 12:45:14 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ClapTrap claptrap("younes");
	std::cout << "------------------------------" << std::endl;
	ScavTrap scavtrap("guardian");
	std::cout << "------------------------------" << std::endl;
	claptrap.attack("Enemy1");
	claptrap.takeDamage(5);
	claptrap.beRepaird(3);
	claptrap.attack("Enemy2");
	claptrap.takeDamage(12);
	claptrap.beRepaird(8);
	std::cout << "------------------------------" << std::endl;
	scavtrap.attack("Enemy3");
	std::cout << "------------------------------" << std::endl;
	scavtrap.takeDamage(15);
	std::cout << "------------------------------" << std::endl;
	scavtrap.guardGate();
	std::cout << "------------------------------" << std::endl;
}