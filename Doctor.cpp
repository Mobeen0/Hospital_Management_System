#include "Doctor.h"



Doctor::Doctor() {

	for (int day = 0; day < 7; day++) {
		for (int hour = 0; hour < 10; hour++) {
			Availability[day][hour][0] = 'N';
			Availability[day][hour][1] = 'o';
			Availability[day][hour][2] = 't';
			Availability[day][hour][3] = ' ';
			Availability[day][hour][4] = 'A';
			Availability[day][hour][5] = 'v';
			Availability[day][hour][6] = 'a';
			Availability[day][hour][7] = 'i';
			Availability[day][hour][8] = 'l';
			Availability[day][hour][9] = 'a';
			Availability[day][hour][10] = 'b';
			Availability[day][hour][11] = 'l';
			Availability[day][hour][12] = 'e';
			Availability[day][hour][13] = '\0';
		}
	}

	Speciality[0] = 'N';
	Speciality[1] = 'O';
	Speciality[2] = '\0';

	EscapeRoute = 0;
	HourlyChargeInPerson = 1000;
	HourlyChargeVideo = 500;
	
	Request = false;

}

void Doctor:: Register() {
	string str;
	cout << "*===========================WELCOME TO Doctor's Registeration Center========================*" << endl;
	cout << "*                                                                                            *" << endl;
	cout << "*                                                                                            *" << endl;
	cout << "*             *************Enter Your Billing information*************                       *" << endl;
	account.InputAccountNum();
	account.InputMode();
	cout << "*                                                                                            *" << endl;

	system("CLS");

	do {
		cout << "*                                                                                            *" << endl;
		cout << "*  Input your Speciality :-     [Gynecologist/Dermatologist/Oncologist/Orthopedic]           *" << endl;
		cin >> str;
	} while (!(setSpeciality(str)));


	system("CLS");
	cout << "*                                                                                            *" << endl;
	InputHospital();
	system("CLS");

	if (Write()) {
		cout << "*                                                                                            *" << endl;
		cout << "===================================DOCTOR ACCOUNT REGISTERED==================================" << endl;
		cout << "*                                                                                            *" << endl;
	}
	else{
		cout << "* Could not register the Account                                                             *" << endl;
	}
	
	system("CLS");
}

void Doctor:: Menu() {
	Date current;
	current.setCurrentDate();
	string choice;
	int len = string(getUsername()).length();
	if (Request) {
		Request = false;
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
		cout << "* =======================================Doctor's MENU====================================== *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 1 to Manage Availability and Hourly Charge :                                         *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 2 to Manage your Appointments              :                                         *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 3 to Display All your Appointments         :                                         *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 4 to Edit your Profile Information         :                                         *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 5 to View Feedbacks                        :                                         *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 6 to Log Out                               :                                         *" << endl;
		cout << "*                                                                                            *" << endl;
		cin >> choice;

		if (choice == "1") {
			system("CLS");
			AvailAndHourSetter();
		}
		if (choice == "2") {			
			EscapeRoute = 2;
			Request = true;
			Update("Personal");
		}
		if (choice == "3") {
			EscapeRoute = 3;
			Request = true;
			Update("Personal");
		}
		if (choice == "4") {
			ManageProfile();
		}
		if (choice == "5") {
			EscapeRoute = 4;
			Request = true;
			Update("Personal");
		}

	} while (!(choice=="6"));

}


void Doctor:: AvailAndHourSetter() {
	Date current;
	current.setCurrentDate();
	string choice;
	int len = string(getUsername()).length();
	int value;

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
		cout << "* =======================================Doctor's MENU====================================== *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 1 view your Availablitiy Hours    :                                                  *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 2 to set your Availability Hours  :                                                  *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 3 to set your Hourly Rates        :                                                  *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 4 to go back                      :                                                  *" << endl;
		cout << "*                                                                                            *" << endl;
		cin >> choice;

		if (choice == "1") {
			system("CLS");
			viewAvailabilityHours();
		}
		if (choice == "2") {
			system("CLS");
			setAvailabilityHours();
		}
		if (choice == "3") {
			do {
				cout << "*                                                                                            *" << endl;
				cout << "* Enter the Value of Hourly Rate (In-Person)     :      ";
				cin >> value;
			} while (value <= 0);
			setHourlyRatePerson(value);		
			do {
				cout << "*                                                                                            *" << endl;
				cout << "* Enter the Value of Hourly Rate (Video)     :      ";
				cin >> value;
			} while (value <= 0);
			setHourlyRateVideo(value);
			Update("Personal");
		}



	} while (!(choice=="4"));

}

