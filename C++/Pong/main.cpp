#include <stdio.h>
#include <conio.h>
#include "pong.h"

int main() {

	int cont = 0, op_juego;	
	MENU M;	
	M.pintar_portada(op_juego);	
	JUGADOR A(6,15);
	A.pintar();
	JUGADOR B(74,15);
	B.pintar();

	PELOTA P(38,14,1,1)

	char tecla;
	M.pintar_portada(op_juego);
	while(1) {
		
		if(kbhit()) {
			A.borrar();	B.borrar();
			tecla = getch();
			if(tecla == 'q' && A.RY() > 5) A.Y(-1); else if(tecla == 'a' && A.RY() < 21) A.Y(1);
			if(tecla == 'o' && A.RY() > 5) B.Y(-1); else if(tecla == 'l' && B.RY() < 21) B.Y(1);
			A.pintar(); B.pintar();
		}
		if(!cont++) P.mover(A,B);
		if(cont > 5) cont = 0;
		pausa(10);
	}
	return 0;
}