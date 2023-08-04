#pragma once

#include<iostream>
#include<string>
#include"Person.h"
using namespace std;
class User: public Person {
protected:
	char Username[100];
	char Password[100];
	int type;

public:
	User();
	User(User&);

	virtual void Menu() { }
	virtual void Register(){ }
	
	virtual int getEscapeRoute() { return 0; }
	virtual void setEscapeRoute(int dummy) { }

	char* getUsername();
	char* getPassword();
	int getType();

	void InputUsername();
	void InputPassword();

	void InputUsernameSignIn();
	void InputPasswordSignIn();

	void setUsername(string);
	void setPassword(string);
	void setInformation(Person&);

	bool ValidPassword(string);

	virtual bool Read() { return true; }
	virtual bool ReadSignIn() { return true; }
	virtual bool Write() { return true; }
	virtual void Display(){ }


};
