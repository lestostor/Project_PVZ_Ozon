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

bool Product::operator!=(const Product& second_product) {
    return !(*this == second_product);
}

bool Product::operator >(const Product& second_product) {
    if (this->_date > second_product._date) return true;
    return false;
}

bool Product::operator <(const Product& second_product) {
    return !(*this > second_product);
}

void Product::set_code(const int code) {
    _code = code;
}

void Product::set_date_for_return(const Date& today) {
    int day = today.get_day(),
        month = today.get_month(),
        year = today.get_year();
    if ((month == 1 || month == 3 || month == 5 || month == 7 ||
        month == 8 || month == 10 || month == 12) && day + 7 > 31) {
        _date.set_day(7 - (31 - day));
        if (month + 1 > 12) {
            _date.set_month(1);
            _date.set_year(year + 1);
        } else {
            _date.set_month(month + 1);
        }
    } else if ((month == 4 || month == 6 || month == 9 || month == 11 &&
        day + 7 <= 30)) {
        _date.set_day(7 - (30 - day));
        _date.set_month(month + 1);
    } else if (month == 2 && _date.if_leap_year(year) && day + 7 > 29) {
        _date.set_day(7 - (29 - day));
        _date.set_month(month + 1);
    } else if (month == 2 && !_date.if_leap_year(year) && day + 7 > 28) {
        _date.set_day(7 - (28 - day));
        _date.set_month(month + 1);
    } else {
        _date.set_day(day + 7);
        _date.set_month(month);
        _date.set_year(year);
    }
}