void Doctor::ManageProfile() {
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
		cout << "* ===============================Doctor's Profile Manager=================================== *" << endl;
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
		if (!(choice == "1" || choice == "2" || choice == "3" || choice == "4")) {
			system("CLS");
		}

	} while (!(choice == "5"));

	system("CLS");



}


void Doctor::PersonalInfo() {
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
		cout << "* =============================Doctor's Personal Information================================ *" << endl;
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
		} while (!(choice == "4"));


}

void Doctor:: setAvailabilityHours() {
	string choice;
	int hourval;
	cout << "*                                                                                            *" << endl;
	cout << "**********************************************************************************************" << endl;
	cout << "*                                                                                            *" << endl;
	do {
		system("CLS");
		cout << "* Press 1 to set All Hours to Available (Week)       :                                       *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 2 to set All Hours to Not Available (Week)   :                                       *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 3 to set All Hours to Available (Day)        :                                       *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 4 to set All Hours to Not Available (Day)    :                                       *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 5 to set a Particular Hour to Available      :                                       *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 6 to set a Particular Hour to Not Available  :                                       *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 7 to go Back                                 :                                       *" << endl;
		cout << "*                                                                                            *" << endl;
		cin >> choice;

		if (choice == "1"){
			for (int day = 0; day < 7; day++) {
				for (int hour = 0; hour < 10; hour++) {
					if (strcmp(Availability[day][hour], "Not Available") == 0) {
						strcpy_s(Availability[day][hour], "Available");
					}
				}
			}
		}
		if (choice == "2") {
			for (int day = 0; day < 7; day++) {
				for (int hour = 0; hour < 10; hour++) {
					if (strcmp(Availability[day][hour], "Available") == 0) {
						strcpy_s(Availability[day][hour], "Not Available");
					}
				}
			}
		}
		if (choice == "3") {
			do {
				cout << "* Enter The Day [Monday-Sunday]   :";
				cin >> choice;
			} while (!(choice == "Monday" || choice == "Tuesday" || choice == "Wednesday" || choice == "Thursday" || choice =="Friday" || choice=="Saturday" || choice=="Sunday"));
			if (choice == "Monday") {
				for (int i = 0; i < 10; i++) {
					if (strcmp(Availability[0][i], "Not Available") == 0) {
						strcpy_s(Availability[0][i], "Available");
					}
				}
			}
			if (choice == "Tuesday") {
				for (int i = 0; i < 10; i++) {
					if (strcmp(Availability[1][i], "Not Available") == 0) {
						strcpy_s(Availability[1][i], "Available");
					}
				}
			}
			if (choice == "Wednesday") {
				for (int i = 0; i < 10; i++) {
					if (strcmp(Availability[2][i], "Not Available") == 0) {
						strcpy_s(Availability[2][i], "Available");
					}
				}
			}
			if (choice == "Thursday") {
				for (int i = 0; i < 10; i++) {
					if (strcmp(Availability[3][i], "Not Available") == 0) {
						strcpy_s(Availability[3][i], "Available");
					}
				}
			}
			if (choice == "Friday") {
				for (int i = 0; i < 10; i++) {
					if (strcmp(Availability[4][i], "Not Available") == 0) {
						strcpy_s(Availability[4][i], "Available");
					}
				}
			}
			if (choice == "Saturday") {
				for (int i = 0; i < 10; i++) {
					if (strcmp(Availability[5][i], "Not Available") == 0) {
						strcpy_s(Availability[5][i], "Available");
					}
				}
			}
			if (choice == "Sunday") {
				for (int i = 0; i < 10; i++) {
					if (strcmp(Availability[6][i], "Not Available") == 0) {
						strcpy_s(Availability[6][i], "Available");
					}
				}
			}
		}
		if (choice == "4") {
			do {
				cout << "* Enter The Day [Monday-Sunday]   :";
				cin >> choice;
			} while (!(choice == "Monday" || choice == "Tuesday" || choice == "Wednesday" || choice == "Thursday" || choice == "Friday" || choice == "Saturday" || choice == "Sunday"));
			if (choice == "Monday") {
				for (int i = 0; i < 10; i++) {
					if (strcmp(Availability[0][i], "Available")) {
						strcpy_s(Availability[0][i], "Not Available");
					}
				}
			}
			if (choice == "Tuesday") {
				for (int i = 0; i < 10; i++) {
					if (strcmp(Availability[1][i], "Available")) {
						strcpy_s(Availability[1][i], "Not Available");
					}
				}
			}
			if (choice == "Wednesday") {
				for (int i = 0; i < 10; i++) {
					if (strcmp(Availability[2][i], "Available")) {
						strcpy_s(Availability[2][i], "Not Available");
					}
				}
			}
			if (choice == "Thursday") {
				for (int i = 0; i < 10; i++) {
					if (strcmp(Availability[3][i], "Available")) {
						strcpy_s(Availability[3][i], "Not Available");
					}
				}
			}
			if (choice == "Friday") {
				for (int i = 0; i < 10; i++) {
					if (strcmp(Availability[4][i], "Available")) {
						strcpy_s(Availability[4][i], "Not Available");
					}
				}
			}
			if (choice == "Saturday") {
				for (int i = 0; i < 10; i++) {
					if (strcmp(Availability[5][i], "Available")) {
						strcpy_s(Availability[5][i], "Not Available");
					}
				}
			}
			if (choice == "Sunday") {
				for (int i = 0; i < 10; i++) {
					if (strcmp(Availability[6][i], "Available")) {
						strcpy_s(Availability[6][i], "Not Available");
					}
				}
			}
		}
		if (choice == "5") {
			do {
				cout << "* Enter The Day [Monday-Sunday]   :";
				cin >> choice;
				cout << "* Enter the Hour [8-17]           :";
				cin >> hourval;
			} while (!(choice == "Monday" || choice == "Tuesday" || choice == "Wednesday" || choice == "Thursday" || choice == "Friday" || choice == "Saturday" || choice == "Sunday") || (hourval < 8 || hourval>17));
			if (choice == "Monday") {
				if (strcmp(Availability[0][hourval-8],"Not Available")==0) {
					strcpy_s(Availability[0][hourval - 8], "Available");
				}

			}
			if (choice == "Tuesday") {
				if (strcmp(Availability[1][hourval - 8], "Not Available") == 0) {
					strcpy_s(Availability[1][hourval - 8], "Available");
				}

			}
			if (choice == "Wednesday") {
				if (strcmp(Availability[2][hourval - 8], "Not Available") == 0) {
					strcpy_s(Availability[2][hourval - 8], "Available");
				}

			}
			if (choice == "Thursday") {
				if (strcmp(Availability[3][hourval - 8], "Not Available") == 0) {
					strcpy_s(Availability[3][hourval - 8], "Available");
				}

			}
			if (choice == "Friday") {
				if (strcmp(Availability[4][hourval - 8], "Not Available") == 0) {
					strcpy_s(Availability[4][hourval - 8], "Available");
				}

			}
			if (choice == "Saturday") {
				if (strcmp(Availability[5][hourval - 8], "Not Available") == 0) {
					strcpy_s(Availability[5][hourval - 8], "Available");
				}

			}
			if (choice == "Sunday") {
				if (strcmp(Availability[6][hourval - 8], "Not Available") == 0) {
					strcpy_s(Availability[6][hourval - 8], "Available");
				}

			}
		}

		if (choice == "6") {
			do {
				cout << "* Enter The Day [Monday-Sunday]   :";
				cin >> choice;
				cout << "* Enter the Hour [8-17]           :";
				cin >> hourval;
			} while (!(choice == "Monday" || choice == "Tuesday" || choice == "Wednesday" || choice == "Thursday" || choice == "Friday" || choice == "Saturday" || choice == "Sunday") || (hourval<8 || hourval>17 ));
			if (choice == "Monday") {
				if (strcmp(Availability[0][hourval - 8], "Available") == 0) {
					strcpy_s(Availability[0][hourval - 8], "Not Available");
				}
				
			}
			if (choice == "Tuesday") {
				if (strcmp(Availability[1][hourval - 8], "Available") == 0) {
					strcpy_s(Availability[1][hourval - 8], "Not Available");
				}
				
			}
			if (choice == "Wednesday") {
				if (strcmp(Availability[2][hourval - 8], "Available") == 0) {
					strcpy_s(Availability[2][hourval - 8], "Not Available");
				}
				
			}
			if (choice == "Thursday") {
				if (strcmp(Availability[3][hourval - 8], "Available") == 0) {
					strcpy_s(Availability[3][hourval - 8], "Not Available");
				}
				
			}
			if (choice == "Friday") {
				if (strcmp(Availability[4][hourval - 8], "Available") == 0) {
					strcpy_s(Availability[4][hourval - 8], "Not Available");
				}
				
			}
			if (choice == "Saturday") {
				if (strcmp(Availability[5][hourval - 8], "Available") == 0) {
					strcpy_s(Availability[5][hourval - 8], "Not Available");
				}
				
			}
			if (choice == "Sunday") {
				if (strcmp(Availability[6][hourval - 8], "Available") == 0) {
					strcpy_s(Availability[6][hourval - 8], "Not Available");
				}
				
			}
		}

		Update("Personal");



	} while (!(choice=="7"));

}

