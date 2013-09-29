#include "miniwin.h"

using namespace miniwin;

const int TAM = 25;

struct Coord
{
	int x, y;
};

struct Pieza
{
	Coord orig;
	Coord perif[3];
};

void cuadrado(int x, int y, int col) {
	color(col);
	rectangulo_lleno(x * TAM,
					 y * TAM,
					 x * TAM + TAM,
					 y * TAM + TAM);
}

void pieza_s1_horiz(int x, int y) {
	color(VERDE);
	cuadrado(x, y);
	cuadrado(x - 1, y - 1);
	cuadrado(x, y - 1);
	cuadrado(x + 1, y);
}

void pinta_pieza(const Pieza& P) {
	cuadrado(VERDE);
	cuadrado(P.orig.x,P.orig.y);
	for(int i = 0; i < 3; i++) {
		cuadrado(P.orig.x + P.perif[i].x,
		         P.orig.y + P.perif[i].y);
	}
}

void pieza_s1_vert(int x, int y) {
	color(VERDE);
	cuadrado(x + 1, y - 1);
	cuadrado(x + 1, y);
	cuadrado(x + 1, y);
	cuadrado(x, y + 1);	
}

int main() {
	vredimensiona(TAM * 10, TAM * 20);
	// pieza_s1_horiz(2,2);
	// pieza_s1_vert(2,6);
	int x = 0, y = 0;
	int t = tecla();
	pieza_s1(x,y);
	refresca();
	while(t != ESCAPE) {
		if(t == ABAJO) {
			y++;
		} else if(t == ARRIBA) {
			y--;
		} else if(t == IZQUIERDA) {
			x--;
		} else if(t == DERECHA) {
			x++;
		}
		if(t != NINGUNA) {
			borra();
			pieza_s1(x,y);
			refresca();
		}
		t = tecla();
	}
	vcierra();
}