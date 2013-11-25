#include "miniwin.h"
using namespace miniwin;

const int XTAM = 400;
const int YTAM = 300;
const int RADIO = 15;

int main() {
	vredimensiona(XTAM, YTAM);
	float x = 50, y= 50;
	float dx = 2, dy =2; 
	while (tecla() != ESCAPE)
	{
		/* Pasos para crear una Animacion borrar, pintar, refrescar */
		borra();
		circulo(x, y, RADIO);
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
		dy += 0.3;
		espera(10);
	}
	vcierra();
	return 0;
}