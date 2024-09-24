/*
 * PosicionTablero.h
 *
 *  Created on: 29/07/2008
 *      Author: Facundo
 */

#ifndef POSICIONTABLERO_H_
#define POSICIONTABLERO_H_

class PosicionTablero {
public:
	PosicionTablero();
	PosicionTablero(int x, int y);
	virtual ~PosicionTablero();

	void valor(int);
	void ocupada(bool);
	void posicion(int);

	int valor();
	int posicion();
	bool ocupada();
private:
	int _valor;
	int _posicion;
	bool _ocupada;
};

#endif /* POSICIONTABLERO_H_ */
