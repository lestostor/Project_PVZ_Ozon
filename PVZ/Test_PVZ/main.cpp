#include "Address.h"
#include "Cell.h"
#include "Date.h"
#include "FIO.h"
#include "Product.h"
#include "Worker.h"
#include "TVector.h"
#include <iostream>
//  Copyright 2025 Shcherbakova Olesya


int main() {
    //  test FIO
    std::cout << "TEST FIO" << std::endl;

    FIO person1, person2("Zheltuhin", "Michael", "davidovich"),
        person3(person2);
    try {
        FIO person4("smirnov1", "oleg", "nikolaevich");
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what();
    }
    std::cout << "person2 == person3 is " << (person2 == person3) << std::endl;

    std::cout << std::endl;

    //  test address
    std::cout << "TEST ADDRESS" << std::endl;

    Address address1, address2("ivanovskaya", "ivanovskiy",
        "ivanovo", "ivanovskaya", 50), address3(address2);
    try {
        Address address2("ivanovskaya", "ivanovski2y",
            "ivanovo", "ivanovskaya", 50);
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what();
    }
    std::cout << "address2 == address3 is " << (address2 == address3)
        << std::endl;

    std::cout << std::endl;

    //  test worker
    std::cout << "TEST WORKER" << std::endl;

    Worker worker1, worker2(person2, "workmail@gmail.com", address2),
        worker3(worker2);
    try {
        Worker worker4(person2, "workmailgmail.com", address2);
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what();
    }
    std::cout << std::endl;

    //  test date
    std::cout << "TEST DATE" << std::endl;

    Date date1, date2(1, 3, 2025), date3(date2);
    try {
        Date date4(29, 2, 2025);
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what();
    }
    std::cout << "date2 > date1 is " << (date2 > date1) << std::endl;

    std::cout << std::endl;

    //  test product
    std::cout << "TEST PRODUCT" << std::endl;

    Product product1, product2(1111, 10, false, 0, false, date2),
        product3(product2);
    std::cout << "product2 > product1 is " << (product2 > product1)
        << std::endl;

    std::cout << std::endl;

    //  test cell
    std::cout << "TEST CELL" << std::endl;

    Cell cell1, cell2(1, {product1, product2}), cell3(cell2);

    std::cout << "TEST CELL: delete and add" << std::endl;
    cell2.delete_product(product2);
    cell2.add_new_products(product3);
    std::cout << "cell2 > cell1 is " << (cell2 > cell1) << std::endl;
    std::cout << "cell2 == cell3 is " << (cell2 == cell3) << std::endl;
    
    std::cout << "TEST CELL: get product" << std::endl;
    TVector<Cell> cells({ cell1, cell2 });
    TVector<Product> products = get_products(cells, 4700000083001);  //  cell2

    try {
        TVector<Product> products = get_products(cells, 4700000083002);
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what();  //  non-existent cell
    }
    std::cout << std::endl;

    try {
        TVector<Product> products = get_products(cells, 4700000083000);
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what();  //  empty
    }
    std::cout << std::endl;

    try {
        TVector<Product> products = get_products(cells, 470000830031);
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what();  //  wrong code (not enough digits)
    }
    std::cout << std::endl;

    try {
        TVector<Product> products = get_products(cells, 470000008305315345);
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what();  //  (many digits)
    }

    return 0;
}
