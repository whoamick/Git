#include "boevic.h"
boevic::boevic() {

	strcpy_s(effects, strlen(effects) + 1, "");
	seria = 0;

}
boevic::~boevic()
{
	
}
boevic::boevic(const char* eff, int ser, const char* naz, int per1) : ganr(naz, per1) {
	strcpy_s(effects, strlen(eff) + 1, eff);
	this->seria = ser;
}
boevic::boevic(const boevic& obj) : ganr(obj) {
	strcpy_s(this->effects, strlen(obj.effects) + 1, obj.effects);
	this->seria = obj.seria;
}
char* boevic::getEffects()
{
	return effects;
}

int boevic::getSeria()
{
	return seria;
}

void boevic::setEffects(const char* eff)
{
	strcpy_s(effects, strlen(eff) + 1, eff);
}

void boevic::setSeria(int ser)
{
	this->seria = ser;
}

ostream& operator<<(ostream& on, boevic& obj1)
{
	on << dynamic_cast<ganr&>(obj1);
	return on << setw(20) << obj1.effects << setw(21) << obj1.effects;
}
bool boevic::operator==(boevic& other)
{
	if (!(strcmp(this->effects, other.effects)))
		return true;
	else
		return false;
}

istream& operator>>(istream& in, boevic& obj2)
{
	in >> dynamic_cast<ganr&>(obj2);
	cout << endl
		<< "[3] Вид спецэффектов: ";
	in.ignore();
	in.getline(obj2.effects, 32);
	cout << endl
		<< "[4] Количество серий: ";
	in >> obj2.seria;

	return in;
}


