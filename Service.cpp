#include <iostream>
#include <string>
#include "Service.h"
#include <algorithm>

using namespace std;

//constructor
Service::Service() {
	this->rep;
	this->undoList.push_back(this->rep);
	this->redoList.push_back(this->rep);
}

//destructor
Service::~Service() {
}

//adauga un element 
//in: element de tip Entitate
//out: -
void Service::adauga(Entitate& e) {
	this->undoList.push_back(this->rep);
	rep.addElem(e);
	this->redoList.push_back(this->rep);
}

//sterge un element
//in: element de tip Entitate
//out -
void Service::deleteElem(Entitate& e) {
	this->undoList.push_back(this->rep);
	rep.delElem(e);
	this->redoList.push_back(this->rep);
}

//actualizarea unui element
//in: element de tip Entitate
//out: -
void Service::update(Entitate& e) {
	this->undoList.push_back(this->rep);
	rep.update(e);
	this->redoList.push_back(this->rep);
}

//actualizarea unui element cu date prestabilite
//in: element de tip Entitate
//out: -
void Service::update_manual(Entitate& e) {
	this->undoList.push_back(this->rep);
	rep.update_manual(e);
	this->redoList.push_back(this->rep);
}

//returneaza dimensiunea repo-ului
//in: -
//out: dimensiunea Repository-ului (int)
int Service::getSize() {
	return rep.getSize();
}

//insereaza un element de tip entitate pe o anumita pozitie
//in: element de tip entitate
//out: -
void Service::insert(Entitate& e) {
	this->undoList.push_back(this->rep);
	rep.insertElem(e);
	this->redoList.push_back(this->rep);
}

//afisare all
//in: -
//out: un vector de tip Entitate cu toate elementele din el
vector<Entitate> Service::getAll() {
	return rep.getAll();
}

//incarca elemente de tip entitate in repo
//in: -
//out: -
void Service::incarcaElemente() {
	rep.incarcaElemente();
}



//reface ultima operatie
void Service::undo() {
	auto actual_state = undoList.back();
	undoList.pop_back();
	redoList.push_back(this->rep);
	this->rep = actual_state;
	this->undoList = undoList;
}

//redo
void Service::redo() {
	auto actual_state = redoList.back();
	redoList.pop_back();
	undoList.push_back(this->rep);
	this->rep = actual_state;
	this->redoList = redoList;
}