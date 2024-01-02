/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 10:17:01 by yowazga           #+#    #+#             */
/*   Updated: 2023/09/25 20:19:14 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap claptrap("younes");

	claptrap.attack("Enemy1");
	claptrap.takeDamage(5);
	claptrap.beRepaird(80);
	claptrap.beRepaird(3);
	claptrap.attack("Enemy2");
	claptrap.takeDamage(12);
}