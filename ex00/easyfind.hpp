/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:26:20 by sadoming          #+#    #+#             */
/*   Updated: 2025/07/30 16:27:53 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <vector>

#include <array>
#include <iostream>

template <typename T>
typename T::iterator easyfind(T &container, int to_find)
{
	return std::find(container.begin(), container.end(), to_find);
}

#endif
