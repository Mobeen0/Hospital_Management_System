#include<iostream>
using namespace std;
#include "../Date.h"
#include "../Address.h"
#include "../Person.h"
#include "../User.h"
#include "../Patient.h"
#include "../Oladoc.h"
#include "../DoctorSpecialities.h"
#include "../Appointment.h"


int main() {

	Admin admin("AdminUser","pass123456");
	admin.Write();

	Oladoc o;

	o.startup();	


	/*Appointment a;
	a.Read();*/
	

	return 0;
}