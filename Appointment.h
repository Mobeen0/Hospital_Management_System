#pragma once
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include"Patient.h"
#include"Doctor.h"
#include "ShowRecords.h"

class Appointment {
private:
	char Day[50];
	int hour;

	char Status[50];
	char BookingType[50];
	long long int DoctorCNIC;
	long long int PatientCNIC;

	char DoctorName[100];
	char PatientName[100];



public:
	Appointment();



	
	void MakeAppointment();
	bool QuickAppointment();
	void CustomisedAppointment();
	
	void DoctorAppointmentManager();


	void setStatus(string);
	char* getStatus();


	void setDay(int);
	void setDay(string);
	char* getDay();
	int getDayExact();

	void setHourExact(int);
	void setHour(int);
	int getHour();
	

	void setBooking(string);
	char* getBooking();

	void setDoctorName(string);
	char* getDoctorName();

	void setPatientName(string);
	char* getPatientName();

	long long int getDoctorCNIC();
	void setDoctorCNIC(long long int);

	long long int getPatientCNIC();
	void setPatientCNIC(long long int);

	void getPatient(int &, Patient&);
	bool getDoctor(string,Doctor&);
	void getDoctor(Doctor&);

	void setAppointmentValues(Patient&,Doctor&, int);
	void setAppointment(Appointment&);

	void Display();

	void ShowPatientAppointments();
	void ShowDoctorAppointments();
	void RequestCancel(long long int, string, int);
	void CancelPatientAppointments();

	bool Read();
	void Write();
	void Update(string);
	void Update(string ,long long int);

};

