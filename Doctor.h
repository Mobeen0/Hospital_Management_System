#pragma once
#include <iostream>
#include <fstream>
#include<string>
#include<iomanip>
#include "User.h"
#include "Account.h"
#include "Address.h"
#include "DateTime.h"

using namespace std;

class Doctor:public User {
protected:


	Account account;
	int HourlyChargeInPerson;
	int HourlyChargeVideo;
	char HospitalName[70];
	Address Hospital;
	char Availability[7][10][50];
	char Speciality[50];
	int EscapeRoute;
	bool Request;

public:

	Doctor();

	void Register();
	void Menu();

	void AvailAndHourSetter();
	void ManageProfile();
	void PersonalInfo();
	void viewAvailabilityHours();
	void setAvailabilityHours();

	void AppointmentMenu();

	void setUser(User&);
	char* getAvailability(int, int);
	void setAvailability(string,int ,int);
	bool setSpeciality(string);
	char* getSpeciality();

	void InputHospital();

	void setHospitalName(string);
	char* getHospitalName();
	void setHospital(Address&);
	Address& getHospital();
	void setDoc(Doctor&);
	Account& getAccount();
	void setAccount(Account&);

	void setHourlyRatePerson(int);
	int getHourlyRatePerson();

	void setHourlyRateVideo(int);
	int getHourlyRateVideo();

	void setEscapeRoute(int);
	int getEscapeRoute();

	void setRequest(bool);
	bool getRequest();
	

	bool validLocationHospital(string);

	void Display();
	void DisplayAvailableHours();

	
	
	bool Read();
	bool ReadChange();
	bool ReadSignIn();
	bool Write();
	void Update(string);
	

};
