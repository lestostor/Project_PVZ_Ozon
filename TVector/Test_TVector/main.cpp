#include "TVector.h"
#include <iostream>
#include <cstdlib>
#include <iterator>
#include <Windows.h>
//  Copyright 2025 Shcherbakova Olesya

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
    } else {
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
    } else {
        std::cerr << "Expected result is " << expected <<
            ", but actual is " << actual << "." << std::endl;
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
    std::cout << count_success + count_failed << " test" <<
    (count_success + count_failed > 1 ? "s" : "") << " ran." << std::endl;
    set_color(2, 0);
    std::cout << "[  PASSED  ] ";
    set_color(7, 0);
    std::cout << count_success << " test" <<
        (count_success > 1 ? "s" : "") << std::endl;
    if (count_failed > 0) {
        set_color(4, 0);
        std::cout << "[  FAILED  ] ";
        set_color(7, 0);
        std::cout << count_failed << " test" <<
            (count_failed > 1 ? "s." : ".") << std::endl;
    }
}
};  // namespace TestSystem

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
        TVector<int> vec({ 1, 2, 3, 4, 5 });
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
    size_t expected_result = 15;
    TVector<int> vec(5);
    size_t actual_result = vec.capacity();

    return TestSystem::check(expected_result, actual_result);
}

bool test7_try_get_data() {
    int* expected_result = new int[5];
    for (int i = 0; i < 5; i++) expected_result[i] = i + 1;
    TVector<int> vec({ 1, 2, 3, 4, 5 });
    int* actual_result = vec.data();

    for (int i = 0; i < 5; i++) {
        if (!TestSystem::check(expected_result[i], actual_result[i]))
            return false;
    }
    return true;
}

bool test8_try_get_iterator_begin() {
    TVector<int> vec({ 1, 2, 3, 4, 5 });
    int mass[5] = { 1, 2, 3, 4, 5 };
    int* expected_result = std::begin(mass);
    int* actual_result = vec.begin();

    return TestSystem::check(*expected_result, *actual_result);
}

bool test9_try_get_iterator_end() {
    TVector<int> vec({ 1, 2, 3, 4, 5 });
    int mass[5] = { 1, 2, 3, 4, 5 };
    int* expected_result = std::end(mass) - 1;
    int* actual_result = vec.end() - 1;

    return TestSystem::check(*expected_result, *actual_result);
}

bool test10_try_get_front() {
    TVector<int> vec({ 1, 2, 3, 4, 5 });
    int expected_result = 1;
    int actual_result = vec.front();

    return TestSystem::check(expected_result, actual_result);
}

bool test11_try_get_back() {
    TVector<int> vec({ 1, 2, 3, 4, 5 });
    int expected_result = 5;
    int actual_result = vec.back();

    return TestSystem::check(expected_result, actual_result);
}

bool test12_try_check_is_empty_if_full() {
    TVector<int> vec({ 1, 2, 3, 4, 5 });
    bool expected_result = false;
    bool actual_result = vec.is_empty();

    return TestSystem::check(expected_result, actual_result);
}

bool test13_try_check_is_empty_if_empty() {
    TVector<int> vec;
    bool expected_result = true;
    bool actual_result = vec.is_empty();

    return TestSystem::check(expected_result, actual_result);
}

bool test14_try_clear_vector() {
    TVector<int> vec({ 1, 2, 3, 4, 5 });
    bool expected_result = true;
    vec.clear();
    bool actual_result = vec.is_empty();

    return TestSystem::check(expected_result, actual_result);
}

bool test15_try_push_back() {
    TVector<int> vec({ 1, 2, 3, 4, 5 });
    int expected_result = 6;
    vec.push_back(6);
    int actual_result = *(vec.end() - 1);

    return TestSystem::check(expected_result, actual_result);
}

bool test16_try_push_back_with_reset_memory() {
    TVector<int> vec({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 });
    int expected_result = 15;
    vec.push_back(15);
    int actual_result = *(vec.end() - 1);

    return TestSystem::check(expected_result, actual_result);
}

bool test17_try_push_front() {
    TVector<int> vec({ 2, 3, 4, 5 });
    int expected_result = 1;
    vec.push_front(1);
    int actual_result = *(vec.begin());

    return TestSystem::check(expected_result, actual_result);
}

