#include <iostream>
using namespace std;

int main() {
	int choise;

	do {
		system("cls");
		cout << "\tGeneral" << endl;
		cout << "0 - exit" << endl;
		cout << "1 - admin" << endl;
		cout << "2 - operator" << endl;
		cout << "3 - user" << endl;
		cout << "Your choise: ";
		cin >> choise;
		switch (choise) {
		case 1: system("..\\x64\\Debug\\Admin.exe");  break;
		case 2: system("..\\x64\\Debug\\Operator.exe");  break;
		case 3: system("..\\x64\\Debug\\User.exe");  break;
		}
	} while (choise != 0);
	return 0;
}