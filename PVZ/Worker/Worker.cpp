#include "Worker.h"
#include <stdexcept>
//  Copyright 2025 Shcherbakova Olesya

Worker::Worker() {
	_worker = FIO();
	_mail = "workersmail@gmail.com";
	_address = Address();
}

Worker::Worker(const FIO worker, const std::string mail,
	const Address address) : _worker(worker), _address(address) {
	if (!check_mail(mail))
		throw std::logic_error("Not found '@'\n");
	_mail = mail;
}

Worker::Worker(const Worker& other_worker) {
	_worker = other_worker._worker;
	_mail = other_worker._mail;
	_address = other_worker._address;
}

bool Worker::check_mail(const std::string mail) {
	for (int i = 0; i < mail.size(); i++) {
		if (mail[i] == '@') return true;
	}
	return false;
}
