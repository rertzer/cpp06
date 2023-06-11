/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <rertzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:14:33 by rertzer           #+#    #+#             */
/*   Updated: 2023/06/11 20:53:00 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int	main()
{
	std::srand(std::time(0));
	for (int i = 0; i < 12; i++)
	{
		Base * p = generate();
		identify(p);
		identify(*p);
		delete (p);
	}
		return 0;
}

