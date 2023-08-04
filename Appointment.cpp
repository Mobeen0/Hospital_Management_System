#include"Appointment.h"


Appointment::Appointment() {
	Day[0] = 'N';
	Day[1] = 'O';
	Day[2] = '\0';

	Status[0] = 'N';
	Status[1] = 'O';
	Status[2] = '\0';

	BookingType[0] = 'N';
	BookingType[1] = 'O';
	BookingType[2] = '\0';

	DoctorName[0] ='N';
	DoctorName[1] = 'O';
	DoctorName[2] = '\0';

	PatientName[0]='N';
	PatientName[1] = 'O';
	PatientName[2] = '\0';

}

void Appointment::MakeAppointment() {
	string choice;
	bool result;

	do {
		system("CLS");
		cout << "*======================================Create Appointment====================================*" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 1 to Make a Quick Appointment       :                                                *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 2 to Make a Customised Appointment  :                                                *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 3 to go Back                        :                                                *" << endl;
		cout << "*                                                                                            *" << endl;
		cin >> choice;

		if (choice == "1") {		

			result= QuickAppointment();

			if (result) {
				cout << "*  Appointment Successfully Made " << endl;
			}
			else {
				cout << "* Could not Find the relevant Doctor " << endl;
			}
			cout << "* Enter a msg to Contiue :  ";
			cin >> choice;
			return;
		}
		if (choice == "2") {
			system("CLS");
			CustomisedAppointment();

		}

	} while (!(choice=="3"));




}

bool Appointment::QuickAppointment() {
	string Name;
	Patient tempPatient;
	int index=0;
	getPatient(index, tempPatient);

	do {
		cout << "*                                                                                            *" << endl;
		cout << "*  Enter the Area of Concern     :  [Gynecologist/Dermatologist/Oncologist/Orthopedic]       *" << endl;
		cin >> Name;
	} while (!(Name == "Gynecologist" || Name == "Dermatologist" || Name == "Oncologist" || Name == "Orthopedic"));

	int length = 0;




	Doctor tempDoctor;
	
	ifstream fDoctor("Doctor.dat", ios::binary);
	while (fDoctor.read((char*)&tempDoctor, sizeof(tempDoctor))) {
		if (strcmp(tempDoctor.getSpeciality(),Name.c_str())==0) {
			for (int day = 0; day < 7; day++) {
				for (int hour = 0; hour < 10; hour++) {
					if (strcmp(tempDoctor.getAvailability(day, hour),"Available")==0) {
						cout << "Avail " << endl;
						tempDoctor.setAvailability("Pending", day, hour);
						
						tempPatient.setStatus("Pending");
							
						tempPatient.setDoctorName(tempDoctor.getName());
							
						tempPatient.setBooking("Person");
							
						setAppointmentValues(tempPatient, tempDoctor, index);

						tempPatient.Update("Personal");
						tempDoctor.Update("Personal");
						
						setDay(day);
						setHourExact(hour);
						fDoctor.close();
						Write();
						return true;
						
						
					}
				}
			}

		}
	}
	fDoctor.close();

	return false;

}

