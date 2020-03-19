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
	vector<Entitate> getAll();
	int getSize();
};
