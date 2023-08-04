#include "ShowRecords.h"


ShowRecords:: ShowRecords() {

	 GynecologistCounter=0;
	 DermatologistCounter=0;
	 OncologistCounter=0;
	 OrthopedicCounter=0;

}

void ShowRecords:: ShowAllDoctors() {
	int counter = 0;
	int length = 0;
	string Name="";

	Doctor tempDoctor;
	ifstream fDoctor("Doctor.dat", ios::binary);
	cout << "* ========================================================================================== *" << endl;
	cout << "*                                                                                            *" << endl;
	while (fDoctor.read((char*)&tempDoctor, sizeof(tempDoctor))) {
		if (string(tempDoctor.getName()).find(Name) != -1) {
			cout << "*                                                                                            *" << endl;
			tempDoctor.Display();
			counter++;
		}
	}
	fDoctor.close();
	cout << "*                                                                                            *" << endl;
	cout << "* ========================================================================================== *" << endl;
	cout << "* Enter a message to go back                                                                 *" << endl;
	cin >> Name;

}


void ShowRecords::ShowRecordsSpeciality() {

	string *choice = new string;
	Date current;
	current.setCurrentDate();


	do {
		system("CLS");
		cout << "**********************************************************************************************" << endl;
		cout << "*                                                                             "; current.display(); cout << "     *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* ==============================Patient's Doctor Information================================ *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 1 to View All Doctors by Speciality :                                                *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Search Doctor by Speciality          : [Gynecologist/Dermatologist/Oncologist/Orthopedic]  *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 3 to go back...                    :                                                 *" << endl;
		cout << "*                                                                                            *" << endl;
		cin >> *choice;
	} while (!(*choice=="3"|| *choice=="1" || *choice=="Gynecologist"|| *choice=="Dermatologist"|| *choice=="Oncologist" || *choice=="Orthopedic"));

	system("CLS");
	if (*choice == "1") {
		Doctor *tempDoctor = new Doctor;
		ifstream fDoctor("Doctor.dat", ios::binary);
		while (fDoctor.read((char*)&*(tempDoctor), sizeof(*tempDoctor))) {

		
			if (strcmp(tempDoctor->getSpeciality(), "Gynecologist") == 0) {
				GynecologistCounter++;
			}
			if (strcmp(tempDoctor->getSpeciality(), "Dermatologist") == 0) {
				DermatologistCounter++;
			}
			if (strcmp(tempDoctor->getSpeciality(), "Oncologist") == 0) {
				OncologistCounter++;
			}
			if (strcmp(tempDoctor->getSpeciality(), "Orthopedic") == 0) {
				OrthopedicCounter++;
			}

		}
		fDoctor.close();

		Gyndoctors = new Gynecologist[GynecologistCounter];
		Dermdoctors = new Dermatologist[DermatologistCounter];
		Oncoldoctors = new Oncologist[OncologistCounter];
		Orthopdoctors = new Orthopedic[OrthopedicCounter];

		int indexG = 0;
		int indexD = 0;
		int indexOn = 0;
		int indexOr = 0;

		ifstream fDoctor1("Doctor.dat", ios::binary);

		while (fDoctor1.read((char*)&(* tempDoctor), sizeof(*tempDoctor))) {

			if (strcmp(tempDoctor->getSpeciality(), "Gynecologist") == 0) {
				Gyndoctors[indexG].setDoctor(*tempDoctor);
				indexG++;
			}
			if (strcmp(tempDoctor->getSpeciality(), "Dermatologist") == 0) {
				Dermdoctors[indexD].setDoctor(*tempDoctor);
				indexD++;
			}
			if (strcmp(tempDoctor->getSpeciality(), "Oncologist") == 0) {
				Oncoldoctors[indexOn].setDoctor(*tempDoctor);
				indexOn++;
			}
			if (strcmp(tempDoctor->getSpeciality(), "Orthopedic") == 0) {
				Orthopdoctors[indexOr].setDoctor(*tempDoctor);
				indexOr++;
			}

		}
		fDoctor1.close();

		Date current;
		current.setCurrentDate();
		cout << "*****************************WELCOME TO THE OLADOC CONSOLE LOGIN******************************" << endl;
		cout << "*                                                                             "; current.display(); cout << "     *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* ====================================DISPLAYING DOCTORS==================================== *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* ------------------------------------Gynecologists----------------------------------------- *" << endl;
		cout << "*                                                                                            *" << endl;
		for (int i = 0; i < GynecologistCounter; i++) {
			cout << "*                                                                                            *" << endl;
			Gyndoctors[i].Display();

		}
		cout << "*                                                                                            *" << endl;
		cout << "* ------------------------------------Dermatologist----------------------------------------- *" << endl;
		cout << "*                                                                                            *" << endl;
		for (int i = 0; i < DermatologistCounter; i++) {
			cout << "*                                                                                            *" << endl;
			Dermdoctors[i].Display();
		}

		cout << "*                                                                                            *" << endl;
		cout << "* --------------------------------------Oncologist------------------------------------------ *" << endl;
		cout << "*                                                                                            *" << endl;
		for (int i = 0; i < OncologistCounter; i++) {
			cout << "*                                                                                            *" << endl;
			Oncoldoctors[i].Display();
		}

		cout << "*                                                                                            *" << endl;
		cout << "* --------------------------------------Orthopedic------------------------------------------ *" << endl;
		cout << "*                                                                                            *" << endl;
		for (int i = 0; i < OrthopedicCounter; i++) {
			cout << "*                                                                                            *" << endl;
			Orthopdoctors[i].Display();
		}
		if (GynecologistCounter > 0) {
			delete[] Gyndoctors;
		}
		if (DermatologistCounter > 0) {
			delete[] Dermdoctors;
		}
		if (OncologistCounter > 0) {
			delete[] Oncoldoctors;
		}
		if (OrthopedicCounter > 0) {
			delete[] Orthopdoctors;
		}
		delete tempDoctor;
	}


	if (!(*choice == "1" || *choice == "3")) {
		Doctor * tempDoctor = new Doctor;
		ifstream fDoctor("Doctor.dat", ios::binary);

		cout << "*                                                                                            *" << endl;
		cout << "*------------------------------------DOCTORS IN " << *choice << "--------------------------------------*" << endl;
		while (fDoctor.read((char*)&(*tempDoctor), sizeof(*tempDoctor))) {


			if (strcmp(tempDoctor->getSpeciality(), choice->c_str()) == 0) {
				cout << "*                                                                                            *" << endl;
				tempDoctor->Display();
			}
		}

		fDoctor.close();
		delete tempDoctor;
	}

	if (*choice == "3") {
		
	}
	else {

		cout << "*                                                                                            *" << endl;
		cout << "* Enter anything to go back to the Menu                                                      *" << endl;
		cin >> *choice;
	}

	delete choice;
}

