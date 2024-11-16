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

float FtC(float temp) { //хуйня,якую трэба зрабіць як-небудзь менш(але няпэўна)
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
enum vybar { //lvl 1 Rookie
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
enum histType { //Сумненна, але окэээй
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

void vybHIST(double* data, char* dataZ, int dataCounter, char tempType) {
	bool cry = true;
	for (int i = 1, g = 0; g < dataCounter; g += 2) {

		if (dataZ[g] == tempType || tempType == 'A') { //Зрабіць фцыю dataZ[g] = peremenaya || peremenaya = 'A'
			cout << "<" << i << "> " << data[g] << dataZ[g] << " = " << data[g + 1] << dataZ[g + 1] << endl;
			cry = false;
			i++;
		}

	}
	if (cry) {
		cout << "Bruh,nie ma danych" << endl;
	}
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


