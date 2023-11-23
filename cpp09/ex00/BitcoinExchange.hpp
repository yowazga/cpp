/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:54:22 by yowazga           #+#    #+#             */
/*   Updated: 2023/11/12 12:51:26 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

typedef std::map<int, double> data;

struct btc
{
	int date;
	double value;
};

void parsLine(btc& dataLine, std::string& line);