#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include"Doctor.h"
#include "Patient.h"
#include "DoctorSpecialities.h"

using namespace std;

class ShowRecords {
	int GynecologistCounter;
	int DermatologistCounter;
	int OncologistCounter;
	int OrthopedicCounter;

	Gynecologist* Gyndoctors;
	Dermatologist* Dermdoctors;
	Oncologist* Oncoldoctors;
	Orthopedic* Orthopdoctors;
public:


	ShowRecords();

	void ShowAllDoctors();
	void ShowRecordsSpeciality();
	void ShowRecordsLocation();
	void ShowRecordsName();
	void NameFinder(string);
	~ShowRecords();


};
