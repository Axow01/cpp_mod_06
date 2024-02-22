/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:43:35 by mmarcott          #+#    #+#             */
/*   Updated: 2024/02/22 13:56:32 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(int nb, std::string string): _nb(nb), _string(string) {}

Data::Data(const Data &copy): _nb(copy._nb), _string(copy._string) {
	*this = copy;
}

Data::~Data(void) {}

Data	&Data::operator=(const Data &rhs) {
	if (this != &rhs) {
		_nb = rhs._nb;
		_string = rhs._string;
	}
	return (*this);
}

const int	&Data::getNb(void) const {
	return (_nb);
}

const std::string	&Data::getString(void) const {
	return (_string);
}

void	Data::setNb(int nb) {
	_nb = nb;
}

void	Data::setString(std::string string) {
	_string = string;
}
