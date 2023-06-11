/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <rertzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 19:57:19 by rertzer           #+#    #+#             */
/*   Updated: 2023/06/11 20:51:54 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base *	generate(void)
{
	Base *	p;
	int		i = std::rand();
	if (i % 3 == 0)
	{
		p = new A();
		std::cout << "generated an A object\n";
	}
	else if (i % 3 == 1)
	{
		p = new B();
		std::cout << "generated an B object\n";
	}
	else
	{
		p = new C();
		std::cout << "generated an C object\n";
	}
	return p;
}

void	identify(Base * p)
{
	A* pa = dynamic_cast<A*>(p);
	B* pb = dynamic_cast<B*>(p);
	C* pc = dynamic_cast<C*>(p);
	if (pa != 0)
		std::cout << p << " is a A pointer\n";
	else if (pb != 0)
		std::cout << p << " is a B pointer\n";
	else if (pc != 0)
		std::cout << p << " is a C pointer\n";
	else
		std::cout << "Oups! something got wrong\n";
}

void	identify(Base & p)
{
	try
	{
		A & ra = dynamic_cast<A&>(p);
		std::cout << &ra << " is a A reference\n";
	}
	catch (std::exception & bc)
	{
	}
	try
	{
		B & rb = dynamic_cast<B&>(p);
		std::cout << &rb << " is a B reference\n";
	}
	catch (std::exception & bc)
	{
	}
	try
	{
		C & rc = dynamic_cast<C&>(p);
		std::cout << &rc << " is a C reference\n";
	}
	catch (std::exception & bc)
	{
	}
}
