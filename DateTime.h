#pragma once
#include "Date.h"
#include<iostream>
using namespace std;

class DateTime: public Date {
private:
	int Hour;
public:
	DateTime();
	DateTime(int, int, int, int);

	int getHour();
	void setHour(int);

	void display();
};