void ShowRecords::ShowRecordsLocation() {


	string *choice= new string;
	Date current;
	current.setCurrentDate();

	do {
		system("CLS");
		cout << "**********************************************************************************************" << endl;
		cout << "*                                                                             "; current.display(); cout << "     *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* ==============================Patient's Doctor Information================================ *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 1 to View All Doctors by Location           :                                        *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Enter City Name to Only Show Doctors of that City :                                        *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 3 to go back...                             :                                        *" << endl;
		cout << "*                                                                                            *" << endl;
		cin >> *(choice);
	} while (!(*(choice) == "3" || *(choice) == "Peshawar" || *(choice)=="Karachi" || *(choice)=="Islamabad" || *(choice)=="Quetta" || *(choice)=="Lahore" || *(choice)=="1"));

	system("CLS");
	Doctor myDoctor;
	if (*(choice) == "1") {
		Doctor* tempDoctor= new Doctor;
		ifstream fDoctor("Doctor.dat", ios::binary);
		
		cout << "*                                                                                            *" << endl;
		cout << "*------------------------------------DOCTORS IN KARACHI--------------------------------------*" << endl;
		while (fDoctor.read((char*)&(* (tempDoctor)), sizeof(*(tempDoctor)))) {
			myDoctor.setDoc(*tempDoctor);
			if (strcmp(tempDoctor->getHospital().getCity(), "Karachi") == 0) {
				myDoctor.Display();
			}
		}
		fDoctor.close();

		ifstream fDoctor1("Doctor.dat", ios::binary);
		cout << "*                                                                                            *" << endl;
		cout << "*------------------------------------DOCTORS IN Islamabad------------------------------------*" << endl;

		while (fDoctor1.read((char*)&(* (tempDoctor)), sizeof(*(tempDoctor)))) {

			myDoctor.setDoc(*tempDoctor);
			if (strcmp(tempDoctor->getHospital().getCity(), "Islamabad") == 0) {
				myDoctor.Display();
			}
		}
		fDoctor1.close();


		ifstream fDoctor2("Doctor.dat", ios::binary);
		cout << "*                                                                                            *" << endl;
		cout << "*------------------------------------DOCTORS IN LAHORE---------------------------------------*" << endl;

		while (fDoctor2.read((char*)&(*(tempDoctor)), sizeof(*(tempDoctor)))) {
			myDoctor.setDoc(*tempDoctor);
			if (strcmp(tempDoctor->getHospital().getCity(), "Lahore") == 0) {
				myDoctor.Display();
			}
		}
		fDoctor2.close();


		ifstream fDoctor3("Doctor.dat", ios::binary);
		cout << "*                                                                                            *" << endl;
		cout << "*------------------------------------DOCTORS IN PESHAWAR---------------------------------------*" << endl;

		while (fDoctor3.read((char*)&( * (tempDoctor)), sizeof(*(tempDoctor)))) {
			myDoctor.setDoc(*tempDoctor);

			if (strcmp(tempDoctor->getHospital().getCity(), "Peshawar") == 0) {
				myDoctor.Display();
			}
		}
		fDoctor3.close();


		ifstream fDoctor4("Doctor.dat", ios::binary);
		cout << "*                                                                                            *" << endl;
		cout << "*------------------------------------DOCTORS IN QUETTA---------------------------------------*" << endl;

		while (fDoctor4.read((char*)&(* (tempDoctor)), sizeof(*(tempDoctor)))) {

			myDoctor.setDoc(*tempDoctor);
			if (strcmp(tempDoctor->getHospital().getCity(), "Quetta") == 0) {
				myDoctor.Display();
			}
		}
		fDoctor4.close();
		delete tempDoctor;
	}

	if (!(*(choice) == "1" || *(choice)=="3")) {
		Doctor *tempDoctor = new Doctor;
		ifstream fDoctor("Doctor.dat", ios::binary);

		cout << "*                                                                                            *" << endl;
		cout << "*------------------------------------DOCTORS IN " << *choice<< "--------------------------------------*" << endl;
		while (fDoctor.read((char*)&(* tempDoctor), sizeof(*(tempDoctor)))) {
			myDoctor.setDoc(*tempDoctor);

			if (strcmp(tempDoctor->getHospital().getCity(), choice->c_str()) == 0) {
				cout << "*                                                                                            *" << endl;
				myDoctor.Display();
			}
		}
		fDoctor.close();
		delete tempDoctor;

	}
	if (*(choice) == "3") {

	}
	else {

	cout << "* Enter a key to go back... ";
	cin >> *(choice);
	}

	delete choice;
}

