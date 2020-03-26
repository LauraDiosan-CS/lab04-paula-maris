#pragma once

#include <ostream>
using namespace std;

class Entitate {
private:
	int ziua;
	int suma;
	char* tip;
	char* desc;
public:
	Entitate();
	Entitate(int ziua, int suma, const char* tip, const char* desc);
	Entitate(const Entitate&);
	Entitate& operator=(const Entitate&);
	int getZiua();
	int getSuma();
	char* getTip();
	char* getDesc();
	void setDesc(char* desc);
	void setTip(char* tip);
	void setSuma(int suma);
	void setZiua(int ziua);
	bool operator==(const Entitate&);
	friend ostream& operator<<(ostream& os, const Entitate& s);
	void afisare();
	~Entitate();
};