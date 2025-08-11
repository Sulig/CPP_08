/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 12:22:41 by sadoming          #+#    #+#             */
/*   Updated: 2025/08/11 17:14:13 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

// Containers
#include <vector>
#include <list>

int main()
{
	// Test with a vector
	std::vector<int> arr_i;
	arr_i.push_back(5);
	arr_i.push_back(7);
	arr_i.push_back(3);

	try {
		std::cout << *easyfind(arr_i, 7) << std::endl; // Expected -> 7
		std::cout << *easyfind(arr_i, 10) << std::endl; // Expected -> Exception
	} catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl; // Expected -> Element not found
	}
	//** */

	// Test with a list
	//** */
	std::list<int> arr_l;
	arr_l.push_back(5);
	arr_l.push_back(7);
	arr_l.push_back(3);

	try {
		std::cout << *easyfind(arr_l, 3) << std::endl; // Expected -> 3
		std::cout << *easyfind(arr_l, 10) << std::endl; // Expected -> Exception
	} catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl; // Expected -> Element not found
	}
	//********************** */
	return (0);
}
