/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:20:17 by mmarcott          #+#    #+#             */
/*   Updated: 2024/02/22 15:12:55 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib>
#include <ctime>

static Base*	generate(void) {
	srand(time(NULL));
	switch (std::rand() % 3) {
	case 1:
		std::cout << "Generated: A" << std::endl;
		return (new A());
		break;
	case 2:
		std::cout << "Generated: B" << std::endl;
		return (new B());
		break;
	case 0:
		std::cout << "Generated: C" << std::endl;
		return (new C());
		break;
	default:
		std::cout << "Generated: A" << std::endl;
		return (new A());
		break;
	}
}

static void	identify(Base* p) {
	if (A* ptr = dynamic_cast<A*>(p))
		std::cout << "Type: A" << std::endl;
	else if (B* ptr = dynamic_cast<B*>(p))
		std::cout << "Type: B" << std::endl;
	else if (C* ptr = dynamic_cast<C*>(p))
		std::cout << "Type: C" << std::endl;
	else
		std::cout << "Couldn't identify the type." << std::endl;
}

static void	identify(Base& p) {
	static int	i = 0;
	std::string	types[3] = {"A", "B", "C"};

	while (i < 3) {
		try {
			if (i == 0) {
				Base& nothing = dynamic_cast<A&>(p);
				(void)nothing;
			} else if (i == 1) {
				Base& nothingB = dynamic_cast<B&>(p);
				(void) nothingB;
			} else if (i == 2) {
				Base& nothingC = dynamic_cast<C&>(p);
				(void) nothingC;
			}
		}
		catch(const std::exception& e) {
			i++;
			identify(p);
			return ;
		}
		std::cout << "Type ref is: " << types[i] << std::endl;
		i = 0;
		break;
	}
}

int	main(void) {
	Base*	thing;

	thing = generate();
	identify(thing);
	identify(*thing);
	return (0);
}
