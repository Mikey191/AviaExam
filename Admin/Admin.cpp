#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <map>
#include "..\\Classes\Cities.h"
#include "..\\Classes\Flights.h"
using namespace std;

void load_operators(map<string, string>& _operators);
void save_operators(map<string, string>& _operators);

void print_operators(map<string, string>& _operators);
void add_operator(map<string, string>& _operators);
void edit_operator(map<string, string>& _operators);
void delete_operator(map<string, string>& _operators);

int main() {
	//добавляет оператора
	//добавляет города
	//просматривает список рейсов
	Flights all_flights;
	Cities all_cities;
	map<string, string> _operators;
	load_operators(_operators);
	cout << "Admin" << endl;
	//сделать проверку на логин пароль админа(они будут храниться в отдельном файле)
	ifstream is("..\\db\\admin.txt");
	string is_login, is_password;
	is >> is_login;
	is >> is_password;
	string enter_login, enter_password;
	system("cls");
	cout << "enter login: ";
	cin >> enter_login;
	system("cls");
	cout << "enter password: ";
	cin >> enter_password;
	system("cls");
	if (is_login == enter_login && is_password == enter_password) {
		int choise;
		do {
			system("cls");
			cout << "your actions admin?" << endl;
			cout << "0 - exit" << endl;

			cout << "1 - add operator" << endl;
			cout << "2 - delete operator" << endl;
			cout << "3 - edit operator" << endl;

			cout << "4 - add city" << endl;
			cout << "5 - delete city" << endl;

			cout << "6 - seen list of flight" << endl;
			cout << "7 - print all operators" << endl;
			cout << "8 - print all cities" << endl;
			cout << "choise>>>>";
			cin >> choise;
			switch(choise){
			case 1: add_operator(_operators); break;
			case 2: delete_operator(_operators); break;
			case 3: edit_operator(_operators); break;
			case 4: all_cities.add_city(); break;
			case 5: all_cities.delete_city(); break;
			case 6: all_flights.print_flights(); break;
			case 7: print_operators(_operators); break;
			case 8: all_cities.print_cities(); break;
			}
		} while (choise != 0);
	}
	else cout << "not found your login/password" << endl;

	system("pause");
	return 0;
}

void load_operators(map<string, string>& _operators)
{
	ifstream is("..\\db\\operators.txt");
	string operator_login, operator_password;
	if (is) {
		while (!is.eof()) {
			is >> operator_login;
			is >> operator_password;
			_operators.insert(make_pair(operator_login, operator_password));
		}
	}
	is.close();
}

void save_operators(map<string, string>& _operators)
{
	ofstream os("..\\db\\operators.txt");
	for (auto& it_operator : _operators) {
		os << it_operator.first << endl;
		os << it_operator.second << endl;
	}
	os.close();
}

void print_operators(map<string, string>& _operators)
{
	system("cls");
	for (auto& it_operator : _operators) {
		cout << it_operator.first << " " << it_operator.second << endl;
	}
	system("pause");
}

void add_operator(map<string, string>& _operators)
{
	system("cls");
	cout << "\tAdd operator" << endl;
	string operator_login, operator_password;
	bool flag = false;
	cout << "enter operators login: ";
	cin >> operator_login;
	cout << "enter operators password: ";
	cin >> operator_password;
	for (auto& it_operators : _operators)
		if (it_operators.first == operator_login) flag = true; 
	if (!flag) _operators.emplace(make_pair(operator_login, operator_password));
	else cout << "this login is using" << endl;

	save_operators(_operators);
}

void edit_operator(map<string, string>& _operators)
{
	system("cls");
	string temp_login;
	bool flag = false;
	system("cls");
	cout << "\tEditor" << endl;
	cout << "enter login for edit: ";
	cin >> temp_login;
	for (auto& it_operator : _operators) {
		if (it_operator.first == temp_login) {
			flag = true;
			cout << "do you whant change only password or login & password?" << endl;
			cout << "1 - change only password" << endl;
			cout << "2 - change login and password" << endl;
			int choise;
			cin >> choise;
			switch (choise) {
			case 1:
				cout << "enter new password: ";
				cin >> it_operator.second;
				cout << "new login/password: " << it_operator.first << " / " << it_operator.second << endl;
				break;
			case 2:
				string new_login, new_password;
				_operators[temp_login].erase();
				cout << "enter new login: ";
				cin >> new_login;
				cout << "enter new password: ";
				cin >> new_password;
				_operators.emplace(make_pair(new_login, new_password));
				cout << "new login/password: " << new_login << " / " << new_password << endl;
			}
		}
	}
	if (!flag)cout << "login " << temp_login << " is not found!" << endl;

	save_operators(_operators);
}

void delete_operator(map<string, string>& _operators)
{
	system("cls");
	string temp_login;
	bool flag = false;
	cout << "\tdelete operator" << endl;
	cout << "enter login for delete" << endl;
	cin >> temp_login;
	for (auto& it_operators : _operators) {
		if (it_operators.first == temp_login) {
			flag = true;
			_operators[temp_login].erase();
		}
	}
	if (!flag) cout << "Login " << temp_login << " is not found!" << endl;
	system("pause");

	save_operators(_operators);
}
