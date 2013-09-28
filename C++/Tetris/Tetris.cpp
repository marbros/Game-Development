#include "miniwin.h"

using namespace miniwin;

const int TAM = 25;

void cuadrado(int x, int y, int col) {
	color(col);
	rectangulo_lleno(x * TAM,
					 y * TAM,
					 x * TAM + TAM,
					 y * TAM + TAM);
}

void pieza_s1(int x, int y) {
	color(VERDE);
	cuadrado(x, y);
	cuadrado(x + 1, y + 0);
	cuadrado(x + 1, y + 1);
	cuadrado(x + 2, y + 1);
}

int main() {
	vredimensiona(TAM * 10, TAM * 20);
	for(int i = 0; i < 10; i++) {
		cuadrado(1, i*2, AMARILLO);
	}
	refresca();
}