bool test18_try_push_front_with_reset_memory() {
    TVector<int> vec({ 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 });
    int expected_result = 1;
    vec.push_front(1);
    int actual_result = *(vec.begin());

    return TestSystem::check(expected_result, actual_result);
}

bool test19_try_pop_back() {
    TVector<int> vec({ 1, 2, 3, 4, 5 });
    int expected_result = 4;
    vec.pop_back();
    int actual_result = *(vec.end() - 1);

    return TestSystem::check(expected_result, actual_result);
}

bool test20_try_pop_back_without_reset_memory() {
    TVector<int> vec({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 });
    int expected_result = 14;
    vec.pop_back();
    int actual_result = *(vec.end() - 1);

    return TestSystem::check(expected_result, actual_result);
}

bool test21_try_pop_front() {
    TVector<int> vec({ 1, 2, 3, 4, 5 });
    int expected_result = 2;
    vec.pop_front();
    int actual_result = *(vec.begin());

    return TestSystem::check(expected_result, actual_result);
}

bool test22_try_pop_front_without_reset_memory() {
    TVector<int> vec({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 });
    int expected_result = 2;
    vec.pop_front();
    int actual_result = *(vec.begin());

    return TestSystem::check(expected_result, actual_result);
}

bool test23_try_push_back_after_pop_front() {
    TVector<int> vec({ 1, 2, 3, 4 });
    int expected_result = 5;
    vec.pop_front();
    vec.push_back(5);
    int actual_result = *(vec.end() - 1);

    return TestSystem::check(expected_result, actual_result);
}

bool test24_try_push_front_after_pop_back() {
    TVector<int> vec({ 2, 3, 4, 5 });
    int expected_result = 1;
    vec.pop_back();
    vec.push_front(1);
    int actual_result = *(vec.begin());

    return TestSystem::check(expected_result, actual_result);
}

bool test25_try_erase_elem() {
    TVector<int> vec({ 1, 2, 3, 4, 5 });
    int expected_result = 4;
    vec.erase(vec.begin() + 2);
    int actual_result = *(vec.begin() + 2);

    return TestSystem::check(expected_result, actual_result);
}

bool test26_try_erase_elem_without_reset_memory() {
    TVector<int> vec({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 });
    int expected_result = 14;
    vec.erase(vec.begin() + 2);
    int actual_result = vec.size();

    return TestSystem::check(expected_result, actual_result);
}

bool test27_try_push_back_after_erase() {
    TVector<int> vec({ 1, 2, 3, 4, 5 });
    int expected_result = 6;
    vec.erase(vec.begin() + 1);
    vec.push_back(6);
    int actual_result = vec.back();

    return TestSystem::check(expected_result, actual_result);
}

bool test28_try_push_front_after_erase() {
    TVector<int> vec({ 1, 2, 3, 4, 5 });
    int expected_result = 0;
    vec.erase(vec.begin() + 1);
    vec.push_front(0);
    int actual_result = vec.front();

    return TestSystem::check(expected_result, actual_result);
}

bool test29_try_push_back_after_erase_without_reset_mem() {
    TVector<int> vec({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 });
    int expected_result = 16;
    vec.erase(vec.begin() + 2);
    vec.push_back(16);
    int actual_result = vec.back();

    return TestSystem::check(expected_result, actual_result);
}

bool test30_try_insert() {
    TVector<int> vec({ 1, 2, 4, 5 });
    int expected_result = 3;
    vec.insert(vec.begin() + 2, 3);
    int actual_result = *(vec.begin() + 2);

    return TestSystem::check(expected_result, actual_result);
}

bool test31_try_insert_with_reset_capacity() {
    TVector<int> vec({ 1, 2, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 });
    int expected_result = 30;
    vec.insert(vec.begin() + 2, 3);
    int actual_result = vec.capacity();

    return TestSystem::check(expected_result, actual_result);
}

bool test32_try_insert_after_pop_front() {
    TVector<int> vec({ 1, 2, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 });
    int expected_result = 3;
    vec.pop_front();
    vec.insert(vec.begin() + 1, 3);
    int actual_result = *(vec.begin() + 1);

    return TestSystem::check(expected_result, actual_result);
}

