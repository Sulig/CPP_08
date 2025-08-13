/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:56:08 by sadoming          #+#    #+#             */
/*   Updated: 2025/08/13 16:41:29 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

int main()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	// Exception FullException test ->
	try {
		sp.addNumber(5); // This will throw an exception because the span is full
	} catch (const Span::FullException &e) {
		std::cerr << e.what() << std::endl;
	}

	// Execption NotEnoughNumbers test ->
	try {
		Span sp2 = Span(2);
		sp2.addNumber(1);
		std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
	} catch (const Span::NotEnoughNumbersException &e) {
		std::cerr << e.what() << std::endl;
	}

	// addRange test ->
	std::cout << "Testing addRange:" << std::endl;
	Span sp3 = Span(10);
	sp3.addNumber(1);
	try { sp3.addRange(sp); }
	catch (const Span::FullException &e) {
		std::cerr << e.what() << std::endl;
		//should't have to arrive here, but maybe can be a memory error.
	}

	for (unsigned int num = 0; num < sp3.getActualSize(); num++)
		std::cout << sp3.getActualNumbers()[num] << " ";
	std::cout << std::endl;
	//** */

	// test with more than 10000 nums!
	std::cout << "Testing with more than 10000 numbers:" << std::endl;
	Span sp4 = Span(10000);
	for (int i = 0; i < 10000; i++)
		sp4.addNumber(rand() % 100000);

	/*
	{
		for (unsigned int num = 0; num < sp4.getActualSize(); num++)
			std::cout << sp4.getActualNumbers()[num] << " ";
		std::cout << std::endl;
	}
	*/
	std::cout << "Shortest span: " << sp4.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp4.longestSpan() << std::endl;

	return 0;
}
