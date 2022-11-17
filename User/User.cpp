#include <iostream>
using namespace std;

int main() {
	//ввод города выбытия и получения списка рейсов на из такого города
	//ввод города прибытия и получения списка рейсов на из такого города
	//ввод города выбытия и прибытия и получения списка рейсов на из такого города
	//бронирование билета на рейс
	cout << "User" << endl;
	int choise;
	do {
		system("cls");
		cout << "your actions uzver?" << endl;
		cout << "0 - exit" << endl;

		cout << "1 - enter up city and choise flight" << endl;
		cout << "2 - enter down city and choise flight" << endl;
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
	system("pause");
	return 0;
}