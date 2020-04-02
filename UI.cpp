#include <iostream>
#include <string>
#include "UI.h"
#include <ctime> 
#include <time.h>
#include <string.h>
#include "Test.h"
#include "Entitate.h"
#include "RepositorySTL.h"

using namespace std;

UI::UI() {
	this->serv;
}

UI::~UI() {

}

//ui pentru adaugare
void UI::adauga(Service& serv) {
	int ziua;
	int suma;
	char tip[10];
	char desc[20];
	char tipuri[2][5] = { "in","out" };
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
	int cont2 = 0;
	if (ziua > 31)
	{
		while (cont2 == 0)
		{
			cout << "Dati un numar intre [0,31]: ";
			cin >> ziua;
			if (ziua <= 31)
				cont2++;
		}
	}
	cout << "Dati suma: ";
	cin >> suma;
	int cont = 0;
	if (suma < 0)
	{
		while (cont == 0)
		{
			cout << "Dati un numar intreg pozitiv! " << endl;
			cin >> suma;
			if (suma >= 0)
				cont++;
		}
	}
	cout << "Dati tipul (in/out): ";
	cin >> tip; int cont1 = 0;
	for (int i = 0; i < sizeof tipuri; i++)
		if (strcmp(tip, tipuri[i]) == 0)
			cont1++;
	while (cont1 == 0)
	{
		cout << "Dati un tip valid: ";
		cin >> tip;
		for (int i = 0; i < sizeof tipuri; i++)
			if (strcmp(tip, tipuri[i]) == 0)
				cont1++;
	}
	cout << "Dati descrierea: ";
	cin >> desc;
	cout << endl;
	Entitate s(ziua, suma, tip, desc);
	serv.adauga(s);
}

void UI::deleteElem(Service& serv) {
	int poz = 0; int nr_elem;
	vector<Entitate> elem = serv.getAll();
	nr_elem = elem.size();
	cout << "Dati pozitia elementului pe care doriti sa-l stergeti: (intre 1 si " << nr_elem << ") ";
	cin >> poz;
	cout << endl;
	serv.deleteElem(elem[poz - 1]);
}

//stergerea tuturor tranzactiilor din ziua 5 pana in ziua 10
void UI::delete5_10(Service& serv) {
	vector<Entitate> elem = serv.getAll();
	for (int i = 0; i < elem.size(); i++)
	{
		Entitate tranz;
		tranz = elem[i];
		//if ((strcmp(tranz.getTip(), "in") == 0))          -daca vreau sa sterg tranz care au tipul IN!!!
		if (tranz.getZiua() >= 5 && tranz.getZiua() <= 10)
			serv.deleteElem(tranz);
	}
}

void UI::modif_zi_10(Service& serv) {
	vector<Entitate> elem = serv.getAll();
	for (int i = 0; i < elem.size(); i++)
	{
		Entitate tranz;
		tranz = elem[i];
		if (tranz.getZiua() == 10)
		{
			serv.update_manual(elem[i]);
		}
	}
}

//actualizarea unei tranzactii
void UI::update(Service& serv) {
	int elem_update = 0;
	int nr_poz = 0;
	vector<Entitate> elem = serv.getAll();
	nr_poz = elem.size();
	cout << "Dati pozitia elementului pe care doriti sa-l schimbati: (intre 1 si " << nr_poz << ") ";
	cin >> elem_update;
	cout << endl;
	serv.update(elem[elem_update - 1]);
}

//ui pt inserare
void UI::insereaza(Service& serv) {
	int ziua;
	int suma;
	char tip[10];
	char desc[20];
	char tipuri[6][10] = { "in","out"};
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
	int cont2 = 0;
	if (ziua > 31)
	{
		while (cont2 == 0)
		{
			cout << "Dati un numar intre [0,31]: ";
			cin >> ziua;
			if (ziua <= 31)
				cont2++;
		}
	}
	cout << "Dati suma: ";
	cin >> suma;
	int cont = 0;
	if (suma < 0)
	{
		while (cont == 0)
		{
			cout << "Dati un numar intreg pozitiv! " << endl;
			cin >> suma;
			if (suma >= 0)
				cont++;
		}
	}
	cout << "Dati tipul (in/out): ";
	cin >> tip; int cont1 = 0;
	for (int i = 0; i < sizeof tipuri; i++)
		if (strcmp(tip, tipuri[i]) == 0)
			cont1++;
	while (cont1 == 0)
	{
		cout << "Dati un tip valid: ";
		cin >> tip;
		for (int i = 0; i < sizeof tipuri; i++)
			if (strcmp(tip, tipuri[i]) == 0)
				cont1++;
	}
	cout << "Dati descrierea: ";
	cin >> desc;
	cout << endl;
	Entitate s(ziua, suma, tip, desc);
	serv.adauga(s);
}

//afiseaza toate elem din vector
void UI::afisareAll(Service& serv) {
	vector<Entitate> elem = serv.getAll();
	for (int i = 0; i < elem.size(); i++) {
		cout << i + 1 << ".) ";
		elem[i].afisare();
		cout << endl;
	}
}

//incarca elemente
void UI::incarcaElemente(Service& serv) {
	serv.incarcaElemente();
}

//afisare pentru toate tipurile de tip in
void UI::afisareIN(Service& serv) {
	vector<Entitate> elem = serv.getAll();
	int k = 1;
	for (int i = 0; i < elem.size(); i++) {
		if (strcmp(elem[i].getTip(), "in") == 0)
		{
			cout << k << ".) ";
			elem[i].afisare();
			cout << endl;
			k++;
		}
	}
}

// afisarea sumei tuturor tranzactiilor de tip -in-
void UI::afisareSumaIN(Service& serv) {
	vector<Entitate> elem = serv.getAll();
	int suma = 0;
	for (int i = 0; i < elem.size(); i++) {
		if (strcmp(elem[i].getTip(), "in") == 0)
		{
			suma += elem[i].getSuma();
		}
	}
	cout << "Suma tuturor tranzactiilor de tipul -in- este: "<< suma;
	cout << endl;
}

//ia input de la tastatura pt o optiune din meniu
int UI::getinput() {
	int choice;
	cin >> choice;
	return choice;
}

//afisarea meniului
void UI::afisaremeniu()
{
	cout << "------------------------------------------------------------------------------------------------------------------------";
	cout << endl << "Main Menu\n" << endl;
	cout << "Optiuni:\n";
	cout << "1 - Adaugare cheltuiala\n";
	cout << "2 - Stergere cheltuiala\n";
	cout << "3 - Update cheltuiala\n";
	cout << "4 - Afisarea tuturor cheltuielilor din tipul -in-\n";
	cout << "5 - Stergerea tuturor tranzactiilor din ziua 5 pana in ziua 10\n";
	cout << "6 - Afisarea sumei tuturor tranzactiilor de tipul -in-\n";
	cout << "8 - Modifica tranzactiile din ziua 10 astfel: la descriere -> Salar, iar la suma -> 2000\n";
	cout << "9 - Undo\n";
	cout << "10 - Redo\n";
	cout << "11 - Afisare\n";
	cout << "12 - Exit\n";
	cout << endl << "Alegeti optiunea: ";
}