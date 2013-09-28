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

int main() {
	vredimensiona(TAM * 10, TAM * 20);
	for(int i = 0; i < 10; i++) {
		cuadrado(1, i*2, AMARILLO);
	}
	refresca();
}