void Doctor:: DisplayAvailableHours() {
	cout << "*                                                                                            *" << endl;
	cout << "* Available Hours :-                                                                         *" << endl;
	for (int day = 0; day < 7; day++) {
		if (day == 0) {
			cout << "Monday :- ";
		}
		if (day == 1) {
			cout << "Tuesday :- ";
		}
		if (day == 2) {
			cout << "Wednesday :- ";
		}
		if (day == 3) {
			cout << "Thursday :- ";
		}
		if (day == 4) {
			cout << "Friday :- ";
		}
		if (day == 5) {
			cout << "Saturday :- ";
		}
		if (day == 6) {
			cout << "Sunday :- ";
		}
		for (int hour = 0; hour < 10; hour++) {
			if (strcmp(Availability[day][hour],"Available") == 0) {
				cout << hour + 8 << ":00, ";
			}
		}
		cout << endl;
	}

}

void Doctor:: viewAvailabilityHours() {

	Date current;
	current.setCurrentDate();
	string choice;
	int len = string(getUsername()).length();

	int NoSetCounter[7][10];
	int AvailableCounter[7][10];
	int BookedCounter[7][10];
	int NotAvailableCounter[7][10];
	int PendingCounter[7][10];

	for (int i = 0; i < 7; i++) {
		for (int c = 0; c < 10; c++) {
			NoSetCounter[i][c] = 0;
			AvailableCounter[i][c] = 0;
			BookedCounter[i][c] = 0;
			NotAvailableCounter[i][c] = 0;
			PendingCounter[i][c] = 0;
		}
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
		cout << "* =================================Doctor's Availability Hours============================== *" << endl;
		cout << "*                                                                                            *" << endl;
		for (int day = 0; day < 7; day++) {
			for (int hour = 0; hour < 10; hour++) {
				if (strcmp(Availability[day][hour], "Available") == 0) {
					AvailableCounter[day][hour] = 1;
				}
				if (strcmp(Availability[day][hour], "Not Available") == 0) {
					NotAvailableCounter[day][hour] = 1;
				}
				if (strcmp(Availability[day][hour], "Booked")==0) {
					cout << "SHHESH" << endl;
					BookedCounter[day][hour] = 1;
				}
				if (strcmp(Availability[day][hour], "Pending")==0) {
					PendingCounter[day][hour] = 1;
				}
			}
		}

		cout << "*                                                                                            *" << endl;
		cout << "* Not Available Hours :-                                                                     *" << endl;
		for (int day = 0; day < 7; day++) {
			if (day == 0) {
				cout << "Monday :- ";
			}
			if (day == 1) {
				cout << "Tuesday :- ";
			}
			if (day == 2) {
				cout << "Wednesday :- ";
			}
			if (day == 3) {
				cout << "Thursday :- ";
			}
			if (day == 4) {
				cout << "Friday :- ";
			}
			if (day == 5) {
				cout << "Saturday :- ";
			}
			if (day == 6) {
				cout << "Sunday :- ";
			}
			for (int hour = 0; hour < 10; hour++) {
				if (NotAvailableCounter[day][hour] == 1) {
					cout << hour+8 << ":00, ";
				}
			}
			cout << endl;
		}
		cout << "*                                                                                            *" << endl;
		cout << "* Available Hours :-                                                                         *" << endl;
		for (int day = 0; day < 7; day++) {
			if (day == 0) {
				cout << "Monday :- ";
			}
			if (day == 1) {
				cout << "Tuesday :- ";
			}
			if (day == 2) {
				cout << "Wednesday :- ";
			}
			if (day == 3) {
				cout << "Thursday :- ";
			}
			if (day == 4) {
				cout << "Friday :- ";
			}
			if (day == 5) {
				cout << "Saturday :- ";
			}
			if (day == 6) {
				cout << "Sunday :- ";
			}
			for (int hour = 0; hour < 10; hour++) {
				if (AvailableCounter[day][hour] == 1) {
					cout << hour+8 << ":00, ";
				}
			}
			cout << endl;
		}
		cout << "*                                                                                            *" << endl;
		cout << "* Booked Hours :-                                                                            *" << endl;
		for (int day = 0; day < 7; day++) {
			if (day == 0) {
				cout << "Monday :- ";
			}
			if (day == 1) {
				cout << "Tuesday :- ";
			}
			if (day == 2) {
				cout << "Wednesday :- ";
			}
			if (day == 3) {
				cout << "Thursday :- ";
			}
			if (day == 4) {
				cout << "Friday :- ";
			}
			if (day == 5) {
				cout << "Saturday :- ";
			}
			if (day == 6) {
				cout << "Sunday :- ";
			}
			for (int hour = 0; hour < 10; hour++) {
				if (BookedCounter[day][hour] == 1) {
					cout << hour +8<< ":00, ";
				}
			}
			cout << endl;
		}

		cout << "*                                                                                            *" << endl;
		cout << "* Pending Hours :-                                                                           *" << endl;
		for (int day = 0; day < 7; day++) {
			if (day == 0) {
				cout << "Monday :- ";
			}
			if (day == 1) {
				cout << "Tuesday :- ";
			}
			if (day == 2) {
				cout << "Wednesday :- ";
			}
			if (day == 3) {
				cout << "Thursday :- ";
			}
			if (day == 4) {
				cout << "Friday :- ";
			}
			if (day == 5) {
				cout << "Saturday :- ";
			}
			if (day == 6) {
				cout << "Sunday :- ";
			}
			for (int hour = 0; hour < 10; hour++) {
				if (PendingCounter[day][hour] == 1) {
					cout << hour +8 << ":00, ";
				}
			}
			cout << endl;
		}
		cout << "* Enter a key to go back... ";
		cin >> choice;

	} while (false);

}

