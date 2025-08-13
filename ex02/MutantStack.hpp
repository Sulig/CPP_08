/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:32:39 by sadoming          #+#    #+#             */
/*   Updated: 2025/08/13 19:04:43 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		MutantStack() : std::stack<T>() {}
		MutantStack(const MutantStack &other) : std::stack<T>(other) {}
		~MutantStack() {}

		MutantStack &operator=(const MutantStack &other)
		{
			if (this != &other)
				std::stack<T>::operator=(other);
			return *this;
		}

		// Iterators
		/* Using member `c` of stack to recreate iterators function */
		iterator begin() { return this->c.begin(); }
		const_iterator begin() const { return this->c.begin(); }

		iterator end() { return this->c.end(); }
		const_iterator end() const { return this->c.end(); }

		// Reverse iterators
		reverse_iterator rbegin() { return this->c.rbegin(); }
		const_reverse_iterator rbegin() const { return this->c.rbegin(); }

		reverse_iterator rend() { return this->c.rend(); }
		const_reverse_iterator rend() const { return this->c.rend(); }
};

#endif
