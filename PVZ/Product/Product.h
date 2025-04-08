#pragma once
#include "Date.h"
//  Copyright 2025 Shcherbakova Olesya


class Product {
    int _code;  //код
    int _price;  //цена
    bool _prepay;  //предоплата
    int _age_limit = 0;  //возрастное ограничение (0 - без ограничений)
    bool _returnability = true;
    Date _date;
};