bool Doctor:: validLocationHospital(string Location) {

	if (Location == "Islamabad" || Location == "Karachi" || Location == "Quetta" || Location == "Peshawar" || Location == "Lahore") {
		return true;
	}

	return false;

}

void Doctor::InputHospital() {
	string name;
	int count = 0;
		count = 0;
		cout << "* Enter the Hospital/Clinic Name : ";
		do {
			if (count == 0)
			{
				count++;
			}
			else {
				getline(cin, name);
			}
		} while (name.length() == 0);
	
	setHospitalName(name);
	Address add;
	cout << "*                                                                                            *" << endl;
	cout << "*                                                                                            *" << endl;
	cout << "* Enter the Address of the Hospital : " << endl;
	cout << "* Enter the Area :- ";
	name = "";
	count = 0;
	do {
		if (count == 0)
		{
			count++;
		}
		else {
			getline(cin, name);
		}
	} while (name.length() == 0);
	Hospital.setArea(name);
	cout << "*                                                                                            *" << endl;
	cout << endl;
		name = "";
		count = 0;
		cout << "* Enter the City (Pakistan) :- ";
		do {
			
			if (count == 0)
			{
				count++;
			}
			else {
				
				getline(cin, name);
				count++;
			}
		} while (name.length() == 0 || !(name == "Islamabad" || name == "Karachi" || name == "Quetta" || name == "Peshawar" || name == "Lahore"));
		Hospital.setCity(name);
		cout << "*                                                                                            *" << endl;

}