void Appointment::CustomisedAppointment() {
	string choice;
	do {
		system("CLS");
		cout << "*======================================Create Appointment====================================*" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 1 to Directly make Appointment by entering Name :                                    *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 2 to show the list of doctors                   :                                    *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 3 to go back                                    :                                    *" << endl;
		cout << "*                                                                                            *" << endl;
		cin >> choice;

		if (choice == "1") {
			Doctor tempDoctor;
			string name;
			int hourval=0;
			int dayval=0;
			int count = 0;

			Patient tempPatient;
			getPatient(hourval,tempPatient);
			do {
				if (count == 0)
				{
					count++;
				}
				else {
					if (count != 1) {
						cout << "Enter the Name of the Doctor  :  ";
					}
					count++;
					getline(cin, name);
				}
			} while (!(getDoctor(name,tempDoctor)));
			cout << "* Doctor's Available Timings are : " << endl;
			tempDoctor.DisplayAvailableHours();
			do {
				do {
					cout << "* Enter The Day [Monday-Sunday]   :";
					cin >> choice;
					cout << "* Enter the Hour [8-17]           :";
					cin >> hourval;
				} while (!(choice == "Monday" || choice == "Tuesday" || choice == "Wednesday" || choice == "Thursday" || choice == "Friday" || choice == "Saturday" || choice == "Sunday") || (hourval < 8 || hourval>17));
				hourval = hourval - 8;
				if (choice == "Monday")
					dayval = 0;
				if (choice == "Tuesday")
					dayval = 1;
				if (choice == "Wednesday")
					dayval = 2;
				if (choice == "Thursday")
					dayval = 3;
				if (choice == "Friday")
					dayval = 4;
				if (choice == "Saturday")
					dayval = 5;
				if (choice == "Sunday")
					dayval = 6;
			} while (!(strcmp(tempDoctor.getAvailability(dayval,hourval),"Available")==0));
			tempDoctor.setAvailability("Pending", dayval, hourval);

			tempPatient.setStatus("Pending");

			tempPatient.setDoctorName(tempDoctor.getName());

			tempPatient.setBooking("Person");

			setAppointmentValues(tempPatient, tempDoctor, hourval);

			tempPatient.Update("Personal");
			tempDoctor.Update("Personal");

			setDay(dayval);
			setHourExact(hourval);
			Write();

		}
		if (choice == "2") {
			ShowRecords s;
			s.ShowAllDoctors();
		}
	} while (!(choice == "3"));
	
		
	

}


void Appointment::DoctorAppointmentManager() {
	string choice;
	do {
		system("CLS");
		cout << "* ====================================Appointments Viewer=================================== *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 1 to deal with Pending Appointments                                                  *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 2 to deal with Booked Appointments                                                   *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 3 to Exit the Appointments Viewer                                                    *" << endl;
		cout << "*                                                                                            *" << endl;
		cin >> choice;
		if (choice == "1") {
			Doctor tempDoctor;
			string str;
			getDoctor(tempDoctor);
			Appointment tempAppointment;
			int count = 0;
			ifstream fAppointment("Appointment.dat", ios::binary | ios::app);
			while (fAppointment.read((char*)&tempAppointment, sizeof(tempAppointment))) {
				if (strcmp(tempAppointment.getDoctorName(), tempDoctor.getName()) == 0) {
					if (strcmp(tempAppointment.getStatus(), "Pending") == 0) {
						count++;
						tempAppointment.Display();
					}
				}
			}
			fAppointment.close();
			if (count != 0) {
				do {
					cout << "*                                                                                            *" << endl;
					cout << "* Enter the Day [Monday-Sunday] :- ";
					cin >> str;
				} while (!(str == "Monday" || str == "Tuesday" || str == "Wednesday" || str == "Thursday" || str == "Friday" || str == "Saturday" || str == "Sunday"));
				setDay(str);
				do {
					cout << "* Enter the Hour                :- ";
					cin >> count;
				} while (count < 8 || count>17);
				setHour(count);
				do {
					cout << "* Enter the Value you want to Change it to [Booked/Canceled] " << endl;
					cin >> str;
				} while (!(str == "Booked" || str == "Canceled"));
				if (str == "Booked")
					Update("Booked",tempDoctor.getCNIC());
				if (str == "Canceled")
					Update("Canceled",tempDoctor.getCNIC());

				cout << "* Done" << endl;
				cin >> str;
			}
			else {
				cout << "* You Have no Pending Appoinments  " << endl;
				cin >> str;
			}
		}
		if (choice == "2") {
			Doctor tempDoctor;
			string str;
			getDoctor(tempDoctor);
			Appointment tempAppointment;
			int count = 0;
			ifstream fAppointment("Appointment.dat", ios::binary | ios::app);
			while (fAppointment.read((char*)&tempAppointment, sizeof(tempAppointment))) {
				if (strcmp(tempAppointment.getDoctorName(), tempDoctor.getName()) == 0) {
					if (strcmp(tempAppointment.getStatus(), "Booked") == 0) {
						count++;
						tempAppointment.Display();
					}
				}
			}
			fAppointment.close();
			if (count != 0) {
				do {
					cout << "*                                                                                            *" << endl;
					cout << "* Enter the Day [Monday-Sunday] :- ";
					cin >> str;
				} while (!(str == "Monday" || str == "Tuesday" || str == "Wednesday" || str == "Thursday" || str == "Friday" || str == "Saturday" || str == "Sunday"));
				setDay(str);
				do {
					cout << "* Enter the Hour                :- ";
					cin >> count;
				} while (count < 8 || count>17);
				setHour(count);
				do {
					cout << "* Enter the Value you want to Change it to [Complete/Canceled] " << endl;
					cin >> str;
				} while (!(str == "Complete" || str == "Canceled"));
				if (str == "Complete")
					Update("Complete",tempDoctor.getCNIC());
				if (str == "Canceled")
					Update("Canceled",tempDoctor.getCNIC());

				cout << "* Done" << endl;
				cin >> str;
			}
			else {
				cout << "* You have no Booked Appointments " << endl;
				cin >> str;
			}
		}

	} while (!(choice == "3"));
}


