/*
 * Matriz.h
 *
 *  Created on: 30/07/2008
 *      Author: v921335
 */

#ifndef MATRIZ_H_
#define MATRIZ_H_

#include <iostream>
#include "Framework.h"

template <class C, int X, int Y> class Matriz : public Object {
public:

	Matriz();
	virtual ~Matriz();
	C * matriz();
	void matriz( Matriz<C,X,Y> * matriz );
	C * agregar(C* valor, int xIndex, int yIndex);
	C * obtener(int xIndex, int yIndex);
	bool sonIndicesValidos(int xIndex, int yIndex);
	void borrar();
	int limiteX();
	int limiteY();
	bool esPosicionValida(int posicion);

private:

	void inicializar();
	C * _matriz[X][Y];
};

#define _INCLUDE_IMPLEMENTATION
#include "Matriz.cpp"
#undef _INCLUDE_IMPLEMENTATION

#endif /* MATRIZ_H_ */



