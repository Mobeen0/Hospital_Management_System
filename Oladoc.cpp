#include "Oladoc.h"


void Oladoc::setChoice(string passed) {
	strcpy_s(choice, passed.c_str());
}

void Oladoc::chCoverPage() {
	string option;
	current.setCurrentDate();
	
	system("CLS");

		cout << "	    +	     +             +        ++++           +           ++" << endl;
		cout << "	 +     +     +            + +       +    +      +     +      +" << endl;
		cout << "	+       +    +           +++++      +     +    +       +    +" << endl;
		cout << "	 +     +     +          +     +     +    +      +     +      +" << endl;
		cout << "	    +        ++++++    +       +    ++++           +           ++" << endl;


		cout << endl;

		cout << "	******************************************************************" << endl;
		cout << "	*================================================================*" << endl;
		cout << "	*                                               Date: "; current.display(); cout << " *" << endl;
		cout << "	*                                                                *" << endl;
		cout << "	*                                                                *" << endl;
		cout << "	*  Press 1 to login:                                             *" << endl;
		cout << "	*                                                                *" << endl;
		cout << "	*  Press 2 to Register:                                          *" << endl;
		cout << "	*                                                                *" << endl;
		cout << "	*  Press 3 to Show List of Doctors:                              *" << endl;
		cout << "	*                                                                *" << endl;
		cout << "	*  Press Any Key to Refresh:                                     *" << endl;
		cout << "	*                                                                *" << endl;
		cout << "	******************************************************************" << endl;
		cout << "	*================================================================*" << endl;
		cout << endl;
		cout << "Your choice : ";
		cin >> option;
		setChoice(option);
		if ((choice[0] == '1' && choice[1] == '\0') || (choice[0] == '2' && choice[1] == '\0') || (choice[0] == '3' && choice[1] == '\0')) {

		}
		else {
			system("CLS");
		}



}
void Oladoc::startup() {


	do {
		chCoverPage();

		if (choice[0] == '1' && choice[1]=='\0') {
			Login();

		}
	
		if (choice[0] == '2' && choice[1]=='\0') {
			Registration();
		}

		if (choice[0] == '3' && choice[1] == '\0') {
			system("CLS");
			ShowRecords tempRecord;
			tempRecord.ShowAllDoctors();
		}
		
	} while (true);


	
	

}


void Oladoc::Registration() {
	string name;
	Person temp;
	int count = 0;

	Patient tempPatient;
	Doctor tempDoctor;
	Admin tempAdmin;


	system("CLS");
	cout << "**************************WELCOME TO THE OLADOC CONSOLE REGISTRATION**************************" << endl;
	cout << "*                                                                             "; current.display(); cout<< "     *" << endl;
	cout << "*                                                                                            *" << endl;
	cout << "* ====================================PERSONAL INFORMATION================================== *" << endl;
	temp.InputName();
	temp.InputPhoneNum();
	cout << "*                                                                                            *" << endl;
	temp.InputDate();

	cout << "*                           Valid date has been recognized                                   *" << endl;
	cout << "*                                                                                            *" << endl;
	temp.InputAddress();
	
	cout << "*                                                                                            *" << endl;
	cout << "* ========================================================================================== *" << endl;
	cout << "*                                                                                            *" << endl;
	cout << "*                                                                                            *" << endl;
	cout << "* ====================================USERNAME INFORMATION================================== *" << endl;
	cout << "*                                                                                            *" << endl;
	user.setInformation(temp);
	
			do {
				user.InputUsername();
				user.InputPassword();
				user.InputCNIC();
				user.InputEmail();

				tempPatient.setUser(user);
				tempDoctor.setUser(user);
				tempAdmin.setUser(user);
				count++;
			} while (!(tempPatient.Read() && tempDoctor.Read() && tempAdmin.Read()));
			

	system("CLS");
	
	cout << "*                                                                                            *" << endl;
	do {
	cout << "*                                                                                            *" << endl;
	cout << "*                                                                                            *" << endl;
	cout << "*                      +Thank you for providing basic information+                           *" << endl;
	cout << "*                                                                                            *" << endl;
	
		cout << "*                                                                                            *" << endl;
		cout << "* Enter 1 if you want to Register as Doctor :                                                *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Enter 2 if you want to Register as Patient :                                               *" << endl;
		cout << "*                                                                                            *" << endl;
		cin >> name;
		
	} while (!(name =="1"|| name=="2"));

	system("CLS");

	if (name == "1") { // doctors registration (taking speciality and stuff)
		Userptr = &tempDoctor;

		Userptr->Register();
	}
	else { // choice is 2 then patients account is going to be registered
		Userptr = &tempPatient; // for Polymorphism

		Userptr->Register();
		
		// now store in the file
		// also create a login function
	}	

}