bool test33_try_insert_after_erase() {
    TVector<int> vec({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 });
    int expected_result = 3;
    vec.erase(vec.begin() + 1);
    vec.insert(vec.begin() + 3, 3);
    int actual_result = *(vec.begin() + 4);  // +1 - without override

    return TestSystem::check(expected_result, actual_result);
}

bool test34_try_find_elem() {
    TVector<int> vec({ 1, 2, 2, 3, 4 });
    int expected_result = 1;
    int actual_result = find(vec, 2);

    return TestSystem::check(expected_result, actual_result);
}

bool test35_try_find_non_existent_elem() {
    TVector<int> vec({ 1, 2, 3, 4, 5 });
    int expected_result = -1;
    int actual_result = find(vec, 6);

    return TestSystem::check(expected_result, actual_result);
}

bool test36_try_find_elem_after_erase() {
    TVector<int> vec({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 });
    int expected_result = 3;
    vec.erase(vec.begin() + 2);
    int actual_result = find(vec, 5);

    return TestSystem::check(expected_result, actual_result);
}

bool test37_try_find_elem_after_insert() {
    TVector<int> vec({ 1, 2, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 });
    int expected_result = 2;
    vec.insert(vec.begin() + 2, 3);
    int actual_result = find(vec, 3);

    return TestSystem::check(expected_result, actual_result);
}

bool test38_try_find_deleted_elem() {
    TVector<int> vec({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 });
    int expected_result = -1;
    vec.erase(vec.begin() + 2);
    int actual_result = find(vec, 3);

    return TestSystem::check(expected_result, actual_result);
}

bool test39_try_find_last_elem() {
    TVector<int> vec({ 1, 2, 2, 3, 4 });
    int expected_result = 2;
    int actual_result = find_last(vec, 2);

    return TestSystem::check(expected_result, actual_result);
}

bool test40_try_find_non_existent_last_elem() {
    TVector<int> vec({ 1, 2, 2, 3, 4 });
    int expected_result = -1;
    int actual_result = find_last(vec, 5);

    return TestSystem::check(expected_result, actual_result);
}

bool test41_try_find_last_elem_after_erase() {
    TVector<int> vec({ 1, 2, 3, 4, 5, 5, 7, 8, 9, 10, 11, 12, 13, 14, 15 });
    int expected_result = 4;
    vec.erase(vec.begin() + 5);
    int actual_result = find_last(vec, 5);

    return TestSystem::check(expected_result, actual_result);
}

bool test42_try_find_last_elem_after_insert() {
    TVector<int> vec({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 });
    int expected_result = 3;
    vec.insert(vec.begin() + 2, 3);
    int actual_result = find_last(vec, 3);

    return TestSystem::check(expected_result, actual_result);
}

bool test43_try_find_last_deleted_elem() {
    TVector<int> vec({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 });
    int expected_result = -1;
    vec.erase(vec.begin() + 2);
    int actual_result = find_last(vec, 3);

    return TestSystem::check(expected_result, actual_result);
}

bool test44_try_find_all_elems() {
    TVector<int> vec({ 1, 2, 3, 2, 4, 2 });
    int* expected_result = new int[3];
    for (int i = 0; i < 3; i++)
        expected_result[i] = 2 * i + 1;
    int* actual_result = find_all(vec, 2);

    bool result = true;
    for (int i = 0; i < 3; i++)
        result &= TestSystem::check(expected_result[i], actual_result[i]);

    return result;
}

bool test45_try_find_all_non_existent_elems() {
    TVector<int> vec({ 1, 2, 3, 4, 5});
    int* expected_result = nullptr;
    int* actual_result = find_all(vec, 6);

    return TestSystem::check(expected_result, actual_result);
}

bool test46_try_find_all_after_erase() {
    TVector<int> vec({ 1, 2, 3, 2, 4, 2 });
    int* expected_result = new int[3];
    expected_result[0] = 1;
    expected_result[1] = 2;
    expected_result[2] = 4;
    vec.erase(vec.begin() + 2);

    int* actual_result = find_all(vec, 2);

    bool result = true;
    for (int i = 0; i < 3; i++)
        result &= TestSystem::check(expected_result[i], actual_result[i]);

    return result;
}

