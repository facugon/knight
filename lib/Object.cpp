#include "Object.h"

/*	--------------------------------------------------
 * 	Clase .
 *
 *
 * 	creación 26/03/08
 * 	ultima modificación 27/03/08
 *	-------------------------------------------------- */

using namespace std;

Object::Object(){
	this->nombre(NULL);
}

Object::~Object(){
	delete this->nombre();
}

bool Object::isEqual ( Object * objeto ) {
	return this == objeto;
}

bool Object::isNull ( Object * objeto ) {
	return objeto == NULL;
}

bool Object::notNull ( Object * objeto ) {
	return not this->isNull( objeto );
}

bool Object::notEqual ( Object * objeto ) {
	return not this->isEqual( objeto );
}

void Object::inspeccionar(){
	cout << this->_nombre << endl;
}

string * Object::nombre(){
	return this->_nombre;
}

void Object::nombre(string * nombre){
	this->_nombre = nombre;
}

