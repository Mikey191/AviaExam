#include "Tickets.h"

Tickets::Tickets()
{
	ifstream is("..\\db\\tickets.txt");
	_ticket temp_ticket;
	string temp_number_flight;
	while (!is.eof()) {
		is >> temp_number_flight;
		if (temp_number_flight == "") break;
		else {
			temp_ticket.number_flight = temp_number_flight;
			is >> temp_ticket.fio_passanger;
			is >> temp_ticket.date_birthday_passenger.day;
			is >> temp_ticket.date_birthday_passenger.month;
			is >> temp_ticket.date_birthday_passenger.year;
			tickets.emplace(make_pair(temp_ticket.number_flight, temp_ticket));
		}
	}
	is.close();
}

Tickets::~Tickets()
{
	ofstream os("..\\db\\tickets.txt");
	for (auto& it_ticket : tickets) {
		os << it_ticket.second.number_flight << endl;
		os << it_ticket.second.fio_passanger << endl;
		os << it_ticket.second.date_birthday_passenger.day << endl;
		os << it_ticket.second.date_birthday_passenger.month << endl;
		os << it_ticket.second.date_birthday_passenger.year << endl;
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

	system("cls");
	cout << "\tYour ticket" << endl;
	cout << "Number flight: " << temp_ticket.number_flight << endl;
	cout << "Fio: " << temp_ticket.fio_passanger << endl;
	cout << "Date birthday: " << temp_ticket.date_birthday_passenger.day << "." << temp_ticket.date_birthday_passenger.month << "." << temp_ticket.date_birthday_passenger.year << endl;

	system("pause");
}

void Tickets::print_all_tickets()
{
	for (auto& it_tickets : tickets) {
			cout << "Number flight: " << it_tickets.second.number_flight << endl;
			cout << "Fio: " << it_tickets.second.fio_passanger << endl;
			cout << "Date birthday: " << it_tickets.second.date_birthday_passenger.day << "." << it_tickets.second.date_birthday_passenger.month << "." << it_tickets.second.date_birthday_passenger.year << endl;
			cout << "=====" << endl;
	}
	system("pause");
}

void Tickets::print_tickets_for_number_flight()
{
	string temp_number_flight;
	cout << "\tList passanger" << endl;
	cout << "enter Flight number: ";
	cin >> temp_number_flight;
	bool flag = 0;
	cout << "List passanger on "<< temp_number_flight << "flight:" << endl;
	for (auto& it_tickets : tickets) {
		if (it_tickets.first == temp_number_flight) {
			flag = 1;
			cout << "Number flight: " << temp_number_flight << "\tFio: " << it_tickets.second.fio_passanger << endl;
		}
	}
	if (!flag) cout << "Flight " << temp_number_flight << " have no passanger!" << endl;
	system("pause");
}


