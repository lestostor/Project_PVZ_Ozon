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
    explicit Cell(const int);
    Cell(const int, const TVector<Product>);
    Cell(const Cell&);

    Cell& operator = (const Cell&);
    bool operator == (const Cell&) const;
    bool operator != (const Cell&) const;
    bool operator > (const Cell&) const;
    bool operator < (const Cell&) const;

    TVector<Product> get_products();

    void add_new_product(const Product&);
    void delete_product(const Product&);

    friend TVector<Product> get_products_by_code(const TVector<Cell>&,
        const long long int);
    friend void give_products(Cell&, TVector<Product>&, const int, const Date);
    friend void return_products(Cell&, TVector<Product>&);
};
