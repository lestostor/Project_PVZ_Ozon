#pragma once
#include "Date.h"

class Product {
	int _code;  //���
	int _price;  //����
	bool _prepay;  //����������
	int _age_limit = 0;  //���������� ����������� (0 - ��� �����������)
	bool _returnability = true;
	Date _date;
};