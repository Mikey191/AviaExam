#include "Tickets.h"

Tickets::Tickets()
{
	ifstream is("..\\db\\tickets.txt");
	_ticket temp_ticket;
	string temp_number_flight;
	while (!is.eof()) {
		is >> temp_ticket.number_flight;
		is >> temp_ticket.fio_passanger;
		is >> temp_ticket.date_birthday_passenger.day;
		is >> temp_ticket.date_birthday_passenger.month;
		is >> temp_ticket.date_birthday_passenger.year;
		tickets.insert(make_pair(temp_ticket.number_flight, temp_ticket));
	}
	is.close();
}

Tickets::~Tickets()
{
	ofstream os("..\\db\\tickets.txt");
	for (auto& it_ticket : tickets) {
		os << it_ticket.second.number_flight;
		os << it_ticket.second.fio_passanger;
		os << it_ticket.second.date_birthday_passenger.day;
		os << it_ticket.second.date_birthday_passenger.month;
		os << it_ticket.second.date_birthday_passenger.year;
	}
	os.close();
}

void Tickets::add_ticket()
{
	cout << "\tBooking ticket" << endl;
	_ticket temp_ticket;
	string ticket_number_flight, ticket_fio;
	int ticket_birth_day, ticket_birth_month, ticket_birth_year;
	cout << "enter number flight: ";
	cin >> ticket_number_flight;
	cout << "enter fio: ";
	cin >> ticket_fio;
	cout << "enter birth day passanger: ";
	cin >> ticket_birth_day;
	cout << "enter birth month passanger: ";
	cin >> ticket_birth_month;
	cout << "enter birth year passanger: ";
	cin >> ticket_birth_year;

	temp_ticket.number_flight = ticket_number_flight;
	temp_ticket.fio_passanger = ticket_fio;
	temp_ticket.date_birthday_passenger.day = ticket_birth_day;
	temp_ticket.date_birthday_passenger.month = ticket_birth_month;
	temp_ticket.date_birthday_passenger.year = ticket_birth_year;

	tickets.insert(make_pair(temp_ticket.number_flight, temp_ticket));
}

void Tickets::print_tickets_for_number_flight()
{
	for (auto& it_tickets : tickets) {
		cout << "Number flight: " << it_tickets.second.number_flight << endl;
		cout << "Number fio: " << it_tickets.second.fio_passanger << endl;
		cout << "Date birthday: " << it_tickets.second.date_birthday_passenger.day << "." << it_tickets.second.date_birthday_passenger.month << "." << it_tickets.second.date_birthday_passenger.year << endl;
		cout << "=====" << endl;
	}
	system("pause");
}
