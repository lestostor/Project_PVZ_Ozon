#include "Date.h"
#include <stdexcept>
//  Copyright 2025 Shcherbakova Olesya

Date::Date() {
    _day = 1;
    _month = 1;
    _year = 2025;
}

Date::Date(const int day, const int month, const int year) {
    if (day > 30 || month > 12 ||
        month == 2 && day == 29 && !if_leap_year(year))
        throw std::invalid_argument("Wrong date\n");
    _day = day;
    _month = month;
    _year = year;
}

Date::Date(const Date& other_date) {
    if (&other_date == NULL)
        throw std::logic_error("No object\n");
    _day = other_date._day;
    _month = other_date._month;
    _year = other_date._year;
}

bool Date::if_leap_year(const int year) {
    if (year % 4 == 0 || year % 4 == 0 && year % 100 != 0 ||
        year % 400 == 0) return true;
    return false;
}

bool Date::operator==(const Date& second_date) {
    if (_day == second_date._day && _month == second_date._month &&
        _year == second_date._year) return true;
    return false;
}
