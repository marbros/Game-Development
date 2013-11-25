#include "miniwin.h"
using namespace miniwin;

int main() {
	vredimensiona(800, 600);
	int x = 200, y= 200;
	for (int i = 0; i < 200; ++i)
	{
		/* Pasos para crear una Animacion borrar, pintar, refrescar */
		borra();
		circulo(x, y, 30);
		refresca();
		x += 2;
		y += 2;
		espera(10);
	}
	circulo(200, 200, 30);
	refresca();
	return 0;
}