#pragma once
#include "ganr.h"

class boevic : protected ganr
{
protected:
	char effects[32];
	int seria;
public:

	boevic();
	boevic(const char* eff, int ser, const char* naz, int per1);
	boevic(const boevic& obj);
	~boevic();
	char* getEffects();
	int getSeria();
	void setEffects(const char*);
	void setSeria(int);
	friend istream& operator>>(istream& in, boevic& obj1);
	friend ostream& operator<<(ostream& on, boevic& obj1);
	bool operator==(boevic& other);

};