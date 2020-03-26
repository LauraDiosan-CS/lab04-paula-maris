#pragma once

#include "Entitate.h" 
#include <vector>

using namespace std;

class RepositorySTL
{
private:
	vector<Entitate> elem;

public:
	RepositorySTL();
	RepositorySTL(const RepositorySTL& r);
	~RepositorySTL();
	void addElem(Entitate);
	bool findElem(Entitate);
	vector<Entitate>deleteElem(Entitate);
	void update(Entitate);
	void update_manual(Entitate);
	void delElem(Entitate);
	void incarcaElemente();
	Entitate getItemFromPos(int);
	vector<Entitate> getAll();
	int getSize();
	void insertElem(Entitate& e);
	vector<Entitate> filtruTip(string tip_tranz);
	vector<Entitate> filtruSuma(int suma);
	vector<Entitate> filtruZiua(int ziua);
	int sumaTip(string tip);
	Entitate& maxTip(string tip);
};
