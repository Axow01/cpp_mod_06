/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:43:18 by mmarcott          #+#    #+#             */
/*   Updated: 2024/02/22 13:58:53by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <cstdint>

static uintptr_t	serialize(Data *ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

static Data	*deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}

int	main(void) {
	Data		testData(10, "This is a string!");
	uintptr_t	raw;
	Data*		dData;

	std::cout << testData.getNb() << " " << testData.getString() << std::endl;
	raw = serialize(&testData);
	std::cout << "Serialized Data raw: " << raw << std::endl;
	dData = deserialize(raw);
	std::cout << "Deserialized data int: " << dData->getNb() << " string: " << dData->getString() << std::endl;
	std::cout << "testData: " << &testData << " dData: " << dData << std::endl;
	return (0);
}
