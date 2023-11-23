/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:19:50 by yowazga           #+#    #+#             */
/*   Updated: 2023/11/23 16:51:17 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <list>
#include <sys/time.h>
#include <deque>

int compares = 0;

long get_time_us();

//generate a number from jacob stahl sequence
size_t jacob_stahl[] = {2, 2, 6, 10, 22, 42, 86, 170, 342, 682, 1366,
        2730, 5462, 10922, 21846, 43690, 87382, 174762, 349526, 699050,
        1398102, 2796202, 5592406, 11184810, 22369622, 44739242, 89478486,
        178956970, 357913942, 715827882, 1431655766, 2863311530, 5726623062,
        11453246122, 22906492246, 45812984490, 91625968982, 183251937962,
        366503875926, 733007751850, 1466015503702, 2932031007402, 5864062014806,
        11728124029610, 23456248059222, 46912496118442, 93824992236886, 187649984473770,
        375299968947542, 750599937895082, 1501199875790165, 3002399751580331,
        6004799503160661, 12009599006321322, 24019198012642644, 48038396025285288,
        96076792050570576, 192153584101141152, 384307168202282304, 768614336404564608,
        1537228672809129216, 3074457345618258432, 6148914691236516864};

template <typename T>
void fille_container(char **av, T& container)
{
	for (int i = 0; av[i] != nullptr; i++)
	{
		std::istringstream iss(av[i]);
		int value;
		iss >> value;
		container.push_back(value);
	}
}
template <typename Vit>
void print_container(Vit begin, Vit end)
{
	for(Vit it = begin; it != end; it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}
template <typename Vit>
void	swap_ranges(Vit it, Vit it_end, Vit second_it)
{
	for(; it < it_end; it++, second_it++)
		std::iter_swap(it, second_it);
	std::iter_swap(it, second_it);
}

template <typename Vit>
Vit ranged_binary_search(Vit begin, Vit end, int value, size_t unit_size)
{
	size_t unit_end = unit_size - 1;
	while (begin < end)
	{
		size_t count = std::distance(begin, end) / unit_size;
		size_t mid = (count / 2);
		Vit mid_it = begin + (mid * unit_size);
		Vit mid_it_end = mid_it + unit_end;
		compares++;
		if (*mid_it_end < value)
			begin = mid_it_end + 1;
		else
			end = mid_it;
	}
	return end;
}
template <typename Vec>
void pant_to_mainchchain(Vec& pent, Vec& mainchain, Vec& mainchain_idxs, size_t unit_size, size_t idx)
{
	typedef typename Vec::iterator Vit;
	Vit it = pent.begin() + (unit_size * idx);
	Vit it_end = it + unit_size - 1;
	Vit mchain_end = mainchain.begin() + mainchain_idxs[idx];
	Vit insertion_pos = ranged_binary_search(mainchain.begin(), mchain_end, *it_end, unit_size);
	size_t insertion_idx = std::distance(mainchain.begin(), insertion_pos);
	mainchain_idxs.erase(mainchain_idxs.begin() + idx);
	for (Vit it = mainchain_idxs .begin(); it != mainchain_idxs.end(); it++)
		if ((size_t)*it >= insertion_idx)
			(*it) += unit_size;
	mainchain.insert(insertion_pos, it, it_end + 1);
	pent.erase(it, it_end + 1);
}

template <typename Vec, typename Vit>
void  ford_johnson_recursion(Vec& container, size_t pair_size, Vit end)
{
	Vit new_end = end;
	size_t unit_size = pair_size / 2;
	size_t unit_end = unit_size - 1;
	for(Vit it = container.begin(); it < end; it += pair_size)
	{
		Vit it_end = it + unit_end;
		Vit second_it = it + unit_size;
		if (second_it >= end)
		{
			new_end = it;
			break ;
		}
		Vit second_it_end = second_it + unit_end; 
		compares++;
		if (*it_end > *second_it_end)
			swap_ranges(it, it_end, second_it);
	}
	if (pair_size * 2 <= (size_t)std::distance(container.begin(), new_end))
		ford_johnson_recursion(container, pair_size * 2, new_end);
	/*--------------------------reverse recursion------------------------*/ 
	Vec mainchain;
	Vec mainchain_idxs;
	Vec pent;
	mainchain.insert(mainchain.end(), container.begin(), container.begin() + pair_size);
	for (Vit it = container.begin() + pair_size; it < end; it += pair_size)
	{
		pent.insert(pent.end(), it, it + unit_size);
		Vit second_it = it + unit_size;
		if (second_it >= end)
			break;
		mainchain_idxs.push_back(std::distance(mainchain.begin(), mainchain.end()));
		mainchain.insert(mainchain.end(), second_it, second_it + unit_size);
	}
	mainchain_idxs.push_back(std::distance(mainchain.begin(), mainchain.end()));
	container.erase(container.begin(), end);
	for (size_t i = 0; jacob_stahl[i] <= (pent.size() / unit_size); i++)
		for (long j = jacob_stahl[i] - 1; j >= 0;j--)
			pant_to_mainchchain(pent, mainchain, mainchain_idxs, unit_size, j);
	while (!pent.empty())
		pant_to_mainchchain(pent, mainchain, mainchain_idxs, unit_size, 0);
	container.insert(container.begin(), mainchain.begin(), mainchain.end());
}
template <typename Vec>
void start_container(char **av, Vec& container, std::string name, bool print = false)
{
	long start_time;
	long end_time;

	start_time = get_time_us();
	fille_container(av, container);
	compares = 0;
	ford_johnson_recursion(container, 2, container.end());
	end_time = get_time_us();
	if (print)
	{
		std::cout << "After: ";
		print_container(container.begin(), container.end());
	}
	std::cout << "Number of compares: " << compares << std::endl;
	std::cout << "Time to process a range of "
			<< container.size() << " elements with std::"
			<< name << ": " << end_time - start_time << " us" << std::endl;
}