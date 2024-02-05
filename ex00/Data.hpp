/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:35:14 by mmarcott          #+#    #+#             */
/*   Updated: 2024/02/05 12:09:28 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HPP_DATA
# define HPP_DATA

# include <iostream>
# include <string>
# include <cmath>

class Data {
	public:
		Data(const std::string data);
		Data(const Data &copy);
		~Data(void);

		Data	&operator=(const Data &rhs);

		char		toChar(void) const;
		float		toFloat(void) const;
		double		toDouble(void) const;
		int			toInt(void) const;
		void		printChar(void) const;
		void		printFloat(void) const;
		void		printDouble(void) const;
		void		printInt(void) const;
		std::string	getData(void) const;
	private:
		std::string	_data;
};

#endif
