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
	cout << endl << "[5] ���: ";
	in.ignore(); //������������� �������� ������
	in.getline(obj2.mif, 80);
	cout << endl << "[6] �������� �����: ";
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
		<< setw(5) << "[�] "
		<< setw(14) << "��������: "
		<< setw(20) << "�����������������:(���) "
		<< setw(17) << "�����������: "
		<< setw(20) << "���������� ������: "
		<< setw(13) << "���: "
		<< setw(10) << "�������� �����:($)"
		<< endl;
}
void fantasy::showopt()
{
	system("CLS");
	cout << "�������� �������� ��� ���������:" << endl
		<< endl << "[1] ��������: "
		<< endl << "[2] �����������������:(���)"
		<< endl << "[3] �����������: "
		<< endl << "[4] ���������� ������: "
		<< endl << "[5] ���: "
		<< endl << "[6] �������� �����: "
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
		cout << "��� ������ :" << mif << endl;
		cout << "������� ����� ���: ";
		cin >> tchar;
		setMif(tchar);
		break;
	case '6':
		system("CLS");
		cout << "�������� ���� ������ :" << sbor << endl;
		cout << "������� ����� �������� ����: ";
		cin >> tint;
		setSbor(tint);
		break;
	default: cout << endl << "������� ���� �� ��������� ����������!"
		<< endl;
		system("pause"); break;
	}
}