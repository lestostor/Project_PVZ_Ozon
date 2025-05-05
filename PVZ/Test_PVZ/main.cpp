#include "Address.h"
#include "Cell.h"
#include "Date.h"
#include "FIO.h"
#include "Product.h"
#include "Worker.h"
//  Copyright 2025 Shcherbakova Olesya


int main() {
    FIO person1, person2("зубенко", "михаил", "петрович"), person3(person2);
    Address address1, address2("ивановская", "ивановский",
        "кохма", "ивановская", 92), address3(address2);
    Worker worker1, worker2(person2, "workmail@gmail.com", address2),
        worker3(worker2);
    Date date1, date2(1, 3, 25), date3(date2);

    return 0;
}
