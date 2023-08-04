#pragma once
#include<iostream>
#include<string>
#include <fstream>
#include "Doctor.h"


using namespace std;


class Gynecologist: public Doctor {
	
public:
	Gynecologist();

	void setDoctor(Doctor&);
};



class Dermatologist :public Doctor {


public:
	Dermatologist();
	void setDoctor(Doctor&);
};

class Oncologist :public Doctor {

public:
	Oncologist();
	void setDoctor(Doctor&);
};

class Orthopedic :public Doctor {

public:
	Orthopedic();
	void setDoctor(Doctor&);
};
