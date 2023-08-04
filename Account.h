#pragma once

#include<iostream>
using namespace std;
#include<string>
class Account {
private:
	char AccountNum[100];
	float Balance;
	char EGateway[100];
	char Bank[100];
	float fine;
public:

	Account();

	void WithdrawBalance(int);
	void DepositBalance(int);

	char* getAccountNum();
	float getBalance();
	char* getEGateway();
	char* getBank();
	float getFine();

	bool onlyNum(string);
	void InputAccountNum();
	void InputMode();

	void setAccountNum(string);
	void setBalance(float);
	void setFine(float);
	void setBank(string);
	void setEGateway(string);

};