/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 10:17:01 by yowazga           #+#    #+#             */
/*   Updated: 2023/09/24 16:17:02 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamoundTrap.hpp"

int main()
{
	ClapTrap claptrap("younes");
	std::cout << "------------------------------" << std::endl;
	ScavTrap scavtrap("guardian");
	std::cout << "------------------------------" << std::endl;
	FragTrap fragtrap("frag");
	std::cout << "------------------------------" << std::endl;
	DiamoundTrap diamoundtap("diamound");
	std::cout << "------------------------------" << std::endl;
	claptrap.attack("Enemy1");
	claptrap.takeDamage(5);
	claptrap.beRepaird(3);
	claptrap.attack("Enemy2");
	claptrap.takeDamage(12);
	claptrap.beRepaird(8);
	std::cout << "------------------------------" << std::endl;
	scavtrap.attack("Enemy3");
	scavtrap.takeDamage(15);
	scavtrap.guardGate();
	std::cout << "------------------------------" << std::endl;
	fragtrap.attack("Enemy4");
	fragtrap.takeDamage(10);
	fragtrap.highFivesGuys();
	std::cout << "------------------------------" << std::endl;
	diamoundtap.whoAmI();
	std::cout << "------------------------------" << std::endl;
}