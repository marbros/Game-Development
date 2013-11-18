class JUGADOR {
	int x,y;
	public:
		JUGADOR(int _x, int _y);
		void pintar() const;
		void borrar() const;
		void mover_cpu(int _x, int _y, int _dx);
		void Y(int _y) { y += _y; }	
		int RY() { return y; }
		int RX() { return x; }
};

class PELOTA
{
	int x,y;
	int dx, dy;
public:
	PELOTA(int _x, int _y, int dx, int dy);
	void pintar() const;
	void borrar() const;
	void mover(JUGADOR A, JUGADOR B);
	void asign(int _x, int _y) { x = _x; y = _y;}
	int PX () { return x; }
	int PY() { return y; }
	int DX() { return dx; }
	~PELOTA();

};

class MENU
{
public:
	void pintar_portada(int &a);
	~MENU();

	/* data */
};