void Doctor::setHospitalName(string HospitalName) {
	strcpy_s(this->HospitalName, HospitalName.c_str());
}
char* Doctor::getHospitalName() {
	return HospitalName;
}


void Doctor::setRequest(bool value) {
	Request = value;
}
bool Doctor::getRequest() {
	return Request;
}

void Doctor::setHourlyRatePerson(int value) {
	if (value > 0) {
		HourlyChargeInPerson = value;
	}
}
int Doctor::getHourlyRatePerson() {
	return HourlyChargeInPerson;
}

void Doctor::setHourlyRateVideo(int value) {
	if (value > 0) {
		HourlyChargeVideo = value;
	}
}
int Doctor::getHourlyRateVideo() {
	return HourlyChargeVideo;
}

void Doctor:: setUser(User& other) {

	setName(other.getName());
	setPhoneNum(other.getPhoneNum());
	setCNIC(other.getCNIC());
	setDate(other.getDate());
	setAddress(other.getAddress());
	setUsername(other.getUsername());
	setPassword(other.getPassword());
	setEmail(other.getEmail());
}

bool Doctor:: setSpeciality(string Speciality) {
	if (Speciality == "Gynecologist" || Speciality == "Dermatologist" || Speciality == "Oncologist" || Speciality == "Orthopedic") {
		strcpy_s(this->Speciality, Speciality.c_str());
		return true;
	}
	return false;
}
char* Doctor::getSpeciality() {
	return Speciality;
}

