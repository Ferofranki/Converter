#include <stdio.h> 
#include <iostream>
#include <stdlib.h>

using namespace std;
int cels, fahr, kelv;

void zapisToData(int* dataCounter, double* data, double temp1, double temp2, char znak1, char znak2, char* dataZ) {
	data[*dataCounter] = temp1;
	dataZ[*dataCounter] = znak1;
	(*dataCounter)++;
	data[*dataCounter] = temp2;
	dataZ[*dataCounter] = znak2;
	(*dataCounter)++;
	
}

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

int check(float temp, char stopnie) {
	if (stopnie == 'F') {
		if (temp < -459.67) {
			cout << "Nie ma takiej temperatury" << endl;
			return -999.0;
		}
	}
	else if (stopnie == 'C') {
		if (temp < -273.15) {
			cout << "Nie ma takiej temperatury" << endl;
			return -999.0;
		}
	}
	else if (stopnie == 'K') {
		if (temp < 0) {
			cout << "Nie ma takiej temperatury" << endl;
			return -999.0;
		}
	}
	return temp;
}
enum vybar {
	FC = 1,
	FK,
	CF,
	CK,
	KC,
	KF,
	history,
	end
};
void menu() {
	cout << "1. Fahr to Celsius" << endl;
	cout << "2. Fahr to Kelvin" << endl;
	cout << "3. Celsius to Fahr" << endl;
	cout << "4. Celsius to Kelvin" << endl;
	cout << "5. Kelvin to Celsius" << endl;
	cout << "6. Kelvin to Fahr" << endl;
	cout << "7. Pokaz historie" << endl;
	cout << "8. Bye-bye" << endl;
}



int main()
{
	double data[100] = { 0 };
	int dataCounter = 0;
	
	char dataZ[100];




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
			temp = check(temp, 'F');
			if (temp == -999.0) {
				break;
			}
			cout << "W Celsiusach: " << FtC(temp) << endl;
			zapisToData(&dataCounter, data, temp, FtC(temp), 'F', 'C', dataZ);
			break;
		case 2:
			cout << "Temp w Fahr: ";
			cin >> temp;
			temp = check(temp, 'F');
			if (temp == -999.0) {
				break;
			}
			cout << "W Kelwinach: " << FtK(temp) << endl;
			zapisToData(&dataCounter, data, temp, FtK(temp), 'F', 'K', dataZ);
			break;
		case 3:
			cout << "Temp w Celsiusach: ";
			cin >> temp;
			temp = check(temp, 'C');
			if (temp == -999.0) {
				break;
			}
			cout << "W Fahr: " << CtF(temp) << endl;
			zapisToData(&dataCounter, data, temp, CtF(temp), 'C', 'F', dataZ);
			break;
		case 4:
			cout << "Temp w Celsiusach: ";
			cin >> temp;
			temp = check(temp, 'C');
			if (temp == -999.0) {
				break;
			}
			cout << "W Kelwinach: " << CtK(temp) << endl;
			zapisToData(&dataCounter, data, temp, CtK(temp), 'C', 'K', dataZ);
			break;
		case 5:
			cout << "Temp w Kelwinach: ";
			cin >> temp;
			temp = check(temp, 'K');
			if (temp == -999.0) {
				break;
			}
			cout << "W Celsiusach: " << KtC(temp) << endl;
			zapisToData(&dataCounter, data, temp, KtC(temp), 'K', 'C', dataZ);
			break;
		case 6:
			cout << "Temp w Kelwinach: ";
			cin >> temp;
			temp = check(temp, 'K');
			if (temp == -999.0) {
				break;
			}
			cout << "W Fahr: " << KtF(temp) << endl;
			zapisToData(&dataCounter, data, temp, KtF(temp), 'K', 'F', dataZ);
			break;
		case 7:
			cout << "\tHistoria" << endl;
			for (int i = 1, g = 0; i <= dataCounter / 2; i++, g += 2) {
				cout << "<" << i << "> " << data[g] << dataZ[g] << " = " << data[g + 1] << dataZ[g + 1] << endl;
			}
			break;
		case 8:
			cout << "Do zobaczenia" << endl;
			return 0;
			
		default:
			cout << "Nie mozesz tego zrobic" << endl;


		}
		
		cout << "Enter zeby kontynuowac" << endl;
		cin.ignore(); //каб скіпаць першы enter
		cin.get(); //каб увесці толькі enter і нічога іншага
	}
}