#pragma once
#include<iostream>
#include <fstream>
#include<iomanip>
#include "User.h"
#include "Account.h"
#include "DateTime.h"
using namespace std;


class Patient:public User  {
private:
	char Status[30];
	char DoctorName[100];
	DateTime ScheduleTime;
	char TypeOfBooking[30];
	Account account;
	int EscapeRoute;
public:
	
	Patient();
	Patient(User&);
	
	
	void Register();
	void Login();
	void Menu();
	void Display();
	
	
	void setUser(User&);
	void setAccount(Account&);
	void setStatus(string);
	char* getStatus();
	void setDoctorName(string);
	char* getDoctorName();
	void setBooking(string);
	char* getBooking();
	void setScheduleTime(DateTime&);
	DateTime& getScheduleTime();
	void setPatient(Patient&);
	Account& getAccount();
	void setEscapeRoute(int);
	int getEscapeRoute();



	void ManageProfile();
	void PersonalInfo();
	void DoctorSort();
	void ManageAppointment();



	bool Read();
	bool ReadChange();
	bool ReadSignIn();
	bool Write();
	void Update(string);

	



};
