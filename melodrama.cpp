#include "melodrama.h"
melodrama::melodrama() {
	strcpy_s(strana, strlen(strana) + 1, "");
	godik = 0;

}
melodrama::~melodrama() {
	
}
melodrama::melodrama(const char* str_na, int god, const char* nazv, int per1) : ganr(nazv, per1) {
	strcpy_s(strana, strlen(str_na) + 1, str_na);
	this->godik = god;
}
melodrama::melodrama(const melodrama& obj) : ganr(obj) {
	strcpy_s(this->strana, strlen(obj.strana) + 1, obj.strana);
	this->godik = obj.godik;
}
char* melodrama::getStrana()
{
	return strana;
}
bool melodrama::operator==(melodrama& other)
{
	if (!(strcmp(this->strana, other.strana)))
		return true;
	else
		return false;
}
int melodrama::getGodik()
{
	return godik;
}

void melodrama::setStrana(const char* s)
{
	strcpy_s(strana, strlen(s) + 1, s);
}

void melodrama::setGodik(int g)
{
	this->godik = g;
}

ostream& operator<< (ostream& on, melodrama& obj2)
{
	on << dynamic_cast<ganr&>(obj2);
	return on << setw(27) << obj2.strana
		<< setw(16) << obj2.godik;
}

istream& operator>>(istream& in, melodrama& obj1)
{
	in >> dynamic_cast<ganr&>(obj1);
	cout << endl << "[3] Страна производитель: ";
	in.ignore(); //игнорирование символов потока
	in.getline(obj1.strana, 32);
	cout << endl << "[4] Год выпуска: ";
	in >> obj1.godik;
	return in;
}

