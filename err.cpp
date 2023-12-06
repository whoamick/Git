#include "err.h"
//#include<iostream>
using namespace std;
int enterInt(int min, int max)
{
	int value;
	while (true) {
		cin >> value;
		rewind(stdin);
		try
		{
		
			if (value < min || value > max)throw exception("ќшибка ввода!");
			break;
		
		}
		catch (const std::exception& exp)
		{
			cout << exp.what() << endl;
			cout << "¬ведено значение вне диапазона!" << endl;
		}
		
	}
	return value;
}
bool IsAllSpace(const char* str)
{
	for (int i = 0; i < strlen(str); ++i)
		if (!isspace(str[i])) return false;
	return true;
}