/*
 * Caballero.h
 *
 *  Created on: 29/07/2008
 *      Author: v921335
 */

#ifndef CABALLERO_H_
#define CABALLERO_H_

#include "PosicionTablero.h"
#include "Tablero.h"
#include <stack>

// -------------------------

typedef struct movimiento{
	int columna;
	int fila;
} MOVIMIENTO;

// -------------------------

class Caballero {
public:
	Caballero();
	virtual ~Caballero();
	void posicion(PosicionTablero *);
	PosicionTablero * posicion(void);
	void tablero(Tablero *);
	Tablero * tablero();

	// mueve al caballero a una nueva posicion del tablero
	// retorna la posicion en la que cayo
	PosicionTablero * mover(int,int);

	void obtenerCaminos();
	int saltos();
	void saltos(int);
	bool puedeMoverseDesde(int,int,stack<int> *);
	void ocuparPosicion(PosicionTablero *);
	void incSaltos();
	void decSaltos();
	bool pasaControles(stack<int> *);

private:
	MOVIMIENTO movimientos[8];	// estructura estatica, no se modifican los movimientos
	PosicionTablero * _posicion;
	Tablero * _tablero;
	int _saltos;
};

#endif /* CABALLERO_H_ */



