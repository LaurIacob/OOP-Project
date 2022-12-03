#include <iostream>
#include <time.h>
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

	~Location() {
		delete[] locationName;
		locationName = nullptr;
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
		const string eventName;
		string date;
		Location location;
	public:
		Event() :eventName(""){
			date = "";
			location = Location();
		}

		Event(string name, string newDate, Location newLocation) :eventName(name){
			date = newDate;
			location = newLocation;
		}

		Event(const Event& newEvent) :eventName(newEvent.eventName){
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

	};

	class Ticket {
	private:
		int ticketID;
		char tribune;
		bool isVip;
		int* seatNo;
		Event event;
		static int noTickets;
	public:

		Ticket() {
			tribune = ' ';
			isVip = false;
			seatNo = new int[10];
			event = Event();
			noTickets = 0;
			ticketID = 0;
		}

		Ticket(int newID, char newTribune, bool newIsVip, int* newSeatNo, Event newEvent) {
			tribune = newTribune;
			isVip = newIsVip;
			seatNo = new int[sizeof(newSeatNo)*sizeof(int)];
			*seatNo = *newSeatNo;
			event = newEvent;
			noTickets++;
			ticketID = newID;
		}

		~Ticket() {
			delete[] seatNo;
			seatNo = nullptr;
		}


		Event getEvent() {
			return event;
		}

		const int getTicketID() {
			return ticketID;
		}

		void setTicketID(int newID) {
			ticketID = newID;
		}

		void setEvent(Event newEvent) {
			event = newEvent ;
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

		int* getSeatNo() {
			int* copy = new int[sizeof(seatNo)*sizeof(int)];
			*copy = *seatNo;
			return copy;
		}

		void setSeatNo(int* newSeatNo) {
			int* seatNo = new int[sizeof(newSeatNo) * sizeof(int)];
			*seatNo = *newSeatNo;
		}

		static void setNoTickets(int newNoTickets) {
			noTickets = newNoTickets;
		}

		static int generateRandomTicketID() {
			srand(time(0));
			return rand();
		}
		
	};

	void  main() {
		Location l;
		Event e;
		int i[2] = { 1,2 };

		Ticket::setNoTickets(0);
		Ticket t(Ticket::generateRandomTicketID(), 'A', false, i, e);
		cout << t.getTicketID();

	}
