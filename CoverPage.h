#pragma once

#include<iostream>
#include "Date.h"
using namespace std;


class CoverPage {
protected:
	char choice[50];
	Date current;
public:
	
	CoverPage();
	void chCoverPage();

	void setChoice(string);
	char* getChoice();


};