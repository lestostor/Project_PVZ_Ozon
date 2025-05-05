#include "FIO.h"
#include <iostream>
#include <stdexcept>
#include <string>
//  Copyright 2025 Shcherbakova Olesya

FIO::FIO(const std::string fname, const std::string sname,
    const std::string lname) {
    if (!(check_name(fname) && check_name(sname) && check_name(lname)))
        throw std::logic_error("Unexpected symbols\n");

    _name = convert_to_normal_form(fname);
    _surname = convert_to_normal_form(sname);
    _patronymic = convert_to_normal_form(lname);
}

FIO::FIO() {
    std::string default_fname = "Иван",
        default_sname = "Иванов",
        default_lname = "Иванович";

    _name = default_fname;
    _surname = default_sname;
    _patronymic = default_lname;
}

FIO::FIO(const FIO& original) {
    if (&original == NULL)
        throw std::logic_error("No object\n");
    _name = original._name;
    _surname = original._surname;
    _patronymic = original._patronymic;
}

const std::string FIO::get_first_name() {
    return _name;
}

const std::string FIO::get_second_name() {
    return _surname;
}

const std::string FIO::get_last_name() {
    return _patronymic;
}

void FIO::set_first_name(const std::string fname) {
    if (!check_name(fname))
        throw std::logic_error("Unexpected symbols\n");
    _name = convert_to_normal_form(fname);
}

void FIO::set_second_name(const std::string sname) {
    if (!check_name(sname))
        throw std::logic_error("Unexpected symbols\n");
    _surname = convert_to_normal_form(sname);
}

void FIO::set_last_name(const std::string lname) {
    if (check_name(lname))
        throw std::logic_error("Unexpected symbols\n");
    _patronymic = convert_to_normal_form(lname);
}

bool FIO::check_name(const std::string name) {
    int lenght = name.length();
    return check_corrections(name, lenght);
}

bool FIO::check_corrections(const std::string str, int lenght) {
    for (int i = 0; i < lenght; i++) {
        if (str[0] >= 'A' && str[0] <= 'Z' ||  //  A - Z
            str[i] >= 'a' && str[i] <= 'z' ||  //  a - z
            str[i] >= 'А' && str[i] <= 'Я' ||
            str[i] >= 'а' && str[i] <= 'я') continue;
        else
            return false;
    }
    return true;
}

std::string FIO::convert_to_normal_form(const std::string str) {
    std::string new_str = "";
    int lenght = str.length();
    if (str[0] >= 'a' && str[0] <= 'z' ||
        str[0] >= 'а' && str[0] <= 'я')
        new_str += str[0] - 32;
    else if (str[0] == 'ё')
        new_str += 'Ё';
    else new_str += str[0];

    for (int i = 1; i < lenght; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z' ||
            str[i] >= 'А' && str[i] <= 'Я') {
            new_str += str[i] + 32;
        } else if (str[i] == 'Ё') {
            new_str += 'ё';
        } else {
            new_str += str[i];
        }
    }

    return new_str;
}
