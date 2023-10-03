/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:29:57 by yowazga           #+#    #+#             */
/*   Updated: 2023/10/02 09:53:35 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include "AMateria.hpp"


class Ice : public AMateria
{
	public:
		Ice(void);
		Ice(Ice const & other);
		~Ice(void);
		Ice& operator=(Ice const & other);
		AMateria *clone(void) const;
		void use(ICharacter & target);
};

#endif