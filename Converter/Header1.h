#pragma once
#include <iostream>
using namespace std;



void zapisToData(int* dataCounter, double* data, double temp1, double temp2, char znak1, char znak2, char* dataZ) {
	data[*dataCounter] = temp1;
	dataZ[*dataCounter] = znak1;
	(*dataCounter)++;
	data[*dataCounter] = temp2;
	dataZ[*dataCounter] = znak2;
	(*dataCounter)++;

}

float FtC(float temp) { //што за хуйня
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
enum vybar { //lvl 1
	FC = 1,
	FK,
	CF,
	CK,
	KC,
	KF,
	history,
	delHistory,
	koniec
};
enum histType {
	C = 1,
	F,
	K,
	WSIO
};

void menu() {
	cout << "1. Fahr to Celsius" << endl
		 << "2. Fahr to Kelvin" << endl
		 << "3. Celsius to Fahr" << endl
		 << "4. Celsius to Kelvin" << endl
		 << "5. Kelvin to Celsius" << endl
		 << "6. Kelvin to Fahr" << endl
		 << "7. Pokaz historie" << endl
		 << "8. Usun historie" << endl
		 << "9. Bye-bye" << endl;
}

void delData(double* data, char* dataZ, int delData, int k) { //lvl 99 mafia boss
	for (int i = delData * 2 - 2; i < k - 1; i++) {
		if (dataZ[i + 2] != 0) {
			data[i] = data[i + 2];
			dataZ[i] = dataZ[i + 2];
		}
	}
	for (int i = delData * 2 - 1; i < k - 1; i++) {
		if (dataZ[i + 1] != 0) {
			data[i] = data[i + 2];
			dataZ[i] = dataZ[i + 2];
		}
	}
}


