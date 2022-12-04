#include "Location.h"
char* Location::getLocationName() {
	if (locationName != nullptr)
	{
		char* copy = new char[strlen(locationName) + 1];
		strcpy_s(copy, strlen(locationName) + 1, locationName);
		return copy;
	}
	else
	{
		return nullptr;
	}
}

void Location::setLocationName(const char* locationName) {

	if (locationName != nullptr) {
		if (this->locationName != nullptr) {
			delete[] this->locationName;
		}
		this->locationName = new char[strlen(locationName) + 1];
		strcpy_s(this->locationName, strlen(locationName) + 1, locationName);
	}


}

ostream& operator<<(ostream& out, Location loc)
{
	out << loc.locationName << " " << loc.maxNoSeats << " " << loc.noRows;
	return out;
}

istream& operator>>(istream& in, Location& loc)
{
	cout << "Enter no. of rows:";
	in >> loc.noRows;
	cout << "Enter no. of max seats:";
	in >> loc.maxNoSeats;
	cout << "Enter location name:";
	string locName;
	in >> locName;
	loc.setLocationName(locName.c_str());
	return in;
}
