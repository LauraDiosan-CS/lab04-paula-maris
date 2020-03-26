#pragma once

#include <iostream>
#include <string>
#include "Service.h"

using namespace std;

class UI {
private:
	Service serv;
public:
	UI();
	~UI();
	void adauga(Service& serv);
	void update(Service& serv);
	void deleteElem(Service& serv);
	void delete5_10(Service& serv);
	void modif_zi_10(Service& serv);
	void insereaza(Service& serv);
	void afisareAll(Service& serv);
	void incarcaElemente(Service& serv);
	void afisareIN(Service& serv);
	void afisareSumaIN(Service& serv);
	int getinput();
	void afisaremeniu();

};
