#include<iostream>
using namespace std;
#include<string>
#include "Address.h"

Address::Address() {
	House = 0;
	Street = 0;
	PostalCode = 0;
	
}
Address::Address(int House, int Street, string Area, string City, int PostalCode) {
	this->House = House;
	this->Street = Street;
	strcpy_s(this->Area, Area.c_str());
	strcpy_s(this->City, City.c_str());
	this->PostalCode = PostalCode;

}
int Address:: getHouse() {
	return House;
}
int Address::getStreet() {
	return Street;
}
char* Address::getArea() {
	return Area;
}
char* Address::getCity() {
	return City;
}
int Address::getPostalCode() {
	return PostalCode;
}

void Address::setHouse(int House) {
	this->House = House;
}
void Address::setStreet(int Street) {
	this->Street = Street;
}
void Address::setArea(string Area) {
	strcpy_s(this->Area, Area.c_str());
}
void Address::setCity(string City) {
	strcpy_s(this->City, City.c_str());
}
void Address::setPostalCode(int PostalCode) {
	this->PostalCode = PostalCode;
}

void Address::display() {
	cout << "House# : " << House << "      Street# : " << Street << endl;
	cout << "Area : " << Area << "      City : " << City << endl;
	cout << "Postal Code : " << PostalCode << endl;
}

bool Address:: verifyAddress() {
	if (House < 0|| House >=10000) {
		return false;
	}
	if (Street < 0 || Street >=1000) {
		return false;
	}
	string tempcity = City;
	if ((tempcity=="Islamabad") || (tempcity=="islamabad") || (tempcity =="Karachi") || (tempcity=="karachi")||(tempcity== "Lahore") || (tempcity=="lahore")
		|| (tempcity =="Peshawar")|| (tempcity =="peshawar")|| (tempcity=="Quetta") || (tempcity=="quetta")) {
		return true;
	}
	return false;
	
}