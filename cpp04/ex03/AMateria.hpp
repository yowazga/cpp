/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:02:20 by yowazga           #+#    #+#             */
/*   Updated: 2023/10/02 12:47:15 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

class ICharacter;

class AMateria
{
	protected:
		std::string const type;
	public:
		AMateria(void);
		AMateria(const std::string& type);
		AMateria(const AMateria& other);
		~AMateria(void);
		AMateria& operator=(AMateria const & other);
		std::string const & getType() const; 
		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter& target);
		
};

#endif