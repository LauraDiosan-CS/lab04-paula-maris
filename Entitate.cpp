#include "Entitate.h"
#include <string.h>
#include <iostream>
#include <istream>
#include <cstddef>
#include <ostream>

using namespace std;

//constructor default(fara param)
Entitate::Entitate() {
	this->tip = NULL;
	this->desc = NULL;
	this->suma = 0;
	this->ziua = 0;
}

//constructor cu param
Entitate::Entitate(int ziua, int suma, const char* tip, const char* desc) {
	this->tip = new char[strlen(tip) + 1];
	strcpy_s(this->tip, strlen(tip) + 1, tip);
	this->desc = new char[strlen(desc) + 1];
	strcpy_s(this->desc, strlen(desc) + 1, desc);
	this->ziua = ziua;
	this->suma = suma;
}

//constructor de copiere
Entitate::Entitate(const Entitate& s) {
	this->tip = new char[strlen(s.tip) + 1];
	strcpy_s(this->tip, strlen(s.tip) + 1, s.tip);
	this->desc = new char[strlen(s.desc) + 1];
	strcpy_s(this->desc, strlen(s.desc) + 1, s.desc);
	this->suma = s.suma;
	this->ziua = s.ziua;
}

//destructor
Entitate::~Entitate() {
	if (tip) delete[]tip;
	if (desc) delete[]desc;
	tip = NULL;
	desc = NULL;
	ziua = -1;
	suma = -1;
}

//getter pentru zi
int Entitate::getZiua() {
	return this->ziua;
}

//setter pentru zi
void Entitate::setZiua(int z) {
	this->ziua = z;
}

//getter pentru suma
int Entitate::getSuma() {
	return this->suma;
}

//setter pentru suma
void Entitate::setSuma(int sum) {
	this->suma = sum;
}

//getter pentru tip
char* Entitate::getTip() {
	return this->tip;
}

//setter pentru tip
void Entitate::setTip(char* t) {
	if (tip) delete[]tip;
	tip = new char[strlen(t) + 1];
	strcpy_s(tip, strlen(t) + 1, t);
}

//getter pentru descriere
char* Entitate::getDesc() {
	return this->desc;
}

//setter pentru descriere
void Entitate::setDesc(char* d) {
	if (desc) delete[]desc;
	desc = new char[strlen(d) + 1];
	strcpy_s(desc, strlen(d) + 1, d);
}

//suprascrie operatorul = pentru elem de tip Entitate
Entitate& Entitate::operator=(const Entitate& s) {
	this->setZiua(s.ziua);
	this->setSuma(s.suma);
	this->setTip(s.tip);
	this->setDesc(s.desc);
	return *this;
}

//operatorul de egalitate
bool Entitate::operator==(const Entitate& s) {
	return (ziua == s.ziua) && suma == s.suma && (strcmp(tip, s.tip) == 0) && (strcmp(desc, s.desc) == 0);
}

//afisare
ostream& operator<<(ostream& os, const Entitate& s)
{
	os << "Ziua: " << s.ziua << ", suma: " << s.suma << ", tipul: " << s.tip << ", descrierea: "<< s.desc<< endl;
	return os;
}

//afisare2
void Entitate::afisare() {
	cout << "Ziua: " << this->ziua << ", suma: " << this->suma << ", tipul: " << this->tip << ", descrierea: "<<this->desc;
}