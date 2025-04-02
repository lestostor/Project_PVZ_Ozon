#pragma once
#include "FIO.h"
#include "Address.h"

class Worker {
	FIO _worker;
	char* _mail;
	Address _address;
};