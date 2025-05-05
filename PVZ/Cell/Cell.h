#pragma once
#include "Product.h"
#include "TVector.h"
//  Copyright 2025 Shcherbakova Olesya


class Cell {
    int _num = 0;
    TVector<Product> _products;

 public:
    Cell() = default;
    Cell(const int, const TVector<Product>);
    Cell(const Cell&);
};
