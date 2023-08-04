#include "Patient.h"

Patient::Patient() {
	EscapeRoute = 0;
	

	DoctorName[0] = 'N';
	DoctorName[1] = 'O';
	DoctorName[2] = '\0';

	Status[0] = 'N';
	Status[1] = 'O';
	Status[2] = '\0';
	TypeOfBooking[0] = 'N';
	TypeOfBooking[1] = 'O';
	TypeOfBooking[2] = '\0';


}

Patient::Patient(User& other):User(other) {
	EscapeRoute = 0;


	DoctorName[0] = 'N';
	DoctorName[1] = 'O';
	DoctorName[2] = '\0';

	Status[0] = 'N';
	Status[1] = 'O';
	Status[2] = '\0';
	TypeOfBooking[0] = 'N';
	TypeOfBooking[1] = 'O';
	TypeOfBooking[2] = '\0';




}

void Patient::Register() {

	string tempstr;
	
	
	cout << "*===========================WELCOME TO Patient's Registeration Center========================*" << endl;
	cout << "*                                                                                            *" << endl;
	cout << "*                                                                                            *" << endl;
	cout << "*             *************Enter Your Billing information*************                       *" << endl;
	account.InputAccountNum();
	account.InputMode();
	cout << "*                                                                                            *" << endl;
	
	system("CLS");

	if (Write()) {
		cout << "*=======================Congradulations your Account has been Registered=====================*" << endl;
		cout << "*                                                                                            *" << endl;

	}
	

}

int Patient::getEscapeRoute() {
	return EscapeRoute;

}

void Patient:: setEscapeRoute(int value) {
	EscapeRoute = value;
}
void Patient:: Login() {
	

}

void Patient::Menu() {

		Date current;
		current.setCurrentDate();
		string choice;
		int len = string(getUsername()).length();
		
	
		if (strcmp(getStatus(), "Requested") == 0) {
			setStatus("NO");
			Update("Personal");
		}

		do {
			if (EscapeRoute != 0) {
				system("CLS");
				return;
			}
			system("CLS");
			cout << "**********************************************************************************************" << endl;
			cout << "*                                                                             "; current.display(); cout << "     *" << endl;
			cout << "* Logged In: " << Username << setw(82 - len - 1) << "*" << endl;
			cout << "* Wallet   : " << account.getBalance() << "                                                                           *" << endl;
			cout << "*                                                                                            *" << endl;
			cout << "* =======================================Patient's MENU===================================== *" << endl;
			cout << "*                                                                                            *" << endl;
			cout << "*                                                                                            *" << endl;
			cout << "* Press 1 to Search for Doctors  :                                                           *" << endl;
			cout << "*                                                                                            *" << endl;
			cout << "* Press 2 to Manage Appointments :                                                           *" << endl;
			cout << "*                                                                                            *" << endl;
			cout << "* Press 3 to Manage your Account :                                                           *" << endl;
			cout << "*                                                                                            *" << endl;
			cout << "* Press 4 to Log out             :                                                           *" << endl;
			cout << "*                                                                                            *" << endl;
			cin >> choice;

			if (choice == "1") {
				system("CLS");
				DoctorSort();
			}
			if (choice == "2") {
				system("CLS");
				ManageAppointment();
			}
			if (choice == "3") {
				system("CLS");
				ManageProfile();
			}

		} while (!(choice == "4"));

	system("CLS");


}

