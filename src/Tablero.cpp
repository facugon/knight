/*
 * Tablero.cpp
 *
 *  Created on: 29/07/2008
 *      Author: v921335
 */

#include <iostream>
#include "Tablero.h"
#include "PosicionTablero.h"

using namespace std;

Tablero::Tablero() {
	this->construir();
}

Tablero::~Tablero() {
	delete this->_posiciones;
}

Matriz<PosicionTablero,8,8> * Tablero::posiciones(){
	return this->_posiciones;
}

void Tablero::posiciones(Matriz<PosicionTablero,8,8> * aMatrizOrNULL){
	this->_posiciones = aMatrizOrNULL;
}

void Tablero::construir(){
	PosicionTablero * posicion;
	int contador=1;

///// creo una matriz de 64 posiciones de tablero
	this->posiciones( new Matriz<PosicionTablero,8,8> );

///// seteo todas las instancias de posiciones con sus valores en cada posicion de la matriz
	for(int x=0;x<8;x++){
		for(int y=0;y<8;y++){
			posicion = new PosicionTablero(x,y);
			// el valor es lo que necesito para obtener el camino
			posicion->valor( contador );
			posicion->posicion( 64-contador );
			this->posiciones()->agregar(posicion,x,y);
			contador++;
		}
	}

}


PosicionTablero * Tablero::obtenerPosicion(int posicionTablero){

	PosicionTablero * posicion = NULL;

	if ( this->posiciones()->esPosicionValida(posicionTablero) ){
		for(int x = 0;x < 8; x++){
			for(int y = 0;y < 8; y++){
				posicion = this->posiciones()->obtener(x,y);
				if( posicion->posicion() == posicionTablero ){
					return posicion;
				}
			}
		}
	};
	return NULL;
}

PosicionTablero * Tablero::obtenerPosicion(int xIndex, int yIndex){

	return this->posiciones()->obtener(xIndex,yIndex);

}

bool Tablero::caeAdentro(int xIndex, int yIndex){
	return ( xIndex >= 0 and xIndex < 8 and yIndex >= 0 and yIndex < 8 );
}

