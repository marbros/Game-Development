#include "Space.h"
#include <conio.h>

#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80

class nave {
	int x,y;
	int corazones;
	int vidas;

	public:
		nave(int _x, int _y, int _corazones, int _vidas): x(_x),y(_y), corazones(_corazones), vidas(_vidas) {};
		int X() { return x; }
		int Y() { return y; }
		int VID() { return vidas; }
		void COR() { corazones--; }
		void pintar();
		void borrar();
		void mover();
		void pintar_corazones();
		void morir();
};

// nave::nave (int _x, int _y): x(_x),y(_y) {}

void nave::pintar() {
	gotoxy(x,y); printf("  %c",30);
	gotoxy(x,y+1); printf(" %c%c%c",40,207,41);
	gotoxy(x,y+2); printf("%c%c %c%c",30,190,190,30);
}

void nave::borrar() {
	gotoxy(x,y); printf("       ");
	gotoxy(x,y+1); printf("       ");
	gotoxy(x,y+2); printf("       ");
}

void nave::mover() {

	if (kbhit()) //Se ha presionado una tecla
	{
		char tecla = getch();
		borrar();
		if(tecla == IZQUIERDA && x > 3) x--;
		if(tecla == DERECHA && x+6 < 77) x++;
		if(tecla == ARRIBA && y > 4) y--;
		if(tecla == ABAJO && y+3 <33) y++;
		if(tecla == 'e') corazones--;
		pintar();
		pintar_corazones();
	}	
}

void nave::pintar_corazones() {

	gotoxy(50,2); printf("VIDAS %d",vidas);
	gotoxy(64,2); printf("Vidas");
	gotoxy(70,2); printf("      ");
	for (int i = 0; i < corazones; ++i) {
		gotoxy(70+i+i,2); printf("%c ",3);
	}
}

void nave::morir() {
	if(corazones == 0) {
		borrar();
		gotoxy(x,y);   printf("   **   ");
		gotoxy(x,y+1); printf("  ****  ");
		gotoxy(x,y+2); printf("   **   ");
		Sleep(200);

		borrar();
		gotoxy(x,y);   printf(" * ** *");
		gotoxy(x,y+1); printf("  **** ");
		gotoxy(x,y+2); printf(" * ** *");	
		Sleep(200);

		borrar();
		vidas--;
		corazones = 3;
		pintar_corazones();
		pintar();							
	}
}