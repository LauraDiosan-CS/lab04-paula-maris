#include "RepositorySTL.h"

//constructor fara param
RepositorySTL::RepositorySTL() {
	this->elem;
}

//constuctor de copiere
RepositorySTL::RepositorySTL(const RepositorySTL& r) {
	this->elem = r.elem;
}

//destructor
RepositorySTL::~RepositorySTL() {

}

//adaugare element nou
void RepositorySTL::addElem(Entitate s) {
	elem.push_back(s);
}

//dimensiunea
int RepositorySTL::getSize() {
	return elem.size();
}

//getAll
vector<Entitate> RepositorySTL::getAll() {
	return elem;
}
