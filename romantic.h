#pragma once
#include "melodrama.h"

class romantic : protected melodrama
{
private:
	char gg[32];
	int reit;

public:
	romantic();
	romantic(const char* geroi, int reiting, const char* str_na, int god, const char* nazv, int per1);
	romantic(const romantic& obj);
	~romantic();
	char* getGg();
	int getReit();
	void setGg(const char*);
	void setReit(int);
	void shapka();
	void showopt();
	void change();
	friend istream& operator>>(istream& in, romantic& obj2);
	friend ostream& operator<<(ostream& on, romantic& obj2);
	friend ofstream& operator<<(ofstream& on, romantic& ss);
	friend ifstream& operator>>(ifstream& in, romantic& ss);
	bool operator==(romantic& other);

};
