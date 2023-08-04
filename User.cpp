#include "User.h"

User::User() {
	type = 0;
}

User::User(User& other) {
	for (int i = 0; i < 100; i++) {
		Username[i] = other.Username[i];
		Password[i] = other.Password[i];
		type = other.type;
	}
}


int User::getType() {
	return type;
}
char* User::getUsername() {
	return Username;
}
char* User::getPassword() {
	return Password;
}

void User::InputUsername() {

	string name;
	int count = 0;
	cout << "* Enter your *NEW* UserName : ";
	do {
		if (count == 0)
		{
			count++;
		}
		else {
			getline(cin, name);
		}
	} while (name.length() == 0);
	setUsername(name);
}

void User:: InputUsernameSignIn() {
	string name;
	int count = 0;
	cout << "* Enter your UserName : ";
	do {
		if (count == 0)
		{
			count++;
		}
		else {
			getline(cin, name);
		}
	} while (name.length() == 0);
	setUsername(name);

}
void User::InputPasswordSignIn() {
	string name;
	int count = 0;
	do {
		if (count == 0)
		{
			count++;
		}
		else {
			cout << "* Enter your Password : ";
			getline(cin, name);
		}
	} while (name.length() == 0 || name.length() < 8);
	setPassword(name);

}
void User:: InputPassword() {

	string name;
	int count = 0;
	do {
		if (count == 0)
		{
			count++;
		}
		else {
			cout << "* Enter your Password : ";
			getline(cin, name);
		}
	} while (!(ValidPassword(name)));
	setPassword(name);
	name = "";
	count = 0;
	do {
		if (count == 0)
		{
			count++;
		}
		else {
			cout << "* Re-Enter your Password : ";
			getline(cin, name);
		}
	} while (!(name == getPassword()));

}

bool User:: ValidPassword(string p) {

	bool Ucase = false;
	bool Lcase = false;
	bool digit = false;
	bool special = false;

	for (int i = 0; i < p.length(); i++) {
		if (p[i] >= 65 && p[i] <= 90) {
			Ucase = true;
		}
		else {
			if (p[i] >= 97 && p[i] <= 122) {
				Lcase = true;
			}
			else {
				if (p[i] >= 48 && p[i] <= 57) {
					digit = true;
				}
				else
				{
					special = true;
				}
			}
		}

	}

	return(((p.length()>8) && special && digit && Lcase && Ucase));

}

void User::setUsername(string Username) {
	strcpy_s(this->Username, Username.c_str());
}
void User::setPassword(string Password) {

	strcpy_s(this->Password, Password.c_str());

}

void User:: setInformation(Person& info) {
	setName(info.getName());
	setPhoneNum(info.getPhoneNum());
	setCNIC(info.getCNIC());
	setDate(info.getDate());
	setAddress(info.getAddress());
	setEmail(info.getEmail());

}





