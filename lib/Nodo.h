#ifndef NODO_H
#define NODO_H

#include <iostream>
#include "Object.h"


template <class C> class Nodo : public Object {
	public:
		Nodo(){
			valor = NULL;
			siguiente = NULL;
			anterior = NULL;
		};
	
		Nodo(C * valor, Nodo * anterior){
			this->_valor(valor);
			this->siguiente = NULL;
			this->anterior = anterior;
		};

		virtual ~Nodo() {};		

		C * _valor() { return this->valor; };

		Nodo * _siguiente() { return this->siguiente; };

		void _siguiente(Nodo * nodo) { this->siguiente = nodo; };
		
		Nodo * _anterior() { return this->anterior; };
		
		void _anterior(Nodo * nodo) { this->anterior = nodo; };

    private:
        C * valor;
        Nodo * siguiente;
        Nodo * anterior;
		void _valor(C * valor) { this->valor = valor; };

};

#endif // NODO_H
