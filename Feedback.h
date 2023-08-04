#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>

#include "Doctor.h"
#include "Patient.h"
#include "Appointment.h"

using namespace std;


class Feedback {
private:
	char Review[350];
	float Rating;
	long long int DocCNIC;
	long long int PatCNIC;
public:
	Feedback();

	void setReview(string);
	void setRating(float);
	
	char* getReview();
	float getRating();
	
	void getPatient(Patient&);
	void getAppointment();

	void ShowDoctor();
	void InputReview();

	void Write();
	void Read(Doctor&);


};

