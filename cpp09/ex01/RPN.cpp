/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:59:31 by yowazga           #+#    #+#             */
/*   Updated: 2023/11/13 10:37:16 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

PRNCalculator::PRNCalculator() {}

PRNCalculator::PRNCalculator(const PRNCalculator &other)
{
	if (this != &other)
		*this = other;
}
PRNCalculator::~PRNCalculator() {}

PRNCalculator& PRNCalculator::operator=(const PRNCalculator &other)
{
	if(this != &other)
	{
		for (size_t i = 0; i < other._stack.size(); i++)
			this->_stack.push(other._stack.top());
	}
	return *this;
}
int PRNCalculator::evaluate(const std::string &expr)
{
	std::istringstream pars(expr);
	std::string token;
	
	while (pars >> token)
	{
		if (std::isdigit(token[0]))
		{
			int value = std::atoi(token.c_str());
			if (value < 0 || value > 9)
				throw std::string("Error: Invalid number");
			this->_stack.push(value);
		}
		else if (isOperator(token[0]))
		{
			if (this->_stack.size() < 2)
				throw std::string("Error: Not enough operands");
			int operand2 = this->_stack.top();
			_stack.pop();
			int operand1 = this->_stack.top();
			_stack.pop();
			int result = performOperation(token[0], operand1, operand2);
			_stack.push(result);
		}
		else
			throw std::string("Error: Invalid token");
	}
	return this->_stack.top();
}
bool PRNCalculator::isOperator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}
int PRNCalculator::performOperation(char op, int operand1, int operand2)
{
	switch (op)
	{
		case '+':
			return operand1 + operand2;
		case '-':
			return operand1 - operand2;
		case '*':
			return operand1 * operand2;
		case '/':
			if (operand2 == 0)
				throw std::string("Error: Division by zero");
			return operand1 / operand2;
		default:
			throw std::string("Error: Unknow operator");
	}
}
