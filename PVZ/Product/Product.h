#pragma once
#include "Date.h"
//  Copyright 2025 Shcherbakova Olesya

class Product {
    int _code;
    int _price = 0;
    bool _prepay;
    int _age_limit = 0;  //  0 - without limit
    bool _returnability = true;
    Date _date;

 public:
     Product() = default;
     Product(const int, const int, const bool, const int,
         const bool, const Date);
     Product(const Product&);

     bool operator == (const Product&);
     bool operator != (const Product&);
     bool operator > (const Product&);
     bool operator < (const Product&);

     void set_code(const int);
     void set_date_for_return(const Date&);
};
