/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 12:22:54 by sadoming          #+#    #+#             */
/*   Updated: 2025/08/11 20:00:53 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <stdexcept>
# include <algorithm>
# include <vector>

# define INT_MAX 2147483647

class Span
{
	private:
		unsigned int	_n;
		unsigned int	_actualSize;
		std::vector<int>	_numbers;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span &other);
		~Span();

		Span &operator=(const Span &other);

		unsigned int getActualSize() const;

		void addNumber(int number);
		int shortestSpan() const;
		int longestSpan() const;

		class FullException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class NotEnoughNumbersException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

#endif
