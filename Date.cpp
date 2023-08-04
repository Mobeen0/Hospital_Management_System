#include<iostream>
#include "Date.h"
using namespace std;

Date::Date() {
	Day = 0;
	Month = 0;
	Year = 0;
}

Date::Date(int d, int m,int y) {
	
		Day = d;
		Month = m;
		Year = y;
}

Date::Date(Date& other) {
	Day = other.Day;
	Month = other.Month;
	Year = other.Year;
}

void Date::setDay(int Day) {
	this->Day = Day;

}

void Date::setMonth(int Month) {
	this->Month = Month;
}

void Date::setYear(int Year) {
	this->Year = Year;

}

int Date::getDay() {

	return Day;
}
int Date::getMonth() {
	return Month;
}

int Date::getYear() {
	return Year;
}

bool Date::verifyDate() {
	if (Day <= 0 || Day > 31) {
		return false;
	}
	if (Month <= 0 || Month > 12) {
		return false;
	}
	if (Year < 1910 || Year >2004) {
		return false;
	}
	return true;
}

void Date::display() {
	if (Day < 10) {
		if (Month<10) {
			cout << '0' << Day << "/0" << Month <<'/' << Year;
			return;
		}
		cout << '0' << Day << '/' << Month << '/' << Year;
		return;
	}
	else {
		if (Month < 10) {
			cout << Day << "/0" << Month << '/' << Year;
		}
		else {
			cout << Day << '/' << Month << '/' << Year;
		}
	}
	return;
}


void Date::setCurrentDate() {
	long long int elapsed_seconds;
	elapsed_seconds = time(0);


	long long int nyear = 31536000;
	long long int lyear = 31622400;

	long long int month30 = 2592000;
	long long int sday = 86400;

	int start = 1970;
	bool solved_year = false;
	bool solved_month = false;
	bool solved_day = false;
	

	for (int i = start; !(solved_year); i++) {

		if (elapsed_seconds < nyear) {
			Year = i;
			solved_year = true;
		}
		else {

			if (i % 4 == 0) {
				
				elapsed_seconds = elapsed_seconds - lyear;
			}
			else {
				elapsed_seconds = elapsed_seconds - nyear;
			}
		}
	}

	if (Year % 4 == 0) {
		for (int m = 1; !(solved_month); m++) {

			if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
				elapsed_seconds = elapsed_seconds - month30 - sday;
				if (elapsed_seconds < 0) {
					solved_month = true;
					Month = m;
					elapsed_seconds = elapsed_seconds + month30 + sday;
				}
			}
			if (m == 4 || m == 6 || m == 9 || m == 11) {
				elapsed_seconds = elapsed_seconds - month30;
				if (elapsed_seconds < 0) {
					solved_month = true;
					Month = m;
					elapsed_seconds = elapsed_seconds + month30;
				}
			}
			if (m == 2) {
				elapsed_seconds = elapsed_seconds - month30 + sday;
				if (elapsed_seconds < 0) {
					solved_month = true;
					Month = m;
					elapsed_seconds = elapsed_seconds + month30 - sday;
				}
			}
		}
	}
	else
	{
		for (int m = 1; !(solved_month); m++) {

			if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
				elapsed_seconds = elapsed_seconds - month30 - sday;
				if (elapsed_seconds < 0) {
					solved_month = true;
					Month = m;
					elapsed_seconds = elapsed_seconds + month30 + sday;
				}
			}
			if (m == 4 || m == 6 || m == 9 || m == 11) {
				elapsed_seconds = elapsed_seconds - month30;
				if (elapsed_seconds < 0) {
					solved_month = true;
					Month = m;
					elapsed_seconds = elapsed_seconds + month30;
					
				}

			}
			if (m == 2) {
				elapsed_seconds = elapsed_seconds - month30 + sday + sday;
				if (elapsed_seconds < 0) {
					solved_month = true;
					Month = m;
					elapsed_seconds = elapsed_seconds + month30 - sday -sday;
				}
			}
		}
	}

	for (int i = 1; !(solved_day); i++) {
		
		if (elapsed_seconds < 0) {
			solved_day = true;
			Day = i - 1;
		}

		elapsed_seconds = elapsed_seconds - sday;
	}
}

bool Date:: operator==(Date& other) {
	if (Day == other.Day) {
		if (Month == other.Month) {
			if (Year == other.Year) {
				return true;
			}
		}
	}
	
	return false;
}
bool Date:: operator>(Date& other) {
	
	if(Year> other.Year){
		return true;
	}
	if (Year == other.Year) {
		if (Month > other.Month) {
			return true;
		}
		if (Month == other.Month) {
			if (Day > other.Day) {
				return true;
			}
		}
	}

	return false;

}
bool Date:: operator<(Date& other) {

	if (Year < other.Year) {
		return true;
	}
	if (Year == other.Year) {
		if (Month < other.Month) {
			return true;
		}
		if (Month == other.Month) {
			if (Day < other.Day) {
				return true;
			}
		}
	}

	return false;
}
