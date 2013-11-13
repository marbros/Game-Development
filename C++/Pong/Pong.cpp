#include <stdio.h>
#include ""

class JUGADOR {
	int x,y;
	public:
		JUGADOR(int _x, int _y);
		void pintar() const;
		void borrar() const;	
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

int main() {
	
	JUGADOR A(6,15);
	A.pintar();
	JUGADOR B(74,15);
	B.pintar();
	return 0;
}