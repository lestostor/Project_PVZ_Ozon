#pragma once
#include <string>
#include "C:/Users/user/Project_PVZ_Ozon/Project_PVZ_Ozon/PVZ/FIO/FIO.h"
#include "C:/Users/user/Project_PVZ_Ozon/Project_PVZ_Ozon/PVZ/Address/Address.h"
//  Copyright 2025 Shcherbakova Olesya


class Worker {
    FIO _worker;
    std::string _mail;
    Address _address;

 public:
    Worker();
    Worker(const FIO, const std::string, const Address);
    Worker(const Worker&);

 private:
    bool check_mail(const std::string);
};
