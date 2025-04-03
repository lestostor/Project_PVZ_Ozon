#include "TVector.h"
#include <iostream>
#include <cstdlib>
#include <windows.h>

void set_color(int text_color, int bg_color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bg_color << 4) | text_color);
}

namespace TestSystem {
    int count_success = 0, count_failed = 0;

    void start_test(bool(*test)(), const char* name_of_test) {
        set_color(2, 0);
        std::cout << "[ RUN      ]";
        set_color(7, 0);
        std::cout << name_of_test << std::endl;

        bool status = test();

        if (status == true) {
            set_color(2, 0);
            std::cout << "[       OK ]" << std::endl;
            count_success++;
        }
        else {
            set_color(4, 0);
            std::cout << "[  FAILED  ]" << std::endl;
            count_failed++;
        }
        set_color(7, 0);
    }

    template <class T>
    bool check(const T& expected, const T& actual) {
        if (expected == actual) {
            return true;
        }
        else {
            std::cerr << "Expected result is " << expected << ", but actual is " << actual << "." << std::endl;
            return false;
        }
    }

    void print_init_info() {
        set_color(2, 0);
        std::cout << "[==========] " << std::endl;
        set_color(7, 0);
    }

    void print_final_info() {
        set_color(2, 0);
        std::cout << "[==========] ";
        set_color(7, 0);
        std::cout << count_success + count_failed << " test" << (count_success + count_failed > 1 ? "s" : "") << " ran." << std::endl;
        set_color(2, 0);
        std::cout << "[  PASSED  ] ";
        set_color(7, 0);
        std::cout << count_success << " test" << (count_success > 1 ? "s" : "") << std::endl;
        if (count_failed > 0) {
            set_color(4, 0);
            std::cout << "[  FAILED  ] ";
            set_color(7, 0);
            std::cout << count_failed << " test" << (count_failed > 1 ? "s." : ".") << std::endl;
        }
    }
};

bool test1_try_create_empty_vector() {
    bool expected_result = true;
    bool actual_result = true;
    try {
        TVector<int> vec;
    }
    catch (const std::exception& ex) {
        actual_result = false;
        throw std::logic_error("Vector wasn't created\n");
    }

    return TestSystem::check(expected_result, actual_result);
}

bool test2_try_create_vector() {
    bool expected_result = true;
    bool actual_result = true;
    try {
        TVector<int> vec(5);
    }
    catch (const std::exception& ex) {
        actual_result = false;
        throw std::logic_error("Vector wasn't created\n");
    }

    return TestSystem::check(expected_result, actual_result);
}

bool test3_try_convert_mass_to_vector() {
    bool expected_result = true;
    bool actual_result = true;
    try {
        TVector<int> vec({ 1,2,3,4,5 });
    }
    catch (const std::exception& ex) {
        actual_result = false;
        throw std::logic_error("Vector wasn't created\n");
    }

    return TestSystem::check(expected_result, actual_result);
}

bool test4_try_copy_vector() {
    bool expected_result = true;
    bool actual_result = true;
    try {
        TVector<int> vec1(5);
        TVector<int> vec2(vec1);
    }
    catch (const std::exception& ex) {
        actual_result = false;
        throw std::logic_error("Vector wasn't created\n");
    }

    return TestSystem::check(expected_result, actual_result);
}

bool test5_try_get_size() {
    size_t expected_result = 5;
    TVector<int> vec(5);
    size_t actual_result = vec.size();

    return TestSystem::check(expected_result, actual_result);
}

bool test6_try_get_capacity() {
    size_t expected_result = 5;
    TVector<int> vec(5);
    size_t actual_result = vec.capacity();

    return TestSystem::check(expected_result, actual_result);
}

int main() {
    TestSystem::start_test(test1_try_create_empty_vector, "test1_try_create_empty_vector");
    TestSystem::start_test(test2_try_create_vector, "test2_try_create_vector");
    TestSystem::start_test(test3_try_convert_mass_to_vector, "test3_try_convert_mass_to_vector");
    TestSystem::start_test(test4_try_copy_vector, "test4_try_copy_vector");
    TestSystem::start_test(test5_try_get_size, "test5_try_get_size");
    TestSystem::start_test(test6_try_get_capacity, "test6_try_get_capacity");

    TestSystem::print_final_info();

	return 0;
}