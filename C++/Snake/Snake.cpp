#include <windows.h>
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

void pintar() {
	//lineas hori
	for (int i = 2; i < 78; ++i) {
	 	gotoxy(i,3); printf("%c", 205);
		gotoxy(i,23); printf("%c", 205);
	}
	//lineas Ver
	for (int i = 4; i < 23; ++i) {
	 	gotoxy(2,i); printf("%c", 186);
		gotoxy(77,i); printf("%c", 186);
	}
	//Esquinas
	gotoxy(2,3); printf("%c",201);
	gotoxy(2,23); printf("%c",200);
	gotoxy(77,3); printf("%c",187);
	gotoxy(77,23); printf("%c",188);
}

int main() {
	pintar();
	system("pause>null");
	return 0;
}