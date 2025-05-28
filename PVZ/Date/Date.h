#pragma once
#include <string>
//  Copyright 2025 Shcherbakova Olesya

class Date {
    int _day;
    int _month;
    int _year;

 public:
     Date();
     Date(const int, const int, const int);
     Date(const std::string, const std::string);
     Date(const Date&);

     bool operator == (const Date&);
     bool operator != (const Date&);
     bool operator > (const Date&);
     bool operator < (const Date&);

     void set_day(const int);
     void set_month(const int);
     void set_year(const int);

     int get_day() const;
     int get_month() const;
     int get_year() const;

     std::string convert_to_string() const;

     bool if_leap_year(const int year);
 private:
    Date parse(const std::string, const std::string);
};
