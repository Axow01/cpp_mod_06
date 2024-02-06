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

bool	isDouble(const std::string data) {
	bool	foundPoint = false;

	for (int i = 0; data[i]; i++) {
		if (data[i] == '.')
			foundPoint = true;
		if (!isnumber(data[i]) && !(i > 0 && data[i] == '.'))
			return (false);
	}
	if (foundPoint)
		return (true);
	return (false);
}

template <typename T>
Data<T>::Data(const std::string data, T conv): _data(data), _conv(conv) {}

template <typename T>
Data<T>::Data(const Data &copy): _data(copy._data), _conv(copy._conv) {
	*this = copy;
}

template <typename T>
Data<T>::~Data(void) {}

template <typename T>
Data<T>	&Data<T>::operator=(const Data &rhs) {
	if (this != &rhs) {
		_data = rhs._data;
		_conv = rhs._conv;
	}
	return (*this);
}

template <typename T>
std::string	Data<T>::getData(void) const {
	return (_data);
}

template <typename T>
T	Data<T>::getConv(void) const {
	return (_conv);
}