void ShowRecords:: ShowRecordsName() {
	string choice;
	Date current;
	current.setCurrentDate();
	do {
		system("CLS");
		cout << "**********************************************************************************************" << endl;
		cout << "*                                                                             "; current.display(); cout << "     *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* ==============================Patient's Doctor Information================================ *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Enter the Name of the Doctor you Want to Search :                                          *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* Press 2 to Exit                                 :                                          *" << endl;
		cout << "*                                                                                            *" << endl;
		cout << "* ";

		cin >> choice;
		

		if (!(choice == "2")) {
			NameFinder(choice);
		}

	} while (!(choice=="2"));

		system("CLS");

}

void ShowRecords:: NameFinder(string Name) {
	int counter = 0;
	int length = 0;
	length = Name.length();
	
		Doctor tempDoctor;
		ifstream fDoctor("Doctor.dat", ios::binary);

		cout << "*                                                                                            *" << endl;
		cout << "* DOCTORS with Name  : " << Name << setw(94 - 24 - length) << "*" << endl;
		while (fDoctor.read((char*)&tempDoctor, sizeof(tempDoctor))) {
			if (string(tempDoctor.getName()).find(Name) != -1) {
				cout << "*                                                                                            *" << endl;
				tempDoctor.Display();
				counter++;
			}
		}
		fDoctor.close();

		if (counter == 0) {
			cout << "*                                                                                            *" << endl;
			cout << "* No Doctor Registered with the Name : " << Name << setw(94 - length - 40) << "*" << endl;
			cout << "*                                                                                            *" << endl;
		}

		cout << "* Enter a message to go back                                                                 *" << endl;
		cin >> Name;

}


ShowRecords::~ShowRecords() {
	
}


