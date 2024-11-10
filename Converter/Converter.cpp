#include <stdio.h> 
#include <iostream>
#include <stdlib.h>
#include "header1.h"

using namespace std;
int cels, fahr, kelv;

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
