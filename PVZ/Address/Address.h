#pragma once
#include <string>
//  Copyright 2025 Shcherbakova Olesya

class Address {
    std::string _area;
    std::string _region;
    std::string _city;
    std::string _street;
    int _building;

 public:
    Address();
    Address(const char*, const char*, const char*, const char*, const int);
    Address(const Address&);

 private:
    bool check_correction(const std::string);
    std::string convert_to_normal_form(const std::string);
};
