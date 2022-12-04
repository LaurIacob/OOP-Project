#pragma once
#include "Location.h"
#include <string>
using namespace std;
class Event {
private:
	string eventName;
	string date;
	Location location;
public:
	Event() :eventName("") {
		date = "";
		location = Location();
	}

	Event(string name, string newDate, Location newLocation) :eventName(name) {
		date = newDate;
		location = newLocation;
	}

	Event(const Event& newEvent) :eventName(newEvent.eventName) {
		date = newEvent.date;
		location = newEvent.location;
	}

	Location getLocation() {
		return location;
	}

	void setLocation(Location newLocation) {
		location = newLocation;
	}

	string getDate() {
		return date;
	}

	void setDate(string newDate) {
		date = newDate;
	}

	const string getEventName() {
		return eventName;
	}

	Event& operator = (const Event& event) {
		date = event.date;
		location = event.location;
		return *this;
	}


	friend ostream& operator<<(ostream& out, Event ev);
	friend istream& operator>>(istream& in, Event& ev);
};