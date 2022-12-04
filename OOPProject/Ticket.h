#pragma once
#include "Event.h"
#include <time.h>
class Ticket {
private:
	const int ticketID;
	char tribune;
	bool isVip;
	int* seatNo;
	Event event;
	static int noTickets;
public:

	Ticket() :ticketID(0) {
		tribune = ' ';
		isVip = false;
		seatNo = new int[10];
		event = Event();
		noTickets++;
		
	}

	Ticket(int newID, char newTribune, bool newIsVip, int* newSeatNo, Event newEvent) :ticketID(Ticket::generateRandomTicketID()) {
		tribune = newTribune;
		isVip = newIsVip;
		seatNo = new int[sizeof(newSeatNo) * sizeof(int)];
		*seatNo = *newSeatNo;
		event = newEvent;
		noTickets++;
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

	int* getSeatNo() {
		int* copy = new int[sizeof(seatNo) * sizeof(int)];
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

	friend ostream& operator<<(ostream& out, Ticket tk);
	friend istream& operator>>(istream& in, Ticket& tk);
};