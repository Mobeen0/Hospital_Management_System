#pragma once
#include<iostream>
using namespace std;
#include<string>
#include "Date.h"
#include "Address.h"
#include "Person.h"
#include "User.h"
#include "Patient.h"
#include "Doctor.h"
#include "Admin.h"
#include "ShowRecords.h"
#include "Appointment.h"
#include "Feedback.h"

class Oladoc {
private:
	User user;
	User* Userptr;
	char choice[50];
	Date current;
	

public:


	void startup();
	void chCoverPage();
	void Registration();
	void Login();

	void setChoice(string);

	

	



};