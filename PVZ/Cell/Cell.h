#pragma once
#include "Product.h"
#include "TVector.h"
#include <cmath>
//  Copyright 2025 Shcherbakova Olesya


class Cell {
    int _num = 0;  //  3 last digits of the code
    TVector<Product> _products;

 public:
    Cell() = default;
    Cell(const int, const TVector<Product>);
    Cell(const Cell&);

    bool operator == (const Cell&) const;
    bool operator != (const Cell&) const;
    bool operator > (const Cell&) const;
    bool operator < (const Cell&) const;

    void add_new_products(const Product&);
    void delete_product(const Product&);

    friend TVector<Product> get_products(const TVector<Cell>&,
        const long long int);
    friend void give_products(Cell&, TVector<Product>&);
};
