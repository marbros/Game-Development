#include <windows.h>
#include <iostream>
#include "miniwin.h"
#include <list>;

using namespace miniwin;
using namespace std;

const int XTAM = 80, YTAM = 40;
const int SZ = 12;

struct Punto {
	int x, y;
};

void gotoxy(int x, int y) {
	HANDLE hCon;
	COORD dwPos;

	dwPos.X = x;
	dwPos.Y = y;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hCon,dwPos);
}

void pintar() {
	//lineas hori
	for (int i = 2; i < 78; ++i) {
	 	gotoxy(i,3);
	 	printf("%c", 205);
		gotoxy(i,23);
		printf("%c", 205);
	}
	//lineas Ver
	for (int i = 4; i < 23; ++i) {
	 	gotoxy(2,i); printf("%c", 186);
		gotoxy(77,i); printf("%c", 186);
	}
	//Esquinas
	gotoxy(2,3); printf("%c",201);
	gotoxy(2,23); printf("%c",200);
	gotoxy(77,3); printf("%c",187);
	gotoxy(77,23); printf("%c",188);
}

void cuadrado(const Punto& p, int c) {
	color(c);
	rectangulo_lleno(p.x*SZ, p.y*SZ, (p.x+1)*SZ-1, (p.y+1)*SZ-1);
}

bool hay_choque(const Punto& cabeza, const list<Punto>& cola) {
	if(cabeza.x >= XTAM || cabeza.x < 0) {
		return true;	
	} 
	if(cabeza.y >= YTAM || cabeza.y < 0) {
		return true;
	} 
	list<Punto>::const_iterator it;
	for (it = cola.begin(); it != cola.end(); it++) {
		if(cabeza.x == it->x && cabeza.y == it->y) {
			return true;
		}
	}
	return false;
}

Punto al_azar() {
	Punto p = {rand() % XTAM, rand() % YTAM};
	return p;
}

int main() {
	vredimensiona(XTAM * SZ, YTAM * SZ);
	pintar();
	Punto cabeza = {30, 20};
	Punto comida = al_azar();
	int vx = 1, vy = 0; //velocidad
	list<Punto> cola;
	int retraso = 0, engorda = 0;
	int t = tecla();
	bool choque = false;
	while(t != ESCAPE && !choque) {
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
			cola.push_front(cabeza);
			if(engorda > 0) {
				engorda--;
			}else {
				cola,pop_back();
			}
			cabeza.x += vx;
			cabeza.y += vy;
			if(hay_choque(cabeza, cola)) {
				choque = true;
			} else if(cabeza.x == comida.x && cabeza.y = = comida.y) {
				engorda = 5;
				comida = al_azar();
				if(hay_choque(comida, cola) || comida.y == cabeza.y) {
					comida = al_azar();
				}
			}
			retraso = 0;
		}
		if(!choque) {
			borra();
			list<Punto>::const_iterator it;
			for(it = cola.begin(); it != cola.end(); it++) {
				cuadrado(*it, VERDE);
			}
			cuadrado(cabeza, ROJO);
			cuadrado(comida, AMARILLO);
			refresca();
		}
		espera(30);
		t = tecla();
	}
	//vcierra();
	return 0;
}