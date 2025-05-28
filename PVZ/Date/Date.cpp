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

Date::Date(const std::string date_str, const std::string format) :Date(parse(date_str,format)) {
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

std::string Date::convert_to_string() const {
    std::string date_str = "";
    if (_day < 10)
        date_str += "0" + std::to_string(_day) + '.';
    else
        date_str += std::to_string(_day) + '.';

    if (_month < 10)
        date_str += "0" + std::to_string(_month) + '.';
    else
        date_str += std::to_string(_month) + '.';

    date_str += std::to_string(_year);
    return date_str;
}

Date Date::parse(const std::string date_str, const std::string format) {
    std::string day = "", month = "", year = "";
    for (int i = 0; date_str[i] != '\0'; i++) {
        if (format[i] == 'D')
            day += date_str[i];
        else if (format[i] == 'M')
            month += date_str[i];
        else if (format[i] == 'Y')
            year += date_str[i];
        else if (date_str[i] == format[i])
            continue;
    }

    if (day[0] == '0')
        day = day[1];
    if (month[0] == '0')
        month = month[1];
    if (year.size() != 4)
        year = "20" + year;

    return Date(std::atoi(day.c_str()), std::atoi(month.c_str()),
        std::atoi(year.c_str()));
}
