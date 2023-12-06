#pragma once
#include "melodrama.h"

class drama : protected melodrama
{
private:
	char prod[32];
	int ocen;

public:
	drama();
	drama(const char* producer, int ocenka, const char* str_na, int god, const char* nazv, int per1);
	drama(const drama& obj);
	~drama();
	char* getProd();
	int getOcen();
	void setProd(const char*);
	void setOcen(int);
	void change();
	friend ostream& operator<<(ostream& on, drama& obj4);
	friend istream& operator>>(istream& in, drama& obj4);
	friend ofstream& operator<<(ofstream& on, drama& ss);
	friend ifstream& operator>>(ifstream& in, drama& ss);
	bool operator==(drama& other);
	void shapka();
	void showopt();

};