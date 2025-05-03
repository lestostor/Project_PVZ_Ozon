#include "Address.h"
#include <string>
#include <stdexcept>
//  Copyright 2025 Shcherbakova Olesya

Address::Address(const std::string area, const std::string region,
	const std::string city,const std::string street, const std::string building) :
_area(area), _region(region), _city(city), _street(street), _building(building)
{}

Address::Address(const Address& other_address) {
	if (&other_address == NULL)
		throw std::logic_error("Нет объекта ");
	_area = other_address._area;
	_region = other_address._region;
	_city = other_address._city;
	_street = other_address._street;
	_building = other_address._building;
}
