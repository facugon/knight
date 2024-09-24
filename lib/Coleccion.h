#ifndef COLECCION_H
#define COLECCION_H

#include <iostream>

#include "Object.h"
#include "Nodo.h"

template <class C> class Coleccion : public Object {
public:
	class iterator;

	Coleccion() {
	    this->primero = NULL;
	    this->ultimo = NULL;
	    this->size = 0;
	};

	virtual ~Coleccion() {};

	bool isEmpty () {
		return this->primero == NULL;
	};

	bool notEmpty () {
		return not ( this->primero == NULL );
	}

	C * remover(C * valor) {
		Nodo<C> * nodo;

		if ( nodo = this->buscarNodoCon(valor) ){
			this->sacarNodo(nodo);
			delete nodo;
		}
		return valor;
	};

	int _size() { return this->size; };

	void add(C * valor) {
		this->agregarNodo( new Nodo<C>( valor, this->_ultimo() ) );
		this->incSize();
	};

	void add(Coleccion * col) {
		int i = 0;
		Nodo<C> * aux = col->_primero();

		for(;i < col->_size(); i++){
			this->add( aux->_valor() );
			aux = aux->_siguiente();
		}
	};

	C * first() { return this->_primero()->_valor(); };

	C * last() { return this->_ultimo()->_valor(); };
/* ------------------------------------------------------
 * Método Coleccion >> detectar.
 * - Evalua cada uno de los objetos de la colección con el
 * criterio pasado como parámetro y lo retorna si lo encuentra
 * si no retorna NULL.
 * - Retorna el objeto encontrado o NULL.
 * - Recibe como parámetro un puntero al metodo o funcion que evalua
 * un objeto del mismo tipo que el de la coleccion.
 * - La funcion evaluadora debe recibir como parametro un objeto
 * del mismo tipo que el de la coleccion y devolver un tipo bool.
 *
 * ejemplo de funcion evaluadora
 *
 * 		bool funcEvaluadora ( Object * obj )
 * 			{ return obj->atributo not_eq NULL }
 *
 * creacion 01/04/2008
 * modificacion 01/04/2008
 * Facundo
 * ------------------------------------------------------ */
	C * detect( bool (metodoEvaluador)(C *) ){
		int i = 0;
		Nodo<C> * aux = this->_primero();

		for (; i< this->size; i++){
			if( metodoEvaluador( aux->_valor() ) ) return aux->_valor();
			aux = aux->_siguiente();
		}
		return NULL;	// si no encuentra el objeto buscado devuelve NULL
	};

////////////////////////////////////////////////////////////////

	bool include ( C * valor ) {
		iterator it;

		it = this->iterator();

		while ( not it.isNull() ) {
			if ( valor->isEqual ( it.current() ) ) return true;
			it->next();
		}
		return false;

	};

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////

	iterator * iterador () {
		return new iterator( this );
	};


private: // el manejo de Coleccion, es una lista doble enlasada
	// atributos ----------------------
	    Nodo<C> * primero;
	    Nodo<C> * ultimo;
	    int size;
	//---------------------------------

	Nodo<C> * _primero() { return this->primero; };

	Nodo<C> * _ultimo() { return this->ultimo; };

	void _primero(Nodo<C> * nodo) { this->primero = nodo; };

	void _ultimo(Nodo<C> * nodo) { this->ultimo = nodo; };

	void incSize() { this->size++; };

	void decSize() { this->size--; };

	void _size(int valor) { return this->size = valor; };

	void agregarNodo(Nodo<C> * nodo) {
		if ( this->_primero() == NULL ) this->_primero(nodo);
		else this->_ultimo()->_siguiente( nodo );
		this->_ultimo( nodo );
	};

	void sacarNodo(Nodo<C> * nodo){
		Nodo<C> * nodoAnt = nodo->_anterior();
		Nodo<C> * nodoSig = nodo->_siguiente();


		if ( this->_size() == 1 ){// es el único
			this->_ultimo( NULL );
			this->_primero( NULL );
		}
		else if ( nodoAnt == NULL ) {// es el primero
			this->_primero( nodoSig );
			nodoSig->_anterior( NULL );
		}
		else if ( nodoSig == NULL ) {// es el último
			this->_ultimo( nodoAnt );
			nodoAnt->_siguiente( NULL );
		}
		else { // uno del medio
			nodoAnt->_siguiente(nodoSig);
			nodoSig->_anterior(nodoAnt);
		}

		this->decSize();
	};

	Nodo<C> * buscarNodoCon( C * valor ){
		int i = 0;
		Nodo<C> * aux = this->_primero();

		for(; i < this->_size(),aux->_valor() not_eq valor; i++ )
			aux = aux->_siguiente();

		return aux;
	};
};
// ---------------------------------------------------------
// ---------------------------------------------------------
// ---------------------------------------------------------

template <class C> class Coleccion<C>::iterator {
public:
	iterator() {
		this->coleccion	= NULL;
		this->actual 	= NULL;
	};

	iterator( Coleccion<C> * col ) {
		this->coleccion	= col->_primero();
		this->actual 	= col->_primero();
	};

	virtual ~iterator(){};

// ---------------------------------------------------------

	void operator= ( Coleccion<C> * col ) {
		this->coleccion	= col->_primero();
		this->actual 	= col->_primero();
	};

	void operator++ () {
		this->_actual( this->_actual()->_siguiente() );
	};

	void operator-- () {
		this->_actual( this->_actual()->_anterior() );
	};

	void inc () {	// aumenta una posicion en el iterador
		this->_actual( this->_actual()->_siguiente() );
	};

	void dec () {	// disminuye una posicion en el iterador
		this->_actual( this->_actual()->_anterior() );
	};

	bool hasNext () {
		return this->_actual()->_siguiente() not_eq NULL;
	};

	bool hasPrevious () {
		return this->_actual()->_anterior() not_eq NULL;
	};

	bool isNull() {
		return this->_actual() == NULL;
	}

	C * next () { // retorna el elemento siguiente
		this->inc();
		return this->_actual()->_valor();
	};

	C * previous () { // retorna el elemento anterior
		this->dec();
		return this->_actual()->_valor();
	};

	C * current () { // retorna el elemento actual
		return this->_actual()->_valor();
	};

	void reset() {	// pone el iterador en la primer posicion
		this->_actual( this->_coleccion() );
	};

private:
// elemento sobre el que se itera la col, apunta al ultimo leido
	Nodo<C> * coleccion;
	Nodo<C> * actual;

	Nodo<C> * _actual () {	// getter
		return this->actual;
	};

	void _actual ( Nodo<C> * nodo ) {	// setter
		this->actual = nodo;
	};

	Nodo<C> * _coleccion () {	// getter
		return this->coleccion;
	};

	void _coleccion ( Nodo<C> * nodo ) {	// setter
		this->coleccion = nodo;
	};
};



#endif // Coleccion_H