void Oladoc::Login() {
	system("CLS");
	Patient tempPatient;
	Doctor tempDoctor;
	Admin tempAdmin; // remember to polymorph
	cout << "*****************************WELCOME TO THE OLADOC CONSOLE LOGIN******************************" << endl;
	cout << "*                                                                             "; current.display(); cout << "     *" << endl;
	cout << "*                                                                                            *" << endl;
	cout << "* ===================================ENTER SIGN IN DETAILS================================== *" << endl;
	cout << "*                                                                                            *" << endl;
	user.InputUsernameSignIn();
	user.InputPasswordSignIn();
	tempPatient.setUser(user);
	tempDoctor.setUser(user);
	tempAdmin.setUser(user);
	Userptr = &tempPatient;
	if (Userptr->ReadSignIn()) {
		cout << "*****************************YOU HAVE SIGNED IN TO OLADOC AS User*****************************" << endl;
		system("CLS");
		do {
			system("CLS");
			Userptr->setEscapeRoute(0);
			Userptr->Menu();
			if (Userptr->getEscapeRoute() == 1) {
				ShowRecords record;
				record.ShowRecordsSpeciality();
				
			}
			if (Userptr->getEscapeRoute() == 2) {
				ShowRecords record;
				record.ShowRecordsLocation();
			}
			if (Userptr->getEscapeRoute() == 3) {
				ShowRecords record;
				record.ShowRecordsName();
			}
			if (Userptr->getEscapeRoute() == 4) {
				Appointment appointment;
				appointment.MakeAppointment();

			}
			if (Userptr->getEscapeRoute() == 5) {
				Appointment appointment;
				appointment.ShowPatientAppointments();
			}
			if (Userptr->getEscapeRoute() == 6) {
				Appointment appointment;
				appointment.CancelPatientAppointments();
			}
			if (Userptr->getEscapeRoute() == 7) {
				Feedback feedback;
				feedback.getAppointment();
			}
		} while (Userptr->getEscapeRoute() != 0);
	}
	else {
		Userptr = &tempDoctor;
		if (Userptr->ReadSignIn()) {

			cout << "****************************YOU HAVE SIGNED IN TO OLADOC AS DOCTOR************************" << endl;
			system("CLS");
			do {
				system("CLS");
				Userptr->setEscapeRoute(0);
				Userptr->Menu();
				if (Userptr->getEscapeRoute() == 2) {
					Appointment appointment;
					appointment.DoctorAppointmentManager();
				}
				if (Userptr->getEscapeRoute() == 3) {
					Appointment appointment;
					appointment.ShowDoctorAppointments();
				}
				if (Userptr->getEscapeRoute() == 4) {
					Feedback feedback;
					feedback.ShowDoctor();
				}
			} while (Userptr->getEscapeRoute() != 0);

			
		}
		else {
			Userptr = &tempAdmin;
			if (Userptr->ReadSignIn()) {
				system("CLS");
				Userptr->Menu();
			}
			else {
				string str;
				cout << "**************************INCORRECT USERNAME OR PASSWORD*********************************" << endl;
				cin >> str;
			}
		}
	}

}

