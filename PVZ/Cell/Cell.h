#pragma once
//  Copyright 2025 Shcherbakova Olesya


class Cell {
    int _num = 0;
    int _sum = 0;

 public:
    Cell() = default;
    Cell(const int, const int);
    Cell(const Cell&);
};
