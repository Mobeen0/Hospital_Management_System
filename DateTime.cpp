#include "DateTime.h"

DateTime::DateTime() {

	Hour = 0;
}

DateTime::DateTime(int Hour, int Day, int Month, int Year):Date(Day,Month,Year) {
	if (Hour > 24 || Hour < 0) {
		this->Hour = 0;
	}
	else {
		this->Hour = Hour;
	}

}
int DateTime::getHour() {
	return Hour;
}
void DateTime::setHour(int Hour) {
	if (Hour > 24 || Hour < 0) {
		// do nothing
	}
	else {
		this->Hour = Hour;
	}
}

void DateTime::display() {
	if (Hour < 10) {
		cout << "0" << Hour << ":" << "00";
	}
	else {
		cout << Hour << ":" << "00";
	}

}