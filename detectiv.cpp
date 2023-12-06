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
	cout << endl << "[5] �����: ";
	in.ignore(); //������������� �������� ������
	in.getline(obj2.kng, 32);
	cout << endl << "[6] ������:($) ";
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
		<< setw(5) << "[�] "
		<< setw(14) << "��������: "
		<< setw(25) << "�����������������:(���)"
		<< setw(20) << "�����������: "
		<< setw(21) << "���������� ������: "
		<< setw(17) << "�����: "
		<< setw(22) << "������:($)"
		<< endl;
}
void detectiv::showopt() {

	system("CLS");
	cout << "�������� �������� ��� ���������: " << endl
		<< endl << "[1] ��������: "
		<< endl << "[2] �����������������:(���)"
		<< endl << "[3] �����������: "
		<< endl << "[4] ���������� ������: "
		<< endl << "[5] �����: "
		<< endl << "[6] ������:($) "
		<< endl << "[0] �����."
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
		cout << "��� ������������ ������ :" << effects << endl;
		cout << "������� ����� ��� ������������: ";
		cin >> tchar;
		setEffects(tchar);
		break;
	case '4':
		system("CLS");
		cout << "���������� ����� ������ :" << seria << endl;
		cout << "������� ����� ���������� ������: ";
		cin >> tint;
		setSeria(tint);
		break;
	case '5':
		system("CLS");
		cout << "����� ������ :" << kng << endl;
		cout << "������� ����� �����: ";
		cin >> tchar;
		setKng(tchar);
		break;
	case '6':
		system("CLS");
		cout << "������ ������ :" << budj << endl;
		cout << "������: ";
		cin >> tint;
		setBudj(tint);
		break;
	default: cout << endl << "������� ���� �� ��������� ����������!"
		<< endl;
		system("pause"); break;
	}
}

