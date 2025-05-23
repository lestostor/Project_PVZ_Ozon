#include "Date.h"
#include <stdexcept>
#include <string>
//  Copyright 2025 Shcherbakova Olesya

Date::Date() {
    _day = 1;
    _month = 1;
    _year = 2025;
}

Date::Date(const int day, const int month, const int year) {
    if (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11) ||
        day > 31 || month > 12 ||
        month == 2 && day == 29 && !if_leap_year(year))
        throw std::invalid_argument("Wrong date\n");
    _day = day;
    _month = month;
    _year = year;
}

Date::Date(const std::string& date) {
    std::string day = "", month = "", year = "";
    if (date[0] == '0') {
        day += date[1];
    } else {
        day += date[0];
        day += date[1];
    }
    if (date[3] == '0') {
        month += date[4];
    } else {
        month += date[3];
        month += date[4];
    }
    for (int i = 6; date[i] != '\0'; i++)
        year += date[i];
    _day = std::atoi(day.c_str());
    _month = std::atoi(month.c_str());
    _year = std::atoi(year.c_str());
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

bool Date::operator ==(const Date& second_date) {
    if (_day == second_date._day && _month == second_date._month &&
        _year == second_date._year) return true;
    return false;
}

bool Date::operator !=(const Date& second_date) {
    return !(*this == second_date);
}

bool Date::operator > (const Date& second_date) {
    if (this->_year > second_date._year) return true;
    else if (this->_year < second_date._year) return false;

    if (this->_month > second_date._month) return true;
    else if (this->_month < second_date._month) return false;

    if (this->_day > second_date._day) return true;
    else if (this->_day < second_date._day) return false;
}

bool Date::operator < (const Date& second_date) {
    return !(*this > second_date);
}

void Date::set_day(const int day) {
    _day = day;
}

void Date::set_month(const int month) {
    _month = month;
}

void Date::set_year(const int year) {
    _year = year;
}

int Date::get_day() const {
    return _day;
}

int Date::get_month() const {
    return _month;
}

int Date::get_year() const {
    return _year;
}
