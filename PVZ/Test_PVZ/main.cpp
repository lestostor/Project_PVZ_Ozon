#include "Address.h"
#include "Cell.h"
#include "Date.h"
#include "FIO.h"
#include "Product.h"
#include "Worker.h"
#include <iostream>
//  Copyright 2025 Shcherbakova Olesya


int main() {
    FIO person("зубенко", "михаил", "Петрович");
    Address address("Ивановская", "Ивановский", "Кохма", "Ивановская", 92);
    Worker worker1(person, "workmail@gmail.com", address), worker2(worker1);

    return 0;
}
