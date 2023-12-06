#include "detectiv.h"
detectiv::detectiv() {
	strcpy_s(kng, strlen(kng) + 1, "");
	budj = 0;

}
detectiv::~detectiv()
{
	
}
detectiv::detectiv(const char* kniga, int dengi, const char* eff, int ser, const char* nazv, int per1) : boevic(eff, ser, nazv, per1) {
	strcpy_s(kng, strlen(kniga) + 1, kniga);
	this->budj = dengi;
}

detectiv::detectiv(const detectiv& obj) : boevic(obj) {
	strcpy_s(this->kng, strlen(obj.kng) + 1, obj.kng);
	this->budj = obj.budj;
}
char* detectiv::getKng()
{
	return kng;
}
int detectiv::getBudj()
{
	return budj;
}
void detectiv::setKng(const char* c)
{
	strcpy_s(kng, strlen(c) + 1, c);
}

void detectiv::setBudj(int g)
{
	this->budj = g;
}

ostream& operator<< (ostream& avt, detectiv& obj2)
{
	avt << dynamic_cast<boevic&>(obj2);
	return avt << setw(17) << obj2.kng << setw(22) << obj2.budj << endl;
}

istream& operator>>(istream& in, detectiv& obj2)
{
	in >> dynamic_cast<boevic&>(obj2);
	cout << endl << "[5] Книга: ";
	in.ignore(); //игнорирование символов потока
	in.getline(obj2.kng, 32);
	cout << endl << "[6] Бюджет:($) ";
	in >> obj2.budj;

	return in;
}
ofstream& operator<<(ofstream& on, detectiv& obj)
{
	on.write(reinterpret_cast<char*>(&obj), sizeof(detectiv));
	return on;
}
ifstream& operator>>(ifstream& in, detectiv& obj)
{
	in.read(reinterpret_cast<char*>(&obj), sizeof(detectiv));
	return in;
}
bool detectiv::operator==(detectiv& other)
{
	if (!(strcmp(this->kng, other.kng)))
		return true;
	else
		return false;
}
void detectiv::shapka()
{
	cout << setiosflags(ios::left)
		<< setw(5) << "[№] "
		<< setw(14) << "Название: "
		<< setw(25) << "Продолжительность:(мин)"
		<< setw(20) << "Спецэффекты: "
		<< setw(21) << "Количество частей: "
		<< setw(17) << "Книга: "
		<< setw(22) << "Бюджет:($)"
		<< endl;
}
void detectiv::showopt() {

	system("CLS");
	cout << "Выберите параметр для изменения: " << endl
		<< endl << "[1] Название: "
		<< endl << "[2] Продолжительность:(мин)"
		<< endl << "[3] Спецэффекты: "
		<< endl << "[4] Количество частей: "
		<< endl << "[5] Книга: "
		<< endl << "[6] Бюджет:($) "
		<< endl << "[0] Назад."
		<< endl << endl;
	rewind(stdin);


}
void detectiv::change()
{
	int tint;
	char tchar[32];
	detectiv::showopt();
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
		cout << "Книга сейчас :" << kng << endl;
		cout << "Введите новую книгу: ";
		cin >> tchar;
		setKng(tchar);
		break;
	case '6':
		system("CLS");
		cout << "Бюджет сейчас :" << budj << endl;
		cout << "Бюджет: ";
		cin >> tint;
		setBudj(tint);
		break;
	default: cout << endl << "Введите один из указанных параметров!"
		<< endl;
		system("pause"); break;
	}
}