char * Doctor::getAvailability(int day, int hour) {
	return Availability[day][hour];
}

void Doctor:: setAvailability(string value, int day, int hour) {
	strcpy_s(Availability[day][hour], value.c_str());
}

void Doctor:: setHospital(Address& location) {
	Hospital.setArea(location.getArea());
	Hospital.setCity(location.getCity());

}
Address& Doctor:: getHospital() {
	return Hospital;
}

void Doctor::Display() {
	// can make generic by using current date and using its year...
	
	cout << "* Name : " << Name << "      Speciality : " << Speciality << endl;
	cout << "* Hospital : " << HospitalName << "      Location : " << Hospital.getCity() << endl;
	cout << "* Age : " << (2022 - DateOfBirth.getYear()) << endl;

}


void Doctor:: setEscapeRoute(int value) {
	EscapeRoute = value;
}

int Doctor:: getEscapeRoute() {
	return EscapeRoute;
}

Account& Doctor::getAccount() {
	return account;
}
void Doctor:: setAccount(Account& other) {

	account.setAccountNum(other.getAccountNum());
	account.setBalance(other.getBalance());
	account.setBank(other.getBank());
	account.setEGateway(other.getEGateway());
	account.setFine(other.getFine());

}
void Doctor:: setDoc(Doctor& other) {
	setName(other.getName());
	setPhoneNum(other.getPhoneNum());
	setCNIC(other.getCNIC());
	setDate(other.getDate());
	setAddress(other.getAddress());
	setUsername(other.getUsername());
	setPassword(other.getPassword());
	setHospitalName(other.getHospitalName());
	setHourlyRatePerson(other.getHourlyRatePerson());
	setHourlyRateVideo(other.getHourlyRateVideo());
	setSpeciality(other.getSpeciality());

	for (int day = 0; day < 7; day++) {
		for (int hour = 0; hour < 10; hour++) {
			strcpy_s(Availability[day][hour], string(other.getAvailability(day, hour)).c_str());
		}
	}
	setHospital(other.getHospital());

	setAccount(other.getAccount());
	setEmail(other.getEmail());
	setRequest(other.getRequest());
}

