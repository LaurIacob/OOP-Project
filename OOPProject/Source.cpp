#include <iostream>
using namespace std;

class Location {
private:
	int noRows;
	int maxNoSeats;
	char* locationName;
public:
	int getNoRows() {
		return this->noRows;
	}

	void setNoRows(int noRows) {
		this->noRows = noRows;
	}

	void setMaxNoSeats(int maxNoSeats) {
		this->maxNoSeats = maxNoSeats;
	}

	int getMaxNoSeats() {
		return this->maxNoSeats;
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
	public:
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
		int tribune;
	public:

		int getTribune() {
			return this->tribune;
		}

		void setTribune(int tribune) {
			this->tribune = tribune;
		}
	};
