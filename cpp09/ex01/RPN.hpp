/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:59:33 by yowazga           #+#    #+#             */
/*   Updated: 2023/11/12 18:16:32 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <sstream>

class PRNCalculator
{
	private:
		std::stack<int> _stack;
		bool isOperator(char c);
		int performOperation(char op, int operand1, int operand2);
	public:
		PRNCalculator();
		PRNCalculator(const PRNCalculator &other);
		~PRNCalculator();
		PRNCalculator &operator=(const PRNCalculator &other);

		int evaluate(const std::string &expr);
};