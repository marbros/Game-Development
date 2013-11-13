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
	gotoxy(x, y-1);
}

int main() {
	
}