#pragma once
#include <iostream>
#include <string>
#include <map>
#include "..\Classes\Flights.h"
using namespace std;

struct _ticket {
	string number_flight;
	string fio_passanger;
	_date date_birthday_passenger;
};

class Tickets
{
	multimap<string, _ticket> tickets;
public:
	Tickets();
	~Tickets();
	void add_ticket();
	void print_tickets_for_number_flight();
};

