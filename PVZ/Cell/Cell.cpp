#include "Cell.h"
#include <stdexcept>
//  Copyright 2025 Shcherbakova Olesya

Cell::Cell(const int num, const int sum): _num(num), _sum(sum) {}

Cell::Cell(const Cell& other_cell) {
	if (&other_cell == NULL)
		throw std::logic_error("No object\n");
	_num = other_cell._num;
	_sum = other_cell._sum;
}
