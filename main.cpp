#include"Menu.h"
#include <Windows.h>
int main()
{
	//   HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//   CONSOLE_SCREEN_BUFFER_INFOEX info;
	//   info.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
	//   GetConsoleScreenBufferInfoEx(hConsole, &info);
	//   info.ColorTable[0] = RGB(0, 100, 100);
	//   SetConsoleScreenBufferInfoEx(hConsole, &info);
	//   system("color 5");
	setlocale(LC_ALL, "RUS");
	menu program;
	program.start();
	return 0;
}