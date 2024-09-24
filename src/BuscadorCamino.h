/*
 * BuscadorCamino.h
 *
 *  Created on: 29/07/2008
 *      Author: v921335
 */

#ifndef BUSCADORCAMINO_H_
#define BUSCADORCAMINO_H_

#include "../lib/Framework.h"
#include <iostream>
#include "Tablero.h"
#include "Caballero.h"

class BuscadorCamino : public Object {
public:
	BuscadorCamino();
	virtual ~BuscadorCamino();
	Coleccion<PosicionTablero> * obtenerCaminoCon(Caballero *, Tablero *);
};

#endif /* BUSCADORCAMINO_H_ */
