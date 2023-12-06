#include "fantasy.h"
fantasy::fantasy() {

	strcpy_s(mif, strlen(mif) + 1, "");
	sbor = 0;

}
fantasy::~fantasy() {

}
fantasy::fantasy(const char* mf, int sb, const char* eff, int ser, const char* nazv, int per1) : boevic(eff, ser, nazv, per1) {
	strcpy_s(mif, strlen(mf) + 1, mf);
	this->sbor = sb;
}
fantasy::fantasy(const fantasy& obj) : boevic(obj) {
	strcpy_s(this->mif, strlen(obj.mif) + 1, obj.mif);
	this->sbor = obj.sbor;
}
char* fantasy::getMif()
{
	return mif;
}

int fantasy::getSbor()
{
	return sbor;
}

void fantasy::setMif(const char* v)
{
	strcpy_s(mif, strlen(v) + 1, v);
}

void fantasy::setSbor(int r)
{
	this->sbor = r;
}

ostream& operator<< (ostream& avt, fantasy& obj2)
{
	avt << dynamic_cast<boevic&>(obj2);
	return avt << setw(13) << obj2.mif << setw(10) << obj2.sbor
		<< endl;
}

istream& operator>>(istream& in, fantasy& obj2)
{
	in >> dynamic_cast<boevic&>(obj2);
	cout << endl << "[5] Миф: ";
	in.ignore(); //игнорирование символов потока
	in.getline(obj2.mif, 80);
	cout << endl << "[6] Кассовые сборы: ";
	in >> obj2.sbor;

	return in;
}
bool fantasy::operator==(fantasy& other)
{
	if (!(strcmp(this->mif, other.mif)))
		return true;
	else
		return false;
}

void fantasy::shapka() {
	cout << setiosflags(ios::left)
		<< setw(5) << "[№] "
		<< setw(14) << "Название: "
		<< setw(20) << "Продолжительность:(мин) "
		<< setw(17) << "Спецэффекты: "
		<< setw(20) << "Количество частей: "
		<< setw(13) << "Миф: "
		<< setw(10) << "Кассовые сборы:($)"
		<< endl;
}
void fantasy::showopt()
{
	system("CLS");
	cout << "Выберите параметр для изменения:" << endl
		<< endl << "[1] Название: "
		<< endl << "[2] Продолжительность:(мин)"
		<< endl << "[3] Спецэффекты: "
		<< endl << "[4] Количество частей: "
		<< endl << "[5] Миф: "
		<< endl << "[6] Кассовые сборы: "
		<< endl << endl;
	rewind(stdin);
}
ofstream& operator<<(ofstream& on, fantasy& obj)
{
	on.write(reinterpret_cast<char*>(&obj), sizeof(fantasy));
	return on;
}
ifstream& operator>>(ifstream& in, fantasy& obj)
{
	in.read(reinterpret_cast<char*>(&obj), sizeof(fantasy));
	return in;
}
void fantasy::change()
{
	int tint;
	char tchar[32];
	fantasy::showopt();
	switch (_getch())
	{
	case '1':
		system("CLS");
		cout << "Название сейчас :" << name << endl;
		cout << "Введите новое название: ";
		cin >> tchar;
		setName(tchar);
		break;
	case '2':
		system("CLS");
		cout << "Продолжительность сейчас :" << time << endl;
		cout << "Введите новую продолжительность: ";
		cin >> tint;
		setTime(tint);
		break;
	case '3':
		system("CLS");

		cout << "Вид спецэффектов сейчас :" << effects << endl;
		cout << "Введите новый вид спецэффектов: ";
		cin >> tchar;
		setEffects(tchar);
		break;
	case '4':
		system("CLS");
		cout << "Количество серий сейчас :" << seria << endl;
		cout << "Введите новое количество частей: ";
		cin >> tint;
		setSeria(tint);
		break;
	case '5':
		system("CLS");
		cout << "Миф сейчас :" << mif << endl;
		cout << "Введите новый миф: ";
		cin >> tchar;
		setMif(tchar);
		break;
	case '6':
		system("CLS");
		cout << "Кассовый сбор сейчас :" << sbor << endl;
		cout << "Введите новый кассовый сбор: ";
		cin >> tint;
		setSbor(tint);
		break;
	default: cout << endl << "Введите один из указанных параметров!"
		<< endl;
		system("pause"); break;
	}
}