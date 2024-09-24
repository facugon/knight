/*
 * PosicionTablero.cpp
 *
 *  Created on: 29/07/2008
 *      Author: Facundo
 */

#include "PosicionTablero.h"
#include <iostream>

PosicionTablero::PosicionTablero() {

	this->ocupada(false);
}

PosicionTablero::PosicionTablero(int x, int y) {

	this->ocupada(false);
}

PosicionTablero::~PosicionTablero() {}

////////////////////////////////////////////////////////////////////////

void PosicionTablero::valor(int valor){
	this->_valor = valor;
}
void PosicionTablero::posicion(int pos){
	this->_posicion = pos;
}
void PosicionTablero::ocupada(bool valor){
	this->_ocupada = valor;
}

int PosicionTablero::valor(){
	return this->_valor;
}
int PosicionTablero::posicion(){
	return this->_posicion;
}
bool PosicionTablero::ocupada(){
	return this->_ocupada;
}
