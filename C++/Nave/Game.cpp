#include "Asteroide.h"
#include "Bala.h"
#include <list>
#include <stdlib.h>

using namespace std;

int main() {

	OcultarCursor();
	pintar_limites();
	nave N(37,30,3,3);
	N.pintar();
	N.pintar_corazones();	

	list<Asteroide*> A;
	list<Asteroide*>::iterator keyA;

	for (int i = 0; i < 5; ++i) {
		A.push_back(new Asteroide(rand()%75 + 3, rand()%5 + 4));
	}

	list<Bala*> B;
	list<Bala*>::iterator key;

	bool game_over = false;
	int puntos = 0;

	while(!game_over) {

		gotoxy(4,2); printf("Puntos %d", puntos);
		if(kbhit()) {
			char tecla = getch();
			if(tecla == 'a') {
				B.push_back(new Bala(N.X() + 2, N.Y() -1));
			}
		}

		for(key = B.begin(); key != B.end(); key++) {
			(*key)->mover();
			if((*key)->fuera()) {
				gotoxy((*key)->X(),(*key)->Y()); printf(" ");
				delete(*key);
				key = B.erase(key);
			}
		}

		for (keyA = A.begin(); keyA != A.end(); ++keyA)
		{
			(*keyA)->mover();
			(*keyA)->choque(N);
		}

		for (keyA = A.begin(); keyA != A.end(); ++keyA) {
			for (key = B.begin(); key != B.end(); ++key) {
				if((*keyA)->X() == (*key)->X() && (*keyA)->Y() + 1 == (*key)->Y() || (*keyA)->Y() == (*key)->Y()) {
					gotoxy((*key)->X(), (*key)->Y()); printf(" ");
					delete(*key);
					key = B.erase(key);

					A.push_back(new Asteroide(rand()%74 + 3, 4));
					gotoxy((*keyA)->X(), (*keyA)->Y()); printf(" ");
					delete(*keyA);
					keyA = A.erase(keyA);

					puntos += 5;
				}
			}
		}
		// ast1.mover(); ast1.choque(N);
		// ast2.mover(); ast2.choque(N); 
		// ast3.mover(); ast3.choque(N);
		if(N.VID() == 0) game_over = true;
		N.morir();
		N.mover();
		Sleep(33);		
	}

	system("pause");
	return 0;
}