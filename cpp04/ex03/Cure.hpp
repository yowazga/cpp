/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:11:57 by yowazga           #+#    #+#             */
/*   Updated: 2023/10/02 12:40:40 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
	Cure(void);
	Cure(Cure const & other);
	~Cure(void);
	Cure& operator=(Cure const & other);
	AMateria* clone(void) const;
	void use(ICharacter & target);	
};

#endif