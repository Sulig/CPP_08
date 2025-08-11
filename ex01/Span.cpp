/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:59:45 by sadoming          #+#    #+#             */
/*   Updated: 2025/08/11 20:17:16 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* Constructor & destructor */
Span::Span() : _n(0), _actualSize(0) {}
Span::Span(unsigned int n) : _n(n), _actualSize(0) { _numbers.reserve(n); }
Span::Span(const Span &other) : _n(other._n), _actualSize(other._actualSize), _numbers(other._numbers) {}
Span::~Span() { _numbers.clear(); }
/* ----- */

/* Operator overloads */
Span &Span::operator=(const Span &other) {
	if (this != &other) {
		_n = other._n;
		_actualSize = other._actualSize;
		_numbers = other._numbers;
	}
	return (*this);
}
/* ----- */

/* ----- */
unsigned int Span::getActualSize() const { return (_actualSize); }
/* ----- */

/* Exceptions thowers */
const char	*Span::FullException::what() const throw()
{
	return ("Span is full, cannot add more numbers");
}

const char	*Span::NotEnoughNumbersException ::what() const throw()
{
	return ("Span does not have enough numbers to calculate the span");
}
/* ----- */

/* Functions	*/
void Span::addNumber(int number) {
	if (_actualSize >= _n)
		throw FullException();
	_numbers.push_back(number);
	_actualSize++;
}


int Span::shortestSpan() const {
	if (_actualSize < 2)
		throw NotEnoughNumbersException();
	std::vector<int> sortedNumbers = _numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	int minSpan = INT_MAX;
	for (size_t i = 1; i < sortedNumbers.size(); ++i) {
		int span = sortedNumbers[i] - sortedNumbers[i - 1];
		if (span < minSpan)
			minSpan = span;
	}
	return (minSpan);
}

int Span::longestSpan() const {
	if (_actualSize < 2)
		throw NotEnoughNumbersException();
	std::vector<int> sortedNumbers = _numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	return (sortedNumbers.back() - sortedNumbers.front());
}
/* ----- */
