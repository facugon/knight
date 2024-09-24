/*
 * Caballero.cpp
 *
 *  Created on: 29/07/2008
 *      Author: v921335
 */

#include <iostream>
#include "Caballero.h"
#include <stack>

Caballero::Caballero(){
	this->_posicion = NULL;
	this->_saltos = 0;

	movimientos[4].fila = 1; movimientos[4].columna = 2;
	movimientos[5].fila = 1; movimientos[5].columna = -2;
	movimientos[6].fila = -1; movimientos[6].columna = 2;
	movimientos[7].fila = -1; movimientos[7].columna = -2;

	movimientos[0].fila = 2; movimientos[0].columna = 1;
	movimientos[1].fila = 2; movimientos[1].columna = -1;
	movimientos[2].fila = -2; movimientos[2].columna = 1;
	movimientos[3].fila = -2; movimientos[3].columna = -1;

}

Caballero::~Caballero(){
	delete this->_posicion;
}

void Caballero::posicion(PosicionTablero * posicion){
	this->_posicion = posicion;
}

PosicionTablero * Caballero::posicion(void){
	return this->_posicion;
}

PosicionTablero * Caballero::mover(int xIndex,int yIndex){
	return NULL;
}

void Caballero::tablero(Tablero * tablero){
	this->_tablero = tablero;
}

Tablero * Caballero::tablero(){
	return this->_tablero;
}

void Caballero::obtenerCaminos(){
	this->posicion( this->tablero()->obtenerPosicion(56) );
	this->posicion()->ocupada(true);

	cout << "buscando caminos..." << endl;

	stack<int> * solucion = new stack<int>;
	solucion->push(0);
	this->puedeMoverseDesde(7,0,solucion);

	cout << "obtenidos todos los caminos" << endl;
}

// -----------------------------------------------------

int Caballero::saltos(){
	return this->_saltos;
}

void Caballero::saltos(int saltos){
	this->_saltos = saltos;
}

///// -----------------------------------------------------------------

void Caballero::incSaltos(){
	this->_saltos ++;
}

void Caballero::decSaltos(){
	this->_saltos --;
}

bool Caballero::pasaControles(stack<int> * solucion){

	if ( this->saltos() == 3  && this->posicion()->posicion() != 9 ) return false;
	if ( this->saltos() == 4  && this->posicion()->posicion() != 3 ) return false;
	if ( this->saltos() == 8  && this->posicion()->posicion() != 7 ) return false;
	if ( this->saltos() == 12 && this->posicion()->posicion() != 60 ) return false;
	if ( this->saltos() == 13 && this->posicion()->posicion() != 54 ) return false;
 	if ( this->saltos() == 23 && this->posicion()->posicion() != 11 ) return false;
	if ( this->saltos() == 31 && this->posicion()->posicion() != 63 ) return false;
	if ( this->saltos() == 33 && this->posicion()->posicion() != 31 ) return false;
	if ( this->saltos() == 35 && this->posicion()->posicion() != 36 ) return false;
	if ( this->saltos() == 39 && this->posicion()->posicion() != 0 ) return false;
	if ( this->saltos() == 43 && this->posicion()->posicion() != 32 ) return false;
	if ( this->saltos() == 53 && this->posicion()->posicion() != 34 ) return false;
	if ( this->saltos() == 63) this->tablero()->obtenerPosicion(56)->ocupada(false);
	if ( this->saltos() == 64 ){
		system("pause");
		while( ! solucion->empty() ) {
			cerr << solucion->top() << " ";
			solucion->pop();
		}
		cerr << endl;
		return false;
	}
	return true;
}

///// -----------------------------------------------------------------

bool Caballero::puedeMoverseDesde( int xIndex, int yIndex, stack<int> * solucion ){

	// BACKTRAKING

	PosicionTablero * unaPosicion;
	PosicionTablero * posicionAnterior = this->tablero()->obtenerPosicion(xIndex,yIndex);

	solucion->push( this->posicion()->valor() );

	if ( ! this->pasaControles(solucion) ) return false;

	for(int i=0;i<8;i++){

		int x = xIndex + movimientos[i].fila;
		int y = yIndex + movimientos[i].columna;

		if( this->tablero()->caeAdentro( x , y ) and
			! (unaPosicion = this->tablero()->obtenerPosicion( x , y ))->ocupada() ){
			this->ocuparPosicion(unaPosicion);
			this->incSaltos();

			if ( ! puedeMoverseDesde( x , y , solucion ) ){
				solucion->pop();
				this->decSaltos();
				this->ocuparPosicion(posicionAnterior);
				unaPosicion->ocupada(false);
			}
		}
	}
	return false;
}

void Caballero::ocuparPosicion(PosicionTablero * unaPosicion){
	this->posicion(unaPosicion);
	this->posicion()->ocupada(true);
}


