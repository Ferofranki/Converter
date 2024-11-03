#include <stdio.h> 
#include <iostream>
#include <stdlib.h>

using namespace std;
int cels, fahr, kelv;

float FtC(float temp) {
	float wynik = (temp - 32) * 5.0 / 9.0;
	return wynik;
}
float FtK(float temp) {
	float wynik = (temp + 459.67) * 5.0 / 9.0;
	return wynik;
}
float CtF(float temp) {
	float wynik = temp * 9.0 / 5.0 + 32;
	return wynik;
}
float CtK(float temp) {
	float wynik = temp + 273.15;
	return wynik;
}
float KtC(float temp) {
	float wynik = temp - 273.15;
	return wynik;
}
float KtF(float temp) {
	float wynik = temp * 9.0 / 5.0 - 459.67;
	return wynik;
}

enum vybar {
	FC = 1,
	FK,
	CF,
	CK,
	KC,
	KF,
	end
};
void menu() {
	cout << "1. Fahr to Celsius" << endl;
	cout << "2. Fahr to Kelvin" << endl;
	cout << "3. Celsius to Fahr" << endl;
	cout << "4. Celsius to Kelvin" << endl;
	cout << "5. Kelvin to Celsius" << endl;
	cout << "6. Kelvin to Fahr" << endl;
	cout << "7. Bye-bye" << endl;
	
}

int main()
{
	
	while (true) {
		system("cls");
		menu();
		int vybar;
		cin >> vybar;
		float temp;

		switch (vybar) {
		case 1:
			cout << "Temp w Fahr: ";
			cin >> temp;


			cout << "W Celsiusach: " << FtC(temp) << endl;
			break;
		case 2:
			cout << "Temp w Fahr: ";
			cin >> temp;
			cout << "W Kelwinach: " << FtK(temp) << endl;
			break;
		case 3:
			cout << "Temp w Celsiusach: ";
			cin >> temp;

			cout << "W Fahr: " << CtF(temp) << endl;
			break;
		case 4:
			cout << "Temp w Celsiusach: ";
			cin >> temp;
			cout << "W Kelwinach: " << CtK(temp) << endl;
			break;
		case 5:
			cout << "Temp w Kelwinach: ";
			cin >> temp;
			cout << "W Celsiusach: " << KtC(temp) << endl;
			break;
		case 6:
			cout << "Temp w Kelwinach: ";
			cin >> temp;
			cout << "W Fahr: " << KtF(temp) << endl;
			break;
		case 7:
			cout << "Do zobaczenia" << endl;
			return 0;
		default:
			cout << "Nie mozesz tego zrobic" << endl;


		}
		cout << "Enter zeby kontynuowac" << endl;
		
		cin.get();
	}
}