#include "Account.h"

Account::Account() {
	
	Balance = 3500;
	fine = 0;
}

void Account::WithdrawBalance(int amount) {

	if (amount < 0) {
		return;
	}

	if (amount > Balance) {
		cout << "Can't withdraw Balance !" << endl;
	}
	else {
		Balance = Balance - amount;
	}

}
void  Account::DepositBalance(int amount) {
	if (amount < 0) {
		return;
	}
	else {
		Balance = Balance + amount;
	}
}
char* Account:: getAccountNum() {
	return AccountNum;
}

float Account:: getBalance() {
	return Balance;
}

char* Account:: getEGateway() {
	return EGateway;
}
char* Account:: getBank() {
	return Bank;
}

float Account:: getFine() {
	return fine;
}

void Account::InputAccountNum() {
	string tempstr;

	do {
		cout << "* Enter Account Number (Bank) or Phone Number (EGATEWAY):                                    *" << endl;
		cin >> tempstr;
	} while (!(tempstr.length() == 10 || tempstr.length() == 11 || tempstr.length() == 13) || !(onlyNum(tempstr)));

	setAccountNum(tempstr);
}

void Account::InputMode() {
	string tempstr;
	tempstr = AccountNum;
	if (tempstr.length() == 10 || tempstr.length() == 11) { // its a phone NUMBER so egateway		
		do {
			cout << "*                                                                                            *" << endl;
			cout << "* The list of E-Gateways we support are:  [PayPal/EasyPaisa/JazzCash/ZongPay]                *" << endl;
			cout << "* Enter your E-Gateway Name : ";
			cin >> tempstr;

		} while (!(tempstr == "PayPal" || tempstr == "EasyPaisa" || tempstr == "JazzCash" || tempstr == "ZongPay"));
		setEGateway(tempstr);

	}
	else { // otherwise 13 digits so its an account Number
		do {
			cout << "*                                                                                            *" << endl;
			cout << "* The list of Banks we support are:  [HBL/Alfalah/NBP/UnionPay/PayPak]                       *" << endl;
			cout << "* Enter your Bank Name : ";
			cin >> tempstr;

		} while (!(tempstr == "HBL" || tempstr == "Alfalah" || tempstr == "NBP" || tempstr == "UnionPay" || tempstr == "PayPak"));
		setBank(tempstr);
	}

}

bool Account:: onlyNum(string str) {
	
	
	for (int i = 0; i < str.length(); i++) {
		if (int(char(str[i])) < 48 || int(char(str[i])) > 57) {
			return false;
		}
	}
	return true;

}

void Account:: setAccountNum(string AccountNum) {
	strcpy_s(this->AccountNum, AccountNum.c_str());
}
void Account:: setBalance(float Balance) {
	this->Balance = Balance;
}
void Account::setFine(float amount) {
	if (amount < 0) {

	}
	else {
		Balance = Balance - amount;
	}

}

void Account::setBank(string Bank) {
	string tempstr;
	tempstr = "EGATEWAY-NONE";
	strcpy_s(EGateway, tempstr.c_str());
	strcpy_s(this->Bank, Bank.c_str());
	
}

void Account::setEGateway(string EGateway) {
	string tempstr;

	tempstr = "BANK-NONE";
	strcpy_s(Bank, tempstr.c_str());
	strcpy_s(this->EGateway, EGateway.c_str());
}