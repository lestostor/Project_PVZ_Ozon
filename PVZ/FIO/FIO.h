#pragma once
#include <string>
//  Copyright 2025 Shcherbakova Olesya

class FIO {
    std::string _name;
    std::string _surname;
    std::string _patronymic;
 public:
    FIO(const std::string, const std::string, const std::string);
    FIO();
    FIO(const FIO& original);

    const std::string get_first_name();
    const std::string get_second_name();
    const std::string get_last_name();

    void set_first_name(const std::string);
    void set_second_name(const std::string);
    void set_last_name(const std::string);
 private:
    bool check_name(const std::string);
    bool check_corrections(const std::string, int lenght);
    std::string convert_to_normal_form(const std::string);
};
