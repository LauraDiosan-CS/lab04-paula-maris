#include "RepositorySTL.h"

#include <iostream>
#include <ctime> 
#include <time.h>

using namespace std;


//constructor fara param
RepositorySTL::RepositorySTL() {
	this->elem;
}

//constuctor de copiere
RepositorySTL::RepositorySTL(const RepositorySTL& r) {
	this->elem = r.elem;
}


//adaugarea unui element
//in: elementul de adaugat
//out: -
void RepositorySTL::addElem(Entitate s) {
	elem.push_back(s);
}


//gasirea unui element (true sau false)
//in: elementul de tip Entitate
//out: true daca elementul se afla in Repo, false altfel
bool RepositorySTL::findElem(Entitate s) {
	vector<Entitate>::iterator it;
	it = find(elem.begin(), elem.end(), s);
	if (it != elem.end()) return true;
	return false;

}

//dimensiunea vectorului
//in: -
//out: dimensiunea repository-ului (int)
int RepositorySTL::getSize() {
	return elem.size();
}

//gasirea elementului dupa o pozitie data
Entitate RepositorySTL::getItemFromPos(int i) {
	return elem[i];
}

//destructorul
RepositorySTL::~RepositorySTL()
{}

//returnarea tuturor elementelor
//in: -
//out: un vector de entitati
vector<Entitate> RepositorySTL::getAll() {
	return elem;
}

//eliminare element
//in: elementul de sters
//out: noul repo cu elementul sters
void RepositorySTL::delElem(Entitate s) {
	for (int i = 0; i < elem.size(); i++) {
		if (elem[i] == s) {
			int pos = i;
			elem.erase(elem.begin() + pos);
		}
	}
}



//actualizarea unui element cu date de la tastatura
//in: elementul de actualizat
//out: noul repo cu elementul actualizat
void RepositorySTL::update(Entitate s) {
	for (int i = 0; i < elem.size(); i++)
		if (elem[i] == s)
		{
			cout << "Introduceti modificarile: " << endl;
			int ziua;
			int suma;
			char desc[20];
			char tip[10];
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
			elem[i].setZiua(ziua);
			elem[i].setSuma(suma);
			elem[i].setTip(tip);
			elem[i].setDesc(desc);
			return;
		}
}

//eliminare element
//in: -
//out: noul repo cu elementul sters
vector<Entitate> RepositorySTL::deleteElem(Entitate s) {
	for (int i = 0; i < elem.size(); i++) {
		if (elem[i] == s) {
			int pos = i;
			elem.erase(elem.begin() + pos);
		}
	}
	return elem;
}

//actualizare element cu date prestabilite
//in: entitatea de modificat
//out: noul repo cu elementul actualizat
void RepositorySTL::update_manual (Entitate s) {
	char desc[10] = "Salar";
	for (int i = 0; i < elem.size(); i++) {
		if (elem[i] == s)
		{
			elem[i].setZiua(elem[i].getZiua());   //nu e necesar
			elem[i].setSuma(2000);
			elem[i].setDesc(desc);
			return;
		}
	}
}

//incarcarea unor elemente
//in: -
//out: repository cu 5 elemente in el
void RepositorySTL::incarcaElemente() {
	Entitate s1 = Entitate(5, 30, "in","calatorii");
	Entitate s2 = Entitate(13, 300, "out","altele");
	Entitate s3 = Entitate(20, 140, "in","pizza");
	Entitate s4 = Entitate(10, 140, "in", "pizza");
	Entitate s5 = Entitate(7, 140, "in", "pizza");

	elem.push_back(s1);
	elem.push_back(s2);
	elem.push_back(s5);
	elem.push_back(s3);
	elem.push_back(s4);
}

//insereaza element pe o pozitie data
//in: obiectul de tip Entitate
//out: noul repo ce contine si elementul inserat pe pozitia dorita
void RepositorySTL::insertElem(Entitate& e) {
	int pos;
	cout << "Dati pos";
	cin >> pos;
	elem.insert(elem.begin() + pos, e);

}

//filtru pentru tip
//in: tip_elem-string, tipul elementului
//out: un vector Entitate ce contine doar elementele de un anumit tip
vector<Entitate> RepositorySTL::filtruTip(string tip_elem) {   
	vector<Entitate> newEnt;
	for (int i = 0; i < elem.size(); i++) {
		if (elem[i].getTip() == tip_elem) {
			newEnt.push_back(elem[i]);
		}
	}
	for (int i = 0; i < newEnt.size(); i++) {
		newEnt[i].afisare();
	}

	return newEnt;
}


//filtru pentru suma
//in: suma-int, suma
//out: un vector Entitate ce contine doar elementele cu o anumita suma
vector<Entitate> RepositorySTL::filtruSuma(int suma) {
	vector<Entitate> newEnt;
	for (int i = 0; i < elem.size(); i++) {
		if (elem[i].getSuma() == suma) {
			newEnt.push_back(elem[i]);
		}
	}
	for (int i = 0; i < newEnt.size(); i++) {
		newEnt[i].afisare();
	}
	return newEnt;
}

//filtru pentru zi
//in: ziua-int, ziua
//out: un vector Entitate ce contine doar elementele dintr-o anumita zi
vector<Entitate> RepositorySTL::filtruZiua(int ziua) {
	vector<Entitate> newEnt;
	for (int i = 0; i < elem.size(); i++) {
		if (elem[i].getZiua() == ziua) {
			newEnt.push_back(elem[i]);
		}
	}
	for (int i = 0; i < newEnt.size(); i++) {
		newEnt[i].afisare();
	}
	return newEnt;
}

//suma tipuri
//in: tip-string, tipul elementului
//out: suma-int, suma elementelor de un anumit tip
int RepositorySTL::sumaTip(string tip) {
	int suma = 0;
	for (int i = 0; i < elem.size(); i++) {
		if (elem[i].getTip() == tip) {
			suma += suma + elem[i].getSuma();
		}
	}
	cout << suma;
	return suma;
}


//maxim dupa tip
//in: tip-string, tipul
//out: max-Entitate, elementul cu suma maxima de un anumit tip
Entitate& RepositorySTL::maxTip(string tip) {
	Entitate max = Entitate();
	for (int i = 0; i < elem.size(); i++) {
		if (elem[i].getTip() == tip) {
			if (elem[i].getSuma() > max.getSuma()) {
				max = elem[i];
			}
		}
	}
	max.afisare();
	return max;
}