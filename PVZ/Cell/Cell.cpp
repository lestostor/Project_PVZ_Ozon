#include "Cell.h"
#include <stdexcept>
//  Copyright 2025 Shcherbakova Olesya

Cell::Cell(const int num) : _num(num), _products() {}

Cell::Cell(const int num, const TVector<Product> products) :
    _num(num), _products(products) {}

Cell::Cell(const Cell& other_cell) {
    if (&other_cell == NULL)
        throw std::logic_error("No object\n");
    _num = other_cell._num;
    _products = other_cell._products;
}

void Cell::add_new_product(const Product& product) {
    _products.push_back(product);
}

void Cell::delete_product(const Product& product) {
    _products.erase(_products.begin() + find(_products, product));
}

Cell& Cell::operator = (const Cell& second_cell) {
    if (&second_cell == this)
        return *this;
    this->_num = second_cell._num;
    this->_products = second_cell._products;
    return *this;
}

bool Cell::operator == (const Cell& second_cell) const {
    if (this->_num == second_cell._num) return true;
    return false;
}

bool Cell::operator != (const Cell& second_cell) const {
    return !(*this == second_cell);
}

bool Cell::operator > (const Cell& second_cell) const {
    if (this->_num > second_cell._num) return true;
    return false;
}

bool Cell::operator < (const Cell& second_cell) const {
    return !(*this > second_cell);
}

TVector<Product> Cell::get_products() {
    return _products;
}

TVector<Product>& get_products_by_code(const TVector<Cell>& cells,
    const int64_t code) {
    int number = code % 1000;
    int64_t x = pow(10, 12);
    if (code / x > 9 || number > cells.size() ||
        cells[number - 1]._products.size() == 0 || code / x == 0)
        throw std::logic_error("Product isn't found");

    return cells[number - 1]._products;
}

void give_products(Cell& cell, TVector<Product>& products,
    const int code, const Date today) {
    for (int i = 0; i < products.size(); i++) {
        cell.delete_product(products[i]);
        products[i].set_code(code);
        products[i].set_date_for_return(today);
    }
}

void return_products(Cell& cell, TVector<Product>& products) {
    for (int i = 0; i < products.size(); i++)
        cell.delete_product(products[i]);
}
