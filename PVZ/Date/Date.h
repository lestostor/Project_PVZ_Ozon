#pragma once
//  Copyright 2025 Shcherbakova Olesya

class Date {
    int _day;
    int _month;
    int _year;

 public:
     Date();
     Date(const int, const int, const int);
     Date(const Date&);

     bool operator == (const Date&);

 private:
     bool if_leap_year(const int year);
};
