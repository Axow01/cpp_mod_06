/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:41:22 by mmarcott          #+#    #+#             */
/*   Updated: 2024/02/05 12:11:59by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(const std::string data): _data(data) {}

Data::Data(const Data &copy): _data(copy._data) {
	*this = copy;
}

Data::~Data(void) {}

Data	&Data::operator=(const Data &rhs) {
	if (this != &rhs) {
		_data = rhs._data;
	}
	return (*this);
}

char	Data::toChar(void) const {
	if (_data.length() == 1)
		return (_data[0]);
	return ((char)toInt());
}

float	Data::toFloat(void) const {
	return (std::stof(_data));
}

double	Data::toDouble(void) const {
	return (std::stod(_data));
}

int	Data::toInt(void) const {
	return (std::stoi(_data));
}

std::string	Data::getData(void) const {
	return (_data);
}

void	Data::printChar(void) const {
	std::cout << "char: ";
	if (_data == "nanf" || _data == "nan" || _data == "+inf" || _data == "-inf" || _data == "+inff" || _data == "-inff")
		std::cout << "impossible" << std::endl;
	else {
		try {
			if (!isprint(toInt()))
				throw std::invalid_argument("can't be printed");
			std::cout << toChar() << std::endl;
		} catch (std::exception &e) {
			std::cout << "impossible" << std::endl;
		}
	}
}

void	Data::printInt(void) const {
	std::cout << "int: ";
	if (_data == "nanf" || _data == "nan" || _data == "+inf" || _data == "-inf" || _data == "+inff" || _data == "-inff")
		std::cout << "impossible" << std::endl;
	else {
		try {
			std::cout << toInt() << std::endl;
		} catch (std::exception &e) {
			std::cout << "impossible" << std::endl;
		}
	}
}

void	Data::printFloat(void) const {
	std::cout << "float: ";
	if (_data == "nanf" || _data == "nan")
		std::cout << "nanf" << std::endl;
	else if (_data == "+inff" || _data == "+inf")
		std::cout << "+inff" << std::endl;
	else if (_data == "-inff" || _data == "-inf")
		std::cout << "-inff" << std::endl;
	else {
		try {
			std::cout << toFloat();
			if ((float)toInt() == toFloat())
				std::cout << ".0";
			std::cout << "f" << std::endl;
		} catch (std::exception &e) {
			std::cout << "impossible" << std::endl;
		}
	}
}

void	Data::printDouble(void) const {
	std::cout << "double: ";
	if (_data == "nanf" || _data == "nan")
		std::cout << "nan" << std::endl;
	else if (_data == "+inff" || _data == "+inf")
		std::cout << "+inf" << std::endl;
	else if (_data == "-inff" || _data == "-inf")
		std::cout << "-inf" << std::endl;
	else {
		try {
			std::cout << toDouble();
			if (toDouble() == (double)toInt())
				std::cout << ".0";
			std::cout << std::endl;
		} catch (std::exception &e) {
			std::cout << "impossible" << std::endl;
		}
	}
}
