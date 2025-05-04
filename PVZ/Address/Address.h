#pragma once
#include <string>
//  Copyright 2025 Shcherbakova Olesya

class Address {
    std::string _area;
    std::string _region;
    std::string _city;
    std::string _street;
    std::string _building;

public:
    Address() = default;
    Address(const std::string, const std::string, const std::string,
        const std::string, const std::string);
    Address(const Address&);

private:
    bool check_correction(const std::string);
};
