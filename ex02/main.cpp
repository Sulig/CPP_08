/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:45:00 by sadoming          #+#    #+#             */
/*   Updated: 2025/08/13 19:10:46 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

void test()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}
/**///* */

void myTest()
{
	MutantStack<int> mstack;
	mstack.push(1);
	mstack.push(2);
	mstack.push(3);
	mstack.push(4);
	mstack.push(5);

	MutantStack<int> mstack2(mstack); // Copy constructor
	mstack2.push(6); // Modify the copy

	std::cout << "Iterating through MutantStack:" << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "Reverse Iterating through MutantStack:" << std::endl;
	for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
		std::cout << *rit << " ";
	std::cout << std::endl;

	std::cout << "Size of mstack: " << mstack.size() << std::endl;
	std::cout << "Size of mstack2: " << mstack2.size() << std::endl;
	std::cout << "Top element of mstack: " << mstack.top() << std::endl;
	std::cout << "Top element of mstack2: " << mstack2.top() << std::endl;
}

int main()
{
	std::cout << "Testing MutantStack with subject test function ->" << std::endl;
	test();
	std::cout << "Testing MutantStack with custom test function ->" << std::endl;
	myTest();
	return 0;
}
