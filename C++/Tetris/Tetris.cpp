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
	rectangulo_lleno(20 + 1 + x * TAM,
					 20 + 1 + y * TAM,
					 20 + x * TAM + TAM,
					 20 + y * TAM + TAM);
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

const Coord perifs[6][3] = {
 { {1,0}, {0,1}, {1,1} }, //Cuadrado
 { {1,0}, {-1,1}, {0,1} }, //S
 { {0,1}, {1,1}, {-1,0} }, // 2
 { {0,1}, {0,-1}, {1,1} }, // L
 { {0,1}, {0,-1}, {-1,1} }, //Lr
 { {-1,0}, {1,0}, {0,1} }, //T
 { {1,0}, {0,-1}, {0,2} }, //Palo     
};

void pieza_nueva(Pieza& P) {
	P.orig.x = 12;
	P.orig.y = 2;
	P.color = 1 + rand() % 6;
	//Pieza al azar		
	int r = rand() % 7;
	for (int i = 0; i < 3; ++i) {
	 	P.perif[i] = perifs[r][i];
	} 
	P.perif[0].x = 1; P.perif[0].y = 0;
	P.perif[1].x = 1; P.perif[1].y = 1;
	P.perif[2].x = 0; P.perif[2].y = 1;
}

bool tablero_fila_llena(const Tablero& T, int fila) {
	for (int i = 0; i < COLUMNAS; ++i) {
		if (T[i][fila] == NEGRO) return false;
	}
	return true;
}

void tablero_colapsa(Tablero& T, int fila) {
	//Copiar de abajo a arriba
	for (int j = fila; j < 0; j--) {
		for (int i = 0; i < COLUMNAS; ++i) {
			T[i][fila] = T[i][j-1];
		}
	}
	for (int i = 0; i < COLUMNAS; ++i) {
		T[i][0] = NEGRO;
	}
}

int tablero_cuenta_lineas(Tablero& T) {
	int fila = FILAS - 1, cont = 0;
	while(fila >= 0) {
		if(tablero_fila_llena(T, fila)) {
			tablero_colapsa(T, fila);
		} else {
			fila--;
		}
	}
	return cont;
}

void repinta(const Tablero& T, const Pieza& p, const Pieza& sig ) {
	const int ancho = TAM * COLUMNAS, alto = TAM * FILAS;
	borra();
	tablero_pinta(T);
	color_rgb(128,128, 128);
	linea(20, 20, 20, 20 + alto);
	linea(0, 20 + alto, 20 + ancho);
	linea(20 + ancho, 20 + alto, 20 + ancho, 0);
	texto(40 + ancho,20,"Pieza Siguiente");
	texto(40 + ancho,150,"Nivel");
	texto(40 + ancho,250,"Puntos");	
	pinta_pieza(p)
	pinta_pieza(sig)	
	refresca();	
}

int main() { 
	vredimensiona(TAM * COLUMNAS + 220, TAM * FILAS + 100);
	srand(time(0));

	Tablero T;
	vacia_tablero(T);
	pinta_tablero(T);
	// pieza_s1_horiz(2,2);
	// pieza_s1_vert(2,6);
	// int x = 0, y = 0;
	Pieza s1 = { {2 , 2}, { { -1, -1}, { 0, -1}, { 1, 0} } };
	Pieza c,sig;
	int tic = 0;
	pieza_nueva(c);
	pieza_nueva(sig);
	sig.orig.x = 5;

	repinta(T, c,sig);
	int t = tecla();
	pinta_pieza(s1);
	//pieza_s1(x,y);
	refresca();
	while(t != ESCAPE) {
		if(t == NINGUNA && tic > 30) {
			tic = 0;
			t = ABAJO;
		}

		Pieza copia = c;
		int x = c.orig.x;
		int y = c.orig.y;
		if(t == DERECHA) {
			rota_derecha(s1);
		} else if(t == IZQUIERDA) {
			rota_izquierda(c);
		} 
		if(t != NINGUNA) {
			repinta(T, c,sig);
		}

		// Si hay Colision
		if(tablero_colision(T, c)) {
			c = copia;
			if(t == ABAJO) {
				tablero_incrusta_pieza(T, c);
				int cont = tablero_cuenta_lineas(T,c);
				c = sig;
				pieza_nueva(sig);
				c.orig.x = 5;
			}			
		}
		espera(33);
		tic++;
		t = tecla();
	}
	vcierra();
	return 0;
}