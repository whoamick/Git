#include "ganr.h"
ganr::ganr() {

	strcpy_s(name, strlen(name) + 1, "");
	time = 0;
}
ganr::ganr(const char* nazv, int pr) {
	strcpy_s(name, strlen(nazv) + 1, nazv);
	this->time = pr;
}
ganr::~ganr() {
	
}
ganr::ganr(const ganr& obj) {
	strcpy_s(this->name, strlen(obj.name) + 1, obj.name);
	this->time = obj.time;
}
int ganr::getTime()
{
	return time;
}

char* ganr::getName()
{
	return name;
}

void ganr::setName(const char* nazv)
{
	strcpy_s(name, strlen(nazv) + 1, nazv);
}

void ganr::setTime(int pr)
{
	this->time = pr;
}


ostream& operator<< (ostream& os, ganr& ss)
{
	cout << setiosflags(ios::left);
	return os << setw(14) << ss.name << setw(25) << ss.time;
}

istream& operator>>(istream& in, ganr& obj2)
{
	cout << "Заполните данные о фильме:" << endl;
	cout << endl << "[1] Название фильма: ";
	rewind(stdin);
	in.getline(obj2.name, 32);
	cout << endl << "[2] Продолжительность фильма:(мин) ";
	in >> obj2.time;

	return in;
}
bool ganr::operator==(ganr& other)
{
	if (!(strcmp(this->name, other.name)))
		return true;
	else
		return false;
}