void Patient:: ManageProfile() {
	Date current;
	current.setCurrentDate();
	string choice;
	int len = string(getUsername()).length();
	double amount;
	
	do {
		len = string(getUsername()).length();
		system("CLS");
		cout << "**********************************************************************************************" << endl;
		cout << "*                                                                             "; current.display(); cout << "     *" << endl;
		cout << "* Logged In: " << Username << setw(82 - len - 1) << "*" << endl;
		cout << "* Wallet   : " << account.getBalance() << "                                                                           *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* ===============================Patient's Profile Manager================================== *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 1 to Update your UserName        :                                                   *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 2 to Update your Password        :                                                   *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 3 to Add funds to Your Account   :                                                   *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 4 to Update Personal Information :                                                   *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 5 to Exit Profile Manager        :                                                   *" << endl;
		cout << "*                                                                                            *" << endl;
		cin >> choice;

		if (choice == "1") {
			system("CLS");
			do {
				InputUsername();
			} while (!(ReadChange()));
			Update("Username");
			cout << "UserName Successfully Updated" << endl;
		}
		if (choice == "2") {
			system("CLS");

			InputPassword();
			Update("Password");
			cout << "Password Successfully Updated" << endl;
		}
		if (choice == "3") {
			system("CLS");

			cout << "Enter the ammount you want to Add in your Account : ";
			cin >> amount;
			account.DepositBalance(amount);
			Update("Personal");
			cout << "Balance Successfully Added " << endl;
			

		}
		if (choice == "4") {
			system("CLS");
			PersonalInfo();

		}
		if (!(choice=="1" || choice=="2" || choice =="3" || choice =="4")) {
			system("CLS");
		}
		
	} while (!(choice=="5"));

	system("CLS");



}

void Patient:: PersonalInfo() {

	Date current;
	current.setCurrentDate();
	string choice;
	int len = string(getUsername()).length();

	do {
		system("CLS");
		len = string(getUsername()).length();
		cout << "**********************************************************************************************" << endl;
		cout << "*                                                                             "; current.display(); cout << "     *" << endl;
		cout << "* Logged In: " << Username << setw(82 - len - 1) << "*" << endl;
		cout << "* Wallet   : " << account.getBalance() << "                                                                           *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* =============================Patient's Personal Information=============================== *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 1 to Update Name         :                                                           *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 2 to Update PhoneNumber  :                                                           *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 3 to Update CNIC         :                                                           *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 4 to Leave this Page     :                                                           *" << endl;
		cout << "*                                                                                            *" << endl;
		cin >> choice;

		if (choice == "1") {
			system("CLS");
			InputName();
			Update("Personal");

		}
		if (choice == "2") {
			system("CLS");
			InputPhoneNum();
			Update("Personal");

		}
		if (choice == "3") {
			system("CLS");
			InputCNIC();
			Update("Personal");
		}
		if (!(choice == "1" || choice == "2" || choice == "3")) {
			system("CLS");
		}

	} while (!(choice=="4"));

	system("CLS");
}


void Patient:: DoctorSort() {
	Date current;
	current.setCurrentDate();
	string choice;
	int len = string(getUsername()).length();
	do {
		if (EscapeRoute != 0) {
			system("CLS");
			return;
		}
		system("CLS");
		len = string(getUsername()).length();
		cout << "**********************************************************************************************" << endl;
		cout << "*                                                                             "; current.display(); cout << "     *" << endl;
		cout << "* Logged In: " << Username << setw(82 - len - 1) << "*" << endl;
		cout << "* Wallet   : " << account.getBalance() << "                                                                           *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* ==============================Patient's Doctor Information================================ *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 1 to View Doctors by their Speciality  :                                             *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 2 to Search for a Doctor by their City :                                             *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 3 to Search for a Doctor by their Name :                                             *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 4 to exit Doctor Information Center    :                                             *" << endl;
		cout << "*                                                                                            *" << endl;
		cin >> choice;

		if (choice == "1") {
			system("CLS");
			EscapeRoute = 1;
			
		}
		if (choice == "2") {
			system("CLS");
			EscapeRoute = 2;
		}
		if (choice == "3") {
			system("CLS");
			EscapeRoute = 3;
		}
		
		system("CLS");

	} while (!(choice=="4"));
}

