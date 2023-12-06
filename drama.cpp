#include "drama.h"
drama::drama() {
	strcpy_s(prod, strlen(prod) + 1, "");
	ocen = 0;

}
drama::~drama() {

}
drama::drama(const char* producer, int ocenka, const char* str_na, int god, const char* nazv, int per1) : melodrama(str_na, god, nazv, per1) {
	strcpy_s(prod, strlen(producer) + 1, producer);
	this->ocen = ocenka;
}

drama::drama(const drama& obj) : melodrama(obj) {
	strcpy_s(this->prod, strlen(obj.prod) + 1, obj.prod);
	this->ocen = obj.ocen;
}
char* drama::getProd()
{
	return prod;
}

int drama::getOcen()
{
	return ocen;
}

void drama::setProd(const char* p)
{
	strcpy_s(prod, strlen(p) + 1, p);
}

void drama::setOcen(int v)
{
	this->ocen = v;
}

ostream& operator<< (ostream& avt, drama& obj2)
{
	avt << dynamic_cast<melodrama&>(obj2);
	return avt << setw(17) << obj2.prod
		<< setw(15) << obj2.ocen
		<< endl;
}

istream& operator>>(istream& in, drama& obj2)
{
	in >> dynamic_cast<melodrama&>(obj2);
	cout << endl << "[5] ���������: ";
	in.ignore();
	in.getline(obj2.prod, 80);
	cout << endl << "[6] ������: ";
	in >> obj2.ocen;

	return in;
}
ofstream& operator<<(ofstream& on, drama& obj)
{
	on.write(reinterpret_cast<char*>(&obj), sizeof(drama));
	return on;
}

ifstream& operator>>(ifstream& in, drama& obj)
{
	in.read(reinterpret_cast<char*>(&obj), sizeof(drama));
	return in;
}
bool drama::operator==(drama& other)
{
	if (!(strcmp(this->prod, other.prod)))
		return true;
	else
		return false;
}
void drama::shapka()
{
	cout << setiosflags(ios::left)
		<< setw(5) << "[�] "
		<< setw(14) << "��������: "
		<< setw(20) << "�����������������:(���)"
		<< setw(27) << "������ �������������: "
		<< setw(16) << "��� �������: "
		<< setw(17) << "���������: "
		<< setw(15) << "������:"
		<< endl;
}

void drama::showopt()
{
	system("CLS");
	cout << "�������� �������� ��� ���������:" << endl
		<< endl << "[1] �������� "
		<< endl << "[2] �����������������(���)"
		<< endl << "[3] ������ ������������� "
		<< endl << "[4] ��� ������� "
		<< endl << "[5] ��������� "
		<< endl << "[6] ���������� ������� "
		<< endl << endl;
	rewind(stdin);
}
void drama::change()
{
	int tint;
	char tchar[32];
	drama::showopt();
	switch (_getch())
	{
	case '1':
		system("CLS");
		cout << "�������� ������ :" << name << endl;
		cout << "������� ����� ��������: ";
		cin >> tchar;
		setName(tchar);
		break;
	case '2':
		system("CLS");
		cout << "����������������� ������ :" << time << endl;
		cout << "������� ����� �����������������: ";
		cin >> tint;
		setTime(tint);
		break;
	case '3':
		system("CLS");
		cout << "������ ������������� ������ :" << strana << endl;
		cout << "������� ����� ������ �������������: ";
		cin >> tchar;
		setStrana(tchar);
		break;
	case '4':
		system("CLS");
		cout << "��� ������� ������ :" << godik << endl;
		cout << "������� ����� ��� �������: ";
		cin >> tint;
		setGodik(tint);
		break;
	case '5':
		system("CLS");
		cout << "��������� ������ :" << prod << endl;
		cout << "������� ������ ����������: ";
		cin >> tchar;
		setProd(tchar);
		break;
	case '6':
		system("CLS");
		cout << "������ ������ :" << ocen << endl;
		cout << "������� ����� ������: ";
		cin >> tint;
		setOcen(tint);
		break;
	default: cout << endl << "������� ���� �� ��������� ����������!"
		<< endl;
		system("pause"); break;
	}
}