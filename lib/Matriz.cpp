/*
* Matriz.cpp
*
*  Created on: 31/07/2008
*      Author: v921335
*/

#ifdef _INCLUDE_IMPLEMENTATION

/////#include "Matriz.h"
#include <iostream>

template <class C, int X, int Y>
Matriz<C,X,Y>::Matriz(){
	this->inicializar();
}

template <class C, int X, int Y>
Matriz<C,X,Y>::~Matriz(){}

template <class C, int X, int Y>
C * Matriz<C,X,Y>::matriz(){
	return this->_matriz;
}

template <class C, int X, int Y>
void Matriz<C,X,Y>::matriz( Matriz<C,X,Y> * matriz ){
	this->_matriz = matriz;
}

template <class C, int X, int Y>
C * Matriz<C,X,Y>::agregar(C* valor, int xIndex, int yIndex){
	if ( this->sonIndicesValidos(xIndex,yIndex) ){
		this->_matriz[xIndex][yIndex] = valor;
		return valor; // cuando esta bien, devuelve lo que agrega, sino NULL
	}
	return NULL;
}

template <class C, int X, int Y>
C * Matriz<C,X,Y>::obtener(int xIndex, int yIndex){
	if ( this->sonIndicesValidos(xIndex,yIndex) )
		return (this->_matriz)[xIndex][yIndex];
	return NULL; // cuando los limites estan mal
}


template <class C, int X, int Y>
bool Matriz<C,X,Y>::esPosicionValida(int posicion){
	return ( posicion < X * Y and posicion >= 0 );
}


template <class C, int X, int Y>
bool Matriz<C,X,Y>::sonIndicesValidos(int xIndex, int yIndex){
	if ( ( xIndex >= 0 and xIndex < X ) and ( yIndex >= 0 and yIndex < Y ) ) {
		return true;
	};
	return false;
}

template <class C, int X, int Y>
void Matriz<C,X,Y>::borrar() { this->inicializar(); }

template <class C, int X, int Y>
int Matriz<C,X,Y>::limiteX(){ return this->_xLimit; }

template <class C, int X, int Y>
int Matriz<C,X,Y>::limiteY(){ return this->_yLimit; }


template <class C, int X, int Y>
void Matriz<C,X,Y>::inicializar(){
	for(int i=0;i<X;i++){
		for(int j=0;j<Y;j++){
			_matriz[i][j] = NULL;
		}
	}
}

#endif /* _INCLUDE_IMPLEMENTATION */