void Appointment::getPatient(int & index, Patient& other) {
	Patient tempPatient;

	ifstream fPatient("Patient.dat", ios::binary);
	while (fPatient.read((char*)&tempPatient,sizeof(tempPatient))) {
		
		if (strcmp(tempPatient.getStatus(), "Requested") == 0) {
			other.setPatient(tempPatient);
			fPatient.close();
			return;
		}
	}
	fPatient.close();
}

bool Appointment:: getDoctor(string name, Doctor& other) {
	Doctor tempDoctor;

	ifstream fDoctor("Doctor.dat",ios::binary);
	while (fDoctor.read((char*)&tempDoctor, sizeof(tempDoctor))) {
		if (strcmp(tempDoctor.getName(), name.c_str()) == 0) {
			other.setDoc(tempDoctor);
			fDoctor.close();
			return true;
		}
	}
	fDoctor.close();
	return false;
}

void Appointment:: ShowPatientAppointments() {
	Patient tempPatient;
	int dummy;
	string str;
	getPatient(dummy, tempPatient);

	Appointment tempAppointment;
	int count = 0;
	ifstream fAppointment("Appointment.dat", ios::binary | ios::app);
	while (fAppointment.read((char*)&tempAppointment, sizeof(tempAppointment))) {	
		if (strcmp(tempAppointment.getPatientName(), tempPatient.getName()) == 0) {
			
			if (strcmp(tempAppointment.getStatus(), "Canceled") == 0) {
				
			}
			else {
				count++;
				tempAppointment.Display();
			}

		}
	}
	fAppointment.close();
	
	if (count == 0) {
		cout << "* Sorry you Have No appointments  D:  " << endl;
	}
	cin >> str;

}

void Appointment::ShowDoctorAppointments() {
	Doctor tempDoctor;
	string str;
	getDoctor(tempDoctor);
	Appointment tempAppointment;
	int count = 0;
	ifstream fAppointment("Appointment.dat", ios::binary | ios::app);
	while (fAppointment.read((char*)&tempAppointment, sizeof(tempAppointment))) {
		if (strcmp(tempAppointment.getDoctorName(), tempDoctor.getName()) == 0) {

			if (strcmp(tempAppointment.getStatus(), "Canceled") == 0 || strcmp(tempAppointment.getStatus(),"Completed")==0) {

			}
			else {
				count++;
				tempAppointment.Display();
			}

		}
	}
	fAppointment.close();

	if (count == 0) {
		cout << "* Sorry you Have No appointments  D:  " << endl;
	}
	cin >> str;



}

