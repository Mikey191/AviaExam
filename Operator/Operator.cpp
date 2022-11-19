#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "..\\Classes\Cities.h"
#include "..\\Classes\Flights.h"
#include "..\\Classes\Tickets.h"
using namespace std;
//авторизация
//добавление рейсов
//просмотр списка пассажиров на рейс
int main() {
	cout << "Operator" << endl;
	Cities all_city;
	Flights all_flights;
	Tickets all_tickets;
	cout << "Operator..." << endl;
	system("pause");
	//проверка на существование логина оператора
	ifstream is("..\\db\\operators.txt");
	map<string, string> operators;
	string is_login, is_password;
	while (!is.eof()) {
		is >> is_login;
		is >> is_password;
		operators.insert(make_pair(is_login, is_password));//заполняем мап операторами
	}

	string enter_login, enter_password;
	system("cls");
	cout << "enter login: ";
	cin >> enter_login;
	system("cls");
	cout << "enter password: ";
	cin >> enter_password;
	system("cls");

	for (auto it = operators.begin(); it != operators.end(); ++it) {
		if (it->first == enter_login && it->second == enter_password) {
			int choise;
			do {
				system("cls");
				cout << "your actions operator?" << endl;
				cout << "0 - exit" << endl;

				cout << "1 - add flight" << endl;
				cout << "2 - delete flight" << endl;
				cout << "3 - edit flight(flight number)" << endl;

				cout << "4 - seen list of passanger on flight" << endl;
				cout << "choise>>>>";
				cin >> choise;
				switch (choise) {
				case 1: all_flights.add_flight(all_city); break;
				case 2: all_flights.delete_flight(); break;
				case 3: all_flights.edit_flight(); break;
				case 4: all_tickets.print_tickets_for_number_flight(); break;
				}
			} while (choise != 0);
		}
	}
	system("pause");
	return 0;
}