bool Doctor:: Read() {
	Doctor tempDoctor;
	ifstream fDoctor("Doctor.dat", ios::binary);
	while (fDoctor.read((char*)&tempDoctor, sizeof(tempDoctor))) {
		if ((strcmp(tempDoctor.getUsername(), Username) == 0)) {
			fDoctor.close();
			cout << "*                                                                                            *" << endl;
			cout << "* This Username already exists, please Enter another Username                                *" << endl;
			cout << "*                                                                                            *" << endl;
			return false;
		}
		if ((strcmp(tempDoctor.getEmail(), Email) == 0)) {
			fDoctor.close();
			cout << "*                                                                                            *" << endl;
			cout << "* This Email already exists, please Enter another Email                                      *" << endl;
			cout << "*                                                                                            *" << endl;
			return false;
		}
		if (tempDoctor.getCNIC() == CNIC) {
			fDoctor.close();
			cout << "*                                                                                            *" << endl;
			cout << "* This CNIC already exists, please Enter another CNIC                                        *" << endl;
			cout << "*                                                                                            *" << endl;
			return false;
		}
	}
	fDoctor.close();

	return true;

}


bool Doctor:: ReadSignIn() {
	Doctor tempDoctor;
	ifstream fDoctor("Doctor.dat", ios::binary);
	while (fDoctor.read((char*)&tempDoctor, sizeof(tempDoctor))) {
		
		if ((strcmp(tempDoctor.getUsername(), Username) == 0) && (strcmp(tempDoctor.getPassword(), Password) == 0)) {
			fDoctor.close();
			setDoc(tempDoctor);
			return true;
		}
	}

	fDoctor.close();
	return false;

}
bool Doctor:: ReadChange() {
	Doctor tempDoctor;
	ifstream fDoctor("Doctor.dat", ios::binary);
	while (fDoctor.read((char*)&tempDoctor, sizeof(tempDoctor))) {
		if ((strcmp(tempDoctor.getUsername(), Username) == 0)) {
			fDoctor.close();
			cout << "*                                                                                            *" << endl;
			cout << "* This Username already exists, please Enter another Username                                *" << endl;
			cout << "*                                                                                            *" << endl;
			return false;
		}
	}
	fDoctor.close();

	return true;

}

bool Doctor::Write() {
	ofstream fDoctor("Doctor.dat", ios::binary | ios::app);

	if (fDoctor) {
		fDoctor.write((char*)&*(this), sizeof(*(this)));
		fDoctor.close();
		return true;
	}
	fDoctor.close();
	return false;
}

void Doctor:: Update(string type) {

	Doctor tempDoctor;
	string name1;
	string name2;

	if (type == "Username") {
		fstream fDoctor("Doctor.dat", ios::binary | ios::in | ios::out);
		while (fDoctor.read((char*)&tempDoctor, sizeof(tempDoctor))) {
			if (!(strcmp(tempDoctor.getName(), getName())) && tempDoctor.getCNIC() == getCNIC() && tempDoctor.getPhoneNum() == getPhoneNum()) {
				int first = fDoctor.tellg();
				fDoctor.seekp(first - sizeof(tempDoctor), ios::beg);
				fDoctor.write((char*)&*(this), sizeof(*(this)));
				fDoctor.close();
				return;
			}
		}
		fDoctor.close();
		return;
	}

	if (type == "Password") {
		fstream fDoctor("Doctor.dat", ios::binary | ios::in | ios::out);
		while (fDoctor.read((char*)&tempDoctor, sizeof(tempDoctor))) {
			if (!(strcmp(tempDoctor.getUsername(), getUsername()))) {
				int first = fDoctor.tellg();
				fDoctor.seekp(first - sizeof(tempDoctor), ios::beg);
				fDoctor.write((char*)&*(this), sizeof(*(this)));
				fDoctor.close();
				return;
			}
		}
		fDoctor.close();
		return;
	}

	if (type == "Personal") {
		fstream fDoctor("Doctor.dat", ios::binary | ios::in | ios::out);
		while (fDoctor.read((char*)&tempDoctor, sizeof(tempDoctor))) {
			if (!(strcmp(tempDoctor.getUsername(), getUsername()))) {
				int first = fDoctor.tellg();
				fDoctor.seekp(first - sizeof(tempDoctor), ios::beg);
				fDoctor.write((char*)&*(this), sizeof(*(this)));
				fDoctor.close();
				return;
			}
		}
		fDoctor.close();
		return;
	}

}