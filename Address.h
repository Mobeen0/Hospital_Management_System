#pragma once

#include<iostream>
using namespace std;
#include<string>

class Address {
private:
	int House;
	int Street;
	char Area[100];
	char City[100];
	int PostalCode;

public:

	Address();
	Address(int,int,string,string,int);

	int getHouse();
	int getStreet();
	char* getArea();
	char* getCity();
	int getPostalCode();

	void setHouse(int);
	void setStreet(int);
	void setArea(string);
	void setCity(string);
	void setPostalCode(int);

	void display();
	bool verifyAddress();
};