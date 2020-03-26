#include "Test.h"
#include "Entitate.h"
#include "Service.h"
#include "RepositorySTL.h"
#include <iostream>
#include <cassert>
#include <assert.h>
#include <string.h>
#include <cstddef>
using namespace std;


void test1() {
	Entitate t1 = Entitate();
	assert(t1.getZiua() == 0);
	assert(t1.getSuma() == 0);
	assert(t1.getTip() == NULL);
	assert(t1.getDesc() == NULL);
}

void test2() {
	Entitate t2 = Entitate(26, 400, "in","altele");
	assert(t2.getZiua() == 26);
	assert(t2.getSuma() == 400);
}


void test3()
{
	Entitate t(26, 400, "in","calatorii");
	Entitate t1(24, 1000, "in","altele");
	Entitate t2(23, 1000, "out","pizza");
	RepositorySTL elem;
	elem.addElem(t);
	elem.addElem(t1);
	elem.addElem(t2);
	assert(elem.getSize() == 3);
}

void test4()
{
	Entitate t(26, 400, "in", "banca");
	Entitate t1(24, 1000, "out", "rata");
	Entitate t2(23, 1000, "out", "calatorii");
	RepositorySTL elem;
	elem.addElem(t);
	elem.addElem(t1);
	elem.addElem(t2);
	assert(elem.getSize() == 3);
	elem.delElem(t);
	assert(elem.getSize() != 3);
}

void test5()
{
	Entitate t(26, 400, "in", "banca");
	Entitate t1(24, 1000, "out", "rata");
	Entitate t2(23, 1000, "out", "calatorii");
	RepositorySTL elem;
	elem.addElem(t);
	elem.addElem(t1);
	elem.addElem(t2);
	assert(elem.getSize() == 3);
	assert(elem.findElem(t1) == true);
}

void test6()
{
	Entitate t(26, 400, "in", "banca");
	Entitate t1(24, 1000, "out", "rata");
	Entitate t2(23, 1000, "out", "calatorii");
	RepositorySTL elem;
	elem.addElem(t);
	elem.addElem(t1);
	elem.addElem(t2);
	assert(elem.getSize() == 3);
	elem.delElem(t);
	assert(elem.getItemFromPos(0) == t1);
}

void test7()
{
	Service serv;
	Entitate t(26, 400, "in", "banca");
	Entitate t1(24, 1000, "out", "rata");
	Entitate t2(23, 1000, "out", "calatorii");
	serv.adauga(t);
	serv.adauga(t1);
	serv.adauga(t2);
	assert(serv.getSize() == 3);
}

void test8()
{
	Service serv;
	Entitate t(26, 400, "in", "banca");
	Entitate t1(24, 1000, "out", "rata");
	Entitate t2(23, 1000, "out", "calatorii");
	serv.adauga(t);
	serv.adauga(t1);
	serv.adauga(t2);
	assert(serv.getSize() == 3);
	serv.deleteElem(t1);
	assert(serv.getSize() == 2);
}
