#include "Ticket.h"

ostream& operator<<(ostream& out, Ticket tk)
{
	out << tk.isVip << tk.noTickets << tk.seatNo << tk.ticketID << tk.tribune << tk.event;
	return out;
}

istream& operator>>(istream& in, Ticket& tk)
{
	cout << "Enter tribune:";
	in >> tk.tribune;
	cout << "Enter VIP status of ticket:";
	in >> tk.isVip;
	cout << "Enter event:";
	in >> tk.event;


}
