#pragma once
#include "boevic.h"
class detectiv : protected boevic
{
private:
	char kng[32];
	int budj;

public:
	detectiv();
	detectiv(const char* kniga, int dengi, const char* eff, int ser, const char* nazv, int per1);
	detectiv(const detectiv& obj);
	~detectiv();
	char* getKng();
	int getBudj();
	void setKng(const char*);
	void setBudj(int);
	void change();
	friend istream& operator>>(istream&, detectiv&);
	friend ostream& operator<<(ostream&, detectiv&);
	friend ofstream& operator<<(ofstream&, detectiv&);
	friend ifstream& operator>>(ifstream&, detectiv&);
	bool operator==(detectiv& other);
	void shapka();
	void showopt();
};