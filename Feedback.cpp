#include "Feedback.h"

Feedback::Feedback() {

	
	Rating = 0;
	Review[0] = 'N';
	Review[1] = 'o';
	Review[2] = ' ';
	Review[3] = 'R';
	Review[4] = 'e';
	Review[5] = 'v';
	Review[6] = 'i';
	Review[7] = 'e';
	Review[8] = 'w';
	Review[9] = '\0';

}

void Feedback:: setReview(string Review) {
	strcpy_s(this->Review,Review.c_str());

}
void Feedback::setRating(float Rating) {
	this->Rating = Rating;
}

char* Feedback::getReview() {
	return Review;
}
float Feedback::getRating() {
	return Rating;
}


void Feedback::getPatient(Patient& other) {

}

void Feedback:: InputReview() {

	string name;
	int count = 0;
	cout << "* Enter your Review for the Appointment Against : ";
	do {
		if (count == 0)
		{
			count++;
		}
		else {
			getline(cin, name);
		}
	} while (name.length() == 0);

}

void Feedback::ShowDoctor() {
	Appointment appointment;
	Doctor tempDoctor;
	string str;
	appointment.getDoctor(tempDoctor);

	Appointment tempAppointment;
	ifstream fAppointment("Appointment.dat", ios::binary | ios::app);
	while (fAppointment.read((char*)&tempAppointment, sizeof(tempAppointment))) {
		appointment.setAppointment(tempAppointment);
		//cout << "temp CNIC is " << endl;
		if (strcmp(tempAppointment.getStatus(), "Reviewed") == 0 && tempAppointment.getDoctorCNIC()==tempDoctor.getCNIC()) {
			tempAppointment.Display();
			Read(tempDoctor);
			cout << " Review :  " << Review << endl;
			cout << " Rating:   " << Rating <<endl;
			cout << "===========================================" << endl;
		}

	}

	cout << endl;
	cout << "Enter something to continue   :";
	cin >> str;

}

void Feedback:: getAppointment() {
	Appointment appointment;
	Patient tempPatient;

	int dummy;

	Appointment tempAppointment;
	tempAppointment.getPatient(dummy, tempPatient);
	ifstream fAppointment("Appointment.dat", ios::binary | ios::app);
	while (fAppointment.read((char*)&tempAppointment, sizeof(tempAppointment))) {
		appointment.setAppointment(tempAppointment);
		if (strcmp(tempAppointment.getStatus(), "Complete") == 0 && tempPatient.getCNIC()==tempAppointment.getPatientCNIC()) {
			string name;
			int count = 0;
			cout << "* Enter your Review for the Appointment Against " << appointment.getDoctorName()<< " :  ";
			do {
				if (count == 0)
				{
					count++;
				}
				else {
					getline(cin, name);
				}
			} while (name.length() == 0);
			setReview(name);
			do {
				cout << "Give a Rating  ";
				cin >> Rating;
			} while (Rating<0 || Rating>5);
			return;
			appointment.setStatus("Reviewed");
			appointment.Update("Reviewed");
		}
	}
	fAppointment.close();
	Write();

	
}

void Feedback:: Write() {
	
	ofstream fFeedback("Feedback.dat", ios::binary | ios::app);

	if (fFeedback) {
		fFeedback.write((char*)&*(this), sizeof(*(this)));
		fFeedback.close();
		return;
	}
	fFeedback.close();
	return;

}

void Feedback::Read(Doctor& tempDoctor) {
	ifstream fFeedback("Feedback.dat",ios::binary);

	while (fFeedback.read((char*)&*(this),sizeof(*(this)))) {
		if (tempDoctor.getCNIC() == DocCNIC) {



			fFeedback.close();
			return;
		}	
	}
	fFeedback.close();
}