#include "DoctorSpecialities.h"

Gynecologist::Gynecologist() {

}

void Gynecologist::setDoctor(Doctor& other) {
	setName(other.getName());
	setPhoneNum(other.getPhoneNum());
	setCNIC(other.getCNIC());
	setDate(other.getDate());
	setAddress(other.getAddress());
	setUsername(other.getUsername());
	setPassword(other.getPassword());
	setHospitalName(other.getHospitalName());
	setAccount(other.getAccount());
	setSpeciality(other.getSpeciality());
	setEmail(other.getEmail());

	for (int day = 0; day < 7; day++) {
		for (int hour = 0; hour < 10; hour++) {
			strcpy_s(Availability[day][hour], string(other.getAvailability(day, hour)).c_str());
		}
	}
	setHospital(other.getHospital());
	setHourlyRatePerson(other.getHourlyRatePerson());
	setHourlyRateVideo(other.getHourlyRateVideo());

}


Dermatologist::Dermatologist() {
	
}

void Dermatologist:: setDoctor(Doctor& other) {

	setName(other.getName());
	setPhoneNum(other.getPhoneNum());
	setCNIC(other.getCNIC());
	setDate(other.getDate());
	setAddress(other.getAddress());
	setUsername(other.getUsername());
	setPassword(other.getPassword());
	setHospitalName(other.getHospitalName());
	setAccount(other.getAccount());
	setSpeciality(other.getSpeciality());
	setEmail(other.getEmail());
	for (int day = 0; day < 7; day++) {
		for (int hour = 0; hour < 10; hour++) {
			strcpy_s(Availability[day][hour], string(other.getAvailability(day, hour)).c_str());
		}
	}
	setHospital(other.getHospital());
	setHourlyRatePerson(other.getHourlyRatePerson());
	setHourlyRateVideo(other.getHourlyRateVideo());
}


Oncologist::Oncologist() {
	
}
void Oncologist::setDoctor(Doctor& other) {

	setName(other.getName());
	setPhoneNum(other.getPhoneNum());
	setCNIC(other.getCNIC());
	setDate(other.getDate());
	setAddress(other.getAddress());
	setUsername(other.getUsername());
	setPassword(other.getPassword());
	setHospitalName(other.getHospitalName());
	setAccount(other.getAccount());
	setSpeciality(other.getSpeciality());
	setEmail(other.getEmail());

	for (int day = 0; day < 7; day++) {
		for (int hour = 0; hour < 10; hour++) {
			strcpy_s(Availability[day][hour], string(other.getAvailability(day, hour)).c_str());
		}
	}
	setHospital(other.getHospital());
	setHourlyRatePerson(other.getHourlyRatePerson());
	setHourlyRateVideo(other.getHourlyRateVideo());

}


Orthopedic::Orthopedic() {
	
}
void Orthopedic::setDoctor(Doctor& other) {
	setName(other.getName());
	setPhoneNum(other.getPhoneNum());
	setCNIC(other.getCNIC());
	setDate(other.getDate());
	setAddress(other.getAddress());
	setUsername(other.getUsername());
	setPassword(other.getPassword());
	setHospitalName(other.getHospitalName());
	setAccount(other.getAccount());
	setSpeciality(other.getSpeciality());
	setEmail(other.getEmail());
	for (int day = 0; day < 7; day++) {
		for (int hour = 0; hour < 10; hour++) {
			strcpy_s(Availability[day][hour], string(other.getAvailability(day, hour)).c_str());
		}
	}
	setHospital(other.getHospital());
	setHourlyRatePerson(other.getHourlyRatePerson());
	setHourlyRateVideo(other.getHourlyRateVideo());


}