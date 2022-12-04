#pragma once
#include <string.h>
#include <iostream>
using namespace std;

class Location {
private:
	int noRows;
	int maxNoSeats;
	char* locationName;
public:

	Location() {
		locationName = new char[20];
		noRows = 0;
		maxNoSeats = 0;
	}

	Location(char* name, int rows, int seats) {
		locationName = new char[strlen(name) + 1];
		strcpy(locationName, name);
		noRows = rows;
		maxNoSeats = seats;
	}

	Location(const Location& loc) {
		locationName = new char[strlen(loc.locationName) + 1];
		strcpy(locationName, loc.locationName);
		noRows = loc.noRows;
		maxNoSeats = loc.maxNoSeats;
	}

	~Location() {
		if (locationName != nullptr)
		{
			delete[] locationName;
			locationName = nullptr;
		}
	}

	int getNoRows() {
		return this->noRows;
	}

	void setNoRows(int noRows) {
		this->noRows = noRows;
	}

	int getMaxNoSeats() {
		return this->maxNoSeats;
	}

	void setMaxNoSeats(int maxNoSeats) {
		this->maxNoSeats = maxNoSeats;
	}

	char* getLocationName();

	void setLocationName(const char* locationName);

	friend ostream& operator<<(ostream& out, Location loc);
	friend istream& operator>>(istream& in, Location& loc);
};