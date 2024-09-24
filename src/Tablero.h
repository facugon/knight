/*
 * Tablero.h
 *
 *  Created on: 29/07/2008
 *      Author: v921335
 */

#ifndef TABLERO_H_
#define TABLERO_H_

#include <iostream>
#include "PosicionTablero.h"
#include "../lib/Framework.h"

class Tablero : public Object {
public:
	Tablero();
	virtual ~Tablero();

	Matriz<PosicionTablero,8,8> * posiciones();
	void posiciones(Matriz<PosicionTablero,8,8> *);

	PosicionTablero * obtenerPosicion(int posicion);
	PosicionTablero * obtenerPosicion(int xIndex, int yIndex);
	bool caeAdentro(int,int);

private:
	Matriz<PosicionTablero,8,8> * _posiciones;
	void construir(); // construye el tablero
};

#endif /* TABLERO_H_ */
