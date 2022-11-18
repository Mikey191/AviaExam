#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "..\\Classes\Tickets.h"
#include "..\\Classes\Flights.h"
#include "..\\Classes\Cities.h"
using namespace std;

int main() {
	//ввод города выбытия и получения списка рейсов на из такого города
	//ввод города прибытия и получения списка рейсов на из такого города
	//ввод города выбытия и прибытия и получения списка рейсов на из такого города
	//бронирование билета на рейс
	Tickets ticket;
	Flights flight;
	Cities city;
	cout << "User" << endl;
	int choise;
	do {
		system("cls");
		cout << "your actions uzver?" << endl;
		cout << "0 - exit" << endl;

		cout << "1 - enter up city and choise flight" << endl;
		cout << "2 - enter down city and choise flight" << endl;
		cout << "3 - enter up and down city and choise flight" << endl;

		cout << "4 - booking ticket" << endl;
		cout << "choise>>>>";
		cin >> choise;
		switch (choise) {
		case 1: flight.print_flight_up_cities(); break;//class Flights
		case 2: flight.print_flight_down_cities(); break;//class Flights
		case 3: flight.print_flight_up_down_cities(); break;//class Flights
		case 4: ticket.add_ticket(); break;//class Tickets
		case 5: ticket.print_tickets_for_number_flight(); break;
		}
	} while (choise != 0);
	system("pause");
	return 0;
}