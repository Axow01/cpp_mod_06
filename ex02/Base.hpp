/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:20:48 by mmarcott          #+#    #+#             */
/*   Updated: 2024/02/22 14:24:21 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HPP_BASE
# define HPP_BASE

# include <iostream>

class Base {
	private:
	public:
		virtual	~Base(void);
};

class A: public Base {
	private:
	public:
};

class B: public Base {
	private:
	public:
};

class C: public Base {
	private:
	public:
};

#endif
