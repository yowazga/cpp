/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:15:18 by yowazga           #+#    #+#             */
/*   Updated: 2023/11/13 11:16:54 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void checkError(bool check, std::string string)
{
	if (!check)
	{
		std::cerr << string << std::endl;
		exit(1);
	}
}

void loadDatabase(data& dataBase)
{
	std::ifstream inFile("data.csv");
	checkError(inFile.is_open(), std::string("data.csv") + ": " + std::string(strerror(errno)));
	
	std::string line;
	std::getline(inFile, line);
	checkError(line == "date,exchange_rate", "use 'date,exchange_rate' in first line");
	
	int clines = 1;
	while (std::getline(inFile, line))
	{
		size_t pos = line.find('-');
		while(pos != std::string::npos)
		{
			line.erase(pos, 1);
			pos = line.find('-');
		}
		std::istringstream pars(line);
		int date;
		if (!(pars >> date))
			checkError(false, "Error parsing date.");
		char comma;
		if (!(pars >> comma) || comma != ',')
			checkError(false, "Expected comma.");
		double value;
		if (!(pars >> value))
			checkError(false, "Error parsing value.");
		dataBase[date] = value;
		clines++;
	}	
	checkError(clines > 1, "file is not data");
	inFile.close();
}

std::string datToStr(int date)
{
	std::stringstream ss;
	ss << date;
	std::string dateStr = ss.str();
	dateStr.insert(4, "-");
	dateStr.insert(7, "-");
	return dateStr;
}

void convert(data& dataBase, btc& dataLine)
{
	data::iterator it = dataBase.begin();
	if (dataLine.date < it->first)
		throw std::string("Invalid date => " + datToStr(dataLine.date));
	it = dataBase.lower_bound(dataLine.date);
	if (it->first != dataLine.date)
		it--;
	double price = it->second * dataLine.value;
	std::cout << std::fixed << std::setprecision(2);
	std::cout << datToStr(dataLine.date) << " => " << dataLine.value
			  << " = " << price << std::endl;
}

void	BitcoinExchange(data& dataBase, std::string inputFile)
{
	btc dataLine;
	
	std::fstream input(inputFile.c_str());
	checkError(input.good(), "Cant read" + inputFile);
	
	std::string line;
	std::getline(input, line);
	checkError(line == "date | value", "invalide 'date | value' in first line in the file");
	
	int clines = 1;
	while (std::getline(input, line) && ++clines)
	{
		try
		{
			parsLine(dataLine, line);
			if (dataLine.value < 0) throw std::string("price not a positive number.");
			if (dataLine.value > 1000) throw std::string("too large a number.");
			convert(dataBase, dataLine);
		}
		catch(std::string& e)
		{
			std::cerr << "Error: " << e << std::endl;
		}
	}
	checkError(clines > 1, "file is not data");
}

int main(int ac, char **av)
{
	data dataBase;
	checkError(ac == 2, "Error: could not open file.");
	checkError(std::ifstream(av[1]).good(), std::string(av[1]) + ": " + std::string(strerror(errno)));
	loadDatabase(dataBase);
	BitcoinExchange(dataBase, av[1]);
}
