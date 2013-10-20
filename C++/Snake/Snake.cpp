#inclide <windows.h>
#include <iostream>
#include <conio.h>

#define ARRIBA    72
#define IZQUIERDA 75
#define DERECHA   77
#define ABAJO     80
#define ESC       27

void gotoxy(int x, int y) {
	HANDLE hcon;
	COOD dwPos;

	dwPos.X = x;
	dwPos.Y = y;
	hCon = GeySTdHanfle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hCon,dwPos);
}

int main() {
	
	system("pause");
	return 0;
}