#include <windows.h>
#include <iostream>
#include <conio.h>

#define ARRIBA    72
#define IZQUIERDA 75
#define DERECHA   77
#define ABAJO     80
#define ESC       27

int cuerpo[200][2];

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
	cuerpo[0][0] = 3;
	cuerpo[0][1] = 5;
	cuerpo[1][0] = 4;
	cuerpo[1][1] = 5;
	cuerpo[2][0] = 5;
	cuerpo[2][1] = 5;						
	// for (int i = 0; i < 3; ++i) {
	// 	for (int j = 0; j < 2; ++j) {
	// 		cuerpo[j][i] = rand()%10;
	// 	}
	// }

	for (int i = 0; i < 3; ++i) {
			gotoxy(cuerpo[j][0], cuerpo[j][1]);
			printf("*");
	}	
	pintar();
	system("pause>null");
	return 0;
}