void Patient:: ManageAppointment() {
	Date current;
	current.setCurrentDate();
	string choice;
	int len = string(getUsername()).length();
	do {
		if (EscapeRoute != 0) {
			system("CLS");
			return;
		}
		system("CLS");
		cout << "**********************************************************************************************" << endl;
		cout << "*                                                                             "; current.display(); cout << "     *" << endl;
		cout << "* Logged In: " << Username << setw(82 - len - 1) << "*" << endl;
		cout << "* Wallet   : " << account.getBalance() << "                                                                           *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* ================================Patient's Appointment Center============================== *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 1 to View your Appointments         :                                                *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 2 to Make an Appointment            :                                                *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 3 to Cancel an Appointment          :                                                *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 4 to check any Pending Feedbacks    :                                                *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 5 to go Back                        :                                                *" << endl;
		cout << "*                                                                                            *" << endl;
		cin >> choice;

		if (choice == "1") {
			EscapeRoute = 5;
			setStatus("Requested");
			Update("Personal");
		}
		if (choice == "2") {
				
			setStatus("Requested");				
			Update("Personal");		
			EscapeRoute = 4;
		
		}
		if (choice == "3") {
			setStatus("Requested");
			Update("Personal");
			EscapeRoute = 6;
		}
		if (choice == "4") {
			setStatus("Requested");
			Update("Personal");
			EscapeRoute = 7;
		}
			

	} while (!(choice=="5"));


}


void Patient::Display() {
	cout << "* ================================Patient's Data Center===================================== *" << endl;
	cout << "*                                                                                            *" << endl;

	Patient tempPatient;
	ifstream fPatient("Patient.dat", ios::binary);
	while (fPatient.read((char*)&tempPatient, sizeof(tempPatient))) {
		cout << "*--------------------------------------------------------------------------------------------*" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "Patient Name : " << tempPatient.getName() << "  CNIC :  " << tempPatient.getCNIC() << endl;
		cout << "Patient UserName : " << tempPatient.getUsername() << " Patient Password : " << tempPatient.getPassword() << endl;
		cout << "Patient Email : " << tempPatient.getEmail() << endl;
		cout << "*                                                                                            *" << endl;
		cout << "*--------------------------------------------------------------------------------------------*" << endl;
		
	}

	fPatient.close();
	
	

}
void Patient::setUser(User& other) {
	
	setName(other.getName());
	setEmail(other.getEmail());
	setPhoneNum(other.getPhoneNum());
	setCNIC(other.getCNIC());
	setDate(other.getDate());
	setAddress(other.getAddress());
	setUsername(other.getUsername());
	setPassword(other.getPassword());
	
}
void Patient::setAccount(Account& other) {
	account.setAccountNum(other.getAccountNum());
	account.setBalance(other.getBalance());
	account.setBank(other.getBank());
	account.setEGateway(other.getEGateway());
	account.setFine(other.getFine());

}
void Patient::setStatus(string stat) {
	strcpy_s(this->Status, stat.c_str());

}
char* Patient::getStatus() {
	return Status;
}
void Patient::setBooking(string book) {
	strcpy_s(this->TypeOfBooking, book.c_str());
}

char* Patient:: getBooking() {
	return TypeOfBooking;
}


Account& Patient::getAccount() {
	return account;
}

void Patient::setScheduleTime(DateTime& other) {

	ScheduleTime.setYear(other.getYear());
	ScheduleTime.setMonth(other.getMonth());
	ScheduleTime.setDay(other.getDay());
	ScheduleTime.setHour(other.getHour());

}
DateTime& Patient::getScheduleTime() {
	return ScheduleTime;
}

void Patient:: setDoctorName(string DoctorName) {
	strcpy_s(this->DoctorName, DoctorName.c_str());

}
char* Patient::getDoctorName() {
	return DoctorName;
}

void Patient::setPatient(Patient& other) {

	this->setName(other.getName());
	this->setEmail(other.getEmail());
	this->setPhoneNum(other.getPhoneNum());
	this->setCNIC(other.getCNIC());
	this->setDate(other.getDate());
	this->setAddress(other.getAddress());
	this->setUsername(other.getUsername());
	this->setPassword(other.getPassword());
	this->setAccount(other.getAccount());
	this->setStatus(other.getStatus());
	this->setBooking(other.getBooking());
	this->setDoctorName(other.getDoctorName());
	this->setScheduleTime(other.getScheduleTime());	


}
bool Patient::Read() {
	Patient tempPatient;
	ifstream fPatient("Patient.dat", ios::binary);
	while (fPatient.read((char*)&tempPatient, sizeof(tempPatient))) {
		
		if ((strcmp(tempPatient.getUsername(), Username) == 0)) {
			fPatient.close();
			cout << "*                                                                                            *" << endl;
			cout << "* This Username already exists, please Enter another Username                                *" << endl;
			cout << "*                                                                                            *" << endl;
			return false;
		}
		if ((strcmp(tempPatient.getEmail(), Email) == 0)) {
			fPatient.close();
			cout << "*                                                                                            *" << endl;
			cout << "* This Email already exists, please Enter another Email                                      *" << endl;
			cout << "*                                                                                            *" << endl;
			return false;
		}
		if (tempPatient.getCNIC() == CNIC) {
			fPatient.close();
			cout << "*                                                                                            *" << endl;
			cout << "* This CNIC already exists, please Enter another CNIC                                        *" << endl;
			cout << "*                                                                                            *" << endl;
			return false;
		}
	}

	fPatient.close();

	return true;
}

