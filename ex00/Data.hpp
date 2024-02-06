/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:35:14 by mmarcott          #+#    #+#             */
/*   Updated: 2024/02/06 15:15:39 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HPP_DATA
# define HPP_DATA

# include <iostream>
# include <string>
# include <cmath>

template <typename T>
class Data {
	public:
		Data(const std::string data, T conv);
		Data(const Data &copy);
		~Data(void);

		Data	&operator=(const Data &rhs);

		std::string	getData(void) const;
		T			getConv(void) const;
	private:
		std::string	_data;
		T			_conv;
};

bool	isDouble(const std::string data);

#endif