bool test47_try_find_all_after_insert() {
    TVector<int> vec({ 1, 2, 3, 2, 4, 2 });
    int* expected_result = new int[4];
    expected_result[0] = 1;
    expected_result[1] = 2;
    expected_result[2] = 4;
    expected_result[3] = 6;

    vec.insert(vec.begin() + 2, 2);

    int* actual_result = find_all(vec, 2);

    bool result = true;
    for (int i = 0; i < 4; i++)
        result &= TestSystem::check(expected_result[i], actual_result[i]);
    
    return result;
}

bool test48_try_find_all_with_deleted_elem() {
    TVector<int> vec({ 1, 2, 3, 2, 4, 2 });
    int* expected_result = new int[2];
    expected_result[0] = 1;
    expected_result[1] = 4;

    vec.erase(vec.begin() + 3);
    int* actual_result = find_all(vec, 2);

    return TestSystem::check(expected_result[0], actual_result[0]) &&
        TestSystem::check(expected_result[1], actual_result[1]);
}

bool test49_try_emplace_by_value() {
    TVector<int> vec({ 1, 2, 3, 2, 4, 2 });
    int* expected_result = new int[3];
    for (int i = 0; i < 3; i++)
        expected_result[i] = 2 * i + 1;
    vec.emplace(2, 5);
    int* actual_result = find_all(vec, 5);
    
    bool result = true;
    for (int i = 0; i < 3; i++)
        result &= TestSystem::check(expected_result[i], actual_result[i]);
    
    return result;
}

bool test50_try_emplace_by_value_non_existent_elem() {
    TVector<int> vec({ 1, 2, 3, 2, 4, 2 });
    int* expected_result = nullptr;
    vec.emplace(5, 6);
    int* actual_result = find_all(vec, 6);
    
    return TestSystem::check(expected_result, actual_result);
}

bool test51_try_emplace_by_value_deleted_elem() {
    TVector<int> vec({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 });
    int expected_result = -1;
    
    vec.erase(vec.begin() + 2);
    int actual_result = find(vec, 3);
    
    return TestSystem::check(expected_result, actual_result);
}

bool test52_try_emplace_by_index() {
    TVector<int> vec({ 1, 2, 3, 4, 5 });
    int expected_result = 5;
    vec.emplace(vec.begin() + 2, 5);
    int actual_result = *(vec.begin() + 2);

    return TestSystem::check(expected_result, actual_result);
}

bool test53_try_emplace_by_index_elem_out_of_range() {
    TVector<int> vec({ 1, 2, 3, 4, 5 });
    int expected_result = false;
    int actual_result = true;
    try {
        vec.emplace(vec.begin() + 5, 5);
    }
    catch (const std::exception& ex) {
        actual_result = false;
    }

    return TestSystem::check(expected_result, actual_result);
}

bool test54_try_emplace_by_value_after_erase() {
    TVector<int> vec({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 });
    int expected_result = -1;

    vec.erase(vec.begin() + 2);
    vec.emplace(3, 20);
    int actual_result = find(vec, 20);

    return TestSystem::check(expected_result, actual_result);
}

bool test55_try_emplace_by_index_after_erase() {
    TVector<int> vec({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 });
    int expected_result = -1;

    vec.erase(vec.begin() + 2);
    vec.emplace(vec.begin() + 5, 20);
    int actual_result = find(vec, 7);

    return TestSystem::check(expected_result, actual_result);
}

bool test56_try_assign_vector() {
    TVector<int> vec1({ 1, 2, 3, 4, 5 }), vec2;
    int* expected_result = new int[5];
    for (int i = 0; i < 5; i++)
        expected_result[i] = i + 1;
    int* actual_result;

    try {
        vec2.assign(vec1);
        actual_result = vec2.data();
    }
    catch (const std::exception&) {
        actual_result = nullptr;
    }
    
    bool result = true;
    for (int i = 0; i < 5; i++)
        result &= TestSystem::check(expected_result[i], actual_result[i]);
    
    return result;
}

bool test57_try_assign_null_vector() {
    TVector<int> *vec1 = NULL, vec2;
    bool expected_result = false;
    bool actual_result = true;
    try {
        vec2.assign(*vec1);
        actual_result = true;
    }
    catch (const std::exception&) {
        actual_result = false;
    }
    
    return TestSystem::check(expected_result, actual_result);
}

bool test58_try_at() {
    TVector<int> vec({ 1, 2, 3, 4, 5 });
    int expected_result = 3;
    int actual_result = vec.at(2);

    return TestSystem::check(expected_result, actual_result);
}

