/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:00:35 by mmarcott          #+#    #+#             */
/*   Updated: 2024/02/27 15:46:00 by mmarcott         ###   ########.fr       */
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

template <typename T>
static void	printThings(T conv){
	if (std::is_same<T, bool>::value) {
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "impossible" << std::endl;
		std::cout << "double: " << "impossible" << std::endl;
		return ;
	}
	char	character = (char)conv;
	int		integer = (int)conv;
	float	floatingP = (float)conv;
	double	doubleN = (double)conv;

	if (isprint(character) && (double)conv <= std::numeric_limits<char>::max() && (double)conv >= std::numeric_limits<char>::min())
		std::cout << "char: " << character << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if ((double)conv > std::numeric_limits<int>::max() || (double)conv < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << integer << std::endl;
	std::cout.setf(std::ios::fixed, std::ios::floatfield);
	std::cout.precision(1);
	if (((double)conv <= std::numeric_limits<float>::max() && (double)conv >= std::numeric_limits<float>::min()) || (double)conv == 0)
		std::cout << "float: " << floatingP << "f" << std::endl;
	else
		std::cout << "float: impossible" << std::endl;
	std::cout << "double: " << doubleN << std::endl;
}

static int	getType(std::string data) {
	if (data.length() == 1 && isprint(data[0]) && !isdigit(data[0]))
		return (0);
	else if (data.back() == 'f' && isnumber(data[0]))
		return (1);
	else if (isDouble(data))
		return (2);
	else {
		return (3);
	}
}

static void	specialNeedsHelmets(std::string data) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (data == "+inf" || data == "+inff") {
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (data == "-inf" || data == "-inff") {
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else if (data == "nan" || data == "nanf") {
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
}

int	main(int argc, char **argv) {
	if (!checkArgs(argc, argv))
		return (1);
	std::string	data = argv[1];
	if (data == "+inf" || data == "+inff" || data == "-inf" || data == "-inff" || data == "nan" || data == "nanf") {
		specialNeedsHelmets(data);
		return (0);
	}
	try {
		switch (getType(data)) {
			case 0:
				printThings<char>(data[0]);
				break;
			case 1:
				printThings<float>(std::stof(data));
				break;
			case 2:
				printThings<double>(std::stod(data));
				break;
			case 3:
				printThings<int>(std::stoi(data));
				break;
		}
	} catch (std::exception &e) {
		printThings<bool>(false);
	}
	return (0);
}
