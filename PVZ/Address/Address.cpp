#include "Address.h"
#include <string>
#include <stdexcept>
//  Copyright 2025 Shcherbakova Olesya

Address::Address(const char* area, const char* region,
const char* city, const char* street, const char* building) {
    bool area_res = check_correction(area);
	bool region_res = check_correction(region);
	bool city_res = check_correction(city);
	bool street_res = check_correction(street);
    bool building_res = check_correction(building);

    if (!(area_res && region_res && city_res &&
        street_res && building_res))
        throw std::logic_error("Unexpected symbols ");
    _area = area;
    _region = region;
    _city = city;
    _street = street;
    _building = building;
}

Address::Address(const Address& other_address) {
    if (&other_address == NULL)
        throw std::logic_error("No object ");
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
            str[i] >= 'À' && str[i] <= 'ÿ' ||
            str[i] == '¸' || str[i] == '¨') continue;
        else
            return false;
    }
    return true;
}
