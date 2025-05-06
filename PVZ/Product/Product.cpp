#include "Product.h"
#include <stdexcept>
//  Copyright 2025 Shcherbakova Olesya

Product::Product(const int code, const int price, const bool prepay,
const int limit, const bool returnability, const Date date) :
_code(code), _price(price), _prepay(prepay), _age_limit(limit),
_returnability(returnability), _date(date) {}

Product::Product(const Product& other_product) {
    if (&other_product == NULL)
        throw std::logic_error("No object\n");
    _code = other_product._code;
    _price = other_product._price;
    _prepay = other_product._prepay;
    _age_limit = other_product._age_limit;
    _returnability = other_product._returnability;
    _date = other_product._date;
}

bool Product::operator==(const Product& second_product) {
    if (_code == second_product._code && _price == second_product._price &&
        _age_limit == second_product._age_limit && _returnability ==
        second_product._returnability && _date == second_product._date)
        return true;
    return false;
}