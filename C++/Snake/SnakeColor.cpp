#include "miniwin.h"

using namespace miniwin;

const int XTAM = 80, YTAM = 40;
const int SZ = 12;

struct Punto {
	int x, y;
};

void cuadrado(const Punto& p, int c) {
	color(c);
	rectangulo_lleno(p.x*SZ, p.y*SZ, (p.x+1)*SZ-1, (p.y+1)*SZ-1);
}

int main() {
	vredimensiona(XTAM * SZ, YTAM * SZ);
	Punto cabeza = {30, 20};
	int vx = 1, vy = 0; //velocidad
	list<Punto> cola;
	int retraso = 0;
	int t = tecla();
	while(t != ESCAPE) {
		retraso++;
		if(t == ARRIBA) {
			vx = 0, vy = -1;
		} else if(t == ABAJO) {
			vx = 0, vy = 1;
		} else if(t == IZQUIERDA) {
			vx = -1, vy = 0;
		} else if(t == DERECHA) {
			vx = 1, vy = 0;
		}
		if(retraso == 8) {
			cola.push_back(cabeza);
			cabeza.x += vx;
			cabeza.y += vy;
			retraso = 0;
		}
		borra();
		list<Punto>::const_iterator it;
		cuadrado(cabeza, VERDE);
		refresca();
		espera(30);
		t = tecla();
	}
	vcierra();
	return 0;
}