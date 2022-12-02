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
		locationName = new char[strlen(loc.locationName)+1];
		strcpy(locationName, loc.locationName);
		noRows = loc.noRows;
		maxNoSeats = loc.maxNoSeats;
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

	char* getLocationName() {
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

	void setLocationName(const char* locationName) {

		if (locationName != nullptr) {
			if (this->locationName != nullptr) {
				delete[] this->locationName;
			}
			this->locationName = new char[strlen(locationName) + 1];
			strcpy_s(this->locationName, strlen(locationName) + 1, locationName);
		}
	}
};

	class Event {
	private:
		char* eventName;
		string date;
		Location location;
	public:

		Event() {
			eventName = new char[20];
			date = "";
			location = Location();
		}

		Event(char* name, string newDate, Location newLocation) {
			eventName = new char[strlen(name) + 1];
			strcpy(eventName, name);
			date = newDate;
			location = newLocation;
		}

		Event(const Event& newEvent) {
			eventName = new char[strlen(newEvent.eventName) + 1];
			strcpy(eventName, newEvent.eventName);
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

		char* getEventName() {
			if (eventName != nullptr)
			{
				char* copy = new char[strlen(eventName) + 1];
				strcpy_s(copy, strlen(eventName) + 1, eventName);
				return copy;
			}
			else
			{
				return nullptr;
			}
		}

		void SetEventName(const char* eventName) {

			if (eventName != nullptr) {
				if (this->eventName != nullptr) {
					delete[] this->eventName;
				}
				this->eventName = new char[strlen(eventName) + 1];
				strcpy_s(this->eventName, strlen(eventName) + 1, eventName);
			}
		}

	};

	class Ticket {
	private:
		char tribune;
		bool isVip;
		int seatNo;
		Event event;
	public:

		Ticket() {
			tribune = ' ';
			isVip = false;
			seatNo = 0;
			event = Event();
		}

		Ticket(char newTribune, bool newIsVip, int newSeatNo, Event newEvent) {
			tribune = newTribune;
			isVip = newIsVip;
			seatNo = newSeatNo;
			event = newEvent;
		}

		Event getEvent() {
			return event;
		}

		void setEvent(Event newEvent) {
			event = newEvent;
		}

		char getTribune() {
			return this->tribune;
		}

		void setTribune(char tribune) {
			this->tribune = tribune;
		}

		bool getIsVip() {
			return isVip;
		}

		void setIsVip(bool vip) {
			isVip = vip;
		}

		int getSeatNo() {
			return seatNo;
		}

		void setSeatNo(int newSeatNo) {
			seatNo = newSeatNo;
		}
	};

	void  main() {
		

	}
