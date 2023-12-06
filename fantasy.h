#pragma once
#include "boevic.h"

class fantasy : protected boevic
{
private:
	char mif[32];
	int sbor;

public:

	fantasy();
	fantasy(const char* mf, int sb, const char* eff, int ser, const char* nazv, int per1);
	fantasy(const fantasy& obj);
	~fantasy();
	char* getMif();
	int getSbor();
	void setMif(const char*);
	void setSbor(int);
	void change();

	/*fantasy& operator=(const fantasy& other);*/
	friend istream& operator>>(istream& in, fantasy& obj3);
	friend ostream& operator<<(ostream& on, fantasy& obj3);

	friend ofstream& operator<<(ofstream&, fantasy&);
	friend ifstream& operator>>(ifstream&, fantasy&);
	bool operator==(fantasy& other);
	void shapka();
	void showopt();
};