bool test59_try_at_out_of_range() {
    TVector<int> vec({ 1, 2, 3, 4, 5 });
    bool expected_result = false;
    bool actual_result = true;
    try {
        int num = vec.at(5);
    }
    catch (const std::exception&) {
        actual_result = false;
    }

    return TestSystem::check(expected_result, actual_result);
}

bool test_60_try_at_after_erase() {
    TVector<int> vec({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 });
    int expected_result = 7;

    vec.erase(vec.begin() + 2);
    int actual_result = vec.at(5);
    return TestSystem::check(expected_result, actual_result);
}

bool test_61_try_at_after_insert() {
    TVector<int> vec({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 });
    int expected_result = 5;

    vec.insert(vec.begin() + 2, 20);
    int actual_result = vec.at(5);
    return TestSystem::check(expected_result, actual_result);
}

bool test62_try_test_at_deleted_elem() {
    TVector<int> vec({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 });
    int expected_result = 4;

    vec.erase(vec.begin() + 2);
    int actual_result = vec.at(2);
    return TestSystem::check(expected_result, actual_result);
}

bool test63_try_test_at_after_pop_front() {
    TVector<int> vec({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 });
    int expected_result = 2;

    vec.pop_front();
    int actual_result = vec.at(0);
    return TestSystem::check(expected_result, actual_result);
}

bool test64_try_test_at_after_pop_back() {
    TVector<int> vec({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 });
    int expected_result = 14;

    vec.pop_back();
    int actual_result = vec.at(vec.size() - 1);
    return TestSystem::check(expected_result, actual_result);
}

int main() {
    TestSystem::start_test(test1_try_create_empty_vector,
        "test1_try_create_empty_vector");
    TestSystem::start_test(test2_try_create_vector, "test2_try_create_vector");
    TestSystem::start_test(test3_try_convert_mass_to_vector,
        "test3_try_convert_mass_to_vector");
    TestSystem::start_test(test4_try_copy_vector, "test4_try_copy_vector");
    TestSystem::start_test(test5_try_get_size, "test5_try_get_size");
    TestSystem::start_test(test6_try_get_capacity, "test6_try_get_capacity");
    TestSystem::start_test(test7_try_get_data, "test7_try_get_data");
    TestSystem::start_test(test8_try_get_iterator_begin,
        "test8_try_get_iterator_begin");
    TestSystem::start_test(test9_try_get_iterator_end,
        "test9_try_get_iterator_end");
    TestSystem::start_test(test10_try_get_front, "test10_try_get_front");
    TestSystem::start_test(test11_try_get_back, "test11_try_get_back");
    TestSystem::start_test(test12_try_check_is_empty_if_full,
        "test12_try_check_is_empty_if_full");
    TestSystem::start_test(test13_try_check_is_empty_if_empty,
        "test13_try_check_is_empty_if_empty");
    TestSystem::start_test(test14_try_clear_vector,
        "test14_try_clear_vector");
    TestSystem::start_test(test15_try_push_back, "test15_try_push_back");
    TestSystem::start_test(test16_try_push_back_with_reset_memory,
        "test16_try_push_back_with_reset_memory");
    TestSystem::start_test(test17_try_push_front, "test17_try_push_front");
    TestSystem::start_test(test18_try_push_front_with_reset_memory,
        "test18_try_push_front_with_reset_memory");
    TestSystem::start_test(test19_try_pop_back, "test19_try_pop_back");
    TestSystem::start_test(test20_try_pop_back_without_reset_memory,
        "test20_try_pop_back_without_reset_memory");
    TestSystem::start_test(test21_try_pop_front, "test21_try_pop_front");
    TestSystem::start_test(test22_try_pop_front_without_reset_memory,
        "test22_try_pop_front_without_reset_memory");
    TestSystem::start_test(test23_try_push_back_after_pop_front,
        "test23_try_push_back_after_pop_front");
    TestSystem::start_test(test24_try_push_front_after_pop_back,
        "test24_try_push_front_after_pop_back");
    TestSystem::start_test(test25_try_erase_elem, "test25_try_erase_elem");
    TestSystem::start_test(test26_try_erase_elem_without_reset_memory,
        "test26_try_erase_elem_without_reset_memory");
    TestSystem::start_test(test27_try_push_back_after_erase,
        "test27_try_push_back_after_erase");
    TestSystem::start_test(test28_try_push_front_after_erase,
        "test28_try_push_front_after_erase");
    TestSystem::start_test(test29_try_push_back_after_erase_without_reset_mem,
        "test29_try_push_back_after_erase_without_reset_memory");
    TestSystem::start_test(test30_try_insert, "test30_try_insert");
    TestSystem::start_test(test31_try_insert_with_reset_capacity,
        "test31_try_insert_with_reset_capacity");
    TestSystem::start_test(test32_try_insert_after_pop_front,
        "test32_try_insert_after_pop_front");
    TestSystem::start_test(test33_try_insert_after_erase,
        "test33_try_insert_after_erase");
    TestSystem::start_test(test34_try_find_elem, "test34_try_find_elem");
    TestSystem::start_test(test35_try_find_non_existent_elem,
        "test35_try_find_non_existent_elem");
    TestSystem::start_test(test36_try_find_elem_after_erase,
        "test36_try_find_elem_after_erase");
    TestSystem::start_test(test37_try_find_elem_after_insert,
        "test37_try_find_elem_after_insert");
    TestSystem::start_test(test38_try_find_deleted_elem,
        "test38_try_find_deleted_elem");
    TestSystem::start_test(test39_try_find_last_elem,
        "test39_try_find_last_elem");
    TestSystem::start_test(test40_try_find_non_existent_last_elem,
        "test40_try_find_non_existent_last_elem");
    TestSystem::start_test(test41_try_find_last_elem_after_erase,
        "test41_try_find_last_elem_after_erase");
    TestSystem::start_test(test42_try_find_last_elem_after_insert,
        "test42_try_find_last_elem_after_insert");
    TestSystem::start_test(test43_try_find_last_deleted_elem,
        "test43_try_find_last_deleted_elem");
    TestSystem::start_test(test44_try_find_all_elems,
        "test44_try_find_all_elems");
    TestSystem::start_test(test45_try_find_all_non_existent_elems,
        "test45_try_find_all_non_existent_elems");
    TestSystem::start_test(test46_try_find_all_after_erase,
        "test46_try_find_all_after_erase");
    TestSystem::start_test(test47_try_find_all_after_insert,
        "test47_try_find_all_after_insert");
    TestSystem::start_test(test48_try_find_all_with_deleted_elem,
        "test48_try_find_all_with_deleted_elem");
    TestSystem::start_test(test49_try_emplace_by_value,
        "test49_try_emplace_by_value");
    TestSystem::start_test(test50_try_emplace_by_value_non_existent_elem,
        "test50_try_emplace_by_value_non_existent_elem");
    TestSystem::start_test(test51_try_emplace_by_value_deleted_elem,
        "test51_try_emplace_by_value_deleted_elem");
    TestSystem::start_test(test52_try_emplace_by_index,
        "test52_try_emplace_by_index");
    TestSystem::start_test(test53_try_emplace_by_index_elem_out_of_range,
        "test53_try_emplace_by_index_elem_out_of_range");
    TestSystem::start_test(test54_try_emplace_by_value_after_erase,
        "test54_try_emplace_by_value_after_erase");
    TestSystem::start_test(test55_try_emplace_by_index_after_erase,
        "test55_try_emplace_by_index_after_erase");
    TestSystem::start_test(test56_try_assign_vector, "test56_try_assign_vec");
    TestSystem::start_test(test57_try_assign_null_vector,
        "test57_try_assign_null_vector");
    TestSystem::start_test(test58_try_at, "test58_try_at");
    TestSystem::start_test(test59_try_at_out_of_range,
        "test59_try_at_out_of_range");
    TestSystem::start_test(test_60_try_at_after_erase,
        "test_60_try_at_after_erase");
    TestSystem::start_test(test_61_try_at_after_insert,
        "test_61_try_at_after_insert");
    TestSystem::start_test(test62_try_test_at_deleted_elem,
        "test62_try_test_at_deleted_elem");
    TestSystem::start_test(test63_try_test_at_after_pop_front,
        "test63_try_test_at_after_pop_front");
    TestSystem::start_test(test64_try_test_at_after_pop_back,
        "test64_try_test_at_after_pop_back");

    TestSystem::print_final_info();

    return 0;
}
