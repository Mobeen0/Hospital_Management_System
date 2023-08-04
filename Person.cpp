#include<iostream>
using namespace std;
#include<string>
#include "Person.h"

Person::Person():DateOfBirth(), address() {
	PhoneNum = 0;
	CNIC = 0;
	Email[0] = 'N';
	Email[1] = '\0';
}
Person:: Person(string Name, long long int PhoneNum, long long int CNIC, Date& DateOfBirth, Address& address): DateOfBirth(DateOfBirth),address(address) {
	strcpy_s(this->Name, Name.c_str());
	this->PhoneNum = PhoneNum;
	this->CNIC = CNIC;
}


char* Person::getName() {
	return Name;
}

char* Person::getEmail() {
	return Email;
}
long long int Person:: getPhoneNum() {
	return PhoneNum;
}
long long int Person::getCNIC() {
	return CNIC;
}
Date& Person::getDate() {
	return DateOfBirth;
}
Address& Person::getAddress() {
	return address;
}



void Person:: InputName() {
	int count = 0;
	string name;
	cout << "* Enter Full Name:-         ";
	do {
		if (count == 0)
		{
			count++;
		}
		else {
			getline(cin, name);
		}
	} while (name.length() == 0);
	setName(name);

}

void Person:: InputEmail() {

	int count = 0;
	string name;
	cout << "* Enter Email Address:-         ";
	do {
		if (count == 0)
		{
			count++;
		}
		else {
			getline(cin, name);
		}
	} while (name.length() == 0);
	setEmail(name);

}

void Person::InputPhoneNum() {
	long long int NUM;
	do {
		cout << "* Enter your Phone Number:-  ";
		cin >> NUM;

		setPhoneNum(NUM);
	} while (!verifyPhoneNum());

}
void Person::InputCNIC() {
	long long int NUM;
	do {
		cout << "* Enter your CNIC:-          ";
		cin >> NUM;

		setCNIC(NUM);
	} while (!verifyCNIC());
}
void Person::InputDate() {

	int DateandAddsetter;
	Date tempdate;
	do {
		cout << "*                    -----Enter your Date of Birth-----                                      *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Enter Day :-                ";
		cin >> DateandAddsetter;
		tempdate.setDay(DateandAddsetter);
		cout << "* Enter Month :-              ";
		cin >> DateandAddsetter;
		tempdate.setMonth(DateandAddsetter);
		cout << "* Enter Year:-                ";
		cin >> DateandAddsetter;
		tempdate.setYear(DateandAddsetter);

		setDate(tempdate);
	} while (!verifyDateOfBirth());

}
void Person::InputAddress() {
	int DateandAddsetter;
	Address tempADD;
	string name;
	int count = 0;
	do {
		cout << "*                         -----Enter your Address of Residency-----                          *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Enter House # :  ";
		cin >> DateandAddsetter;
		tempADD.setHouse(DateandAddsetter);
		cout << "* Enter Street # : ";
		cin >> DateandAddsetter;
		tempADD.setStreet(DateandAddsetter);
		name = "";
		count = 0;
		do {
			if (count != 0) {
				cout << "* Enter your local Area/sector : ";
			}
			else {
				count++;
			}
			getline(cin, name);
		} while (name.length() == 0);
		tempADD.setArea(name);
		cout << "* Enter your Postal Code : ";
		cin >> DateandAddsetter;
		tempADD.setPostalCode(DateandAddsetter);
		cout << "* Enter your City (Pakistan) :  ";
		cin >> name;
		tempADD.setCity(name);
		setAddress(tempADD);
	} while (!(verifyAddress()));
}


void Person::setName(string Name) {
	strcpy_s(this->Name, Name.c_str());
}
void Person::setDate(Date& date) {
	DateOfBirth.setDay(date.getDay());
	DateOfBirth.setMonth(date.getMonth());
	DateOfBirth.setYear(date.getYear());
}
void Person::setEmail(string Email) {
	strcpy_s(this->Email,Email.c_str());
}
void Person::setPhoneNum(long long int PhoneNum) {
	this->PhoneNum = PhoneNum;
}
void Person:: setCNIC(long long int CNIC) {
	this->CNIC = CNIC;
}
void Person:: setAddress(Address& add) {
	address.setHouse(add.getHouse());
	address.setStreet(add.getStreet());
	address.setArea(add.getArea());
	address.setCity(add.getCity());
	address.setPostalCode(add.getPostalCode());
}


bool Person::verifyPhoneNum() {
	long long int num;
	num = PhoneNum;
	if (num == 0)
		return false;
	int count = 0;
	while (num != 0)
	{
		num = num / 10;
		count++;
	}

	if (count == 10 || count == 11) { // case if the first number is 0
		return true;
	}
	return false;
}
bool Person::verifyCNIC() {
	long long int num;
	num = CNIC;
	if (num == 0)
		return false;
	int count = 0;
	while (num != 0)
	{
		num = num / 10;
		count++;
	}

	if (count == 13) { 
		return true;
	}
	return false;
}
bool Person::verifyDateOfBirth() {
	return DateOfBirth.verifyDate();
}
bool Person::verifyAddress() {
	return address.verifyAddress();
}

void Person::display() {

	cout << "************************Personal Information***********************" << endl;
	cout << "Name: " << Name << "    Phone Number: " << PhoneNum << "     CNIC: " << CNIC << endl;
	cout << "Date of Birth: "; DateOfBirth.display(); cout << endl;
	address.display();
	cout << "********************************************************************" << endl;
}