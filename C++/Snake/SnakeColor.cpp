#include "miniwin.h"

using namespace miniwin;

const int XTAM = 80, YTAM = 40;
const int SZ = 12;

void cuadrado(int x, int y, int c) {
	color(c);
	rectangulo_lleno(x*SZ, y*SZ, (x+1)*SZ-1, (y+1)*SZ-1);
}

int main() {
	vredimensiona(XTAM * SZ, YTAM * SZ);
	for (int i = 0; i < 10; ++i) {
		cuadrado(10 + i, 10, VERDE);
	}
	refresca();
	return o;
}