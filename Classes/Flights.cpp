#include "Flights.h"

Flights::Flights()
{
//Номер рейса
//Пункт выбытия
//Пункт назначения
//Дата рейса
//Время вылета
//Время прибытия
//Тип самолета
//Стоимость билета
//Количество мест
	ifstream is("..\\db\\flights.txt");
	_flights temp;
	string temp_number_flight;
	while (!is.eof()) {
		is >> temp_number_flight;
		temp.number_flight = temp_number_flight;
		is >> temp.up_city;
		is >> temp.down_city;
//		is >> temp.date_flight.day;
//		is >> temp.date_flight.month;
//		is >> temp.date_flight.year;
//		is >> temp.time_up.hour;
//		is >> temp.time_up.min;
//		is >> temp.time_down.hour;
//		is >> temp.time_down.min;
//		is >> temp.type_airoplane;
//		is >> temp.ticket_price;
//		is >> temp.number_flight;
		flights.insert(make_pair(temp_number_flight, temp));
	}
	is.close();
}

Flights::~Flights()
{
	ofstream os("..\\db\\flights.txt");
	for (auto it_flight : flights) {
		os << it_flight.second.number_flight << endl;
		os << it_flight.second.up_city << endl;
		os << it_flight.second.down_city << endl;
//		os << it_flight.second.date_flight.day << endl;
//		os << it_flight.second.date_flight.month << endl;
//		os << it_flight.second.date_flight.year << endl;
//		os << it_flight.second.time_up.hour << endl;
//		os << it_flight.second.time_up.min << endl;
//		os << it_flight.second.time_down.hour << endl;
//		os << it_flight.second.time_down.min << endl;
//		os << it_flight.second.type_airoplane << endl;
//		os << it_flight.second.ticket_price << endl;
//		os << it_flight.second.number_flight << endl;
	}
	os.close();
}

void Flights::add_flight(Cities& _cities)
{
	cout << "\tAdd flight" << endl;
	_flights temp_flight;
	string temp_number_flight, temp_up_city, temp_down_city;
	cout << "enter Number of flight: ";
	cin >> temp_number_flight;

	cout << "select Up city: " << endl;
	_cities.print_cities();
	cout << "enter your up city: ";
	cin >> temp_up_city;

	cout << "select Down city: " << endl;
	_cities.print_cities();
	cout << "enter your down city: ";
	cin >> temp_down_city;

	temp_flight.number_flight = temp_number_flight;
	temp_flight.up_city = temp_up_city;
	temp_flight.down_city = temp_down_city;

	flights.insert(make_pair(temp_number_flight, temp_flight));
}

void Flights::delete_flight()
{
	string key_number_flight;
	cout << "\tDelete flight" << endl;
	cout << "enter number flight for delete: ";
	cin >> key_number_flight;

	flights.erase(key_number_flight);
}

void Flights::edit_flight()
{

}

void Flights::print_flight()
{
	for (auto it_flight : flights) {
		cout << "Number flight: " << it_flight.second.number_flight << endl;
		cout << "Up city: " << it_flight.second.up_city << endl;
		cout << "Down city: " << it_flight.second.down_city << endl;
	}
	system("pause");
}
