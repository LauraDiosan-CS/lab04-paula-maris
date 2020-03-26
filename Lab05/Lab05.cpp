// Lab05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Test.h"
#include <iostream>
#include "Entitate.h"
#include "RepositorySTL.h"
#include "Service.h"
#include "UI.h"

using namespace std;

int main()
{
	cout << "start tests..." << endl;
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	cout << "succes" << endl;

	int n;
	int option;
	UI u;
	Service serv;
	u.incarcaElemente(serv);								//daca dorim sa avem deja cateva elemente
	u.afisareAll(serv);
	bool stop = false;
	while (stop == false) {
		u.afisaremeniu();
		option = u.getinput();
		if (option == 1) {									//adaugarea unei tranzactii
			u.adauga(serv);
			u.afisareAll(serv);
		}
		if (option == 2) {									//stergerea unei tranzactii
			u.deleteElem(serv);
			u.afisareAll(serv);
		}
		if (option == 3) {									//actualizarea unei tranzactii
			u.update(serv);
			u.afisareAll(serv);
		}
		if (option == 4) {
			u.afisareIN(serv);								//afisarea tranzactiilor de tipul IN
		}
		if (option == 5) {									//stergerea tranzactiilor din intervalul de zile 5-10
			u.delete5_10(serv);
			u.afisareAll(serv);
		}
		if (option == 6) {
			u.afisareSumaIN(serv);							//afisarea sumei tranzactiilor de tipul IN
		}
		if (option == 7) {
			//serv.max();
		}
		if (option == 8) {
			u.modif_zi_10(serv);							//modificarea tranzactiilor din ziua 10
			u.afisareAll(serv);
		}
		if (option == 9) {
			serv.undo();									//undo
			u.afisareAll(serv);
		}
		if (option == 10) {
			serv.redo();									//redo
			u.afisareAll(serv);
		}
		if (option == 11) {
			u.afisareAll(serv);								//afisarea tuturor tranzactiilor
		}
		if (option == 12) {
			stop = true;									//oprirea programului
		}
	}
	return 0;
}