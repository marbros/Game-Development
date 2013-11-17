#include <stdio.h>
#include <conio.h>
#include "pong.h"
#include <stdio.h>

JUGADOR::JUGADOR(int _x, int _y):x(_x), y(_y) {}

void JUGADOR::pintar() const {
	gotoxy(x, y-1); printf("%c", 219);
	gotoxy(x, y); printf("%c", 219);
	gotoxy(x, y+1); printf("%c", 219);	
}

void JUGADOR::borrar() const {
	gotoxy(x, y-1); printf("%c", " ");
	gotoxy(x, y); printf("%c", " ");
	gotoxy(x, y+1); printf("%c", " ");	
}

void PELOTA::PELOTA(int _x, int _y, int dx, int dy) : x(_x), y(_y), dx(_dx), dy(_dy) {}

PELOTA::pintar() const {
	gotoxy(x,y); printf("%c", 184);
}

void PELOTA::borrar() const {
	gotoxy(x,y); printf(" ");
}

void PELOTA::mover(JUGADOR A, JUGADOR B) {
	borrar();
	x += dx; y += dy;
	pintar();
	if(x + dx == 3 || x + dx == 76) {
		borrar();
		asign(38,14);
		dx =- dx;
	} 
	if(y + dy == 3 || y + dy == 23) {
		dy = -dy;
	}

	if(x + dx == A.RX() && y >= A.RY()-2 && y <= A.RY() +2) {
		dx = -dx;
	}
	if(x + dx == B.RX() && y >= B.RY()-2 && y <= B.RY() +2) {
		dx = -dx;
	}

}