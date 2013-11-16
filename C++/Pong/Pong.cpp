#include <stdio.h>
#include <conio.h>
#include ""

class JUGADOR {
	int x,y;
	public:
		JUGADOR(int _x, int _y);
		void pintar() const;
		void borrar() const;
		void Y(int _y) { y += _y; }	
		int RY() { return y; }
};

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

class PELOTA
{
	int x,y;
	int dx, dy;
public:
	PELOTA(int _x, int _y, int dx, int dy);
	void pintar() const;
	void borrar() const;
	void mover();
	~PELOTA();

};

void PELOTA::PELOTA(int _x, int _y, int dx, int dy) : x(_x), y(_y), dx(_dx), dy(_dy) {}

PELOTA::pintar() const {
	gotoxy(x,y); printf("%c", 184);
}

void PELOTA::borrar() const {
	gotoxy(x,y); printf(" ");
}

void PELOTA::mover() {
	borrar();
	x += dx; y += dy;
	pintar();
	if(x + dx == 3 || x + dx == 76) {
		borrar();
		dx =- dx;
	} 
	if(y + dy == 3 || y + dy == 23) {
		dy = -dy;
	}

}

int main() {
	
	JUGADOR A(6,15);
	A.pintar();
	JUGADOR B(74,15);
	B.pintar();
	PELOTA P(38,14,1,1)

	char tecla;
	int cont = 0;
	while(1) {
		
		if(kbhit()) {
			A.borrar();	B.borrar();
			tecla = getch();
			if(tecla == 'q' && A.RY() > 5) A.Y(-1); else if(tecla == 'a' && A.RY() < 21) A.Y(1);
			if(tecla == 'o' && A.RY() > 5) B.Y(-1); else if(tecla == 'l' && B.RY() < 21) B.Y(1);
			A.pintar(); B.pintar();
		}
		if(!cont++) P.mover();
		if(cont > 5) cont = 0;
		pausa(10);
	}
	return 0;
}