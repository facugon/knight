#include "Char.h"

Char::Char(){}

Char::~Char(){}

Char::Char( char caracter ){
	
	this->_caracter ( caracter );

}

char Char::get() {

	return this->_caracter();

}

char Char::_caracter () {
	
	return * (this->caracter);

}

void Char::_caracter ( char caracter ) {

	this->caracter = new char(caracter);

}

