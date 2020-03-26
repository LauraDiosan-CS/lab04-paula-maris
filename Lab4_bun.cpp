// Lab4_bun.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Test.h"
#include "Entitate.h"
#include "RepositorySTL.h"
#include <iostream>
#include <ctime> 
#include <time.h>
#include <string.h>
#include <string>

using namespace std;

void afisaremeniu()
{
	cout << endl;
	cout << "---------------------------------------------------------------------------------------------------------------------";
	cout << endl << "Main Menu\n" << endl;
	cout << "Optiuni:\n";
	cout << "1 - Adaugare tranzactie\n";
	cout << "2 - Afisare tranzactii\n";
	cout << "3 - Exit\n";
	cout << endl;
}


int main() {
	cout << "start tests..." << endl;
	test1();
	test2();
	test3();
	cout << "succes";
	int option = 0;
	int n = 0;
	bool stop = false;
	RepositorySTL elem;
	while (stop == false)
	{
		afisaremeniu();
		cout << "Dati optiunea: ";
		cin >> option;
		if (option == 1)
		{
			int ziua;
			int suma;
			char tip[3];
			char desc[10];
			cout << "Dati ziua (daca doriti sa fie ziua curenta, introduceti 0): ";
			cin >> ziua;
			if (ziua == 0)
			{
				int LocalDay;
				time_t now = time(NULL);
				tm localTime;
				localtime_s(&localTime, &now);
				LocalDay = (&localTime)->tm_mday;
				ziua = LocalDay;
			}
			cout << "Dati suma: ";
			cin >> suma;
			cout << "Dati tipul (in/out): ";
			cin >> tip; 
			cout << "Dati descrierea: ";
			cin >> desc;
			Entitate t(ziua, suma, tip, desc);
			elem.addElem(t);
			n++;
			cout << "Tranzactie adaugata cu succes! " << endl;
			afisaremeniu();
		}
		if (option == 2)
		{
			cout << "Tranzactiile sunt: " << endl;
			for (int i = 0; i < n; i++) {
				cout << i + 1 << ".) " << elem.getAll()[i] << " ";
				cout << endl;
			}
			afisaremeniu();
		}
		if (option == 3)
		{
			stop = true;
		}
	}
	return 0;
}