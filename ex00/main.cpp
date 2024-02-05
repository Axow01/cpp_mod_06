/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:00:35 by mmarcott          #+#    #+#             */
/*   Updated: 2024/02/05 12:52:10 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

static bool	checkArgs(int ac, char **av) {
	if (ac > 2) {
		std::cerr << "Too much arguments!" << std::endl;
		return (false);
	} else if (ac == 1) {
		std::cerr << "Not enough arguments!" << std::endl;
		return (false);
	} else if (av[1] == 0 || av[1][0] == 0)
		return (false);
	return (true);
}

static bool	printResult(Data &data) {
	data.printChar();
	data.printInt();
	data.printFloat();
	data.printDouble();
	return (true);
}

int	main(int argc, char **argv) {
	if (!checkArgs(argc, argv))
		return (1);
	Data data(argv[1]);
	printResult(data);
	return (0);
}
