#include "Event.h"

ostream& operator<<(ostream& out, Event ev)
{
	out << ev.eventName << " " << ev.date << " " << ev.location;
	return out;
}

istream& operator>>(istream& in, Event& ev)
{
	cout << "Enter event name:";
	in >> ev.eventName;
	cout << "Enter event date";
	in >> ev.date;
	cout << "Enter event Location";
	in >> ev.location;
	return in;
}
