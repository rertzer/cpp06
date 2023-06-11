/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <rertzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 19:51:26 by rertzer           #+#    #+#             */
/*   Updated: 2023/06/11 20:42:11 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_H
# define BASE_H

# include <iostream>
# include <exception>
# include <cstdlib>
# include <ctime>

class	Base
{
	public:
		virtual	~Base(){};
};


class	A: public Base
{};

class	B: public Base
{};

class	C: public Base
{};

Base *	generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif
