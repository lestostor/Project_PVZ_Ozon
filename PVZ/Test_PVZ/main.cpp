#include "Address.h"
#include "Cell.h"
#include "Date.h"
#include "FIO.h"
#include "Product.h"
#include "Worker.h"
#include "TVector.h"
#include <iostream>
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
            std::cerr << "Expected result is " << expected <<
                ", but actual is " << actual << "." << std::endl;
            return false;
        }
    }

    template <class T>
    bool check_not_equal(const T& expected, const T& actual) {
        if (expected == actual) {
            std::cerr << "Expected result and actual result" <<
                "are equal." << std::endl;
            return false;
        }
        else {
            return true;
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

bool test1_try_FIO_constructors() {
    bool expected_result1 = true, expected_result2 = true,
        expected_result3 = true, expected_result4 = false;
    bool actual_result1 = false, actual_result2 = false,
        actual_result3 = false, actual_result4 = true;

    try {
        FIO person1;
        actual_result1 = true;
    }
    catch (const std::exception& ex) {
        actual_result1 = false;
    }
    try {
        FIO person2("Zheltuhin", "Michael", "davidovich");
        actual_result2 = true;
    }
    catch (const std::exception& ex) {
        actual_result2 = false;
    }
    try {
        FIO person2("Zheltuhin", "Michael", "davidovich");
        FIO person3(person2);
        actual_result3 = true;
    }
    catch (const std::exception& ex) {
        actual_result3 = false;
    }
    try {
        FIO person4("smirnov1", "oleg", "nikolaevich");
    }
    catch (const std::exception& ex) {
        actual_result4 = false;
    }

    return TestSystem::check(expected_result1, actual_result1) &&
        TestSystem::check(expected_result2, actual_result2) &&
        TestSystem::check(expected_result3, actual_result3) &&
        TestSystem::check(expected_result4, actual_result4);
}

bool test2_try_address_contructos() {
    bool expected_result1 = true, expected_result2 = true,
        expected_result3 = true, expected_result4 = false;
    bool actual_result1 = false, actual_result2 = false,
        actual_result3 = false, actual_result4 = true;

    try {
        Address address1;
        actual_result1 = true;
    }
    catch (const std::exception& ex) {
        actual_result1 = false;
    }
    try {
        Address address2("ivanovskaya", "ivanovskiy",
            "ivanovo", "ivanovskaya", 50);
        actual_result2 = true;
    }
    catch (const std::exception& ex) {
        actual_result2 = false;
    }
    try {
        Address address2("ivanovskaya", "ivanovskiy",
            "ivanovo", "ivanovskaya", 50);
        Address address3(address2);
        actual_result3 = true;
    }
    catch (const std::exception& ex) {
        actual_result3 = false;
    }
    try {
        Address address4("ivanovskaya", "ivanovski2y",
            "ivanovo", "ivanovskaya", 50);
    }
    catch (const std::exception& ex) {
        actual_result4 = false;
    }

    return TestSystem::check(expected_result1, actual_result1) &&
        TestSystem::check(expected_result2, actual_result2) &&
        TestSystem::check(expected_result3, actual_result3) &&
        TestSystem::check(expected_result4, actual_result4);
}

bool test3_try_worker_constructors() {
    bool expected_result1 = true, expected_result2 = true,
        expected_result3 = true, expected_result4 = false;
    bool actual_result1 = false, actual_result2 = false,
        actual_result3 = false, actual_result4 = true;

    FIO person("Zheltuhin", "Michael", "davidovich");
    Address address("ivanovskaya", "ivanovskiy", "ivanovo", "ivanovskaya", 50);

    try {
        Worker worker1;
        actual_result1 = true;
    }
    catch (const std::exception& ex) {
        actual_result1 = false;
    }
    try {
        Worker worker2(person, "workmail@gmail.com", address);
        actual_result2 = true;
    }
    catch (const std::exception& ex) {
        actual_result2 = false;
    }
    try {
        Worker worker2(person, "workmail@gmail.com", address);
        Worker worker3(worker2);
        actual_result3 = true;
    }
    catch (const std::exception& ex) {
        actual_result3 = false;
    }
    try {
        Worker worker4(person, "workmailgmail.com", address);
    }
    catch (const std::exception& ex) {
        actual_result4 = false;
    }

    return TestSystem::check(expected_result1, actual_result1) &&
        TestSystem::check(expected_result2, actual_result2) &&
        TestSystem::check(expected_result3, actual_result3) &&
        TestSystem::check(expected_result4, actual_result4);
}

bool test4_try_date_constructors() {
    bool expected_result1 = true, expected_result2 = true,
        expected_result3 = true, expected_result4 = false;
    bool actual_result1 = false, actual_result2 = false,
        actual_result3 = false, actual_result4 = true;

    Date date1, date2(1, 3, 2025), date3(date2);
    try {
        Date date1;
        actual_result1 = true;
    }
    catch (const std::exception& ex) {
        actual_result1 = false;
    }
    try {
        Date date2(31, 3, 2025);
        actual_result2 = true;
    }
    catch (const std::exception& ex) {
        actual_result2 = false;
    }
    try {
        Date date2(31, 3, 2025);
        Date date3(date2);
        actual_result3 = true;
    }
    catch (const std::exception& ex) {
        actual_result3 = false;
    }
    try {
        Date date4(29, 2, 2025);
    }
    catch (const std::exception& ex) {
        actual_result4 = false;
    }

    return TestSystem::check(expected_result1, actual_result1) &&
        TestSystem::check(expected_result2, actual_result2) &&
        TestSystem::check(expected_result3, actual_result3) &&
        TestSystem::check(expected_result4, actual_result4);
}

bool test5_try_product_constructors() {
    bool expected_result1 = true, expected_result2 = true,
        expected_result3 = true;
    bool actual_result1 = false, actual_result2 = false,
        actual_result3 = false;

    Date date(30, 4, 2025);

    try {
        Product product1;
        actual_result1 = true;
    }
    catch (const std::exception& ex) {
        actual_result1 = false;
    }
    try {
        Product product2(1111, 10, false, 0, false, date);
        actual_result2 = true;
    }
    catch (const std::exception& ex) {
        actual_result2 = false;
    }
    try {
        Product product2(1111, 10, false, 0, false, date);
        Product product3(product2);
        actual_result3 = true;
    }
    catch (const std::exception& ex) {
        actual_result3 = false;
    }

    return TestSystem::check(expected_result1, actual_result1) &&
        TestSystem::check(expected_result2, actual_result2) &&
        TestSystem::check(expected_result3, actual_result3);
}

bool test6_try_cell_constructors() {
    bool expected_result1 = true, expected_result2 = true,
        expected_result3 = true;
    bool actual_result1 = false, actual_result2 = false,
        actual_result3 = false;
    Date date1(10, 3, 2025), date2(29, 4, 2025);
    Product product1(1111, 250, true, 0, true, date1),
        product2(2222, 10, false, 0, false, date2);

    try {
        Cell cell1;
        actual_result1 = true;
    }
    catch (const std::exception& ex) {
        actual_result1 = false;
    }
    try {
        Cell cell2(1, { product1, product2 });
        actual_result2 = true;
    }
    catch (const std::exception& ex) {
        actual_result2 = false;
    }
    try {
        Cell cell2(1, { product1, product2 });
        Cell cell3(cell2);
        actual_result3 = true;
    }
    catch (const std::exception& ex) {
        actual_result3 = false;
    }

    return TestSystem::check(expected_result1, actual_result1) &&
        TestSystem::check(expected_result2, actual_result2) &&
        TestSystem::check(expected_result3, actual_result3);
}

bool test7_try_delete_product() {
    size_t expected_result = 1;
    Date date1(10, 3, 2025), date2(29, 4, 2025);
    Product product1(1111, 250, true, 0, true, date1),
        product2(2222, 10, false, 0, false, date2);
    Cell cell(1, { product1, product2 });

    cell.delete_product(product1);
    size_t actual_result = cell.get_products().size();

    return TestSystem::check(expected_result, actual_result);
}

bool test8_try_add_product() {
    size_t expected_result = 3;
    Date date1(10, 3, 2025), date2(29, 4, 2025), date3(14, 7, 2025);
    Product product1(1111, 250, true, 0, true, date1),
        product2(2222, 10, false, 0, false, date2),
        product3(3333, 1413, true, 18, false, date3);
    Cell cell(1, { product1, product2 });

    cell.add_new_product(product3);
    size_t actual_result = cell.get_products().size();

    return TestSystem::check(expected_result, actual_result);
}

bool test9_try_add_product_after_delete() {
    Date date1(10, 3, 2025), date2(29, 4, 2025), date3(14, 7, 2025);
    Product product1(1111, 250, true, 0, true, date1),
        product2(2222, 10, false, 0, false, date2),
        product3(3333, 1413, true, 18, false, date3);
    size_t expected_result = 2;

    Cell cell(1, { product1, product2 });
    cell.delete_product(product2);
    cell.add_new_product(product3);
    size_t actual_result = cell.get_products().size();

    return TestSystem::check(expected_result, actual_result);
}

bool test10_try_get_products_by_code() {
    bool expected_result1 = true, expected_result2 = false,
        expected_result3 = false, expected_result4 = false,
        expected_result5 = false;
    bool actual_result1 = false, actual_result2 = true,
        actual_result3 = true, actual_result4 = true,
        actual_result5 = true;

    Date date1(10, 3, 2025), date2(29, 4, 2025),
        date3(31, 3, 2025), date4(28, 2, 2025);
    Product product1(1111, 250, true, 0, true, date1),
        product2(2222, 10, false, 0, false, date2),
        product3(3333, 1563, true, 18, false, date3),
        product4(4444, 410, false, 0, true, date4);
    Cell cell1(1, { product1, product2 }), cell2(2, { product3, product4 });

    TVector<Cell> cells({ cell1, cell2 });
    TVector<Product> products;
    try {
        products = get_products_by_code(cells, 4700000083002);
        actual_result1 = true;
    }
    catch (const std::exception& ex) {
        actual_result1 = false;
    }
    try {
        products = get_products_by_code(cells, 4700000083003);
    }
    catch (const std::exception& ex) {
        actual_result2 = false;  //  non-existent cell
    }
    try {
        products = get_products_by_code(cells, 4700000083000);
    }
    catch (const std::exception& ex) {
        actual_result3 = false;  //  empty
    }
    try {
        products = get_products_by_code(cells, 470000830031);
    }
    catch (const std::exception& ex) {
        actual_result4 = false;  //  wrong code (not enough digits)
    }
    try {
        products = get_products_by_code(cells, 4700000083053150007);
    }
    catch (const std::exception& ex) {
        actual_result5 = false;  //  (many digits)
    }

    return TestSystem::check(expected_result1, actual_result1) &&
        TestSystem::check(expected_result2, actual_result2) &&
        TestSystem::check(expected_result3, actual_result3) &&
        TestSystem::check(expected_result4, actual_result4) &&
        TestSystem::check(expected_result5, actual_result5);
}

bool test11_try_give_products() {
    size_t expected_result = 1;
    Date date1(10, 3, 2025), date2(11, 3, 2025);
    Product product1(1111, 250, true, 0, true, date2),
        product2(2222, 10, false, 0, false, date2),
        product3(3333, 1563, true, 18, false, date2);
    Cell cell(1, { product1, product2, product3 });
    TVector<Product> products({ product1, product2 });

    give_products(cell, products, 1000, date1);
    size_t actual_result = cell.get_products().size();

    return TestSystem::check(expected_result, actual_result);
}

bool test12_try_return_products() {
    size_t expected_result = 1;
    Date date1(10, 3, 2025), date2(11, 3, 2025);
    Product product1(1111, 250, true, 0, true, date2),
        product2(2222, 10, false, 0, false, date2),
        product3(3333, 1563, true, 18, false, date2);
    Cell cell(1, { product1, product2, product3 });
    TVector<Product> products({ product1, product2 });

    return_products(cell, products);
    size_t actual_result = cell.get_products().size();

    return TestSystem::check(expected_result, actual_result);
}

int main() {
    TestSystem::start_test(test1_try_FIO_constructors,
        "FIO.test1_try_FIO_constructors");
    TestSystem::start_test(test2_try_address_contructos,
        "Address.test2_try_address_contructos");
    TestSystem::start_test(test3_try_worker_constructors,
        "Worker.test3_try_worker_constructors");
    TestSystem::start_test(test4_try_date_constructors,
        "Date.test4_try_date_constructors");
    TestSystem::start_test(test5_try_product_constructors,
        "Products.test5_try_product_constructors");
    TestSystem::start_test(test6_try_cell_constructors,
        "Cell.test6_try_cell_constructors");
    TestSystem::start_test(test7_try_delete_product,
        "Cell.test7_try_delete_product");
    TestSystem::start_test(test8_try_add_product,
        "Cell.test8_try_add_product");
    TestSystem::start_test(test9_try_add_product_after_delete,
        "Cell.test9_try_add_product_after_delete");
    TestSystem::start_test(test10_try_get_products_by_code,
        "Cell.test10_try_get_products_by_code");
    TestSystem::start_test(test11_try_give_products,
        "Cell.test11_try_give_products");
    TestSystem::start_test(test12_try_return_products,
        "Cell.test12_try_return_products");

    TestSystem::print_final_info();

    return 0;
}