bool Patient:: ReadSignIn() {
	//char key;
	Patient tempPatient;
	ifstream fPatient("Patient.dat", ios::binary);
	while (fPatient.read((char*)&tempPatient, sizeof(tempPatient))) {
		if ((strcmp(tempPatient.getUsername(), Username) == 0) && (strcmp(tempPatient.getPassword(),Password)==0)) {	
			fPatient.close();
			setPatient(tempPatient);
			return true;
		}
	}

	fPatient.close();
	return false;

}

bool Patient::Write() {
	
	ofstream fPatient("Patient.dat",ios::binary | ios::app);

	if (fPatient) {
		fPatient.write((char*)&*(this), sizeof(*(this)));
		fPatient.close();
		return true;
	}
	fPatient.close();
	return false;

}
bool Patient:: ReadChange() {
	Patient tempPatient;
	ifstream fPatient("Patient.dat", ios::binary);
	while (fPatient.read((char*)&tempPatient, sizeof(tempPatient))) {
		/*tempPatient.display();
		cout << tempPatient.getUsername() << "   and " << tempPatient.getPassword() << endl;*/
		if ((strcmp(tempPatient.getUsername(), Username) == 0)) {
			fPatient.close();
			cout << "*                                                                                            *" << endl;
			cout << "* This Username already exists, please Enter another Username                                *" << endl;
			cout << "*                                                                                            *" << endl;
			return false;
		}
	}

	fPatient.close();

	return true;

}
void Patient:: Update(string type) {

	Patient tempPatient;
	string name1;
	string name2;

	if (type == "Username") {
		fstream fPatient("Patient.dat", ios::binary | ios::in | ios::out);
		while (fPatient.read((char*)&tempPatient, sizeof(tempPatient))) {
			if (!(strcmp(tempPatient.getName(), getName())) && tempPatient.getCNIC() == getCNIC() && tempPatient.getPhoneNum() == getPhoneNum()) {
				int first = fPatient.tellg();
				fPatient.seekp(first - sizeof(tempPatient), ios::beg);
				fPatient.write((char*)&*(this), sizeof(*(this)));
				fPatient.close();
				return;
			}
		}
		fPatient.close();
		return;
	}

	if (type == "Password") {
		fstream fPatient("Patient.dat", ios::binary | ios::in | ios::out);
		while (fPatient.read((char*)&tempPatient, sizeof(tempPatient))) {
			if (!(strcmp(tempPatient.getUsername(), getUsername()))) {
				int first = fPatient.tellg();
				fPatient.seekp(first - sizeof(tempPatient), ios::beg);
				fPatient.write((char*)&*(this), sizeof(*(this)));
				fPatient.close();
				return;
			}
		}
		fPatient.close();
		return;
	}

	if (type == "Personal") {
		fstream fPatient("Patient.dat", ios::binary | ios::in | ios::out);
		while (fPatient.read((char*)&tempPatient, sizeof(tempPatient))) {
			if (!(strcmp(tempPatient.getUsername(), getUsername()))) {
				int first = fPatient.tellg();
				fPatient.seekp(first - sizeof(tempPatient), ios::beg);
				fPatient.write((char*)&*(this), sizeof(*(this)));
				fPatient.close();
				return;
			}
		}
		fPatient.close();
		return;
	}





}
