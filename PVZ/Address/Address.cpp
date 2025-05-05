//  -- coding: utf-8 --
#include "Address.h"
#include <string>
#include <stdexcept>
//  Copyright 2025 Shcherbakova Olesya

Address::Address() {
    _area = "Московская";
    _region = "Московский";
    _city = "Москва";
    _street = "Ленина";
    _building = 25;
}

Address::Address(const char* area, const char* region,
    const char* city, const char* street, const int building) {
    bool area_res = check_correction(area);
    bool region_res = check_correction(region);
    bool city_res = check_correction(city);
    bool street_res = check_correction(street);

    if (!(area_res && region_res && city_res && street_res))
        throw std::logic_error("Unexpected symbols ");
    _area = convert_to_normal_form(area);
    _region = convert_to_normal_form(region);
    _city = convert_to_normal_form(city);
    _street = convert_to_normal_form(street);
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

bool Address::check_correction(const std::string str) {
    int lenght = str.length();
    for (int i = 0; i < lenght; i++) {
        if (str[0] >= 'A' && str[0] <= 'Z' ||  //  A - Z
            str[i] >= 'a' && str[i] <= 'z' ||  //  a - z
            str[i] >= 'А' && str[i] <= 'Я' ||
            str[i] >= 'а' && str[i] <= 'я') continue;
        else
            return false;
    }
    return true;
}

std::string Address::convert_to_normal_form(const std::string str) {
    std::string new_str = "";
    int lenght = str.length();
    if (str[0] >= 'a' && str[0] <= 'z' ||
        str[0] >= 'а' && str[0] <= 'я')
        new_str += str[0] - 32;
    else if (str[0] == 'ё')
        new_str += 'Ё';
    else new_str += str[0];

    for (int i = 1; i < lenght; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z' ||
            str[i] >= 'А' && str[i] <= 'Я') {
            new_str += str[i] + 32;
        } else if (str[i] == 'Ё') {
            new_str += 'ё';
        } else {
            new_str += str[i];
        }
    }

    return new_str;
}
