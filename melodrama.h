#pragma once
#include "ganr.h"
class melodrama : protected ganr
{
protected:
	char strana[32];
	int godik;
public:
	melodrama();
	melodrama(const melodrama& obj);
	melodrama(const char* str_na, int god, const char* nazv, int per1);
	~melodrama();
	char* getStrana();
	int getGodik();
	void setStrana(const char*);
	void setGodik(int);

	friend istream& operator>>(istream& in, melodrama& obj1);
	friend ostream& operator<<(ostream& on, melodrama& obj1);
	bool operator==(melodrama& other);

};