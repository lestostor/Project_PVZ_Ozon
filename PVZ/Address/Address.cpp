#include "Address.h"
#include <string>
#include <stdexcept>
//  Copyright 2025 Shcherbakova Olesya

Address::Address(const std::string area, const std::string region,
const std::string city,const std::string street, const std::string building) {

}

Address::Address(const Address& other_address) {
	if (&other_address == NULL)
		throw std::logic_error("Нет объекта ");
	_area = other_address._area;
	_region = other_address._region;
	_city = other_address._city;
	_street = other_address._street;
	_building = other_address._building;
}

bool check_correction(const std::string str) {
	int lenght = str.length();
	for (int i = 0; i < lenght; i++) {
		if (str[0] >= 'A' && str[0] <= 'Z' ||  //  A - Z
			str[i] >= 'a' && str[i] <= 'z' ||  //  a - z
			str[i] >= 'А' && str[i] <= 'я' ||
			str[i] == 'ё' || str[i] == 'Ё') continue;
		else
			return false;
	}
	return true;
}
