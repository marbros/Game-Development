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
};

typedef int Tablero[COLUMNAS][FILAS];

void cuadrado(int x, int y, int col) {
	color(col);
	rectangulo_lleno(x * TAM,
					 y * TAM,
					 x * TAM + TAM,
					 y * TAM + TAM);
}

void pinta_pieza(const Pieza& P) {
	cuadrado(VERDE);
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

void vacia_tablero(Tablero& T) {
	for (int i = 0; i < COLUMNAS; ++i) {
		for (int j = 0; j < FILAS; ++j) {
			T[i][j] = NEGRO; //Casilla Vacia.
		}
	}
}

void pinta_tablero(const Tablero& T) {
	for (int i = 0; i < COLUMNAS; ++i) {
		for (int j = 0; j < FILAS; ++j) {
			color(T[i][j]);
			cuadrado(i ,j);
		}
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