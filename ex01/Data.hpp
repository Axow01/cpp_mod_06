/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:43:44 by mmarcott          #+#    #+#             */
/*   Updated: 2024/02/22 13:51:10 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HPP_DATA
# define HPP_DATA

# include <iostream>

class Data {
	private:
		int			_nb;
		std::string	_string;
	public:
		Data(int nb, std::string string);
		Data(const Data &copy);
		~Data(void);

		Data	&operator=(const Data &rhs);

		const int			&getNb(void) const;
		const std::string	&getString(void) const;
		void				setNb(int nb);
		void				setString(std::string string);
};

#endif
