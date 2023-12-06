#include "romantic.h"
romantic::romantic() {
	strcpy_s(gg, strlen(gg) + 1, "");
	reit = 0;

}
romantic::~romantic() {

}
romantic::romantic(const char* geroi, int reiting, const char* str_na, int god, const char* nazv, int per1) : melodrama(str_na, god, nazv, per1) {
	strcpy_s(gg, strlen(geroi) + 1, geroi);
	this->reit = reit;
}

romantic::romantic(const romantic& obj) : melodrama(obj) {
	strcpy_s(this->gg, strlen(obj.gg) + 1, obj.gg);
	this->reit = obj.reit;
}
char* romantic::getGg()
{
	return gg;
}

int romantic::getReit()
{
	return reit;
}

void romantic::setGg(const char* g)
{
	strcpy_s(gg, strlen(g) + 1, g);
}

void romantic::setReit(int d)
{
	this->reit = d;
}

ostream& operator<< (ostream& avt, romantic& obj2)
{
	avt << dynamic_cast<melodrama&>(obj2);
	return avt << setw(17) << obj2.gg
		<< setw(10) << obj2.reit
		<< endl;
}

istream& operator>>(istream& in, romantic& obj2)
{
	in >> dynamic_cast<melodrama&>(obj2);
	cout << endl << "[5] Главный герой: ";
	in.ignore();
	in.getline(obj2.gg, 32);
	cout << endl << "[6] Рейтинг:(х/10) ";
	in >> obj2.reit;

	return in;
}
ofstream& operator<<(ofstream& on, romantic& obj)
{
	on.write(reinterpret_cast<char*>(&obj), sizeof(romantic));
	return on;
}
ifstream& operator>>(ifstream& in, romantic& obj)
{
	in.read(reinterpret_cast<char*>(&obj), sizeof(romantic));
	return in;
}

void romantic::shapka()
{
	cout << setiosflags(ios::left)
		<< setw(3) << "[№] "
		<< setw(14) << "Название: "
		<< setw(20) << "Продолжительность:(мин)"
		<< setw(27) << "Страна производитель: "
		<< setw(16) << "Год выпуска: "
		<< setw(13) << "Главный герой: "
		<< setw(22) << "Рейтинг:"
		<< endl;
}
void romantic::showopt()
{
	system("CLS");
	cout << "Выберите параметр для изменения: " << endl
		<< endl << "[1] Название: "
		<< endl << "[2] Продолжительность:(мин) "
		<< endl << "[3] Страна производитель: "
		<< endl << "[4] Год выпуска: "
		<< endl << "[5] Главный герой: "
		<< endl << "[6] Рейтинг: "
		<< endl << endl;
	rewind(stdin);
}
void romantic::change()
{
	int tint;
	char tchar[32];
	romantic::showopt();
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
		cout << "Страна производитель сейчас :" << strana << endl;
		cout << "Введите новую страну производитель: ";
		cin >> tchar;
		setStrana(tchar);
		break;
	case '4':
		system("CLS");
		cout << "Год выпуска сейчас :" << godik << endl;
		cout << "Введите новые год выпуска: ";
		cin >> tint;
		setGodik(tint);
		break;
	case '5':
		system("CLS");
		cout << "Главный Герой сейчас :" << gg << endl;
		cout << "Введите нового главного Героя: ";
		cin >> tchar;
		setGg(tchar);
		break;
	case '6':
		system("CLS");
		cout << "Рейтинг сейчас :" << reit << endl;
		cout << "Введите новый рейтинг: ";
		cin >> tint;
		setReit(tint);
		break;
	default: cout << endl << "Введите один из указанных параметров!"
		<< endl;
		system("pause"); break;
	}
}