void Appointment:: getDoctor(Doctor& other) {
	
	Doctor tempDoctor;
	ifstream fDoctor("Doctor.dat", ios::binary);
	while (fDoctor.read((char*)&tempDoctor, sizeof(tempDoctor))) {
		if ((tempDoctor.getRequest())) {
			other.setDoc(tempDoctor);
			fDoctor.close();
			return;
		}
	}
	fDoctor.close();

	return;

}

void Appointment:: CancelPatientAppointments() {
	Patient tempPatient;
	int dummy;
	string str;
	getPatient(dummy, tempPatient);

	Appointment tempAppointment;
	int count = 0;
	ifstream fAppointment("Appointment.dat", ios::binary | ios::app);
	while (fAppointment.read((char*)&tempAppointment, sizeof(tempAppointment))) {
		if (strcmp(tempAppointment.getPatientName(), tempPatient.getName()) == 0) {
			if (strcmp(tempAppointment.getStatus(), "Canceled") == 0) {

			}
			else {
				count++;

				tempAppointment.Display();
			}
		}
	}
	fAppointment.close();

	if (count == 0) {
		cout << "* Sorry you Have No appointments  D:  " << endl;
		cin >> str;
		return;
	}
	else {
		long long int cnic;
		cout << "* Enter the Doctor CNIC of your Appointment : ";
		cin >> cnic;
		cout << "* Enter day of Appointment : ";
		cin >> str;
		cout << "* Enter time of Appointment : ";
		cin >> dummy;
		
		RequestCancel(cnic,str,dummy);

	}

	

}

void Appointment::RequestCancel(long long int cnic, string day, int hour) {
	string str;
	Appointment tempAppointment;
	ifstream fAppointment1("Appointment.dat", ios::binary | ios::app);
	while (fAppointment1.read((char*)&tempAppointment, sizeof(tempAppointment))) {
		if ((tempAppointment.getDoctorCNIC()==cnic && (strcmp(tempAppointment.getDay(),day.c_str())==0) && tempAppointment.getHour()==hour)) {
			fAppointment1.close();
			setAppointment(tempAppointment);
			Update("Cancel");
			cout << "Appointment Has been Cancelled " <<endl;
			cin >> str;
			return;
		}
	}

	fAppointment1.close();
	cout << "Appointment was not cancelled due to wrong Credentials " << endl;
	cin >> str;
	return;
}

void Appointment:: setAppointmentValues(Patient& patient, Doctor& doctor,int index) {
	setDoctorName(doctor.getName());
	setDoctorCNIC(doctor.getCNIC());

	setPatientName(patient.getName());
	
	setPatientCNIC(patient.getCNIC());

	setStatus(patient.getStatus());
	setBooking(patient.getBooking());
	
}

void Appointment:: setAppointment(Appointment& other) {

	setDoctorName(other.getDoctorName());
	setPatientName(other.getPatientName());
	setDoctorCNIC(other.getDoctorCNIC());
	setPatientCNIC(other.getPatientCNIC());
	setStatus(other.getStatus());
	setBooking(other.getBooking());
	setDay(other.getDay());
	setHour(other.getHour());
	
}

void Appointment:: setStatus(string Status) {
	strcpy_s(this->Status, Status.c_str());
}
char* Appointment::getStatus() {
	return Status;
}


void Appointment::setDay(int day) {
	if (day == 0) {
		strcpy_s(Day,"Monday");
	}
	if (day == 1) {
		strcpy_s(Day, "Tuesday");
	}
	if (day == 2) {
		strcpy_s(Day, "Wednesday");
	}
	if (day == 3) {
		strcpy_s(Day, "Thursday");
	}
	if (day == 4) {
		strcpy_s(Day, "Friday");
	}
	if (day == 5) {
		strcpy_s(Day, "Saturday");
	}
	if (day == 6) {
		strcpy_s(Day, "Sunday");
	}

}
void Appointment::setDay(string Day) {
	strcpy_s(this->Day, Day.c_str());
}
char* Appointment::getDay() {
	return Day;
}
int Appointment::getDayExact() {
	if (strcmp(Day,"Monday")==0) {
		return 0;
	}
	if (strcmp(Day, "Tuesday") == 0) {
		return 1;
	}
	if (strcmp(Day, "Wednesday") == 0) {
		return 2;
	}
	if (strcmp(Day, "Thursday") == 0) {
		return 3;
	}
	if (strcmp(Day, "Friday") == 0)
		return 4;
	if (strcmp(Day, "Saturday") == 0)
		return 5;
	if (strcmp(Day, "Sunday") == 0)
		return 6;

}


