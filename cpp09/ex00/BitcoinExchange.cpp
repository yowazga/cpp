/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:17:52 by yowazga           #+#    #+#             */
/*   Updated: 2023/11/22 14:18:13 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool isLeapYear(int year)
{
	if (year % 4 != 0)
		return false;
	else if (year % 100 == 0 && year % 400 != 0)
		return false;
	return true;
}                                                                   

int getDate(std::string& date)
{
	int year, month, day;
	if (date[date.size() - 1] == ' ')
		date.pop_back();
	std::istringstream pars(date);
	char char1, char2;
	if (date.size() != 10)
		throw std::string("Invalid date => " + date);
	if (!(pars >> year >> char1 >> month >> char2 >> day) || char1 != '-' || char2 != '-' || pars.rdbuf()->in_avail() != 0)
		throw std::string("Invalid date => " + date);
	int daysInMonth[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	if (isLeapYear(year))
		daysInMonth[2] = 29;
	if (year < 2000 || year > 2024 || month < 1 || month > 12 || day < 1 || day > daysInMonth[month])
		throw std::string("Invalid date => " + date);
	return (year * 10000 + month * 100 + day);
}

double getValue(std::string& value)
{
	double val;
	char *endptr;
	if (value[0] == '-')
		value.erase(0, 1);
	val = std::strtod(value.c_str(), &endptr);
	if (*endptr != '\0')
		throw std::string("Invalid value => " + value);
	return val;
}

void parsLine(btc& dataLine, std::string& line)
{
	std::count(line.begin(), line.end(), '|') != 1 ? throw std::string("Bad input => " + line) : 0;
	std::istringstream pars(line);
	std::string date, value;
	std::getline(pars, date, '|');
	std::getline(pars, value, '|');
	dataLine.date = getDate(date);
	dataLine.value = getValue(value);
}