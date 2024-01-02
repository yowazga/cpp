/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamoundTrap.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:58:24 by yowazga           #+#    #+#             */
/*   Updated: 2023/12/21 15:55:11 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOUNDTRAP_HPP
#define DIAMOUNDTRAP_HPP

#include "FragTrap.hpp"


class DiamoundTrap : public ScavTrap , public FragTrap
{
	private:
		std::string	Name;
	public:
		DiamoundTrap();
		DiamoundTrap(const std::string& name);
		~DiamoundTrap();

		void whoAmI();
};

#endif