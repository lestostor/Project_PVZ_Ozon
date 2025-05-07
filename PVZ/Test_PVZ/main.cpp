#include "Address.h"
#include "Cell.h"
#include "Date.h"
#include "FIO.h"
#include "Product.h"
#include "Worker.h"
#include <iostream>
//  Copyright 2025 Shcherbakova Olesya


int main() {
    //  test FIO
    FIO person1, person2("желтухин", "михаил", "давидович"), person3(person2);
    try {
        FIO person4("смирнов1", "олег", "николаевич");
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what();
    }

    //  test address
    Address address1, address2("ивановская", "ивановский",
        "иваново", "ивановская", 50), address3(address2);
    try {
        Address address2("ивановская", "ивановски2й",
            "иваново", "ивановская", 50);
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what();
    }

    //  test worker
    Worker worker1, worker2(person2, "workmail@gmail.com", address2),
        worker3(worker2);
    try {
        Worker worker4(person2, "workmailgmail.com", address2);
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what();
    }

    //  test date
    Date date1, date2(1, 3, 25), date3(date2);
    try {
        Date date4(29, 2, 2025);
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what();
    }

    //  test product
    Product product1, product2(1111, 10, false, 0, false, date2),
        product3(product2);

    //  test cell
    Cell cell1, cell2(2, {product1, product2}), cell3(cell2);
    cell2.delete_product(product2);
    cell2.add_new_products(product3);


    return 0;
}
