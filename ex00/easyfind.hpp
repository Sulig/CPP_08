/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 12:22:54 by sadoming          #+#    #+#             */
/*   Updated: 2025/08/11 17:31:12 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iterator>
# include <iostream>
# include <stdexcept>

template<typename T>
/**
 * Only works with containers with iterators, like:
 *
 *	- std::vector
 *
 *	- std::list
 *
 *	- std::deque
 *
 *	- std::set
 *
 *	- std::map
 *
 * -
 * @brief Searches for an integer in a container and returns an iterator to it.
 * If the integer is not found, it throws a runtime error.
 * @param arr The container to search in.
 * @param to_find The integer to search for.
 * @return An iterator to the found integer.
 * @throws std::runtime_error if the integer is not found in the container.
 ****
 ****
 **		- Note -> the iterator don't works as an array index, it is a pointer to the element.
 *
 **		- To access the value, you need to dereference it with `*it`.
 */
typename	T::iterator easyfind(T& arr, int to_find)
{
	typename T::iterator it = std::find(arr.begin(), arr.end(), to_find);

	if (it == arr.end())
		throw std::runtime_error("Element not found");
	return it;
}

#endif
