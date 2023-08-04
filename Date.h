#pragma once

#include<iostream>
using namespace std;

class Date {
protected:
	int Day;
	int Month;
	int Year;
public:

	Date();
	Date(int, int, int);
	Date(Date&);
	
	void setDay(int);
	void setMonth(int);
	void setYear(int);

	int getDay();
	int getMonth();
	int getYear();

	bool verifyDate();
	void display();

	void setCurrentDate();

	bool operator==(Date&);
	bool operator>(Date&);
	bool operator<(Date&);

};
