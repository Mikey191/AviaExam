#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <map>
#include "..\\Classes\Cities.h"
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
	Cities _cities;
	map<string, string> _operators;
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
			cout << "6 - edit city" << endl;

			cout << "7 - seen list of flight" << endl;
			cout << "choise>>>>";
			cin >> choise;
			switch(choise){
			case 1: add_operator(_operators); break;
			case 2: cout << "delete operator"; break;
			case 3: cout << "edit operator"; break;
			case 4: _cities.add_city(); break;
			case 5: cout << "delete city"; break;
			case 6: cout << "edit city"; break;
			case 7: print_operators(_operators); break;
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
	load_operators(_operators);

	for (auto it_operator : _operators) {
		cout << it_operator.first << " " << it_operator.second << endl;
	}
	system("pause");
}

void add_operator(map<string, string>& _operators)
{
	load_operators(_operators);

	string operator_login, operator_password;
	cout << "enter operators login: ";
	cin >> operator_login;
	cout << "enter operators password: ";
	cin >> operator_password;
	for (auto& it_operators : _operators) {
		if (it_operators.first != operator_login) {
			_operators.insert(make_pair(operator_login, operator_password));
		}
		else cout << "this login is already in use" << endl;
	}

	save_operators(_operators);
}

void edit_operator(map<string, string>& _operators)
{
	load_operators(_operators);


	save_operators(_operators);
}

void delete_operator(map<string, string>& _operators)
{
	load_operators(_operators);

	save_operators(_operators);
}
