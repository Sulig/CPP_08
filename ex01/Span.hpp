/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 12:22:54 by sadoming          #+#    #+#             */
/*   Updated: 2025/08/12 16:10:26 by sadoming         ###   ########.fr       */
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
		std::vector<int> getActualNumbers() const;

		void addNumber(int number);
		int shortestSpan() const;
		int longestSpan() const;

		template<typename T>
		void	addRange(T &arr)
		{
			if (arr.getActualSize() > _n - _actualSize)
				throw FullException();
			_numbers.insert(_numbers.end(), arr.getActualNumbers().begin(), arr.getActualNumbers().end());
			_actualSize += arr.getActualSize();
		}

		/**/
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
