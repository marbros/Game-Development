#include "Nave.h"

class Asteroide {
	int x,y;
	
	public:
		Asteroide(int _x, int _y):x(_x), y(_y) {}
		int X() { return x; }
		int Y() { return y; }
		void pintar();
		void mover();
		void choque(nave &N);
};

void Asteroide::pintar() {
	gotoxy(x,y); printf("%c",184);
}

void Asteroide::mover() {
	gotoxy(x,y); printf(" ");
	y++;
	if (y > 32) {
		x = rand()%71 + 4;
		y = 4;
	}
	pintar();
}

void Asteroide::choque(nave &N) {
	if ((x >= N.X() && x < N.X()+6) && (y >= N.Y() && y <= N.Y()+2)) {
		N.COR();
		N.borrar();
		N.pintar();
		N.pintar_corazones();
		x = rand()%71 + 4;
		y = 4;		
	}
}