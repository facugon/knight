#include "Integer.h"

Integer::Integer(){
	this->entero = NULL;
}

Integer::Integer( int entero ){

	this->_entero ( entero );

}

Integer::~Integer(){}

void Integer::_entero ( int entero ) {

	this->entero = new int(entero);

}

int Integer::_entero () {
	return * (this->entero) ;
}