void Appointment::setHourExact(int value) {
	hour = value + 8;
}
void Appointment::setHour(int value){
	hour = value;
}
int Appointment::getHour() {
	return hour;
}

void Appointment::setBooking(string Booking) {
	strcpy_s(BookingType, Booking.c_str());
}
char* Appointment::getBooking() {
	return BookingType;
}

void Appointment:: setDoctorName(string Name) {
	strcpy_s(DoctorName, Name.c_str());
}
char* Appointment:: getDoctorName() {
	return DoctorName;
}

void Appointment:: setPatientName(string Name) {
	strcpy_s(PatientName, Name.c_str());
}
char* Appointment::getPatientName() {
	return PatientName;
}


long long int Appointment:: getDoctorCNIC() {
	return DoctorCNIC;
}
void Appointment::setDoctorCNIC(long long int value) {
	DoctorCNIC = value;
}

long long int Appointment:: getPatientCNIC() {
	return PatientCNIC;
}
void Appointment:: setPatientCNIC(long long int value) {
	PatientCNIC = value;
}


void Appointment:: Display() {
	cout << "*=====================================Appointment Details====================================*" << endl;
	cout << "*                                                                                            *" << endl;
	cout << "*                                                                                            *" << endl;
	cout << "* Patient Name:  "<< getPatientName()<<"      Patient CNIC : "<< getPatientCNIC() << endl;
	cout << "* Doctor Name:   " << getDoctorName() << "     Doctor CNIC  : " << getDoctorCNIC() << endl;
	cout << "* Appointment Status : " << getStatus() << "      Type  : " << getBooking() << endl;
	cout << "* Appointment Time :  " << getDay()<<" - " << getHour()<<":00 " << endl;
	cout << "*                                                                                            *" << endl;
	cout << "*============================================================================================*" << endl;
}

bool Appointment::Read() {
	Appointment tempAppointment;
	ifstream fAppointment("Appointment.dat",ios::binary | ios::app);
	while (fAppointment.read((char*)&tempAppointment, sizeof(tempAppointment))) {
		setAppointment(tempAppointment);
		if (strcmp(tempAppointment.getStatus(), "Canceled") == 0) {

		}
		else {
			Display();
		}
	}
	fAppointment.close();


	return true;

}
void Appointment::Write() {
	Appointment tempAppointment;
	ofstream fAppointment("Appointment.dat",ios::binary | ios::app);
	if (fAppointment) {
		fAppointment.write((char*)&*(this), sizeof(*(this)));
		fAppointment.close();
	}
	fAppointment.close();
}

void Appointment::Update(string Type) {

	Appointment tempAppointment;
	Doctor tempDoctor;
	Patient tempPatient;
	if (Type == "Cancel") {	
		fstream fAppointment("Appointment.dat", ios::binary | ios::in | ios::out);
		while (fAppointment.read((char*)&tempAppointment, sizeof(tempAppointment))) {
			if ((strcmp(tempAppointment.getDay(), getDay())==0) && (strcmp(tempAppointment.getDoctorName(), getDoctorName()) == 0) && tempAppointment.getHour()==getHour()) {
				int first = fAppointment.tellg();
				fAppointment.seekp(first - sizeof(tempAppointment), ios::beg);
		
				tempAppointment.setStatus("Canceled");
				getDoctor(tempAppointment.getDoctorName(),tempDoctor);
				tempDoctor.setAvailability("Available",tempAppointment.getDayExact(),(tempAppointment.getHour()-8));
				tempDoctor.Update("Personal");
				setAppointment(tempAppointment);
				
				fAppointment.write((char*)&(*this), sizeof((*this)));
				fAppointment.close();
				return;
			}
		}
		fAppointment.close();
		return;
	}
	if (Type == "Reviewed") {
		fstream fAppointment("Appointment.dat", ios::binary | ios::in | ios::out);
		while (fAppointment.read((char*)&tempAppointment, sizeof(tempAppointment))) {
			if ((strcmp(tempAppointment.getDay(), getDay()) == 0) && (strcmp(tempAppointment.getDoctorName(), getDoctorName()) == 0) && tempAppointment.getHour() == getHour()) {
				int first = fAppointment.tellg();
				fAppointment.seekp(first - sizeof(tempAppointment), ios::beg);

				tempAppointment.setStatus("Reviewed");
				setAppointment(tempAppointment);

				fAppointment.write((char*)&(*this), sizeof((*this)));
				fAppointment.close();
				return;
			}
		}
	}
}

