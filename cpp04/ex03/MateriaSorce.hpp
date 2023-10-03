/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSorce.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:19:32 by yowazga           #+#    #+#             */
/*   Updated: 2023/10/02 13:46:18 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* inventory[4];
	public:
		MateriaSource();
		MateriaSource(MateriaSource const & other);
		~MateriaSource();
		MateriaSource& operator=(const MateriaSource& other);
		void learnMateria(AMateria *);
		AMateria* createMateria(std::string const & type);
};

#endif