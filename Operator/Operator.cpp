#include <iostream>"
#include <fstream>
#include <string>
#include <map>
using namespace std;

int main() {
	//авторизация
	//добавление рейсов
	//просмотр списка пассажиров на рейс
	cout << "Operator" << endl;
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
				cout << "3 - edit flight" << endl;

				cout << "4 - seen list of passanger on flight" << endl;
				cout << "choise>>>>";
				cin >> choise;
				switch (choise) {
				case 1: cout << "add flight"; break;
				case 2: cout << "delete flight"; break;
				case 3: cout << "edit flight"; break;
				case 4: cout << "seen list"; break;
				}
			} while (choise != 0);
		}
	}
	system("pause");
	return 0;
}