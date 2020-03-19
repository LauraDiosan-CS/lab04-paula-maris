#include "Test.h"
#include "Entitate.h"
#include <assert.h>
#include "RepositorySTL.h"
#include <iostream>
#include <cassert>
using namespace std;


void test1() {
	Entitate t1 = Entitate();
	assert(t1.getZiua() == 0);
	assert(t1.getSuma() == 0);
	assert(t1.getTip() == NULL);
	assert(t1.getDesc() == NULL);
}

void test2() {
	Entitate t2 = Entitate(26, 400, "in","pizza");
	assert(t2.getZiua() == 26);
	assert(t2.getSuma() == 400);
}


void test3()
{
	Entitate t(26, 400, "in","banca");
	Entitate t1(24, 1000, "out","rata");
	Entitate t2(23, 1000, "out","calatorii");
	RepositorySTL elem;
	elem.addElem(t);
	elem.addElem(t1);
	elem.addElem(t2);
	assert(elem.getSize() == 3);
}