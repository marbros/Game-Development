#include <cstdlib>
#include "miniwin.h"
#include <ctime>

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

	Coord posicion(int n) const;
};

Coord Pieza::posicion(int n) {
	Coord ret = { orig.x, orig.y };
	if(n != 0) {
		ret.x += perif[n-1].x;
		ret.y += perif[n-1].y;
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
	for(int i = 0; i < 4; i++) {
		Coord c = P.posicion(i);
		cuadrado(c.x, c.y);
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
	// int ox = P.orig.x, oy = P.orig.y;
	// T[ox][oy] = P.color;
	for (int i = 0; i < 4; ++i) {
		Coord c = P.posicion(i);
		T[c.x][c.y] = P.color;
	// 	T[ox + P.perif[i].x][oy + P.perif[i].y] = P.color;
	}
}

bool tablero_colision(const Tablero& T, const Pieza& P) {
	for (int i = 0; i < 4; ++i) {
		Coord c = P.posicion(i);
		//Comprobar limites
		if(c.x < 0 || c.x >= COLUMNAS) {
			return true;
		}
		if(c.y < 0 || c.y >= FILAS) {
			return true;
		}
		//Mirar "basurilla"
		if(T[c.x][c.y] != NEGRO) {
			return true;
		}
	}
	return false;
}

void pieza_nueva(Pieza& P) {
	P.orig.x = 5;
	P.orig.y = 3;
	P.color = 1 + rand() % 6;
	P.perif[0].x = 1; P.perif[0].y = 0;
	P.perif[1].x = 1; P.perif[1].y = 1;
	P.perif[2].x = 0; P.perif[2].y = 1;
}


int main() {
	srand(time(0));

	Tablero T;
	vacia_tablero(T);
	pinta_tablero(T);
	//vredimensiona(TAM * COLUMNAS, TAM * FILAS);
	// pieza_s1_horiz(2,2);
	// pieza_s1_vert(2,6);
	// int x = 0, y = 0;
	Pieza s1 = { {2 , 2}, { { -1, -1}, { 0, -1}, { 1, 0} } };
	Pieza c;
	pieza_nueva(c);
	int t = tecla();
	pinta_pieza(s1);
	//pieza_s1(x,y);
	refresca();
	while(t != ESCAPE) {
		int x = c.orig.x;
		int y = c.orig.y;
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

		// Si hay Colision
		if(tablero_colision(T, c)) {
			c.orig.x = x;
			c.orig.y = y;
		}
		t = tecla();
	}
	vcierra();
	return 0;
}