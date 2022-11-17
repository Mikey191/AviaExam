#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	//добавляет оператора
	//добавляет города
	//просматривает список рейсов
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
			case 1: cout << "add oper"; break;
			case 2: cout << "delete operator"; break;
			case 3: cout << "edit operator"; break;
			case 4: cout << "add city"; break;
			case 5: cout << "delete city"; break;
			case 6: cout << "edit city"; break;
			case 7: cout << "seen list"; break;
			}
		} while (choise != 0);
		
		

	}
	else cout << "not found your login/password" << endl;

	system("pause");
	return 0;
}