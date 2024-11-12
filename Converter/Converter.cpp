#include <stdio.h> 
#include <iostream>
#include <stdlib.h>
#include "header1.h"

using namespace std;
int cels, fahr, kelv;





int main()
{
	const int k = 100;
	double data[k] = { 0 };
	int dataCounter = 0;
	
	char dataZ[k] = { 0 };

	bool cry = true;


	while (true) {
		system("cls");
		menu();
		if (dataCounter >= k) {
			cout << "\nPamieci nie ma, nie zapisze\n";
			dataCounter = k;
		}



		int vybar;
		cin >> vybar;
		float temp;
		

		switch (vybar) {
		case FC:
			cout << "Temp w Fahr: ";
			cin >> temp;
			temp = check(temp, 'F');
			if (temp == -999.0) {
				break;
			}
			cout << "W Celsiusach: " << FtC(temp) << endl;
			zapisToData(&dataCounter, data, temp, FtC(temp), 'F', 'C', dataZ);
			break;
		case FK:
			cout << "Temp w Fahr: ";
			cin >> temp;
			temp = check(temp, 'F');
			if (temp == -999.0) {
				break;
			}
			cout << "W Kelwinach: " << FtK(temp) << endl;
			zapisToData(&dataCounter, data, temp, FtK(temp), 'F', 'K', dataZ);
			break;
		case CF:
			cout << "Temp w Celsiusach: ";
			cin >> temp;
			temp = check(temp, 'C');
			if (temp == -999.0) {
				break;
			}
			cout << "W Fahr: " << CtF(temp) << endl;
			zapisToData(&dataCounter, data, temp, CtF(temp), 'C', 'F', dataZ);
			break;
		case CK:
			cout << "Temp w Celsiusach: ";
			cin >> temp;
			temp = check(temp, 'C');
			if (temp == -999.0) {
				break;
			}
			cout << "W Kelwinach: " << CtK(temp) << endl;
			zapisToData(&dataCounter, data, temp, CtK(temp), 'C', 'K', dataZ);
			break;
		case KC:
			cout << "Temp w Kelwinach: ";
			cin >> temp;
			temp = check(temp, 'K');
			if (temp == -999.0) {
				break;
			}
			cout << "W Celsiusach: " << KtC(temp) << endl;
			zapisToData(&dataCounter, data, temp, KtC(temp), 'K', 'C', dataZ);
			break;
		case KF:
			cout << "Temp w Kelwinach: ";
			cin >> temp;
			temp = check(temp, 'K');
			if (temp == -999.0) {
				break;
			}
			cout << "W Fahr: " << KtF(temp) << endl;
			zapisToData(&dataCounter, data, temp, KtF(temp), 'K', 'F', dataZ);
			break;
		case history:
			cout << "\tHistoria" << endl;
			cout << "-------------------------" << endl;
			cout << "1. Tylko C" <<
				"\n2. Tylko F" <<
				"\n3. Tylko K" <<
				"\n4. Pokaz wszystko" << endl;
			int vybHIS;
			cin >> vybHIS;
			switch (vybHIS) {

			case C:
				cry = true;
				for (int i = 1, g = 0; i <= dataCounter / 2; i++, g += 2) {
					
					if (dataZ[g] == 'C') { //Сделать фцию dataZ[g] = peremenaya || peremenaya = 'A'
						cout << "<" << i << "> " << data[g] << dataZ[g] << " = " << data[g + 1] << dataZ[g + 1] << endl;
						cry = false;
					}
					
				}
				if (cry) {
					cout << "Bruh,nie ma danych" << endl;
				}
				break;
			case F:
				cry = true;
				for (int i = 1, g = 0; i <= dataCounter / 2; i++, g += 2) {

					if (dataZ[g] == 'F') {
						cout << "<" << i << "> " << data[g] << dataZ[g] << " = " << data[g + 1] << dataZ[g + 1] << endl;
						cry = false;
					}

				}
				if (cry) {
					cout << "Bruh,nie ma danych" << endl;
				}
				break;
			case K:
				cry = true;
				for (int i = 1, g = 0; i <= dataCounter / 2; i++, g += 2) {

					if (dataZ[g] == 'K') {
						cout << "<" << i << "> " << data[g] << dataZ[g] << " = " << data[g + 1] << dataZ[g + 1] << endl;
						cry = false;
					}

				}
				if (cry) {
					cout << "Bruh,nie ma danych" << endl;
				}
				break;

			case WSIO: 
			for (int i = 1, g = 0; i <= dataCounter / 2; i++, g += 2) {
				cout << "<" << i << "> " << data[g] << dataZ[g] << " = " << data[g + 1] << dataZ[g + 1] << endl;
			}
			break;
		}
			break;

		case delHistory:
			cout << "\tHistoria" << endl;
			cout << "-------------------------" << endl;
			for (int i = 1, g = 0; i <= dataCounter / 2; i++, g += 2) {
				cout << "<" << i << "> " << data[g] << dataZ[g] << " = " << data[g + 1] << dataZ[g + 1] << endl;
			}
			int del;
			cout << "Co chcesz usunac?" << endl;
			cin >> del;
			if (del >= dataCounter / 2 || del < 0) {
				cout << "Nie ma takiego elementu" << endl;
				break;
			}
			else {
				delData(data, dataZ, del, k);
				dataCounter -= 2;
				cout << "Usunieto" << endl;
			}
			break;


		case koniec:
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
