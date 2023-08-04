#pragma once
#include<iostream>
#include<fstream>
using namespace std;
#include "User.h"
#include "Patient.h"
#include "Doctor.h"


class Admin:public User {
private:


public:
	Admin();
	Admin(string,string);
	
	void setUser(User&);

	void Menu();

	bool ReadSignIn();
	bool Read();
	bool Write();
	
	
};
