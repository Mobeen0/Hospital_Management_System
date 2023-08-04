#pragma once

#include<iostream>
using namespace std;
#include<string>
#include"Date.h"
#include"Address.h"

class Person {
protected:
	char Name[100];
	char Email[100];
	long long int PhoneNum;
	long long int CNIC;
	Date DateOfBirth;
	Address address;

public:

	Person();
	Person(string,long long int, long long int,Date&,Address&);

	char* getName();
	char* getEmail();
	long long int getPhoneNum();
	long long int getCNIC();
	Date& getDate();
	Address& getAddress();

	void setName(string);
	void setEmail(string);
	void setPhoneNum(long long int);
	void setCNIC(long long int);
	void setDate(Date&);
	void setAddress(Address&);

	void InputName();
	void InputEmail();
	void InputPhoneNum();
	void InputCNIC();
	void InputDate();
	void InputAddress();


	bool verifyPhoneNum();
	bool verifyCNIC();
	bool verifyDateOfBirth();
	bool verifyAddress();
	void display();
};