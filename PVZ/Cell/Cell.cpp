#include "Cell.h"
#include <stdexcept>
//  Copyright 2025 Shcherbakova Olesya

Cell::Cell(const int num, const TVector<Product> products) :
    _num(num), _products(products) {}

Cell::Cell(const Cell& other_cell) {
    if (&other_cell == NULL)
        throw std::logic_error("No object\n");
    _num = other_cell._num;
    _products = other_cell._products;
}

void Cell::add_new_products(const Product& product) {
    _products.push_back(product);
}

void Cell::delete_product(const Product& product) {
    _products.erase(_products.begin() + find(_products, product));
}
