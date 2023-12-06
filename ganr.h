#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <conio.h>
using namespace std;

class ganr
{
protected:
	char name[32];
	int time;

public:
	ganr();
	ganr(const char* nazv, int pr);
	ganr(const ganr& obj);
	~ganr();
	int getTime();
	char* getName();
	void setTime(int);
	void setName(const char*);

	friend ostream& operator<<(ostream& os, ganr& ss);
	friend istream& operator>>(istream& in, ganr& obj2);
	bool operator==(ganr& other);

};