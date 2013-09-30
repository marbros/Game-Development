#include "miniwin.h"

using namespace miniwin;

const int TAM = 25;
const int FILAS = 20;
const int COLUMNAS = 10;


struct Coord
{
	int x, y;
};

struct Pieza
{
	Coord orig;
	Coord perif[3];
	int color;

	Coord posicion(int n);
};

Coord Pieza::posicion(int n) {
	Coord ret;
	if(n == 0) {
		ret.x = orig.x;
		ret.y = orig.y;
		return ret;
	} else {
		ret.x = orig.x + perif[n-1].x;
		ret.y = orig.y + perif[n-1].y;
	}
	return ret;
}

typedef int Tablero[COLUMNAS][FILAS];

void cuadrado(int x, int y, int col) {
	color(col);
	rectangulo_lleno(x * TAM,
					 y * TAM,
					 x * TAM + TAM,
					 y * TAM + TAM);
}

void pinta_pieza(const Pieza& P) {
	cuadrado(P.color);
	cuadrado(P.orig.x,P.orig.y);
	for(int i = 0; i < 3; i++) {
		cuadrado(P.orig.x + P.perif[i].x,
		         P.orig.y + P.perif[i].y);
	}
}

Coord rota_derecha(const Coord& c) {
	Coord ret = { -c.y, c.x};
	return ret;
}

void rota_derecha(Pieza& P) {
	for (int i = 0; i < 3; ++i) {
		P.perif[i] = rota_coord(P.perif[i]);
	}
}

Coord rota_izquierda(const Coord& c) {
	Coord ret = { c.y, -c.x};
	return ret;
}

void rota_izquierda(Pieza& P) {
	for (int i = 0; i < 3; ++i) {
		P.perif[i] = rota_izquierda(P.perif[i]);
	}
}

void tablero_vacia(Tablero& T) {
	for (int i = 0; i < COLUMNAS; ++i) {
		for (int j = 0; j < FILAS; ++j) {
			T[i][j] = NEGRO; //Casilla Vacia.
		}
	}
}

void tablero_pinta(const Tablero& T) {
	for (int i = 0; i < COLUMNAS; ++i) {
		for (int j = 0; j < FILAS; ++j) {
			color(T[i][j]);
			cuadrado(i ,j);
		}
	}	
}

void tablero_incrusta_pieza(Tablero& T, const Pieza& P) {
	int ox = P.orig.x, oy = P.orig.y;
	T[ox][oy] = P.color;
	for (int i = 0; i < 3; ++i) {
		T[ox + P.perif[i].x][oy + P.perif[i].y] = P.color;
	}
}

int main() {
	Tablero T;
	vacia_tablero(T);
	pinta_tablero(T);
	//vredimensiona(TAM * COLUMNAS, TAM * FILAS);
	// pieza_s1_horiz(2,2);
	// pieza_s1_vert(2,6);
	// int x = 0, y = 0;
	Pieza s1 = { {2 , 2}, { { -1, -1}, { 0, -1}, { 1, 0} } };
	int t = tecla();
	pinta_pieza(s1);
	//pieza_s1(x,y);
	refresca();
	while(t != ESCAPE) {
		if(t == DERECHA) {
			rota_derecha(s1);
		} else if(t == IZQUIERDA) {
			rota_izquierda(s1);
		} 
		if(t != NINGUNA) {
			borra();
			pinta_pieza(s1)
			refresca();
		}
		t = tecla();
	}
	// vcierra();
	return 0;
}