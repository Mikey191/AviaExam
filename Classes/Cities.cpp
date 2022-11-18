#include "Cities.h"

Cities::Cities()
{
	ifstream is("..\\db\\cities.txt");
	string temp_city;
	while (!is.eof()) { is >> temp_city; name_city.insert(temp_city); }
	is.close();
}

Cities::~Cities()
{
	ofstream os("..\\db\\cities.txt");
	//for (auto it = name_city.begin(); it != name_city.end(); ++it) {
	//	os << *it << endl;
	//}
	
	for (auto& it_city : name_city) {
		os << it_city << endl;
	}
	os.close();
}

void Cities::add_city()
{
	string temp_name_city;
	cout << "enter city for add: ";
	cin >> temp_name_city;
	name_city.insert(temp_name_city);
}

void Cities::print_cities()
{
	for (auto it_city: name_city)
		cout << it_city << endl;

	//for (auto it = name_city.begin(); it != name_city.end(); ++it) {
	//	cout << *it << endl;
	//}

	system("pause");
}

set<string> Cities::GetCities()
{
	return name_city;
}