void Appointment::Update(string Type, long long int DoctorCNIC) {


	Appointment tempAppointment;
	Doctor tempDoctor;
	Patient tempPatient;

	if (Type == "Booked") {
		fstream fAppointment("Appointment.dat", ios::binary | ios::in | ios::out);
		while (fAppointment.read((char*)&tempAppointment, sizeof(tempAppointment))) {
			if ((strcmp(tempAppointment.getDay(), getDay()) == 0) && tempAppointment.getHour() == getHour() && tempAppointment.getDoctorCNIC()==DoctorCNIC) {
				int first = fAppointment.tellg();
				fAppointment.seekp(first - sizeof(tempAppointment), ios::beg);

				tempAppointment.setStatus("Booked");
				tempDoctor.setRequest(true);
				getDoctor(tempDoctor);
				tempDoctor.setAvailability("Booked", tempAppointment.getDayExact(), (tempAppointment.getHour() - 8));
				
				tempDoctor.Update("Personal");
				setAppointment(tempAppointment);

				fAppointment.write((char*)&(*this), sizeof((*this)));
				fAppointment.close();
				return;
			}
		}
	}
	if (Type == "Canceled") {
		fstream fAppointment("Appointment.dat", ios::binary | ios::in | ios::out);
		while (fAppointment.read((char*)&tempAppointment, sizeof(tempAppointment))) {
			if ((strcmp(tempAppointment.getDay(), getDay()) == 0) && tempAppointment.getHour() == getHour() && tempAppointment.getDoctorCNIC() == DoctorCNIC) {
				int first = fAppointment.tellg();
				fAppointment.seekp(first - sizeof(tempAppointment), ios::beg);

				tempAppointment.setStatus("Canceled");
				tempDoctor.setRequest(true);
				getDoctor(tempDoctor);
				tempDoctor.setAvailability("Available", tempAppointment.getDayExact(), (tempAppointment.getHour() - 8));
				tempDoctor.Update("Personal");

				setAppointment(tempAppointment);

				fAppointment.write((char*)&(*this), sizeof((*this)));
				fAppointment.close();
				return;
			}
		}
	}
	if (Type == "Complete") {
		fstream fAppointment("Appointment.dat", ios::binary | ios::in | ios::out);
		while (fAppointment.read((char*)&tempAppointment, sizeof(tempAppointment))) {
			if ((strcmp(tempAppointment.getDay(), getDay()) == 0) && tempAppointment.getHour() == getHour() && tempAppointment.getDoctorCNIC() == DoctorCNIC) {
				int first = fAppointment.tellg();
				fAppointment.seekp(first - sizeof(tempAppointment), ios::beg);

				tempAppointment.setStatus("Complete");
				tempDoctor.setRequest(true);
				getDoctor(tempDoctor);
				tempDoctor.setAvailability("Available", tempAppointment.getDayExact(), (tempAppointment.getHour() - 8));
				tempDoctor.Update("Personal");

				setAppointment(tempAppointment);

				fAppointment.write((char*)&(*this), sizeof((*this)));
				fAppointment.close();
				return;
			}
		}
	}


}