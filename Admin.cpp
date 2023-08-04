#include "Admin.h"

void Admin::setUser(User& other) {

	setName(other.getName());
	setEmail(other.getEmail());
	setPhoneNum(other.getPhoneNum());
	setCNIC(other.getCNIC());
	setDate(other.getDate());
	setAddress(other.getAddress());
	setUsername(other.getUsername());
	setPassword(other.getPassword());
}


bool Admin::Read() {
	Admin tempAdmin;
	ifstream fAdmin("Admin.dat", ios::binary);
	while (fAdmin.read((char*)&tempAdmin, sizeof(tempAdmin))) {
		if ((strcmp(tempAdmin.getUsername(), Username) == 0)) {
			fAdmin.close();
			return false;
		}
	}
	fAdmin.close();

	return true;

}

Admin::Admin() {


}
Admin::Admin(string Username, string Password) {
	
	strcpy_s(this->Username,Username.c_str());
	strcpy_s(this->Password, Password.c_str());

}

bool Admin:: Write() {

	ofstream fPatient("Admin.dat", ios::binary | ios::app);

	if (fPatient) {
		fPatient.write((char*)&*(this), sizeof(*(this)));
		fPatient.close();
		return true;
	}
	fPatient.close();
	return false;

}



bool Admin:: ReadSignIn() {
	Admin tempAdmin;
	ifstream fAdmin("Admin.dat", ios::binary);
	while (fAdmin.read((char*)&tempAdmin, sizeof(tempAdmin))) {
		if ((strcmp(tempAdmin.getUsername(), Username) == 0) && (strcmp(tempAdmin.getPassword(), Password) == 0)) {
			fAdmin.close();
			return true;
		}
	}

	fAdmin.close();
	return false;

}
void Admin::Menu() {
	Date current;
	current.setCurrentDate();
	string choice;
	int len = string(getUsername()).length();
	do {

		system("CLS");
		cout << "**********************************************************************************************" << endl;
		cout << "*                                                                             "; current.display(); cout << "     *" << endl;
		cout << "* Logged In: " << Username << setw(82 - len - 1) << "*" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* =======================================Admin's Value====================================== *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 1 to View All Patients                                                               *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 2 to View All Doctors                                                                *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 3 to Log Out                                                                         *" << endl;
		cout << "*                                                                                            *" << endl;
		cin >> choice;

		if (choice == "1") {
			system("CLS");
			Patient patient;
			patient.Display();
			cin >> choice;
		}
		if (choice == "2") {
			system("CLS");
			Doctor doctor;

			ifstream fDoctor("Doctor.dat",ios::binary);
			while (fDoctor.read((char*)&doctor, sizeof(doctor))) {
				cout << "*--------------------------------------------------------------------------------------------*" << endl;
				cout << "*                                                                                            *" << endl;
				doctor.Display();
				cout << "*                                                                                            *" << endl;
				cout << "*--------------------------------------------------------------------------------------------*" << endl;
				
			}
			fDoctor.close();
			cin >> choice;		
		}
		

	} while (!(choice=="2"));

}