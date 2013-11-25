#include "miniwin.h"
using namespace miniwin;

const int XTAM = 800;
const int YTAM = 600;
const int RADIO = 30;

int main() {
	vredimensiona(XTAM, YTAM);
	int x = 50, y= 50;
	int dx = 2, dy =2; 
	while (tecla() != ESCAPE)
	{
		/* Pasos para crear una Animacion borrar, pintar, refrescar */
		borra();
		circulo(x, y, 30);
		refresca();
		x += dx;
		y += dy;
		// Velocidad  = cantve pixe Pelota * seg
		// Radio 30
		if(x > XTAM - RADIO || x < RADIO) {
			dx = -dx;
		}
		if (y > YTAM - RADIO || y < RADIO) {
			dy = -dy;
		}
		espera(10);
	}
	vcierra();
	return 0;
}