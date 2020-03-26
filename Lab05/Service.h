#pragma once

#include <iostream>
#include <string>
#include "RepositorySTL.h"
using std::vector;

using namespace std;


class Service
{
private:
	RepositorySTL rep;
	vector <RepositorySTL> undoList;
	vector <RepositorySTL> redoList;
public:
	Service();
	~Service();
	vector<Entitate> getAll();
	void adauga(Entitate& e);
	void deleteElem(Entitate& e);
	void update(Entitate& e);
	void insert(Entitate& e);
	void update_manual(Entitate& e);
	void incarcaElemente();
	int getSize();
	void undo();
	void redo();
};
