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
	for (auto& it_city : name_city) {
		os << it_city << endl;
	}
	os.close();
}

void Cities::add_city()
{
	system("cls");
	string temp_name_city;
	cout << "enter city for add: ";
	cin >> temp_name_city;
	name_city.insert(temp_name_city);
}

void Cities::print_cities()
{
	system("cls");
	cout << "\tAll cities" << endl;
	for (auto& it_city: name_city)
		cout << it_city << endl;
	system("pause");
}

void Cities::delete_city()
{
	system("cls");
	string temp_city;
	bool flag = false;
	cout << "\tdelete city" << endl;
	cout << "enter city for delete: ";
	cin >> temp_city;
	for (auto& it_city : name_city) {
		if (it_city == temp_city) {
			flag = true;
			name_city.erase(temp_city);
		}
	}
	if (!flag) cout << "city " << temp_city << " is not found";
	system("pause");
}

set<string> Cities::GetCities()
{
	return name_city;
}
